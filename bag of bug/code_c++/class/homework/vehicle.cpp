#include<bits/stdc++.h>
using namespace std;
class vehicle
{
public:
	vehicle(int x,double y)
	{
		wheels=x;
		weight=y;
	}
	void print()
	{
		cout<<"vehicle:\n";
		cout<<"车轮个数："<<wheels<<"\n车的重量："<<weight<<endl;
	}
protected:
	int wheels;
	double weight;	
};
class car:private vehicle
{
private:
	int passengerload;
public:
	car(int x,double y,int load):vehicle(x,y)
	{
		passengerload=load;
	}
    void print()
	{
		cout<<"car:\n";
		vehicle::print();
		cout<<"载人数："<<passengerload<<endl;
	}
};
class truck:private vehicle
{
private:
	int passengerload;
	double payload;
public:
	truck(int x,double y,int load,double loady):vehicle(x,y)
	{
	    passengerload=load;
		payload=loady;
	}
	void print()
	{
		cout<<"truck:\n";
		vehicle::print();
		cout<<"载人数："<<passengerload<<"\n载重量："<<payload<<endl;
	}
};
int  main()
{
	car car1(8,2.5,6);
	car1.print();
	cout<<"\n";
	truck tr1(12,5.6,30,9.5);
	tr1.print();
    return 0;
}