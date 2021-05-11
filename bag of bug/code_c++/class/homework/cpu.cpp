#include<bits/stdc++.h>
using namespace std;
enum CPU_Rank {P1=1,P2,P3,P4,P5,P6,P7};
class CPU
{
private: 
    CPU_Rank _rank;
 int _frequency;
 float _voltage;
public:
 CPU(int newrank,int newfrequency,float newvoltage);
 void run();
 void stop();
 
 ~CPU(){cout<<"成功调用析构函数"<<endl;}
};
void CPU::run()
{
 cout<<"CPU开始运行"<<endl;
 
}
void CPU::stop()
{
 cout<<"CPU停止运行"<<endl;
}
CPU::CPU(int newrank,int newfrequency,float newvoltage)
{ 
 _rank=(CPU_Rank)newrank;
 _frequency=newfrequency;
 _voltage=newvoltage;
    cout<<"成功调用构造函数"<<endl;
 cout<<"等级："<< _rank<<endl;
 cout<<"频率："<<_frequency<< "MHz" <<endl;
 cout<<"电压："<<_voltage<<"V"<<endl;
} 
int main()
{
    int lev, fre, vol;
    cout << "请输入等级";
    cin >> lev;
    cout << endl;
    cout << "请输入频率";
    cin >> fre;
    cout << endl;
    cout << "请输入电压";
    cin >> vol;
    cout << endl;

    CPU cpu(lev,fre,vol);
    cpu.run();
    cpu.stop();
    return 0;
}