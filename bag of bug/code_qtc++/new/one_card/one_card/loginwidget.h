#ifndef LOGINWIDGET_H
#define LOGINWIDGET_H

#include <QWidget>
#include <QPushButton>
#include <QString>
#include <QMessageBox>
#include <iostream>
#include <string>
#include <fstream>
#include "account.h"
using namespace std;
#define filename "D:\\bag of bug\\code_qtc++\\new\\one_card\\one_card\\user_information.txt"
class LoginWidget : public QWidget
{
    Q_OBJECT
public:
    explicit LoginWidget(QWidget *parent = nullptr);

    void send_back_slot();
    void send_recharge_slot();
    void send_password_slot();
    void change_inf(string , int );
    void show_account_balance();
    void report_loss();
    void recharge();
    string present_account;
    string present_password;
    int balance;
    int status;
signals:
    void back_signal();
    void recharge_signal();
    void password_signal();
private:
    QPushButton b1;
    QPushButton b2;
    QPushButton b3;
    QPushButton b4;
    QPushButton b5;
};
#endif // LOGINWIDGET_H
