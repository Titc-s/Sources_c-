#include "mypushbutton.h"
#include<QDebug>
MyPushButton::MyPushButton(QWidget *parent) : QPushButton(parent)
{
qDebug()<<"案件牛diao用。";
}
MyPushButton::~MyPushButton()
{
qDebug()<<"析构";
}
