#include"Account.h"
void Account::create_account()
{
	string a,b;
	cin>>a>>b;
	account_number=a;
	account_password=b;
}
string Account::output_account_number()
{
	return account_number;
}
string Account::output_account_password()
{
	return account_password;
}
void Account::show_account()
{
	cout<<"����˺�Ϊ��"<<account_number<<endl;
	cout<<"�������Ϊ��"<<account_password<<endl;
}
void Account::change_account(string s1,string s2)
{
	account_number=s1;
	account_password=s2;
}
