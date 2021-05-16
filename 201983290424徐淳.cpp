#include<iostream>
using namespace std;
#define MIN -999
int arc[100][100]; // ���100���� 
int vnum;
void CreateGraph()
{
	int arcnum;
	cout<<"�����붥��ͱߵĸ�����"<<endl;
	cin>>vnum>>arcnum;
	for(int i=0;i<vnum;i++){ // ��ʼ���ߵ�Ȩֵ 
		for(int j=0;j<vnum;j++){
			arc[i][j] = MIN;
		}	
	}
	int weight;
	for(int k=1;k<=arcnum;k++){
		int i,j;
		cout<<"�������"<<k<<"���ߵ����������Ȩֵ��"<<endl;
		cin>>i>>j>>weight;
		arc[i][j] = weight;
	}
}

// �� vunm������Ķ��ͼ���·�� 
void Back() 
{
	int i,j;
	int cost[100],path[100]; // �洢·�����Ⱥ�·��,cost[i]��ʾ��i��Դ����·�� 
	for(i=1;i<vnum;i++){
		cost[i] = MIN;
		path[i] = -1;
	}
	// ����0ΪԴ�� 
	cost[0] = 0;
	path[0] = -1;
	for(j=1;j<vnum;j++){ // ���μ�������±�Ϊ1��vnum-1�ĵ� 
		for(i=j-1;i>=0;i--){
			if(cost[i]+arc[i][j]>cost[j]){
				cost[j] = cost[i]+arc[i][j]; // ����ֵ 
				path[j] = i; // ��¼ǰһ���� 
			}
		}
	} 
	// ���·��
	i = vnum-1;
	cout<<i;
	while(path[i]>=0){ // ǰһ�������0 
		cout<<"<-"<<path[i];
		i = path[i];
	} 
	cout<<endl;
	cout<<cost[vnum-1]<<endl;//�·������ֵ
}

int main()
{
    CreateGraph();
	Back();
	return 0;
}