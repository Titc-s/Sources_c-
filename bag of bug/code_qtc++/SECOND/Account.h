#ifndef _ACCOUNT_H_
#define _ACCOUNT_H_
#include<iostream>
using namespace std;
class Account
{
	private:
		string account_number;
		string account_password;
		int money = 0;
	public:
		void create_account();
		string output_account_number();
		string output_account_password();
		void show_account();
		void change_account(string , string );
};
#endif
