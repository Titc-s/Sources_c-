#include<iostream>  
#include<fstream>  
#include<queue>  
#include<cstring> 
using namespace std;  
#define inf 10000
const int MAX = 100;  
  
struct link  
{  
 int data;
 string name;
 link *lnext;  
};  
struct Node  
{  
 int v; 
 string nn;
 string PeoName;
 link *lnext;  
};  
struct Graph  
{  
  Node node[MAX+1]; //所有的结点  
  int ncount; 
};  
  
int visited[MAX+1]; //查询是否走过的数组 
int pa[MAX+1];  
  
 
int tono(Graph G,string n){
	for(int i=1;i<=G.ncount;++i){
		if(G.node[i].nn==n)
			return i;
	}
}

string toname(Graph G,int q){
		for(int i=1;i<=G.ncount;++i){
		if(G.node[i].v==q)
			return G.node[i].nn;
	}
}
	

Graph CreateGraph()  
{   
    int a,b,c,d;
    cout<<"输入总人数，总边数";
    cin>>a>>b;

    //表的初始化 ,人数是节点 
    Graph G;  
    G.ncount = a;

    int i ;
    string na, ne;
    for(i = 1; i <= a; i ++)  
    {  	cout<<"输入姓名："<<endl;
    	cin>>na;
      G.node[i].PeoName = na;
      cout << "输入地理位置： " ;
      cin >> ne;
      G.node[i].nn = ne;
        G.node[i].v = i;  
        G.node[i].lnext = NULL;  
    }  
  
    int n1 = 0,n2 = 0;  
    link *s;  
    string n5,n6;
    for(int i=0;i<b;++i) 
    {  	cout<<"输入联通一条边的两人地理位置";
    	cin>>n5>>n6;
    	c = tono(G,n5);
		d = tono(G,n6); 
        s = new link;  
        s->data = d;
		s->name = n6;  
        s->lnext=G.node[c].lnext;  
        G.node[c].lnext=s; //从尾部插入  
        //delete(s);  
  
        s=new link;  
        s->data = c;  
        s->name = n5;
        s->lnext=G.node[d].lnext;  
        G.node[d].lnext=s; //无向图  
        //delete(s);  
    }  
    return G;  
}  
  
//打印邻接表   
void printGraph(Graph G)  
{  
  link *p;  
  for(int i = 1; i <= G.ncount; i ++)  
  {  
      cout<<G.node[i].nn<<" -- ";  
  
      p=G.node[i].lnext;  
      while(p!=NULL)  
      {  
          cout<<p->name;  
          p=p->lnext;  
          if(p != NULL)   
              cout<<",";  
      }  
      cout<<endl;  
  }  
}  
  
///BFS求两点之间最短路径 
void shortestPath(Graph G, string n3, string n4)  
{  
	int s,d;
	s = tono(G,n3);
	d = tono(G,n4);
    cout<<"从"<<n3<<"到"<<n4<<"最短路求解过程如下："<<endl;  
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
        //cnt ++;  
        while(p != NULL)  
        {  
            if(!visited[p->data])  
            {  
                visited[p->data] = 1;  
                pa[p->data] = parents;  
                cout<<"访问："<<p->name<<endl;  
                if(p->data == d) //找到了目标结点  
                {  
                    break;  
                }  
                que.push(p->data);  
            }  
            p = p->lnext;  
        }  
    }  
    cout<<"路径如下："<<endl;  
    parents = d;
	string nm = toname(G,parents);  
    int count = 0; 
    while(pa[parents] != -1)  
    {  
        cout<<nm<<" <- ";  
        parents = pa[parents];
		nm = toname(G,parents)  ;
		count++;
    }  
    cout<<nm<<endl; 
	cout<<"总共经过"<<count-1<<"人找到对方"<<endl; 
}

//dist数组中存放着每两个人之间的最少联系人 
int dist[MAX][MAX] ;

//给dist数组赋值 
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
  
int main()  
{  
	string n3,n4;
    int s,d,j;  
    fill(dist[0], dist[0] +MAX * MAX, inf);

    Graph G = CreateGraph();  
    printGraph(G); 
	string nm,nm1;
    while(true)  
    {  	cout<<"-------------查找最短路径---------------"<<endl;
        cout<<"请输入起点和终点:"<<endl;  
        cin>>n3>>n4;
  
        shortestPath(G, n3,n4); 

 
    for(int i=1;i<=G.ncount;++i){
    	for(int f=1;f<=G.ncount;++f){
    		shortestPath1(G,i,f);
		}
	}
	cout<<endl;
	cout<<"------------查找附近能联络的人-------------"<<endl;
	cout<<"查找谁附近能联络的人："<<endl;
	cin>>nm;
	int q = tono(G,nm);
    	for(j=1;j<=G.ncount;++j){
			if(dist[q][j]==1){
			
			nm1 = toname(G,j);
			cout<<nm<<"能通过一次中间人联系"<<nm1<<endl;    		
				}
			if(dist[q][j]==0){
				nm1 = toname(G,j);
				cout<<nm<<"能够直接联系"<<nm1<<endl;
			}	
		}
	} 
      

	
    return 0;  
}
