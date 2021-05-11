 #include "mypushbutton.h"
#include <QDebug>

MypushButton::MypushButton(QWidget *parent) : QPushButton(parent)
{
     qDebug()<<"我的按钮类构造调用";
}

MypushButton::MypushButton(){
    
    qDebug()<<"析构";
    
    
}
