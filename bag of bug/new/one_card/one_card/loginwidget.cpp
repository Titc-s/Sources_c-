#include "loginwidget.h"

LoginWidget::LoginWidget(QWidget *parent) : QWidget(parent)
{
    this->setWindowTitle(QString("信息"));
    this->resize(400, 660);
    b1.setParent(this);
    b1.setText(QString("查询余额"));
    b1.move(100, 60);
    b1.resize(200, 60);
    connect(&b1, &QPushButton::clicked, this, &LoginWidget::show_account_balance);
    b2.setParent(this);
    b2.setText(QString("充值"));
    b2.move(100, 180);
    b2.resize(200, 60);
    connect(&b2, &QPushButton::clicked, this, &LoginWidget::send_recharge_slot);
    b3.setParent(this);
    b3.setText(QString("修改密码"));
    b3.move(100, 300);
    b3.resize(200, 60);
    connect(&b3, &QPushButton::clicked, this, &LoginWidget::send_password_slot);
    b4.setParent(this);
    b4.setText(QString("挂失"));
    b4.move(100, 420);
    b4.resize(200, 60);
    connect(&b4, &QPushButton::clicked, this, &LoginWidget::report_loss);
    b5.setParent(this);
    b5.setText(QString("返回"));
    b5.move(100, 540);
    b5.resize(200, 60);
    connect(&b5, &QPushButton::clicked, this, &LoginWidget::send_back_slot);
}
void LoginWidget::send_back_slot()
{
    emit back_signal();
}
void LoginWidget::send_recharge_slot()
{
    emit recharge_signal();
}
void LoginWidget::send_password_slot()
{
    emit password_signal();
}
void LoginWidget::change_inf(string s, int e)
{
    present_account = s;
    status = e;
}
void LoginWidget::show_account_balance()
{
    string temp1;
    ifstream fin(filename, ios::in);
    while(std::getline(fin, temp1))
    {
        if(temp1 == present_account && status == 1)
        {
            std::getline(fin, temp1);
            std::getline(fin, temp1);
            QString qstr = QString::fromStdString(temp1);
            QMessageBox::about(this, "当前账户余额为      ", qstr);
            std::getline(fin, temp1);
        }
        else if(temp1 == present_account && status == 0)
        {
            QMessageBox::about(this, "提示", "卡已挂失，无法查看余额，请联系管理员");
        }
        else continue;
    }
    fin.close();
}
void LoginWidget::report_loss()
{
    string s1 = "0";
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
            newstring += temp1;
            newstring += '\n';
            std::getline(fin, temp1);
            newstring += temp1;
            newstring += '\n';
            std::getline(fin, temp1);
            newstring += s1;
            newstring += '\n';
        }
        else
        {
            newstring += temp1;
            newstring += '\n';
        }
    }
    QMessageBox::about(this, "tip", "挂失成功     ");
    fin.close();
    ofstream fout(filename, ios::app);
    ofstream file_writer(filename, ios_base::out);
    fout<<newstring;
    fout.close();
    status = 0;
}
