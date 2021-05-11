#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include<QPushButton>
#include"subwidget.h"
#include<QAbstractButton>

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();
    void Myslot();
    void changeWin();
    void dealsub();
 private:
    QPushButton *b2;
    QPushButton b1;

    Subwidget w;
    QPainter *pic;

};
#endif // WIDGET_H
