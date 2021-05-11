#include<bits/stdc++.h>
using namespace std;


class People
{
    public:
        People () { cout << "people 构造" << endl; }
        ~People() { cout << "people 析构" << endl; }
};
class student:virtual public People
{
    public:
        char classNo[7];
        void getmessage()
        {
            cout << classNo << endl;
        }
};
class teacher:virtual public People
{
    public:
        char principalship[11];
        char department[21];
        void getmessage()
        {
            cout << principalship << endl;
            cout << department << endl;
        }
};
class graduate:public student
{
    public:
        char subject[21];
        teacher adviser;
        void getmessage()
        {
            cout << subject << endl;
            cout << adviser.principalship << endl;
            cout << adviser.department << endl;

        }
};
class TA:public graduate,public teacher
{
	public:
		void setmessage()
		{
			cin>>classNo>>principalship>>department>>subject>>adviser.principalship>>adviser.department;
		}
};
  int main()
{
   TA a;
	a.setmessage();
	a.student::getmessage();
	a.teacher::getmessage();
	a.graduate::getmessage();
    return 0;
}