#include "registerwidget.h"

registerwidget::registerwidget(QWidget *parent) : QWidget(parent)
{
    this->setWindowTitle(QString("注册账号"));
    this->resize(300,100);

    b1.setParent(this);
    b1.setText(QString("确定"));
    b1.move(200,20);
    connect(&b1, &QPushButton::clicked, this, &registerwidget::register_account);

    b2.setParent(this);
    b2.setText(QString("取消"));
    b2.move(200,50);
    connect(&b2, &QPushButton::clicked, this, &registerwidget::send_back_slot);

    account.setParent(this);
    account.show();
    account.move(20,22);
    account.resize(160,20);
    account.setPlaceholderText("在此处输入账号");

    password.setParent(this);
    password.show();
    password.move(20,52);
    password.resize(160,20);
    password.setPlaceholderText("在此处输入密码");
}
void registerwidget::register_account()
{
    QString s1 = account.text();
    QString s2 = password.text();
    string str1 = s1.toStdString();
    string str2 = s2.toStdString();
    string temp;
    if(str1 == "")
    {
        QMessageBox::about(this, "tip", "账号为空，注册失败    ");
    }
    else if(str1 != "" && str2 == "")
    {
        QMessageBox::about(this, "tip", "密码为空，注册失败    ");
    }
    else
    {
        int flag = 0;
        ifstream fin(filename, ios::in);
        ofstream fout(filename, ios::app);
        while(std::getline(fin, temp))
        {
            if(temp == str1)flag = 1;
            std::getline(fin, temp);
            std::getline(fin, temp);
            std::getline(fin, temp);
        }
        fin.close();
        if(flag)
        {
            QMessageBox::about(this, "tip", "用户名已存在，注册失败    ");
        }
        else
        {
            QMessageBox::about(this, "tip", "注册成功    ");
            fout<<str1<<endl;
            fout<<str2<<endl;
            fout<<'0'<<endl;
            fout<<'1'<<endl;
            fout.close();
            this->hide();
            emit back_signal();
        }
        account.setText("");
        password.setText("");
    }
}
void registerwidget::send_back_slot()
{
    emit back_signal();
}
