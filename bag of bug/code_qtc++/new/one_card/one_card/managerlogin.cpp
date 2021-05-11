#include "managerlogin.h"

ManagerLogin::ManagerLogin(QWidget *parent) : QWidget(parent)
{
    this->setWindowTitle(QString("管理员登录"));
    this->resize(300,100);
    b1.setParent(this);
    b1.setText(QString("确定"));
    b1.move(200,20);
    connect(&b1, &QPushButton::clicked, this, &ManagerLogin::check);
    b2.setParent(this);
    b2.setText(QString("取消"));
    b2.move(200,50);
    connect(&b2, &QPushButton::clicked, this, &ManagerLogin::send_back_slot);
    password.setEchoMode(QLineEdit::Password);
    password.setParent(this);
    password.show();
    password.move(20,22);
    password.resize(160,20);
    password.setPlaceholderText("在此处输入密码");
}
void ManagerLogin::send_back_slot()
{
    emit back_signal();
    password.setText("");
}
void ManagerLogin::check()
{
    if(password.text() == "123456")
    {
        emit switch_signal();
        password.setText("");
    }
    else
    {
        QMessageBox::about(this, "tip", "密码错误     ");
         password.setText("");
    }
}
