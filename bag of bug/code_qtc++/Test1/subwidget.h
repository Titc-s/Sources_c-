#ifndef SUBWIDGET_H
#define SUBWIDGET_H

#include <QWidget>
#include<QPushButton>
#include<QLineEdit>
#include<QLabel>


class Subwidget : public QWidget
{
    Q_OBJECT
public:
    explicit Subwidget(QWidget *parent = nullptr);

    void sendSlot();

signals:
    // 信号必须有signals 来声明 且没有返回值 ，但 可以有参数  信号就是函数的声明  只需声明无需定义
    // 使用 ：：emit mySignal;
    void mySignal();

private:
    QPushButton b4;
    QPushButton tomato;
    QPushButton potato;
    QPushButton pork;
    QPushButton vegetable;
};

#endif // SUBWIDGET_H
