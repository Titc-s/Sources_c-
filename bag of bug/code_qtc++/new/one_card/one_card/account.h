#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <iostream>
#include <string>
using namespace std;

class account
{
public:
    account();
    string present_account;
    string present_password;
    int present_balance;
    int present_status;
};

#endif // ACCOUNT_H
