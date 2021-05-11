#include<bits/stdc++.h>
using namespace std;
class vehicle
{
    public:
        int Maxspeed, Weight;
         virtual void Run() { cout << "vehicle has run!" << endl; }
        virtual void Stop(){cout << "vehicle has stop!" << endl;}
};
class bicycle:virtual public vehicle
{
    public:
        int Height;
       virtual void Run() { cout << "bicycle has run!" << endl; }
        virtual void Stop(){cout << "bicycle has stop!" << endl;}
};
class motorcar:virtual public vehicle
{
    public:
        int SeatNum;
        virtual void Run() { cout << "motorcar has run!" << endl; }
        virtual void Stop(){cout << "motorcar has stop!" << endl;}
};
class motorcycle:public bicycle,public motorcar
{
    public:
      virtual void Run() { cout << "motorcycle has run!" << endl; }
    virtual void Stop(){cout << "motorcycle has stop!" << endl;}
};
void fun(vehicle *p){
    p->Run();
    p->Stop();
}
int main()
{
    vehicle b;
    bicycle c;
    motorcar d;
    motorcycle a;
    a.Height = 1;
    a.Maxspeed = 1;
    cout << "高度" << a.Height << " 速度" << a.Maxspeed << endl;
    a.Run();
    fun(&a);
    fun(&b);
    fun(&c);
    fun(&d);
    return 0;
}
