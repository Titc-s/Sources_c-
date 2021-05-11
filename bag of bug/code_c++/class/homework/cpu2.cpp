#include<bits/stdc++.h>
using namespace std;
enum CPU_Rank{P1=1,P2,P3,P4,P5,P6,P7};
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
 run();
 stop();
 } 
	class RAM                   
	{
		int x;
	public:
		RAM(int a){x=a;
		cout<<"构造了一个RAM"<<endl;
      run();
      stop();
      }
      ~RAM(){cout<<"析构了一个RAM"<<endl;}
      void run(){
         cout << "RAM开始运行" << endl;
      }
      void stop(){
         cout << "RAM停止运行" << endl;
      }
	};
	class CDROM               
	{
		char y;
	public:
		CDROM(char v){
         y=v;cout<<"构造了一个CDROM"<<endl;
         run();
         stop();
         }
		~CDROM(){cout<<"析构了一个CDROM"<<endl;}
         void run(){
         cout << "CDROM开始运行" << endl;
      }
      void stop(){
         cout << "CDROM停止运行" << endl;
      }
	};
	class Computer           
	{
		CPU cpu;
		RAM ram;
		CDROM cdrom;
	public:
		Computer(CPU_Rank x,int y,float z,int xx,char yy):cpu(x,y,z),ram(xx),cdrom(yy)
		{
			cout<<"构造了一个Computer"<<endl;}
		~Computer(){cout<<"析构了一个Computer"<<endl;}
		void Run(){
         cout<<"Computer开始运行"<<endl;
         }
        void Stop(){
           cout<<"Computer停止运行"<<endl;
           }

	};
	int  main()
	{
		Computer computer1(P6,3,2.9,4,'G');
		computer1.Run();
		computer1.Stop();
      return 0;
   } 
