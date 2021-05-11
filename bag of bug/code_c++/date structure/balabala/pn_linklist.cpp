#include<iostream>
#include<stdlib.h>
#include<string>

using namespace std;

typedef struct Node{

    int data;
    struct Node *prev, *next;
}pNode;

pNode *InitList(pNode **head,int n)
{
    pNode *p, *s;
    (*head) = (pNode *)malloc(sizeof(pNode));
    if((*head)==NULL)
        exit(0);
    (*head)->next = NULL;
    (*head)->prev = NULL;
    p = (*head);
    int i;
    for (i = 0; i < n;i++)
    {
        s = (pNode *)malloc(sizeof(pNode));
        if(s==NULL)
            exit(0);
        cout << "Input the value of the " << i + 1 << "th node:";
        cin >> s->data;//&s->data
        s->next = NULL;
        p->next = s;
        s->prev = p;
        p = s;

    }
    return p;
}

void display(pNode *head)
{
    pNode *p;
    p=head->next;
    if(head->next==NULL)
        cout << "the list is empty!" << endl;
    while(p!=NULL)
    {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}

void deleteList(pNode **head)
{
    pNode *p;
    while((*head)->next!=NULL)
    {
        p = (*head);
        p->next->prev = NULL;
        (*head) = p->next;
        free(p);
    }
}

int search(pNode *head)
{
    int number;
    cout << "cin which u wanna search:";
    cin >> number;
    pNode *p;
    p = head->next;
    while(p!=NULL)
    {
        if(p->data==number)
            return number;
        p = p->next;
    }
    return 0;
}

void deleteNode(pNode **head,int n)
{
    int i;
    pNode *p;
    p = (*head)->next;
    for (i = 1; i < n;i++)
        p = p->next;
    if(p->next==NULL)
    {
        p->prev->next = NULL;
        free(p);
    }
    else{
        p->next->prev = p->prev;
        p->prev->next = p->next;
        free(p);
    }
}

int main()
{
    int n, element, flag;
    pNode *head, *last;
    /*****************/
    cout << "please cin the size:";
    cin >> n;
    last = InitList(&head, n);
    cout << "head data:" << head->next->data << "last data:" << last->data;
    display(head);
    /********************/
    flag = search(head);
    if(flag>0&&flag<=n)
    {
        deleteNode(&head, flag);
        display(head);
    }
    else
        cout << "not exist";
    deleteList(&head);
    display(head);
    return 0;
}