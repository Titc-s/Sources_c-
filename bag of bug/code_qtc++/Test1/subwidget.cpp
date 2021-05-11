#include "subwidget.h"
#include<QLabel>
#include<QWidget>
#include<QDateTime>
Subwidget::Subwidget(QWidget *parent) : QWidget(parent)
{
    resize(800,600);
this ->setWindowTitle("子窗口");
    b4.setParent(this);
    b4.setText("切换主窗口");

   QIcon tomato_ico(":/pic/tomato.jpg");
   tomato.setParent(this);
   tomato.setMinimumSize(200,160);
   tomato.setMaximumSize(200,160);
   tomato.move(10,5);
   tomato.setIcon(tomato_ico);
   tomato.setIconSize(QSize(200,160));
   tomato.setFlat(true);

   QIcon potato_ico(":/pic/potato.jpg");
   potato.setParent(this);
   potato.setMinimumSize(200,160);
   potato.setMaximumSize(200,160);
   potato.move(240,5);
   potato.setIcon(potato_ico);
   potato.setIconSize(QSize(200,160));
   potato.setFlat(true);


   QIcon pork_ico(":/pic/pork.jpg");
   pork.setParent(this);
   pork.setMinimumSize(200,160);
   pork.setMaximumSize(200,160);
   pork.move(470,5);
   pork.setIcon(pork_ico);
   pork.setIconSize(QSize(200,160));
   pork.setFlat(true);



   QIcon vege_ico(":/pic/vegetables.jpg");
   vegetable.setParent(this);
   vegetable.setMinimumSize(200,160);
   vegetable.setMaximumSize(200,160);
   vegetable.move(10,190);
   vegetable.setIcon(vege_ico);
   vegetable.setIconSize(QSize(200,160));
   vegetable.setFlat(true);

   QIcon chip_ico(":/pic/pork.jpg");
   pork.setParent(this);
   pork.setMinimumSize(200,160);
   pork.setMaximumSize(200,160);
   pork.move(470,5);
   pork.setIcon(pork_ico);
   pork.setIconSize(QSize(200,160));
   pork.setFlat(true);


QDateTime current_time = QDateTime::currentDateTime();
QString current_data = current_time.toString("yyyy.MM.dd.hh:ss ddd");
QLineEdit *time = new QLineEdit;

time->move(500,500);
time->setText(current_data);
time->setParent(this);







    connect(&b4,&QPushButton::clicked,this,&Subwidget::sendSlot);

}
void Subwidget::sendSlot()
{
    emit mySignal();
}
