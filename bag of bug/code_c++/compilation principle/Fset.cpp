#ifndef FSET_H
#define FSET_H
#include <fstream>
#include <iomanip>
#include <iostream>
#include <set>
#include <stack>
#include <string>
#include <vector>
using namespace std;

struct node
{
	char name;
	string tuidao;
};
class Fset
{
public:
	Fset();
	bool IsVn(char);
	int Get_Tindex(char);
	int Get_Nindex(char);
	void Get_Gram();
	void Full_First(char);
	void Full_Follow(char);
	void Maneger();
	void Show();

protected:
	int T;
	node gram[100];
	set<char> first[100];
	set<char> follow[100];
	vector<char> vt;
	vector<char> vn;
	vector<char> nvt;

	int Form[10][10];
	vector<char> Astack;
	vector<char> Inputs;
};

#endif

Fset::Fset()
{
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			Form[i][j] = -1;
		}
	}
}

bool Fset::IsVn(char ch)
{
	if (ch >= 'A' && ch <= 'Z')
		return true;
	return false;
}

int Fset::Get_Tindex(char ch)
{
	for (int i = 0; i < nvt.size(); i++)
	{
		if (nvt[i] == ch)
			return i;
	}

	return -1;
}

int Fset::Get_Nindex(char ch)
{
	for (int i = 0; i < vn.size(); i++)
	{
		if (vn[i] == ch)
			return i;
	}
	return -1;
}

void Fset::Get_Gram()
{
	FILE *fp;
	char ch;

	fp = fopen("D:\\G.txt", "r");
	for (int i = 0; i < 10; i++)
	{
		ch = fgetc(fp);
		//	cout<<ch<<endl;
		gram[i].name = ch;
		fgetc(fp);
		fgetc(fp);
		//	cout<<fp;
		ch = fgetc(fp);

		while (ch != '\n' && ch != EOF)
		{
			if (ch == '|')
			{
				i++;
				gram[i].name = gram[i - 1].name;
				ch = fgetc(fp);
			}
			gram[i].tuidao += ch;
			//	cout<<gram[i].tuidao;
			ch = fgetc(fp);
			//	cout<<ch<<endl;
		}
	}

	fclose(fp);
}

void Fset::Full_First(char ch)
{
	int tag = 0;
	int flag = 0;
	for (int i = 0; i < 10; i++)
	{
		if (gram[i].name == ch)
		{ //找推导的第一个字母，
			for (int j = 0; j < gram[i].tuidao.size(); j++)
			{
				if (!IsVn(gram[i].tuidao[j]))
				{ //如果是终结符，则直接压入
					first[Get_Nindex(ch)].insert(gram[i].tuidao[j]);
					break;
				}
				else
				{ //如果是非终结符，则压入该非终结符的除了空集以外的元素
					Full_First(gram[i].tuidao[j]);
					set<char>::iterator it;
					for (it = first[Get_Nindex(gram[i].tuidao[j])].begin(); it != first[Get_Nindex(gram[i].tuidao[j])].end(); it++)
					{
						if (*it == '$')
							flag = 1;
						else
							first[Get_Nindex(ch)].insert(*it);
					}
					if (flag == 0)
						break;
					else
					{
						tag += flag;
						flag = 0;
					}
				}
			}
			if (tag == gram[i].tuidao.size())
			{ //最后判断空集是否应该被压入
				first[Get_Nindex(ch)].insert('$');
			}
		}
	}
}

