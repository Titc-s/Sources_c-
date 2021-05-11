#include "managerwidget.h"

ManagerWidget::ManagerWidget(QWidget *parent) : QWidget(parent)
{
    this->setWindowTitle(QString("当前为管理员模式"));
    this->resize(400, 660);
    b1.setParent(this);
    b1.setText(QString("查找所有账号信息"));
    b1.move(100, 60);
    b1.resize(200, 60);
    connect(&b1, &QPushButton::clicked, this, &ManagerWidget::send_showpeople_signal);
    b2.setParent(this);
    b2.setText(QString("修改用户账号密码"));
    b2.move(100, 180);
    b2.resize(200, 60);
    connect(&b2, &QPushButton::clicked, this, &ManagerWidget::send_managerchange_signal);
    b3.setParent(this);
    b3.setText(QString("挂失/解挂"));
    b3.move(100, 300);
    b3.resize(200, 60);
    connect(&b3, &QPushButton::clicked, this, &ManagerWidget::send_managerchangestatus_signal);
    b3.setParent(this);
    b4.setParent(this);
    b4.setText(QString("注销用户"));
    b4.move(100, 420);
    b4.resize(200, 60);
    connect(&b4, &QPushButton::clicked, this, &ManagerWidget::send_removeaccount_signal);
    b5.setParent(this);
    b5.setText(QString("返回"));
    b5.move(100, 540);
    b5.resize(200, 60);
    connect(&b5, &QPushButton::clicked, this, &ManagerWidget::send_back_slot);
}
void ManagerWidget::send_back_slot()
{
    emit back_signal();
}
void ManagerWidget::send_showpeople_signal()
{
    emit showpeople_signal();
}
void ManagerWidget::send_managerchange_signal()
{
    emit managerchange_signal();
}
void ManagerWidget::send_managerchangestatus_signal()
{
    emit managerchangestatus_signal();
}
void ManagerWidget::send_removeaccount_signal()
{
    emit removeaccount_signal();
}
