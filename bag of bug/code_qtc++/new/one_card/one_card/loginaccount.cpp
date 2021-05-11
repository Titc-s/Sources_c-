#include "loginaccount.h"

LoginAccount::LoginAccount(QWidget *parent) : QWidget(parent)
{
    this->setWindowTitle(QString("登录账号"));
    this->resize(300,100);
    b1.setParent(this);
    b1.setText(QString("确定"));
    b1.move(200,20);
    connect(&b1, &QPushButton::clicked, this, &LoginAccount::login_account);
    b2.setParent(this);
    b2.setText(QString("取消"));
    b2.move(200,50);
    connect(&b2, &QPushButton::clicked, this, &LoginAccount::send_back_slot);
    account_number.setParent(this);
    account_number.show();
    account_number.move(20,22);
    account_number.resize(160,20);
    account_number.setPlaceholderText("在此处输入账号");
    password.setEchoMode(QLineEdit::Password);
    password.setParent(this);
    password.show();
    password.move(20,52);
    password.resize(160,20);
    password.setPlaceholderText("在此处输入密码");
}
void LoginAccount::login_account()
{
    QString s1 = account_number.text();
    QString s2 = password.text();
    string str1 = s1.toStdString();
    string str2 = s2.toStdString();
    int exist = 0;
    int match = 0;
    string temp1;
    string temp2;
    int temp;
    ifstream fin(filename, ios::in);
    while(std::getline(fin, temp1))
    {
        std::getline(fin, temp2);
        if (str1 == temp1)
            {
               exist = 1;
               if(str2 == temp2)
                {
                 match = 1;
                }
        }
        std::getline(fin, temp2);
        std::getline(fin, temp2);
        temp = stoi(temp2);
    }
    fin.close();
    new_temp1 = str1;
    new_temp = temp;
    if(!exist)
    {
        QMessageBox::about(this, "tip", "用户名不存在    ");
    }
    else
    {
        if(match)
        {
            QMessageBox::about(this, "tip", "登录成功    ");
            send_switch_slot();
            send_trans_slot();
            account_number.setText("");
            password.setText("");
        }
        else
        {
            QMessageBox::about(this, "tip", "密码错误    ");
        }
    }
}
void LoginAccount::send_back_slot()
{
    emit back_signal();
    account_number.setText("");
    password.setText("");
}
void LoginAccount::send_switch_slot()
{
    emit switch_signal();
}
void LoginAccount::send_trans_slot()
{
    emit trans_signal();
}
