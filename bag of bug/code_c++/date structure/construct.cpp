#include<bits/stdc++.h>
using namespace std;
typedef struct node{
    int data;
    struct node *next;

} * PHODE, NODE;
PHODE init(){
    PHODE temp = (PHODE)malloc(sizeof(NODE));
    temp->next = NULL;
    return temp;
}
void insert (PHODE head, int newdata)  // 链表尾部插入元素
{

    PHODE temp = (PHODE)malloc(sizeof(NODE));
    temp->data = newdata;
    PHODE p;
    p = head; 
    while(p ->next != NULL)
        p = p->next;// 定义p时它指向最后一个节点
    p->next = temp;
    temp->next = NULL;

}

void headinsert(PHODE head, int newdata) // 头插
{
    PHODE temp = (PHODE)malloc(sizeof(NODE));
    temp->data = newdata;
    temp->next = head->next;
    head->next = temp;
}


void print (PHODE head){
    PHODE temp = head->next;
    while(temp !=NULL){
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;

}
void freenode(PHODE head){
    PHODE p = head, temp;
    while( p != NULL){
        temp = p->next;
        free(p);
        p = temp;
    }

}
int main(){
    PHODE head = init();
    for (int i = 0; i < 10;i++)
        insert(head, i);
        print(head);
        freenode(head);
        return 0;
}