void Fset::Full_Follow(char ch)
{
	for (int i = 0; i < 10; i++)
	{
		if (ch == gram[0].name)
		{
			follow[Get_Nindex(gram[0].name)].insert('#');
		}
		int index = -1;
		int len = gram[i].tuidao.length();
		for (int j = 0; j < len; j++)
		{ //找到所要求的字符的位置
			if (gram[i].tuidao[j] == ch)
				index = j;
		}

		if (index != -1 && index < len - 1)
		{ //如果是aAx的类型
			char next = gram[i].tuidao[index + 1];
			if (!IsVn(next))
			{ // x是终结符则直接加入follow集
				follow[Get_Nindex(ch)].insert(next);
			}
			else
			{ //否则，就是aAB的类型，那么将它的右边的first集加入该符号的follow集合中
				int flag = 0;
				set<char>::iterator it;
				for (it = first[Get_Nindex(next)].begin(); it != first[Get_Nindex(next)].end(); it++)
				{
					if (*it == '$')
						flag = 1;
					else
						follow[Get_Nindex(ch)].insert(*it);
				}

				if (flag && gram[i].name != ch)
				{ //如果aAB形式中B的first集中有空，那么在向右取一位看是否仍然满足
					Full_Follow(gram[i].name);
					set<char>::iterator it;
					for (it = follow[Get_Nindex(gram[i].name)].begin(); it != follow[Get_Nindex(gram[i].name)].end(); it++)
					{
						follow[Get_Nindex(ch)].insert(*it);
					}
				}
			}
		}

		else if (index != -1 && index == len - 1 && ch != gram[i].name) //如果是aA型的，
		{
			Full_Follow(gram[i].name); //求其产生式左边的follow集合，并将其加入该follow集合中去
			set<char>::iterator it;
			char tmp = gram[i].name;
			for (it = follow[Get_Nindex(tmp)].begin(); it != follow[Get_Nindex(tmp)].end(); it++)
				follow[Get_Nindex(ch)].insert(*it);
		}
	}
}

void Fset::Maneger()
{
	this->Get_Gram(); // 36行代码， 打开文本文档并读取内容
	//先划分终结符集和非终结符集
	for (int i = 0; i < 10; i++)
	{
		int flag = 0;
		for (int j = 0; j < vn.size(); j++)
		{							   //求Vn集 非终结符集 名字
			if (vn[j] == gram[i].name) // garm中name存放名字，tuidao存放推导
				flag = 1;			   //如果集合中存在该非终结符（name一定是非终结符），则过，flag置1
		}
		if (flag == 0)
		{ //如果flag=0，说明终结符，则压入
			vn.push_back(gram[i].name);
		}

		flag = 0;
		for (int k = 0; k < gram[i].tuidao.size(); k++)
		{ //求vt集  终结符集
			if (!IsVn(gram[i].tuidao[k]))
			{ //如果在终结符集中没有，那就一定是非终结符
				for (int x = 0; x < vt.size(); x++)
				{
					if (vt[x] == gram[i].tuidao[k])
						flag = 1;
				}
				if (flag == 0)
				{
					vt.push_back(gram[i].tuidao[k]);
				}
			}

			flag = 0;
		}
	}

	//划分完毕后，非终结符集压入#
	vt.push_back('#');

	for (int i1 = 0; i1 < vn.size(); i1++)
	{ //构造first集
		this->Full_First(vn[i1]);
	}

	for (int i2 = 0; i2 < vn.size(); i2++)
	{ //构造follow集
		this->Full_Follow(vn[i2]);
	}

	for (int i3 = 0; i3 < vt.size(); i3++)
	{ //做一个存放，nvt存放除空集外所有的非终结符，
		if (vt[i3] != '$')
			nvt.push_back(vt[i3]);
	}
}

void Fset::Show()
{
	cout << "wtf" << endl;
	for (int j = 0; j < 7; j++)
	{
		cout << gram[j].name << "->";
		for (int j1 = 0; j1 < gram[j].tuidao.size(); j1++)
		{
			cout << gram[j].tuidao[j1];
		}
		cout << endl;
	}
	cout << "First " << endl;
	for (int i = 0; i < vn.size(); i++)
	{
		cout << vn[i] << ":";
		set<char>::iterator it;
		for (it = first[i].begin(); it != first[i].end(); it++)
			cout << *it << "  ";
		cout << endl;
	}

	cout << "Follow " << endl;
	for (int k = 0; k < vn.size(); k++)
	{
		cout << vn[k] << ":";
		set<char>::iterator it1;
		for (it1 = follow[k].begin(); it1 != follow[k].end(); it1++)
			cout << *it1 << "  ";
		cout << endl;
	}
}
