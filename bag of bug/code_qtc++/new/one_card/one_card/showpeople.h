#ifndef SHOWPEOPLE_H
#define SHOWPEOPLE_H

#include <QWidget>
#include <QTableWidget>
#include <QTableWidgetItem>
#include <QPushButton>
#include <QString>
#include <iostream>
#include <string>
#include <fstream>
#include "account.h"
using namespace std;
#define filename "D:\\bag of bug\\code_qtc++\\new\\one_card\\one_card\\user_information.txt"
class ShowPeople : public QWidget
{
    Q_OBJECT
public:
    explicit ShowPeople(QWidget *parent = nullptr);
    void send_back_signal();
    void showpeople();
signals:
    void back_signal();
private:
    QTableWidget t1;
    QPushButton b1;
    QPushButton b2;
};
#endif // SHOWPEOPLE_H
