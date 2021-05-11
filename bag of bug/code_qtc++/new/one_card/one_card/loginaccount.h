#ifndef LOGINACCOUNT_H
#define LOGINACCOUNT_H

#include <QWidget>
#include <QPushButton>
#include <QString>
#include <QMessageBox>
#include <QLineEdit>
#include <iostream>
#include <string>
#include <fstream>
#include "account.h"
using namespace std;
#define filename "D:\\bag of bug\\code_qtc++\\new\\one_card\\one_card\\user_information.txt"
class LoginAccount : public QWidget
{
    Q_OBJECT
public:
    explicit LoginAccount(QWidget *parent = nullptr);

    void send_back_slot();
    void login_account();
    void send_switch_slot();
    void send_trans_slot();
    string new_temp1;
    string mew_temp2;
    int new_temp;
signals:
    void back_signal();
    void switch_signal();
    void trans_signal();
private:
    QPushButton b1;
    QPushButton b2;
    QLineEdit account_number;
    QLineEdit password;
};
#endif // LOGINACCOUNT_H
