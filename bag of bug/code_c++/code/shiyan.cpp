#include<iostream>
#include<string>
using namespace std;
class date
{
	private:
		int year;
		int month;
		int day;
	public:
		date(){};
		date(int y,int m,int d)
		{
			year=y;
			month=m;
			day=d;
		}
		void set()
		{
			cin>>year>>month>>day;
		}
		void show()
		{
			cout<<year<<"."<<month<<"."<<day<<endl;
			
		}
		
};

class People{
	private:
		int num;
		char sex;
		date bir;
		char ID[10];
	public:
		People(){};
		People(int n,int y,int m,int d,char id[10],char s='m' ):bir(y,m,d)
		{
		    num=n;
			sex=s;
			ID[10]=id[10];
		}
	People(People& p) 
    {
    num=p.num;
    sex=p.sex;
    bir=p.bir;
    ID[10]=p.ID[10];
    }
	void input()
	{
		cout<<"录入数据"<<endl;
		cin>>num>>sex;
		bir.set();
		cin>>ID;
		cout<<endl;
	 }
	 void output()
	 {
	 	cout<<"num:"<<num<<endl;
	 	cout<<"sex:"<<sex<<endl;
	 	cout<<"birthday:";
	 	bir.show();
	 	cout<<"ID:"<<ID<<endl;
	  } 
    ~People(){};

	
};
int main()
{
	People peo;
	peo.input();
	peo.output();
	return 0;
}
