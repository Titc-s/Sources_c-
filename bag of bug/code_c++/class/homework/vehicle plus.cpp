#include<bits/stdc++.h>
using namespace std;
class vehicle
{
    public:
        int Maxspeed, Weight;
        void Run() { cout << "vehicle has run!" << endl; }
        void Stop(){cout << "vehicle has stop!" << endl;}
};
class bicycle:virtual public vehicle
{
    public:
        int Height;
         void Run() { cout << "bicycle has run!" << endl; }
        void Stop(){cout << "bicycle has stop!" << endl;}
};
class motorcar:virtual public vehicle
{
    public:
        int SeatNum;
         void Run() { cout << "motorcar has run!" << endl; }
        void Stop(){cout << "motorcar has stop!" << endl;}
};
class motorcycle:public bicycle,public motorcar
{
    public:
     void Run() { cout << "motorcycle has run!" << endl; }
        void Stop(){cout << "motorcycle has stop!" << endl;}
};
int main()
{
    motorcycle a;
    a.Height = 1;
    a.Maxspeed = 1;
    cout << "高度" << a.Height << " 速度" << a.Maxspeed << endl;
    a.Run();
    return 0;
}