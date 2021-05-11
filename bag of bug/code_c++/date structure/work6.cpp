#include<iostream>
#include<string>
using namespace std;


#define MAX_VERTEX_NUM 100
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

int GetFront(LinkQueue &Q)
{
    return Q.front->data;
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
    if(Q.rear==p)
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

typedef struct ArcNode{ // 边结点？？
    int adjvex;      //存储与该边相连的另一个结点的索引
    struct ArcNode *nextarc;  // 存储与表头结点相连的其他表结点的指针
    string info;   // 存储边的信息，例如权值
}ArcNode;

typedef struct VNode{ // 头结点
    char data;
    ArcNode *firstarc;   //指向链表的指针

} VNode, AdjList[MAX_VERTEX_NUM];

typedef struct{
    AdjList vertices;// 存储头节点的数组
    int vexnum, arcnum;  //当前图的vexnum定点数和arcnum弧数
    int kind;   //图的种类
} ALGraph;

int LocateVex(ALGraph &G,char &v1)  //查找结点V1 在图G的存储节点数组中的索引位置
{
    int i;
    for (i = 0; i < G.vexnum;i++)
{
    if(G.vertices[i].data ==v1)
        return i;
}
if(i>G.vexnum)
    return false;
    else
        return 0;
}

void CreateDG(ALGraph &G)
{
    ArcNode *p, *q;
    char v1, v2;
    char v;
    int i, j, k, n;
    cout << "请输入图的顶点数和弧数：" << endl;
    cin >> G.vexnum;
    cin >> G.arcnum;
    cout << "请输入顶点：" << endl;
    for (i = 0; i < G.vexnum;i++)
    {
        cin >> v;
        G.vertices[i].data = v;
        G.vertices[i].firstarc = NULL;
    }
    cout << "请输入弧尾和弧头：";
    for (k = 0; k < G.arcnum;k++)
    {
        cin >> v1;
        cin >> v2;
        i = LocateVex(G, v1);
        j = LocateVex(G, v2);
        if(G.vertices[i].firstarc==NULL)
        {
            p = (ArcNode *)new ArcNode;
            G.vertices[i].firstarc = p;
            q = G.vertices[i].firstarc;
        }
        else
        {
            q = G.vertices[i].firstarc;
            for (n = 0; n < G.arcnum; n++,q=q->nextarc)
            {
                if(!q->nextarc)
                    break;
            }
            p = (ArcNode *)new ArcNode;
            q->nextarc = p;
            q = q->nextarc;
        }
        q->adjvex = j;
        q->nextarc = NULL;
    }
    cout << "图构建成功！";
}

bool visited[MAX_VERTEX_NUM]; // 访问标志数组，通过改数组表示顶点是否已访问

int FirstAdjVex(ALGraph &G,int v)  //找到在图G中，与顶点G.vertices[v]相邻的未被访问的邻接点
{
    int i;
    int n = -1;
    ArcNode *p;
    p = G.vertices[v].firstarc;
    if(p)
    {
        i = p->adjvex;
        if(visited[i]==false)
            n = i;
    }
    return n;
}

int NextAdjVex(ALGraph &G,int v)
{
    int i;
    int n = -1;
    ArcNode *p;
    p = G.vertices[v].firstarc;
    for (i = p->adjvex; i < G.vexnum, p != NULL;)
    {
        i = p->adjvex;
        if(visited[i]==false)
        {
            n = i;
            break;
        }
        else
            p = p->nextarc;
        
    }
    return n;
}

void  VisitFuc(ALGraph &G,int v)
{
    cout << G.vertices[v].data << " ";
}

void DFS(ALGraph &G,int v)    //深度优先 遍历
{
    int w;
    visited[v] = true;//设置索引为v的顶点为已访问
    VisitFuc(G, v);//访问索引为v的顶点
    for (w = FirstAdjVex(G, v); w > 0;w=NextAdjVex(G,v))
    if(!visited[w])
        DFS(G, w);//递归调用DFS
}

void DFSTraverse(ALGraph &G) //深度优先遍历的起始函数，调用此函数开始遍历 
{
    int v;
    for (v = 0; v < G.vexnum;v++)
    {
        visited[v] = false; // 初始化图，将所有顶点都为未被访问状态
        cout << "深度优先搜索：";
        for (v = 0; v < G.vexnum;v++) //遍历所有的点
        {
            if(!visited[v])
                DFS(G, v);   
        }
    }
}

void BFSTraverse(ALGraph &G)
{
    int v, w;
    LinkQueue q;
    InitQueue(q);
    for (v = 0; v < G.vexnum;v++)
        visited[v] = false;
    cout << "广度优先搜索：";
    for (v = 0; v < G.vexnum;v++)
    {
        if(!visited[v])
        {
            visited[v] = true;
            VisitFuc(G, v);
            EnQueue(q, v);//  将该点入队，当 这个点所有的邻接点都被访问了再出列
            while(Empty(q)!=true)
            {
                v = GetFront(q);
                DeQueue(q);
                for (w = FirstAdjVex(G, v); w >=0;w=NextAdjVex(G,v)){
                    if(!visited[w])
                    {
                        visited[w] = true;
                        VisitFuc(G, w);
                        EnQueue(q, w);
                    }
                }
            }
        }
    }
}



int main()
{
    ALGraph G;
    CreateDG(G);
    DFSTraverse(G);
    cout << endl;
    BFSTraverse(G);
    cout << endl;
    return 0;
    }