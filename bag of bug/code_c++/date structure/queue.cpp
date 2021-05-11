#include<iostream>
#include<cstdlib>
#include<queue>
using namespace std;

#define ElemType double


struct QNode    // 队列结点的数据结构
{
    QNode *next;
    ElemType data;
};

struct LinkQueue  // 队列的数据结构
{
    QNode *front;
    QNode *rear;
};

void InitQueue(LinkQueue &Q)
{
    QNode *q;
    q = new QNode;
    q->next = NULL;
    Q.front = q;
    Q.rear = q;
}

int Empty(LinkQueue &Q)
{
    if(Q.rear == Q.front)
        return 1;
    else 
        return 0;
}

void EnQueue(LinkQueue &Q, ElemType e)
{
    QNode *p;
    p = new QNode;   // 创建新节点
    p->next = NULL;    
    p->data = e;
    Q.rear->next = p;    // 插入尾部
    Q.rear = p;       // 将p结点设置为新的尾节点
}

void DeleteQueue(LinkQueue &Q,ElemType e)
{
    QNode *p;
    p = Q.front->next;
    e = p -> data;
    Q.front->next = p->next;
    if(Q.rear ==p)
        Q.rear = Q.front;
    delete p;
}
void DeQueue(LinkQueue &Q)
{
     QNode *p;
    p = Q.front->next;
    Q.front->next = p->next;
    if(Q.rear ==p)
        Q.rear = Q.front;
    delete p;
}
void freeQueue(LinkQueue &Q)
{
    while(Q.front)
  {
      Q.rear = Q.front;
      delete Q.front;
      Q.front = Q.rear;
  }
}

int GetFront(LinkQueue &Q)
{
    return Q.front->next->data;
}

int main()
{
    LinkQueue Q;
    double n;
    InitQueue(Q);
    for (int i = 0; i < 5;i++)
    {
        cin >> n;
        EnQueue(Q, n);
    }
    cout << "ss" << endl;
    cout<<GetFront(Q);
    cout << "ss" << endl;
    DeQueue(Q);
    cout<<GetFront(Q);
    cout<<Empty(Q);
    cout<<endl<<endl;
    queue<int> q;
    for (int i = 0; i < 5;i++)
    {
        cin >> n;
        q.push(n);
    }
    cout << q.front();
    q.pop();
    cout << q.front();
    cout << q.empty();

    return 0;
}

