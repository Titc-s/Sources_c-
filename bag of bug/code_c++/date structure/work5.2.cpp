#include<iostream>
#include<malloc.h>
#include<stack>
using namespace std;

typedef char ElementType;
typedef int Status;
#define OVERFLOW -1


typedef struct BiTNode{
    ElementType data;
    struct BiTNode *lchild, *rchild;

} BiTNode, *BiTree;


BiTree CreateBiTree(BiTree &T)

{
    ElementType ch;
    cin >> ch;
    if(ch=='0')
        T = NULL;
    else{
        T = (BiTree)malloc(sizeof(BiTNode));
        T->data = ch;
         CreateBiTree(T->lchild);
         CreateBiTree(T->rchild);
    }
    return T;
}

BiTree FreeTree(BiTree T)
{
    if(T)
    {
        FreeTree(T->lchild);
        FreeTree(T->rchild);

        free(T);
        T = NULL;
    }
    return T;
}

Status PrintElement(ElementType e){
    cout << e;
    return true;
}

Status InOrderTraverse(BiTree T)  //中序遍历二叉树
{
    stack<BiTree> S;
    BiTree p;
    p = T;
    while(p||!S.empty())
    {
        if(p)
        {
            S.push(p);
            p = p->lchild;
        }
        else{
            p = S.top();
            cout << p->data << " ";
            S.pop();
            p = p->rchild;
        }
    }
    cout << endl;
    return true;
} 

void PerOrderTraverse(BiTree T ) // 先序遍历二叉树
{
    if(T)
    {
        cout << T->data << " ";
        PerOrderTraverse(T->lchild);
        PerOrderTraverse(T->rchild);
    }
}

void PostOrderTraverse(BiTree T) //后序遍历二叉树
{
    if(T)
    {
        PostOrderTraverse(T->lchild);
        PostOrderTraverse(T->rchild);
        cout << T->data << " ";
    }
}

int main()
{
    BiTree T;
    cout << "请按照先序遍历输入二叉树" << endl;
    CreateBiTree(T);
    cout << "先序遍历输出的结果是:";
    PerOrderTraverse(T);
    cout << endl;
    cout << "后序遍历输出的结果是：";
    PostOrderTraverse(T);
    cout << endl;
    cout << "中序遍历输出的结果是：";
    InOrderTraverse(T);

    FreeTree(T);
    return 0;
}