#include<iostream>
#include<fstream>
#include<queue>
#include<cstring>

using namespace std;
#define inf 10000
const int MAX = 100;

struct  link  // 边结构体
{
    int data;  // 存放数据
    string name; //社交人姓名
    link *lnext;// 连接点
};

struct Node   //点结构体
{
    int v;
    string nn;   //结点名称
    link *lnext;
    bool sex;
};

struct Graph
{
    Node node[MAX + 1];
    int ncount;
};

int visited[MAX + 1];
int pa[MAX + 1];

int tono(Graph G,string n)
{
    for (int i = 1; i < G.ncount;++i)
    {
        if(G.node[i].nn==n)
            return i;
    }
}

string toname(Graph G, int q)
{
    for (int i = 1; i < G.ncount;i++)
    {
        if(G.node[i].v==q)
            return G.node[i].nn;
    }
}

Graph CreateGraph()    // 创建图
{
    int a, b, c, d;
    cout << "请分别输入总人数、边数";
    cin >> a >> b;

    // 以人作为结点

    Graph G;
    G.ncount = a;

    int i;
    string Name;
    for (i = 1; i <=a;i++)
    {
        cout << "请输入第" << i << "个结点的人的姓名：" << endl;
        cin >> Name;
        G.node[i].nn = Name;
        G.node[i].v = i;
        G.node[i].lnext = NULL;
    }

    int n1 = 1, n2 = 0;
    link *s;
    string n5, n6;
    for (int i = 1; i <=b;i++)
    {
        cout << "请输入第"<<i<<"条边的两个结点【两个人名】:";
        cin >> n5 >> n6;
        c = tono(G, n5);
        d = tono(G, n6);
        s = new link;
        s->data = d;
        s->name = n6;
        s->lnext = G.node[c].lnext;
        G.node[c].lnext = s;  // 尾插法
        //delete (s)

        s = new link;
        s->data = c;
        s->name = n5;
        s->lnext = G.node[d].lnext;
        G.node[d].lnext = s;   //由于此次为无向图，所以做成双向连接
    }
    return G;
}

void printGraph(Graph G)   // 打印该表
{
    link *p;
    for (int i = 1; i <= G.ncount;i++)
    {
        cout << G.node[i].nn << " -- ";

        p = G.node[i].lnext;
        while(p!=NULL)
        {
            cout << p->name;
            p = p->lnext;
            if(p!=NULL)
                cout << ",";
        }
        cout << endl;
    }
}

//BFS 求两点之间最短路径
void shortestPath(Graph G,string n3,string n4)
{
    int s, d;
    s = tono(G, n3);
    d = tono(G, n4);
    cout << "从" << n3 << "到" << n4 << "最短路求解分析如下：" << endl;
    queue<int> que;
    link *p = NULL;
    int parents = s;
    memset(visited, 0, sizeof(visited));
    memset(pa, 0, sizeof(pa));
    visited[s] = 1;
    pa[s] = -1;
    que.push(s);
    while(!que.empty()){
        p = G.node[que.front()].lnext;
        parents = que.front();
        que.pop();
        // cnt ++?
        while(p!=NULL)
        {
            if(!visited[p->data])
            {
                visited[p->data] = 1;// 访问过
                pa[p->data] = parents;
                cout << "访问：" << p->name << endl;
                if(p->data ==d)
                {
                    break;
                }
                que.push(p->data);
            }
            p = p->lnext;
        }
    }
    cout << "路径如下:" << endl;
    parents = d;
    string Name = toname(G, parents);
    int count = 0;
    while(pa[parents]!=-1)
    {
        cout << Name << " <- ";
        parents = pa[parents];
        Name = toname(G, parents);
        count++;
    }
    cout << Name << endl;
    cout << "一共经过" << count - 1 << "个人找到对方" << endl;
}

int dist[MAX][MAX]; //dist中存储两个人之间的最短路径

void shortestPath1(Graph G, int s,int d)  
{  
    queue<int> que ;  
    link * p = NULL;  
    //int cnt = 0;  
    int parents = s;  
    memset(visited,0,sizeof(visited));  
    memset(pa,0,sizeof(pa));  
    visited[s] = 1;  
    pa[s] = -1;  
    que.push(s);  
    while(!que.empty()){  
        p = G.node[que.front()].lnext;  
        parents = que.front();  
        que.pop();  
        while(p != NULL)  
        {  
            if(!visited[p->data])  
            {  
                visited[p->data] = 1;  
                pa[p->data] = parents;  
                if(p->data == d) //找到了目标结点  
                {  
                    break;  
                }  
                que.push(p->data);  
            }  
            p = p->lnext;  
        }  
    }  
    parents = d;
    //cout<<parents<<" <- ";  
    int count = 0; 
    while(pa[parents] != -1)  
    {  
        parents = pa[parents];
		count++;
    }
    
	dist[s][d] = count-1;  
}  


// void shortestPath1(Graph G,int s,int d)
// {
//     queue<int> que;
//     link *p = NULL;
//     int parents = s;
//     memset(visited, 0, sizeof(visited));
//     memset(pa, 0, sizeof(pa));
//     visited[s] = 1;
//     pa[s]= -1;
//     que.push(s);
//     while(!que.empty())
//     {
//         p = G.node[que.front()].lnext;
//         parents = que.front();
//         que.pop();
//         while(p!=NULL)
//         {
//             if(!visited[p->data])
//             {
//                 visited[p->data] = 1;
//                 pa[p->data] = parents;
//                 if(p->data==d)
//                 {
//                     break;
//                 }
//                 que.push(p->data);
//             }
//             p = p->lnext;
//         }
//     }
//     parents = d;
//     int count = 0;
//     while(pa[parents]!=-1)
//     {
//         parents = pa[parents];
//         count++;
//     }
//     dist[s][d] = count - 1;
// }


int main()
{
    string n3, n4;
    int s, d, j;
    fill(dist[0], dist[0] + MAX * MAX, inf);

    Graph G = CreateGraph();
    printGraph(G);
    string Name, Name1;
     for (int i = 1; i < G.ncount;i++)
            for (int f = 1; f <= G.ncount;f++)
                shortestPath1(G, i, f);
    while(true)
    {
        cout << "----------------查找最短路径-------------" << endl;
        cout << "请输入起点和终点：" << endl;
        cin >> n3 >> n4;

        shortestPath(G,n3,n4);
        // for (int i = 1; i < G.ncount;i++)
        //     for (int f = 1; f <= G.ncount;f++)
        //         shortestPath1(G, i, f);
        cout << endl;
        cout << "-------------查找附近能联络的人员--------" << endl;
        cout << "请输入查找誰附近能联络的人：" << endl;
        cin >> Name;
        int q =tono(G,Name);
        for (j = 1; j <= G.ncount;j++)
        {
            if(dist[q][j]==1)
            {
                Name1 = toname(G, j);
                cout << Name << "能通过一次中间人联系" << Name1 << endl;
            }
            if(dist[q][j]==0)
            {
                Name1 = toname(G, j);
                cout << Name << "能够直接联系" << Name1 << endl;
            }
        }
    }

    return 0;
}