#ifndef MYWIDGET_H
#define MYWIDGET_H

#include <QWidget>
#include <QPushButton>
#include <QString>
#include <QDebug>
#include <QMessageBox>
#include "registerwidget.h"
#include "loginwidget.h"
#include "managerwidget.h"
#include "loginaccount.h"
#include "account.h"
#include "recharge.h"
#include "changepassword.h"
#include "searchinf.h"
#include "managerlogin.h"
#include "showpeople.h"
#include "managerchange.h"
#include "managerchangestatus.h"
#include "removeaccount.h"
class MyWidget : public QWidget
{
    Q_OBJECT
public:
    MyWidget(QWidget *parent = nullptr);

    void switchwidget1();
    void switchwidget2();
    void switchwidget3();
    void switchwidget4();
    void switchwidget5();
    void switchwidget6();
    void switchwidget7();
    void switchwidget8();
    void switchwidget9();
    void switchwidget10();
    void switchwidget11();
    void switchwidget12();
    void switchwidget13();
    void switchwidget14();
    void switchwidget15();
    void switchwidget16();
    void switchwidget17();
    void switchwidget18();
    void switchwidget19();
    void switchwidget20();
    void switchwidget21();
    void switchwidget22();
    void trans_inf();
    ~MyWidget();
private:
    QPushButton b1;
    QPushButton b2;
    QPushButton b3;
    QPushButton b4;
    registerwidget r1;
    LoginWidget l1;
    ManagerWidget m1;
    LoginAccount l2;
    Recharge l3;
    ChangePassword l4;
    ManagerLogin l5;
    ShowPeople s1;
    ManagerChange l6;
    ManagerChangeStatus l7;
    RemoveAccount l8;
};
#endif // MYWIDGET_H
