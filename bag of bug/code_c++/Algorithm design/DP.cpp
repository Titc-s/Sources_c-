#include<iostream>
using namespace std;
#define MIN 0
int arc[100][100];
int vnum;
void CreateGraph()
{
    int arcnum;
    cout<<"请输入顶点和边的个数："<<endl;
    cin>>vnum>>arcnum;
    for(int i=0;i<vnum;i++){ // 初始化边的权值 
        for(int j=0;j<vnum;j++){
            arc[i][j] = MIN;
        }   
    }
    int weight;
    for(int k=1;k<=arcnum;k++){
        int i,j;
        cout<<"请输入第"<<k<<"条边的两个顶点和权值："<<endl;
        cin>>i>>j>>weight;
        arc[i][j] = weight;
    }
}

// 求 vunm个顶点的多段图的最长路径 
void Back() 
{
    int i,j;
    int cost[100],path[100]; // 存储路径长度和路径,cost[i]表示从i到源点的最长路径 
    for(i=1;i<vnum;i++){
        cost[i] = MIN;
        path[i] = -1;
    }
    // 顶点0为源点 
    cost[0] = 0;
    path[0] = -1;
    for(j=1;j<vnum;j++){ // 依次计算后面下标为1到vnum-1的点 
        for(i=j-1;i>=0;i--){
            if(cost[i]+arc[i][j]>cost[j]){
                cost[j] = cost[i]+arc[i][j]; // 更新值 
                path[j] = i; // 记录前一个点 
            }
        }
    } 
    // 输出路径
    i = vnum-1;
    cout<<i;
    while(path[i]>=0){ // 前一个点大于0 
        cout<<"<-"<<path[i];
        i = path[i];
    } 
    cout<<endl;
    cout<<cost[vnum-1]<<endl;//最长路径最终值
}
int main()
{
    CreateGraph();
	Back();
	return 0;
}