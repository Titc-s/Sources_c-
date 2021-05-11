#include<iostream>
#include<string>
#include<queue>
#include<Windows.h>
using namespace std;

#define N 10;
typedef struct pcb {
    char name;
    float arr_time;    //到达时间
    float ser_time;    //所需运行时间
    float start_run_time; //开始运行时间
    float needed_run_time;// 还需要运行时间
    float end_time; // 结束运行时间
    float turnaround_time; //周转时间
    float weight_turnaround_time; // 带权周转时间'
    char state; //状态
    struct pcb *next;
    bool operator<(const pcb  &a) const {
        return arr_time > a.arr_time;
    }
} PCB;

void createProcess(priority_queue<PCB> &p, int n){
    cout << endl
         << endl
         << "创建进程" <<endl;
    PCB r;
    for (int i = 0; i < n; i++)
    {
        cout << "第" << i + 1 << "个进程的名字、到达时间、所需服务时间为：";
        r.name = 'A' + i;
        r.arr_time = rand()%N+1;
        r.ser_time = rand()%N+1;
        cout << r.name<<" " << r.arr_time <<" "<< r.ser_time << endl;
        r.start_run_time = 0;
        r.end_time = 0;
        r.needed_run_time = r.ser_time;
        r.turnaround_time = 0;
        r.weight_turnaround_time = 0;
        p.push(r);
    }
}

void rate(pcb S, int k, int m)
{
    
}
