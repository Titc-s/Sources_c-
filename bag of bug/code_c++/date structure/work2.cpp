#include<iostream>
#include<malloc.h>
using namespace std;


typedef struct node{
    int data;
    struct node *next;
} *PHODE, NODE;

PHODE init(){
    PHODE temp = (PHODE)malloc(sizeof(NODE));
    temp->next = NULL; 
    return temp;
}
void insert (PHODE head)
{
    int newdata;
    cin >> newdata;
    while(newdata!=-1){
    PHODE temp = (PHODE)malloc(sizeof(NODE));
    temp->data = newdata;
    PHODE p;
    p = head;
    while(p ->next != NULL)
        p = p->next;// 定义p时它指向最后一个节点
    p->next = temp;
    temp->next = NULL;
    cin >> newdata;
    }
}
void print (PHODE head){
    PHODE temp = head->next;
    while(temp!=NULL){
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}
void MergeList(PHODE &La, PHODE &Lb,PHODE &Lc)
{
    PHODE pa, pb, pc;
    pa = La->next;
    pb = Lb->next;
    pc = La;
    Lc = pc;
    while(pa && pb){
        if(pa->data <= pb->data){
            pc->next = pa;
            pc = pa;
            pa = pa->next;
        }
        else {
            pc->next = pb;
            pc = pb;
            pb = pb->next;
        }
    }
    pc->next = pa ? pa : pb;
    free(Lb);
}
void freenode(PHODE head){
    PHODE p = head, temp;
    while(p!=NULL){
        temp->next;
        free(p);
        p = temp;
    }
}

int main(){
    PHODE La = init();
    PHODE Lb = init();
    PHODE Lc;
    insert(La);
    insert(Lb);
    MergeList(La, Lb, Lc);
    print(Lc);
    return 0;
    }
