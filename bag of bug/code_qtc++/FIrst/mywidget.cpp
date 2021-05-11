#include "mywidget.h"
#include<QPushButton> // 按钮控件头文件
#include "mypushbutton.h"
myWidget::myWidget(QWidget *parent)
    : QWidget(parent)
{
    QPushButton *btn = new QPushButton;
    btn->show(); // show 以顶层方式弹出窗口控件
    // 让btn 对象 在窗口中
    btn -> setParent(this);
    btn->move(288,299);
    // 显示文本
     btn -> setText("注册账号");


    // 第二个按钮    按照控件的大小创建窗口
    QPushButton *btn2 = new QPushButton("登录账号",this);


    //移动btn2
    btn2-> move(100,100);


    // 重置窗口大小
    resize (600,400);

    // 设置窗口标题
    setWindowTitle("The first Window");

    // 设置固定窗口大小
    setFixedSize(600,500);
    
    
    
    // 创建自己按钮对象
    
}

myWidget::~myWidget()
{
}

