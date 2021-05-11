#include<bits/stdc++.h>
using namespace std;
class Car;
class Boat
{
private:
int Boatwe;
public:
Boat() 
{
Boatwe=998;
}
friend int totalWeight(Boat &,Car &);
};
class Car
{
private:
    int Carwe;
public:
Car( ) 
{
Carwe=899;
}
friend int totalWeight(Boat &,Car &);
};
int totalWeight(Boat &x,Car &y)
{
    return x.Boatwe + y.Carwe;
}
int main()
{
Boat a;
Car b;
cout<<"总重量为"<<totalWeight(a,b)<<endl;
return 0;
}
