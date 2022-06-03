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
		{ //���Ƶ��ĵ�һ����ĸ��
			for (int j = 0; j < gram[i].tuidao.size(); j++)
			{
				if (!IsVn(gram[i].tuidao[j]))
				{ //������ս������ֱ��ѹ��
					first[Get_Nindex(ch)].insert(gram[i].tuidao[j]);
					break;
				}
				else
				{ //����Ƿ��ս������ѹ��÷��ս���ĳ��˿ռ������Ԫ��
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
			{ //����жϿռ��Ƿ�Ӧ�ñ�ѹ��
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
		{ //�ҵ���Ҫ����ַ���λ��
			if (gram[i].tuidao[j] == ch)
				index = j;
		}

		if (index != -1 && index < len - 1)
		{ //�����aAx������
			char next = gram[i].tuidao[index + 1];
			if (!IsVn(next))
			{ // x���ս����ֱ�Ӽ���follow��
				follow[Get_Nindex(ch)].insert(next);
			}
			else
			{ //���򣬾���aAB�����ͣ���ô�������ұߵ�first������÷��ŵ�follow������
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
				{ //���aAB��ʽ��B��first�����пգ���ô������ȡһλ���Ƿ���Ȼ����
					Full_Follow(gram[i].name);
					set<char>::iterator it;
					for (it = follow[Get_Nindex(gram[i].name)].begin(); it != follow[Get_Nindex(gram[i].name)].end(); it++)
					{
						follow[Get_Nindex(ch)].insert(*it);
					}
				}
			}
		}

		else if (index != -1 && index == len - 1 && ch != gram[i].name) //�����aA�͵ģ�
		{
			Full_Follow(gram[i].name); //�������ʽ��ߵ�follow���ϣ�����������follow������ȥ
			set<char>::iterator it;
			char tmp = gram[i].name;
			for (it = follow[Get_Nindex(tmp)].begin(); it != follow[Get_Nindex(tmp)].end(); it++)
				follow[Get_Nindex(ch)].insert(*it);
		}
	}
}

void Fset::Maneger()
{
	this->Get_Gram(); // 36�д��룬 ���ı��ĵ�����ȡ����
	//�Ȼ����ս�����ͷ��ս����
	for (int i = 0; i < 10; i++)
	{
		int flag = 0;
		for (int j = 0; j < vn.size(); j++)
		{							   //��Vn�� ���ս���� ����
			if (vn[j] == gram[i].name) // garm��name������֣�tuidao����Ƶ�
				flag = 1;			   //��������д��ڸ÷��ս����nameһ���Ƿ��ս�����������flag��1
		}
		if (flag == 0)
		{ //���flag=0��˵���ս������ѹ��
			vn.push_back(gram[i].name);
		}

		flag = 0;
		for (int k = 0; k < gram[i].tuidao.size(); k++)
		{ //��vt��  �ս����
			if (!IsVn(gram[i].tuidao[k]))
			{ //������ս������û�У��Ǿ�һ���Ƿ��ս��
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

	//������Ϻ󣬷��ս����ѹ��#
	vt.push_back('#');

	for (int i1 = 0; i1 < vn.size(); i1++)
	{ //����first��
		this->Full_First(vn[i1]);
	}

	for (int i2 = 0; i2 < vn.size(); i2++)
	{ //����follow��
		this->Full_Follow(vn[i2]);
	}

	for (int i3 = 0; i3 < vt.size(); i3++)
	{ //��һ����ţ�nvt��ų��ռ������еķ��ս����
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
