#include <iostream>
#include <fstream>
#include <string>
using namespace std;
 
/************************************
@ Brief:		读取指定行数据
@ Author:		woniu201 
@ Created:		2018/08/31
@ Return:            
************************************/
void ReadLineData(char* fileName, int lineNum, char* data)
{
	ifstream in;
	in.open(fileName);
 
	int line = 1;
	while (in.getline(data, 1024))
	{
		if (lineNum == line)
		{
			break;
		}
		line ++ ;
	}
 
	in.close();
}
 
/************************************
@ Brief:		字符串转string类型
@ Author:		woniu201 
@ Created:		2018/08/31
@ Return:            
************************************/
string CharToStr(char * contentChar)
{
	string tempStr;
	for (int i=0;contentChar[i]!='\0';i++)
	{
		tempStr+=contentChar[i];
	}
	return tempStr;
}
 
 
/************************************
@ Brief:		删除指定行
@ Author:		woniu201 
@ Created:		2018/08/31
@ Return:           
************************************/
void DelLineData(char* fileName, int lineNum)
{
	ifstream in;
	in.open(fileName);
	
	string strFileData = "";
	int line = 1;
	char lineData[1024] = {0};
	while(in.getline(lineData, sizeof(lineData)))
	{
		if (line == lineNum)
		{
			strFileData += "\n";
		}
		else
		{
			strFileData += CharToStr(lineData);
			strFileData += "\n";
		}
		line++;
	}
	in.close();
 
	//写入文件
	ofstream out;
	out.open(fileName);
	out.flush();
	out<<strFileData;
	out.close();
}
 
/************************************
@ Brief:        修改行数据
@ Author:		woniu201 
@ Created:		2018/08/31
@ Return:            
************************************/
void ModifyLineData(char* fileName, int lineNum, char* lineData)
{
	ifstream in;
	in.open(fileName);
 
	string strFileData = "";
	int line = 1;
	char tmpLineData[1024] = {0};
	while(in.getline(tmpLineData, sizeof(tmpLineData)))
	{
		if (line == lineNum)
		{
			strFileData += CharToStr(lineData);
			strFileData += "\n";
		}
		else
		{
			strFileData += CharToStr(tmpLineData);
			strFileData += "\n";
		}
		line++;
	}
	in.close();
 
	//写入文件
	ofstream out;
	out.open(fileName);
	out.flush();
	out<<strFileData;
	out.close();
}
 
int main()
{
	char lineData[1024] = {0};
	/*ReadLineData("D:\\bag of bug\\code_c++\\c++destruct\\sources\\1.json", 21, lineData);
	cout << lineData << endl;
 
	DelLineData("D:\\bag of bug\\code_c++\\c++destruct\\sources\\1.json", 10);
 */
	ModifyLineData("D:\\bag of bug\\code_c++\\c++destruct\\sources\\1.txt", 1, "aaaaaaaaaaaaaa");
	ReadLineData("D:\\bag of bug\\code_c++\\c++destruct\\sources\\1.txt", 1, lineData);
	cout << lineData << endl;
	getchar();
	return 0;
}