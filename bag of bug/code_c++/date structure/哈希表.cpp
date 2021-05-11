#include<iostream>
#include<string>
#define NAME_LEN 30
using namespace std;

static int p=79;

typedef struct{
	string py;
	int m;
	int key;
	int search=1;
	
}Name;
typedef struct{
	Name *people;
	int count;     //当前数据元素个数
	int sizeindex; //hashsize[sizeindex]为当前容量 
}HashTable;

void InitNameTable(Name NameTable[]) {
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
 //将字符串的各个字符所对应的ASCII码相加，所得的整数做为哈希表的关键字
 int i;
for (i=0;i<NAME_LEN;i++){
       int s=0;
 string q=NameTable[i].py;
 for (int j=0; q[j]!='\0';j++)  s+=toascii(q[j]);
       NameTable[i].m=s;
       NameTable[i].key=s%p;
    }
}

void CreateHashTable(Name NameTable[],HashTable &Hashtable){
	Hashtable.people=new Name[100];
	int i;
	for(i=0;i<100;i++)
	Hashtable.people[i].m=0;      //初始化
	for(i=0;i<NAME_LEN;i++){
		int k=NameTable[i].key;
		if(Hashtable.people[k].m==0)
		Hashtable.people[k]=NameTable[i];
		else{
			int j=k;
			while(Hashtable.people[j++].m!=0){
				NameTable[i].search++;
			}
			Hashtable.people[j-1]=NameTable[i]; //线性探测再散列
		}
	}
	Hashtable.count=i;
	Hashtable.sizeindex=100-i;
}

void DisplayNameTable(HashTable Hashtable){
	cout<<"地址     "<<"关键字     "<<"搜索长度     "<<"H(key)     "<<"拼音"<<endl;
	int i;
	for(i=0;i<100;i++){
		if(Hashtable.people[i].m==0)
		cout<<i<<"          "<<"0           "<<"0            "<<"0         "<<endl;
		else{
			cout<<i<<"         "<<Hashtable.people[i].m<<"         "<<Hashtable.people[i].search<<"         "<<Hashtable.people[i].key<<"         "<<Hashtable.people[i].py<<endl;
		}
	if(i==100)
	cout<<"查无此人!"<<endl;
	cout<<endl;
	} 
}

void FindName(HashTable Hashtable){
	string s1;
	cout<<"请输入姓名的拼音：";
	cin>>s1;
	int i;
	for(i=0;i<100;i++)
	if(Hashtable.people[i].py==s1){
		cout<<"姓名："<<s1<<"  关键字："<<Hashtable.people[i].m<<"  查找长度："<<Hashtable.people[i].search<<endl;
	}
	cout<<endl;
}

int main(){
	Name NameTable[NAME_LEN];
	HashTable Hashtable;
	InitNameTable(NameTable);
	CreateHashTable(NameTable,Hashtable);
	while(1){
	cout<<"========================"<<endl<<endl;
	cout<<"1. 显示哈希表"<<endl<<"2. 查找"<<endl<<"3. 退出"<<endl<<endl;
	cout<<"========================"<<endl;
	int choose;
	cout<<"请输入正确的选择：";
	cin>>choose;
		switch(choose){
			case 1 : DisplayNameTable(Hashtable); break;
			case 2 : FindName(Hashtable); break;
			case 3 : return 0;
		}
	}
}








