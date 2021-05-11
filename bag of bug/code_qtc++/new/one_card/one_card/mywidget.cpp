#include "mywidget.h"

MyWidget::MyWidget(QWidget *parent)
    : QWidget(parent)
{
    QMessageBox::about(this, "tip", "欢迎使用一卡通系统    ");
    this->setWindowTitle(QString("一卡通系统"));
    this->resize(400, 540);
    b1.setParent(this);
    b1.setText(QString("注册账号"));
    b1.move(100, 60);
    b1.resize(200, 60);
    connect(&b1, &QPushButton::released, this, &MyWidget::switchwidget1);
    b2.setParent(this);
    b2.setText(QString("登录账号"));
    b2.move(100, 180);
    b2.resize(200, 60);
    connect(&b2, &QPushButton::released, this, &MyWidget::switchwidget3);
    b3.setParent(this);
    b3.setText(QString("管理员系统"));
    b3.move(100, 300);
    b3.resize(200, 60);
    connect(&b3, &QPushButton::released, this, &MyWidget::switchwidget5);
    b4.setParent(this);
    b4.setText(QString("退出系统"));
    b4.move(100, 420);
    b4.resize(200, 60);
    connect(&b4, &QPushButton::released, this, &MyWidget::close);
    connect(&r1, &registerwidget::back_signal, this, &MyWidget::switchwidget2);
    connect(&l1, &LoginWidget::back_signal, this, &MyWidget::switchwidget4);
    connect(&l1, &LoginWidget::recharge_signal, this, &MyWidget::switchwidget10);
    connect(&l1, &LoginWidget::password_signal, this, &MyWidget::switchwidget11);
    connect(&m1, &ManagerWidget::back_signal, this, &MyWidget::switchwidget6);
    connect(&m1, &ManagerWidget::showpeople_signal, this, &MyWidget::switchwidget15);
    connect(&m1, &ManagerWidget::managerchange_signal, this, &MyWidget::switchwidget17);
    connect(&m1, &ManagerWidget::managerchangestatus_signal, this, &MyWidget::switchwidget19);
    connect(&m1, &ManagerWidget::removeaccount_signal, this, &MyWidget::switchwidget21);
    connect(&s1, &ShowPeople::back_signal, this, &MyWidget::switchwidget16);
    connect(&l2, &LoginAccount::back_signal, this, &MyWidget::switchwidget7);
    connect(&l2, &LoginAccount::switch_signal, this, &MyWidget::switchwidget8);
    connect(&l2, &LoginAccount::trans_signal, this, &MyWidget::trans_inf);
    connect(&l3, &Recharge::back_signal, this, &MyWidget::switchwidget9);
    connect(&l4, &ChangePassword::back_signal, this, &MyWidget::switchwidget12);
    connect(&l5, &ManagerLogin::switch_signal, this, &MyWidget::switchwidget13);
    connect(&l5, &ManagerLogin::back_signal, this, &MyWidget::switchwidget14);
    connect(&l6, &ManagerChange::back_signal, this, &MyWidget::switchwidget18);
    connect(&l7, &ManagerChangeStatus::back_signal, this, &MyWidget::switchwidget20);
    connect(&l8, &RemoveAccount::back_signal, this, &MyWidget::switchwidget22);
}
void MyWidget::switchwidget1()
{
    this->hide();
    r1.show();
    QMessageBox::about(this, "tip", "请输入账号和密码以完成注册    \n "
                                    "（账号由数字和字母组成，密码由数字和大小写字母组成）");
}
void MyWidget::switchwidget2()
{
    r1.hide();
    this->show();
}
void MyWidget::switchwidget3()
{
    this->hide();
    l2.show();
}
void MyWidget::switchwidget4()
{
    l1.hide();
    this->show();
}
void MyWidget::switchwidget5()
{
    this->hide();
    l5.show();
}
void MyWidget::switchwidget6()
{
    m1.hide();
    this->show();
}
void MyWidget::switchwidget7()
{
    l2.hide();
    this->show();
}
void MyWidget::switchwidget8()
{
    l2.hide();
    l1.show();
}
void MyWidget::switchwidget9()
{
    l3.hide();
    l1.show();
}
void MyWidget::switchwidget10()
{
    l1.hide();
    l3.show();
}
void MyWidget::switchwidget11()
{
    l1.hide();
    l4.show();
}
void MyWidget::switchwidget12()
{
    l1.show();
    l4.hide();
}
void MyWidget::switchwidget13()
{
    l5.hide();
    m1.show();
}
void MyWidget::switchwidget14()
{
    l5.hide();
    this->show();
}
void MyWidget::switchwidget15()
{
//    m1.hide();
    s1.show();
}
void MyWidget::switchwidget16()
{
    s1.hide();
    m1.show();
}
void MyWidget::switchwidget17()
{
    m1.hide();
    l6.show();
}
void MyWidget::switchwidget18()
{
    l6.hide();
    m1.show();
}
void MyWidget::switchwidget19()
{
    m1.hide();
    l7.show();
}
void MyWidget::switchwidget20()
{
    l7.hide();
    m1.show();
}
void MyWidget::switchwidget21()
{
    m1.hide();
    l8.show();
}
void MyWidget::switchwidget22()
{
    l8.hide();
    m1.show();
}
void MyWidget::trans_inf()
{
    l1.change_inf(l2.new_temp1, l2.new_temp);
    l3.change_inf(l2.new_temp1);
    l4.change_inf(l2.new_temp1);
}
MyWidget::~MyWidget()
{
}
