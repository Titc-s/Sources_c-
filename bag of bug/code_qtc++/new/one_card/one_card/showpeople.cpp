#include "showpeople.h"

ShowPeople::ShowPeople(QWidget *parent) : QWidget(parent)
{
    this->setWindowTitle("人员信息");
    this->resize(350,385);
    t1.setParent(this);
    t1.resize(350,350);
    t1.setColumnCount(3);
    t1.setRowCount(50);
    QStringList header;
    header<<"账号"<<"密码"<<"状态";
    t1.setHorizontalHeaderLabels(header);
    b1.setParent(this);
    b1.move(275,355);
    b1.resize(65,25);
    b1.setText("返回");
    b2.setParent(this);
    b2.move(200,355);
    b2.resize(65,25);
    b2.setText("刷新");
    connect(&b1, &QPushButton::clicked, this, &ShowPeople::send_back_signal);
    connect(&b2, &QPushButton::clicked, this, &ShowPeople::showpeople);
    string temp1;
    string temp2;
    string temp3;
    ifstream fin1(filename, ios::in);
    int i = 0;
    while(std::getline(fin1, temp1))
    {
        std::getline(fin1, temp2);
        std::getline(fin1, temp3);
        std::getline(fin1, temp3);
        QString s1;
        QString s2;
        QString s3;
        s1 = QString::fromStdString(temp1);
        s2 = QString::fromStdString(temp2);
        s3 = QString::fromStdString(temp3);
        t1.setItem(i, 0, new QTableWidgetItem(s1));
        t1.setItem(i, 1, new QTableWidgetItem(s2));
        t1.setItem(i, 2, new QTableWidgetItem(s3));
        i++;
    }
    while(i != 49)
    {
        t1.setItem(i, 0, new QTableWidgetItem(""));
        t1.setItem(i, 1, new QTableWidgetItem(""));
        t1.setItem(i, 2, new QTableWidgetItem(""));
        i++;
    }
}
void ShowPeople::send_back_signal()
{
    emit back_signal();
}
void ShowPeople::showpeople()
{
    string temp1;
    string temp2;
    string temp3;
    ifstream fin1(filename, ios::in);
    int i = 0;
    while(std::getline(fin1, temp1))
    {
        std::getline(fin1, temp2);
        std::getline(fin1, temp3);
        std::getline(fin1, temp3);
        QString s1;
        QString s2;
        QString s3;
        s1 = QString::fromStdString(temp1);
        s2 = QString::fromStdString(temp2);
        s3 = QString::fromStdString(temp3);
        t1.setItem(i, 0, new QTableWidgetItem(s1));
        t1.setItem(i, 1, new QTableWidgetItem(s2));
        t1.setItem(i, 2, new QTableWidgetItem(s3));
        i++;
    }
    while(i != 49)
    {
        t1.setItem(i, 0, new QTableWidgetItem(""));
        t1.setItem(i, 1, new QTableWidgetItem(""));
        t1.setItem(i, 2, new QTableWidgetItem(""));
        i++;
    }
}
