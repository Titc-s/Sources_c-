#ifndef CHANGEPASSWORD_H
#define CHANGEPASSWORD_H

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
#define filename "C:\\study_resource\\class\\c++\\new\\one_card\\one_card\\user_information.txt"
class ChangePassword : public QWidget
{
    Q_OBJECT
public:
    explicit ChangePassword(QWidget *parent = nullptr);
    void send_back_slot();
    void change_inf(string);
    void change_password();
    string present_account;
signals:
    void back_signal();
private:
        QPushButton b1;
        QPushButton b2;
        QLineEdit password;
};
#endif // CHANGEPASSWORD_H
