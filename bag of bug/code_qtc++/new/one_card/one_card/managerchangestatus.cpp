#include "managerchangestatus.h"

ManagerChangeStatus::ManagerChangeStatus(QWidget *parent) : QWidget(parent)
{
    this->setWindowTitle(QString("修改人员信息"));
    this->resize(300,100);
    b1.setParent(this);
    b1.setText(QString("确定"));
    b1.move(200,20);
    connect(&b1, &QPushButton::clicked, this, &ManagerChangeStatus::change_password);
    b2.setParent(this);
    b2.setText(QString("取消"));
    b2.move(200,50);
    connect(&b2, &QPushButton::clicked, this, &ManagerChangeStatus::send_back_slot);
    account.setParent(this);
    account.show();
    account.move(20,22);
    account.resize(160,20);
    account.setPlaceholderText("在此处输入要修改的账号");
    password.setParent(this);
    password.show();
    password.move(20,52);
    password.resize(160,20);
    password.setPlaceholderText("在此处输入状态0(挂失)/1(解挂)");
}
void ManagerChangeStatus::send_back_slot()
{
    emit back_signal();
    account.setText("");
    password.setText("");
}
void ManagerChangeStatus::change_password()
{
    QString s1 = account.text();
    QString s2 = password.text();
    string str1 = s1.toStdString();
    string str2 = s2.toStdString();
    int exist = 0;
    string temp1;
    string newstring="";
    ifstream fin(filename, ios::in);
    while(std::getline(fin, temp1))
    {
        if(temp1 == str1)
        {
            newstring += temp1;
            newstring += '\n';
            std::getline(fin, temp1);
            newstring += temp1;
            newstring += '\n';
            std::getline(fin, temp1);
            newstring += temp1;
            newstring += '\n';
            std::getline(fin, temp1);
            newstring += str2;
            newstring += '\n';
            exist = 1;
        }
        else
        {
            newstring += temp1;
            newstring += '\n';
        }
    }
    if(exist == 1)
    {
        if(str2 == "0")
        {
            QMessageBox::about(this, "tip", "挂失成功     ") ;
        }
        if(str2 == "1")
        {
            QMessageBox::about(this, "tip", "解挂成功     ") ;
        }
        account.setText("");
        password.setText("");
        fin.close();
        ofstream fout(filename, ios::app);
        ofstream file_writer(filename, ios_base::out);
        fout<<newstring;
        fout.close();
        send_back_slot();
    }
    else
    {
        QMessageBox::about(this, "tip", "用户不存在     ") ;
        account.setText("");
        password.setText("");
    }
}
