#include<iostream>
#include<stdio.h>

using namespace std;

#define MaxSize 100 // 定义最大哈希长度 
#define NULLKEY -1  // 定义空关键字值
#define DELKEY -2 //定义被删除关键字值
#define ElemType int

typedef ElemType KeyType;
typedef char *InfoType;

typedef struct{
    KeyType key;
    InfoType data;
    int count;       // 探查（冲突）次数
} HashTable[MaxSize];

//插入关键字k到哈希表中
void InsertHT(HashTable ha, int &n, KeyType k, int p)
{
    int i, adr;
    adr = k % p;
    if (ha[adr].key == NULLKEY || ha[adr].key == DELKEY)
    {
        ha[adr].key = k;
        ha[adr].count = 1;
    }
    else
    {
        i = 1; //记录发生冲突的次数
        do
        {
            adr = (adr + 1) % p;
            i++;
        } while (ha[adr].key != NULLKEY && ha[adr].key != DELKEY);
        ha[adr].key = k;
        ha[adr].count = i;
    }
    n++;
}

// 创建哈希表
void CreateHT(HashTable ha, KeyType x[], int n, int m, int p)
{
    int i, n1 = 0;
    for (i = 0; i < m; i++)
    {
        ha[i].key = NULLKEY;
        ha[i].count = 0;
    }
    for (i = 0; i < n; i++)
        InsertHT(ha, n1, x[i], p);
}

// 在哈希表中查找关键字K
int SearchHT(HashTable ha, int p, KeyType k)
{
    int i = 0, adr;
    adr = k % p;
    while (ha[adr].key != NULLKEY && ha[adr].key != k)
    {
        i++;
        adr = (adr + 1) % p; // 线性探测寻找下一个地址
    }
    if (ha[adr].key == k) // 查找成功
        return adr;
    else
        return -1;
}

int DeleteHT(HashTable ha,int p,int k,int &n)
{
    int adr;
    adr = SearchHT(ha, p, k);
    if(adr!=-1)  //如果在哈希表中找到了关键字
    {
        ha[adr].key = DELKEY;
        n--;
        return 1;
    }
    else
        return 0;
}

void DispHT(HashTable ha,int n,int m)
{
    float avg = 0;
    int i;
    cout << "哈希表地址\t";
    for (i = 0; i < m; i++)
        printf(" %3d", i);
    cout << endl;
    cout << " 哈希表关键字：\t";
    for (i = 0; i < m; i++)
        if (ha[i].key == NULLKEY || ha[i].key == DELKEY)
            cout << "   ";
        else
            printf("%3d", ha[i].key);
    cout << endl;
    cout << "搜索次数：\t";
    for (i = 0; i < m; i++)
        if (ha[i].key == NULLKEY || ha[i].key == DELKEY)
            cout << "    ";
        else
            printf("%3d", ha[i].count);
    cout << endl;
    for (i = 0; i < m; i++)
        if (ha[i].key != NULLKEY && ha[i].key != DELKEY)
            avg = avg + ha[i].count;
    avg = avg / n;
    printf(" 平均搜索长度ASL(%d)=%.3g\n", n, avg);
}

void CompASL(HashTable ha,int m)
{
    int i;
    int s = 0, n = 0;
    for (i = 0; i < m;i++)
    if(ha[i].key!=DELKEY && ha[i].key!=NULLKEY)
    {
        s = s + ha[i].count;
        n++;
    }
   printf(" 查找成功的ASL=%.3g\n",s*1.0/n);
}

int main()
{
  int x[]={16,74,60,43,54,90,46,31,29,88,77};
	int n=11,m=13,p=13,i,k=29;
	HashTable ha;
	CreateHT(ha,x,n,m,p);
	printf("\n");DispHT(ha,n,m);
	i=SearchHT(ha,p,k);
	if (i!=-1)
		printf(" ha[%d].key=%d\n",i,k);
	else
		printf(" 未找到%d\n",k);
	k=77;
	printf(" 删除关键字%d\n",k);
	DeleteHT(ha,p,k,n);
	DispHT(ha,n,m);
	i=SearchHT(ha,p,k);
	if (i!=-1)
		printf(" ha[%d].key=%d\n",i,k);
	else
		printf(" 未找到%d\n",k);
	printf(" 插入关键字%d\n",k);
	InsertHT(ha,n,k,p);
	DispHT(ha,n,m);
	printf("\n");
    return 0;
}
