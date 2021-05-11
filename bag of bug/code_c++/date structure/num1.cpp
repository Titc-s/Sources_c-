#include<iostream>
#include<malloc.h> 
#define listsize=100;

using namespace std;
typedef struct{
	int *elem;
	int length;
}List; 
void  InitList(List &L)
{
	L.elem=(int*)malloc(100*sizeof(int));

	L.length=0;
	
}
void createlist(List &L)
{
	int n;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
		L.elem[i]=a[i];
	}
	L.length=n;
}
int ListLength(List L)
{
	return L.length;
} 
void GetElem(List L,int i,int &e)
{
	e=L.elem[i-1];
}
int  LocateElem(List L,int e)
{
	int i=0;
	for(i=0;i<L.length ;i++)
	{
		if(L.elem[i]==e)
		return 0;
	}
	return 1;

	
}
void ListInsert(List &L,int i,int e)
{
	int j;
	if(i<1||i>L.length+1)
	{
		cout<<"插入位置不合法"<<endl;
		exit(0);
	
	}
	else
	{
		for(j=L.length;j>i;j--)
		{
			L.elem[j]=L.elem [j-1];
		}
		L.elem [i-1]=e;
		L.length=L.length+1;
		
	}
}

void Union (List &La,List Lb)
{
	int e;
	int Lalen=ListLength(La);
	int Lblen=ListLength(Lb);
	for(int i=1;i<=Lblen;i++)
	{
		GetElem(Lb,i,e);
		if(LocateElem(La,e))
		ListInsert(La,++Lalen,e); 
	}
}
void Listsort(List &L)
{
	int t;
	int Llen=ListLength(L);
	for(int i=0;i<Llen;i++)
	for(int j=i+1;j<Llen;j++)
	{
		if(L.elem[i]>L.elem [j])
		{
			t=L.elem [j];
			L.elem [j]=L.elem [i];
			L.elem [i]=t;	
		}
	}
	
}

void mergelist(List La,List Lb,List &Lc)
{
	int ai,bj;
	InitList(Lc);
	int i=1,j=1,k=0;
	int Lalen=ListLength(La);
	int Lblen=ListLength(Lb);
	while(i<=Lalen&&j<=Lblen)
	{
		GetElem(La,i,ai);
		GetElem(Lb,j,bj);
		if(ai<=bj)
		{
			ListInsert(Lc,++k,ai);i++;
		}
		else
		{
			ListInsert(Lc,++k,bj);j++;
		}
		
	}
	while(i<=Lalen)
	{
		GetElem(La,i++,ai);
		ListInsert(Lc,++k,ai);
	}
	while(j<=Lblen)
	{
		GetElem(Lb,j++,bj);
		ListInsert(Lc,++k,bj);
	}
}
void printlist(List L)
{
	for(int i=0;i<L.length;i++)
	{
		cout<<L.elem[i]<<" ";
	}
	cout<<endl;
}



int main()
{
   List La,Lb,Lc,Ld;
   InitList (La);
   InitList (Lb);
   InitList (Ld);
   createlist(La);
   createlist(Lb);
   Union(La,Lb);
   Listsort(La);
   printlist(La);
   createlist(Ld);
   mergelist(La,Ld,Lc);	
   printlist(Lc);
   return 0;
}
