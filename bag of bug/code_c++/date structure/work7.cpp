#include<iostream>
#include<string>
#include<ctype.h>
using namespace std;

#define HashLen 50
#define NAME_LEN 30


typedef struct {
  string py;
  int sum; 
}Name;

typedef struct{
  int address;
  int key;
  int search_time;
  int function_key;
  string Name;
}HashT;

HashT HashTable[HashLen];
Name NameTable[NAME_LEN];
void InitNameTable()
{
       NameTable[0].py="louyuhong";
       NameTable[1].py="shenyinghong";
       NameTable[2].py="wangqi";
       NameTable[3].py="zhuxiaotong";
       NameTable[4].py="zhataotao";
       NameTable[5].py="chenbinjie";
       NameTable[6].py="chenchaoqun";
       NameTable[7].py="chencheng";
       NameTable[8].py="chenjie";
       NameTable[9].py="chenweida";
       NameTable[10].py="shanjianfeng";
       NameTable[11].py="fangyixin";
       NameTable[12].py="houfeng";
       NameTable[13].py="hujiaming";
       NameTable[14].py="huangjiaju";
       NameTable[15].py="huanqingsong";
       NameTable[16].py="jianghe";
       NameTable[17].py="jinleicheng";
       NameTable[18].py="libiao";
       NameTable[19].py="liqi";
       NameTable[20].py="lirenhua";
       NameTable[21].py="liukai";
       NameTable[22].py="louhanglin";
       NameTable[23].py="luchaoming";
       NameTable[24].py="luqiuwei";
       NameTable[25].py="panhaijian";
       NameTable[26].py="shuxiang";
       NameTable[27].py="suxiaolei";
       NameTable[28].py="sunyubo";
       NameTable[29].py="wangwei";

       int i, j;
       for (i = 0; i < NAME_LEN;i++){
         int s = 0;
         string p = NameTable[i].py;
         for (j = 0; j < (NameTable[i].py.length());j++)
           s += toascii(NameTable[i].py[j]);
         NameTable[i].sum = s;
       }
}

void DisPlay(){
 cout << "姓名" << "   " << "Sum"<<endl;
	for (int i = 0; i < NAME_LEN; i++)
	{
		cout << NameTable[i].py << "   " << NameTable[i].sum << endl;
	}
}

void CreateHashTable() {
	for (int  i = 0; i < HashLen; i++)
	{
		HashTable[i].address = i;
		HashTable[i].search_time = 0;

	}
	for (int i = 0; i < NAME_LEN; i++)
	{
//		if (i == 21||i == 23 || i == 24 || i == 27 || i == 28)continue;
		int P = (NameTable[i].sum) % 47;// 位置1
		if (HashTable[P].search_time==0) {
			HashTable[P].key = NameTable[i].sum;
			HashTable[P].function_key = P;
			HashTable[P].search_time = 1;
			HashTable[P].Name = NameTable[i].py;
			//cout << "i=" << i << endl;
		}
		else
		{
			int flag = 1;
			int time = 2;
			int d = 1;
			while (flag) {	
				P = (NameTable[i].sum + d) % 47;// 位置2
				if (HashTable[P].search_time==0) {
					flag = 0;
					HashTable[P].key = NameTable[i].sum;
					HashTable[P].function_key = P;
					HashTable[P].search_time = time;
					HashTable[P].Name = NameTable[i].py;
				}
				d++;
				time++;
			}
			//cout << "i=" << i << endl;
		}
	}
}

void search(string Name) {
	int sum = 0;
	for (int i = 0; i < Name.length(); i++)
	{
		sum+= toascii(Name[i]);
	}
	int d = 0;
	int P = 0;
	while (true)
	{		
		P = (sum + d) % 47;
		if (HashTable[P].Name == Name)
			break;
		d++;
		if (d > 10)
			break;
	}
	if (d <= 10) {
		cout << "位置" << "\t" << "Key" << "\t" << "Times" << "\t" << "H(key)" << "\t" << "拼音" << endl;
		cout << HashTable[P].address << "\t" << HashTable[P].key << "\t" << HashTable[P].search_time << "\t" << HashTable[P].function_key << "\t" << HashTable[P].Name << endl;
	}
	else
	{
		cout << "Can't find the name!" << endl;
	}
}

void displayHashTable() {
	cout << "位置" << "\t" << "Key" << "\t" << "Times" << "\t"<<"H(key)"<<"\t"<<"拼音"<<endl;
	for (int i = 0; i < HashLen; i++) {
		cout << HashTable[i].address << "\t" << HashTable[i].key << "\t" << HashTable[i].search_time << "\t" << HashTable[i].function_key << "\t" << HashTable[i].Name << endl;
	}
}
int main() {
	InitNameTable();
	CreateHashTable();
	//displayHashTable();
	/*------------------------哈希表的建立和查找----------------------

	1. 显示哈希表
	2. 查找
	3. 退出*/
	cout << "------------------------哈希表的建立和查找----------------------" << endl;
	cout << "1. 显示哈希表" << endl;
	cout << "2. 查找" << endl;
	cout << "3. 退出" << endl;
	cout << "==============================================================" << endl;
	int a;
	cout << "Choose the right number:";
	cin >> a;
	while (true)
	{
		if (a == 1) {
			displayHashTable();
		}
		if (a == 2) {
			string A;
			cout << "请输入姓名的拼音:";
			cin >> A;
			search(A);
		}
		if (a == 3) {
			cout << "OVER!" << endl;
			return 0;
		}
	cout << "------------------------哈希表的建立和查找----------------------" << endl;
	cout << "1. 显示哈希表" << endl;
	cout << "2. 查找" << endl;
	cout << "3. 退出" << endl;
	cout << "==============================================================" << endl;
		cout << "Choose the right number:";
		cin >> a;
	}
	return 0;
}

