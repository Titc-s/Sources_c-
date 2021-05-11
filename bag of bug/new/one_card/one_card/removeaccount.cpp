#include "removeaccount.h"

RemoveAccount::RemoveAccount(QWidget *parent) : QWidget(parent)
{
    this->setWindowTitle(QString("修改人员信息"));
    this->resize(300,100);
    b1.setParent(this);
    b1.setText(QString("确定"));
    b1.move(200,20);
    connect(&b1, &QPushButton::clicked, this, &RemoveAccount::remove);
    b2.setParent(this);
    b2.setText(QString("取消"));
    b2.move(200,50);
    connect(&b2, &QPushButton::clicked, this, &RemoveAccount::send_back_slot);
    account.setParent(this);
    account.show();
    account.move(20,22);
    account.resize(160,20);
    account.setPlaceholderText("在此处输入要注销的账号");
}
void RemoveAccount::remove()
{
    QString s1 = account.text();
    string str1 = s1.toStdString();
    int exist = 0;
    string temp1;
    string newstring="";
    ifstream fin(filename, ios::in);
    while(std::getline(fin, temp1))
    {
        if(temp1 == str1)
        {
            std::getline(fin, temp1);
            std::getline(fin, temp1);
            std::getline(fin, temp1);
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
        QMessageBox::about(this, "tip", "注销成功     ") ;
        account.setText("");
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
    }
}
void RemoveAccount::send_back_slot()
{
    emit back_signal();
}
