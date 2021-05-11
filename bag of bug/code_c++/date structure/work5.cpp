#include<stdio.h> //用先序序列创建一棵二叉树，并输出字符D位于二叉树的层数
#include<stdlib.h>
#include<conio.h>
typedef struct BiTNode
{
    char data;
    struct BiTNode *lchild,*rchild;
}BiTNode,*BiTree;

void CreatBiTree(BiTree *T)
{
    char c;
    scanf("%c",&c);
    if(c == ' ') *T=NULL; //如果输出的是空格，则表示创建的子树结束
    else
    {
        *T=(BiTNode*)malloc(sizeof(BiTNode)); //创建根结点
        (*T)->data=c; //向根结点中输入数据
        CreatBiTree(&((*T)->lchild)); //递归地创建左子树
        CreatBiTree(&((*T)->rchild)); //递归地创建右子树
    }
}
//访问二叉树结点，输出包含D字符结点位于二叉树中的层数
void visit(char c,int level)
{
    if(c=='D')
        printf("%c is at %d lever of BiTree\n",c,level);
}
 void PreOrderTraverse(BiTree T,int level)
{
    if(T)    //递归结束条件，T为空
    {
        visit(T->data,level);//访问根结点
        PreOrderTraverse(T->lchild,level+1);
        PreOrderTraverse(T->rchild,level+1);
    }
}

int main()
{
    int level=1;
    BiTree T=NULL; //最开始T指向空
    CreatBiTree(&T);
    PreOrderTraverse(T,level);
    getche();
    return 0;
}