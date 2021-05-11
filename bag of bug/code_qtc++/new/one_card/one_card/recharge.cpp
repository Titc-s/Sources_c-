#include "recharge.h"

Recharge::Recharge(QWidget *parent) : QWidget(parent)
{
    this->setWindowTitle(QString("充值"));
    this->resize(300,100);

    b1.setParent(this);
    b1.setText(QString("确定"));
    b1.move(200,20);
    connect(&b1, &QPushButton::clicked, this, &Recharge::change_balance);

    b2.setParent(this);
    b2.setText(QString("取消"));
    b2.move(200,50);
    connect(&b2, &QPushButton::clicked, this, &Recharge::send_back_slot);

    money.setParent(this);
    money.show();
    money.move(20,22);
    money.resize(160,20);
    money.setPlaceholderText("在此处输入金额");
}
void Recharge::change_inf(string s)
{
    present_account = s;
}
void Recharge::change_balance()
{
    QString s1 = money.text();
    string str1 = s1.toStdString();
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
            int temp_int1;
            int temp_int2;
            temp_int2 = stoi(temp1);
            temp_int1 = temp_int2 + stoi(str1);
            temp1 = to_string(temp_int1);
            newstring += temp1;
            newstring += '\n';
        }
        else
        {
            newstring += temp1;
            newstring += '\n';
        }
    }
    QMessageBox::about(this, "tip", "充值成功     ") ;
    money.setText("");
    fin.close();
    ofstream fout(filename, ios::app);
    ofstream file_writer(filename, ios_base::out);
    fout<<newstring;
    fout.close();
    send_back_slot();
}
void Recharge::send_back_slot()
{
    emit back_signal();
    money.setText("");
}
