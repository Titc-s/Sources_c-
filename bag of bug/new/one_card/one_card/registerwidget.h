#ifndef REGISTERWIDGET_H
#define REGISTERWIDGET_H

#include <QWidget>
#include <QPushButton>
#include <QString>
#include <QMessageBox>
#include <QLineEdit>
#include <iostream>
#include <string>
#include <fstream>
#include "account.h"
using namespace std;
#define filename "C:\\study_resource\\class\\c++\\new\\one_card\\one_card\\user_information.txt"
class registerwidget : public QWidget
{
    Q_OBJECT
public:
    explicit registerwidget(QWidget *parent = nullptr);
    void send_back_slot();
    void register_account();
signals:
    void back_signal();
private:
    QPushButton b1;
    QPushButton b2;
    QLineEdit account;
    QLineEdit password;
};
#endif // REGISTERWIDGET_H
