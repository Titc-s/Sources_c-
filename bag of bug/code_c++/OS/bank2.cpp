#include<iostream>

using namespace std;

const int MAXRESOURCE = 60;
const int MAXPROCESS = 30;
int Avalibale[MAXRESOURCE];
int MAX[MAXPROCESS][MAXRESOURCE];  //最大需求矩阵
int Allocation[MAXPROCESS][MAXRESOURCE];  // 分配矩阵
int Need[MAXPROCESS][MAXRESOURCE];  //需求矩阵
int Request[MAXPROCESS];//请求矩阵
int Work[MAXPROCESS];
bool Finish[MAXPROCESS];// 查看是否有足够的资源分配给进程。
int SouNum, ProNum;
int Safe[MAXPROCESS];

void Init()
{
    cout << "请输入进程数:";
    cin >> ProNum;
    cout << "请输入总资源数：";
    cin >> SouNum;
    cout << "请输入资源可利用数：";
    for (int j = 0; j < SouNum;j++)
        cin >> Avalibale[j];
    cout << "请输入个进程对个资源最大需求数：" << endl;
    for (int i = 0; i < ProNum;i++)
        for (int j = 0; j < SouNum;j++)
            cin >> MAX[i][j];
    cout << "请输入各进程已得到的资源数：" << endl;
    for (int i = 0; i < ProNum;i++)
        for (int j = 0; j < SouNum;j++)
            cin >> Allocation[i][j];
    for (int i = 0; i < ProNum;i++)
        for (int j = 0; j < SouNum;j++)
            Need[i][j] = MAX[i][j] - Allocation[i][j];
}

void show()
{
    cout << "当前资源可利用数为：" << endl;
    for (int j = 0; j < SouNum;j++)
        cout << Avalibale[j] << " ";
    cout << endl;
    cout << "各进程对各资源的最大需求数分别为：" << endl;
    for (int i = 0; i < ProNum; i++)
        for (int j = 0; j <SouNum;j++)
        {
            cout << MAX[i][j] << " ";
            if(j==SouNum-1)
                cout << endl;
        }
    cout << "各进程得到的各资源数分别为：" << endl;
    for (int i = 0; i < ProNum; i++)
        for (int j = 0; j <SouNum;j++)
        {
            cout << Allocation[i][j] << " ";
            if(j==SouNum-1)
                cout << endl;
        }
    cout << "各进程仍需的各资源数分别为：" << endl;
    for (int i = 0; i < ProNum; i++)
        for (int j = 0; j <SouNum;j++)
        {
            cout << Need[i][j] << " ";
            if(j==SouNum-1)
                cout << endl;
        }
}

bool IsSafe()
{
    for (int j = 0; j < SouNum;j++)
        Work[j] = Avalibale[j];
    for (int i = 0; i < ProNum;i++)
        Finish[i] = false;
    int i, j, k, l = 0;
    while(l<ProNum)
    {
        int index = l;
        for (i = 0; i < ProNum;i++)
        {
            if(Finish[i]==true)
                continue;
            for (j = 0; j < SouNum;j++)
                if(Need[i][j]>Work[j])
                    break;
            if(j==SouNum)
            {
                Finish[i] == true;
                for (k = 0; k < SouNum;k++)
                    Work[k] += Allocation[i][k];
                Safe[l++] = i;
            }
            else
                continue;
        }
        if(l==index)
        {
            cout << "没有安全序列 " << endl;
            return false;
        }
    }
    return true;
}

void Banker()
{
    int i;
    bool flag = false;
    cout << "请输入请求资源的进程号:";
    cin >> i;
    cout << "请依次输入该进程请求的各类资源数：" << endl;
    for (int j = 0; j < SouNum;j++)
    {
        cin >> Request[j];
        if(Request[j]>Need[i][j])
        {
            cout << "请求资源数超多所需最大值，请求失败" << endl;
            flag = false;
        }
        if(Request[j]>Avalibale[j])
        {
            cout << "系统内资源不足，请求失败，进程需等待" << endl;
            flag = true;
        }
    }
    if(flag==false){
        for (int j = 0; j < SouNum;j++)
        {
            Avalibale[j] -= Request[j];
            Allocation[i][j] += Request[j];
            Need[i][j] -= Request[j];
        }
        if(IsSafe())
        {
            cout << "资源分配成功"<<endl;
            cout << "安全序列为：";
            for (int i = 0; i < ProNum - 1;i++)
                cout << "P" << Safe[i] << "->";
            cout << "P" << Safe[ProNum - 1] << endl;
        }
        else
        {
            cout << "资源分配失败，进程等待" << endl;
            for (int j = 0; j < SouNum;j++)
            {
                Avalibale[j] += Request[j];
                Allocation[i][j] -= Request[j];
                Need[i][j] += Request[j];
            }
        }
    }
}

int main()
{
    Init();
    if(IsSafe())
        cout << "初始系统安全" << endl;
    else{
        cout << "初始系统不安全！" << endl;
        return 0;
    }
    while(1){
        int s = 0;
        cout << "*********************************" << endl;
		cout << "1、查询当前资源分配情况" << endl;
		cout << "2、请求资源" << endl;
		cout << "3、退出" << endl;
		cout << "*********************************" << endl;
		cout << "请选择您希望执行的操作：";
		cin >> s;
        if (s == 1)
            show();
        else if(s==2)
            Banker();
        else if(s==3)
            break;
        else
            cout << "不存在该操作，请重新输入" << endl;
        cout << endl;
    }
    system("pause");
    return 1;
}