#include <iostream>
#include <malloc.h>
using namespace std;
typedef struct Node {
	int data;
	struct  Node *next;
}*Linklist;
void Initlist(Linklist &L)
{
	Linklist P;
	L = (Linklist)malloc(sizeof(Node));
	L->next = NULL;
	P = (Linklist)malloc(sizeof(Node));
	int i;
	cin >> i;
	while (i != -10000)
	{
		P->data = i;
		P->next = L->next;
		L->next = P;
		P = (Linklist)malloc(sizeof(Node));
		cin >> i;
	}
}
void Putoutlist(Linklist L)
{
	Linklist P;
	P = L->next;
	while (P != NULL)
	{
		cout << P->data << " ";
		P = P->next;
	}
	cout << "链表输出完毕！" << endl;
}
void Mergelist(Linklist &La, Linklist &Lb, Linklist &Lc)
{
	Linklist P, Q, S;
	P = La->next;
	Q = Lb->next;

	S = La;//新的Lc的遍历指针，默认把La的头结点拿出来作为新的头结点，其实也可以拿Lb的； 
	Lc = La;//把新的Lc先指向头结点 
	while ((P != NULL) && (Q != NULL))
	{
		if (P->data <= Q->data)
		{
			S->next = P;
			S = P;
			P = P->next;
		}
		else {
			S->next = Q;
			S = Q;
			Q = Q->next;
		}
	}
	S->next = P ? P : Q;
}
int main()
{
	Linklist La, Lb;
	Initlist(La);
	Initlist(Lb);
	Putoutlist(La);
	Putoutlist(Lb);
	Linklist Lc;  
	Mergelist(La, Lb, Lc);
	Putoutlist(Lc);
	free(Lb);
	system("pause");
	return 0;
}