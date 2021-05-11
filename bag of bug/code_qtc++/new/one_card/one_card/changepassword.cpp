#include "changepassword.h"

ChangePassword::ChangePassword(QWidget *parent) : QWidget(parent)
{
    this->setWindowTitle(QString("修改密码"));
    this->resize(300,100);
    b1.setParent(this);
    b1.setText(QString("确定"));
    b1.move(200,20);
    connect(&b1, &QPushButton::clicked, this, &ChangePassword::change_password);
    b2.setParent(this);
    b2.setText(QString("取消"));
    b2.move(200,50);
    connect(&b2, &QPushButton::clicked, this, &ChangePassword::send_back_slot);
    password.setParent(this);
    password.show();
    password.move(20,22);
    password.resize(160,20);
    password.setPlaceholderText("在此处输入密码");
}
void ChangePassword::change_inf(string s)
{
    present_account = s;
}
void ChangePassword::change_password()
{
    QString s1 = password.text();
    string str1 = s1.toStdString();
    if(s1 == "")
    {
        QMessageBox::about(this, "tip", "密码不能为空     ");
    }
    else
    {
        string temp1;
        string newstring="";
        ifstream fin(filename, ios::in);
        while(std::getline(fin, temp1))
        {
            if(temp1 == present_account)
                {
                    newstring += temp1;
                    newstring += '\n';
                    std::getline(fin, temp1);
                    newstring += str1;
                    newstring += '\n';
                }
                else
                {
                    newstring += temp1;
                    newstring += '\n';
                }
        }
        QMessageBox::about(this, "tip", "修改成功     ") ;
        password.setText("");
        fin.close();
        ofstream fout(filename, ios::app);
        ofstream file_writer(filename, ios_base::out);
        fout<<newstring;
        fout.close();
        send_back_slot();
    }
}
void ChangePassword::send_back_slot()
{
    emit back_signal();
    password.setText("");
}
