#include "widget.h"
#include"mypushbutton.h"
#include <QPushButton>
#include<QWidget>
#include<QApplication>
#include<QMessageBox>
#include<QDebug>
#include<QLineEdit>
#include<QCompleter>
#include<QAbstractButton>
#include<QLabel>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    QPushButton * btn= new QPushButton;
    //btn ->show(); 以顶层方式弹出窗口控件
    //让btn对象 依赖在mywidget 窗口中。
    btn ->setParent(this);
    btn ->setText("注册账号");
    QPushButton *btn2= new QPushButton("登录系统",this);
    QPushButton *btn3= new QPushButton("管理员选项",this);
    QPushButton *btn4= new QPushButton("退出系统",this);
    // 重置窗口
    resize (400,300);
    // 移动按钮位置
    btn-> move(200,170);
    btn2-> move(200,200);
    btn3-> move(200,230);
    btn4-> move(200,260);
    // 设置窗口标题
    setWindowTitle("管理员系统");
     b2 = new QPushButton("test",this);
     b2-> move(200,280);
  //  QMessageBox::information(NULL,"Title","欢迎来到管理系统",QMessageBox::Yes|QMessageBox::No);
// 创建一个自己的按钮对象
    MyPushButton * myBtn = new MyPushButton;

    myBtn->setText("俺");
    myBtn->move(200,0);
    myBtn-> setParent(this);

      connect(btn,&QPushButton::clicked,this,&Widget::close);


      connect(btn2,&QPushButton::released,this,&Widget::Myslot);
      connect(b2,&QPushButton::released,btn2,&QPushButton::hide);

    b1.setParent(this);
    b1.setMinimumSize(33,33);
    b1.setMaximumSize(33,33);
    b1.move(100,150);

    //显示子窗口;
    //w.show();
    connect(&b1,&QPushButton::released,this,&Widget::changeWin);
    connect(&w,&Subwidget::mySignal,this,&Widget::dealsub);

    QLineEdit *edit=new QLineEdit;
      edit->show();


    edit->setParent(this);
    edit->move(100,100);

    QCompleter completer(QStringList()<<"aab"<<"123"<<"998");
    completer.setFilterMode(Qt::MatchContains);
    edit->setCompleter(&completer);


  //this->setStyleSheet("border-image:url(C:\\Users\\12401\\Desktop\\re\\information\\fxzx.gif)");
  QIcon b1_ico(":/new/food/pic/pork.jpg");
  b1.setIcon(b1_ico);
  b1.setIconSize(QSize(28,28));

  QLabel *tomato = new QLabel("tomato");
  tomato->setParent(this);
  tomato->move(20,20);
  QImage *logo_img=new QImage(":/new/food/pic/potato.jpg");
  QImage *scaled_logo_img = new QImage;
  *scaled_logo_img=logo_img->scaled(150,120,Qt::KeepAspectRatio);
  tomato->setPixmap(QPixmap::fromImage(*scaled_logo_img));

  // 设置背景
/*QWidget *bb = new QWidget(this);
bb->setAutoFillBackground(true);
QPalette palette;
QPixmap pixmap(":/pic/pass word.jpg");
palette.setBrush(QPalette::Window,QBrush(pixmap));
bb->show();
*/
  //设置背景
 this->setAutoFillBackground(true);
QPalette palette = this->palette();
palette.setBrush(QPalette::Window,QBrush(QPixmap(":/pic/pass word.jpg").scaled(this->size(),Qt::IgnoreAspectRatio,Qt::SmoothTransformation)));
this->setPalette(palette);







}
void Widget::Myslot()
{
    b2->setText("123");
}

void Widget::changeWin()
{
    //子窗口显示
    w.show();
    //本窗口隐藏
    this->hide();

}
void Widget::dealsub(){
    w.hide();
    show();

}
Widget::~Widget()
{
    qDebug()<<"Mywidget西沟调用";
}
