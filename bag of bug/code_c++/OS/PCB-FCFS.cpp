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

void print(priority_queue<PCB> p) {
    PCB q;
    cout << "进程名\t到达时间 服务时间 开始时间 完成时间 周转时间 带权周转时间" << endl;
    while(p.size()!= 0){
        q = p.top();
        cout << q.name << "\t   " << q.arr_time << "\t" << q.ser_time << "\t";
        cout << q.start_run_time << "\t" << q.end_time << "\t   " << q.turnaround_time << " \t       " << q.weight_turnaround_time << endl;
        p.pop();
    }
    cout << endl
         << endl;
}

void runProcess(priority_queue<PCB> &p ,priority_queue<PCB> &q,int n){
    PCB s;
    float finishTimeOfPriorProcess;
    for (int i = 0; i < n;i++){
        s = p.top();
        if(i==0){
            while(s.needed_run_time!= 0){
                cout << "正在运行的进程为" << endl;
                cout << "进程名 \t 到达时间 服务时间 已运行时间 还剩运行时间" << endl;
                cout << s.name << "    \t" << s.arr_time << "    \t" << s.ser_time << "\t  ";
                cout << s.ser_time - s.needed_run_time << "\t         " << s.needed_run_time << endl;
                s.needed_run_time--;
                Sleep(1000);
            }
            s.start_run_time = s.arr_time;
            s.end_time = s.start_run_time + s.ser_time;
            s.turnaround_time = s.end_time - s.arr_time;
            s.weight_turnaround_time = float(s.turnaround_time * 1.0 / s.ser_time);
            s.state = 'C';
            finishTimeOfPriorProcess = s.end_time;
        }
        else{ 
            while(s.needed_run_time != 0){
                cout <<"正在运行的进程" << endl;
                cout<< "进程名\t到达时间 服务时间 已运行时间 还剩运行时间" << endl;
				cout << s.name << "  \t" << s.arr_time<< "  \t " << s.ser_time << "\t  ";
				cout << s.ser_time- s.needed_run_time << "\t       " << s.needed_run_time << endl;
				s.needed_run_time--;//当前进程的估计运行时间减1
                Sleep(1000);
            }
            s.start_run_time = finishTimeOfPriorProcess>s.arr_time ? finishTimeOfPriorProcess : s.arr_time;
			s.end_time = s.start_run_time + s.ser_time;
			s.turnaround_time = s.end_time - s.arr_time;
			s.weight_turnaround_time = float(s.turnaround_time*1.0 / s.ser_time);
			s.state = 'C';
			finishTimeOfPriorProcess = s.end_time;

        }
        q.push(s);
        p.pop();
        cout << "进程" << s.name << "执行结束之后就绪队列的进程" << endl;
        print(p);
    }
    cout << endl
         << endl;
}

int main()
{
    priority_queue<PCB> p, q;
    unsigned seed = N;
    srand(seed);
    int n;
    cout << "请输入进程个数:";
    cin>>n;
    createProcess(p, n);
    runProcess(p, q, n);
    cout << "所有进程执行结束之后的相关情况" << endl
         << endl;
    print(q);
    getchar();
    return 0;
}