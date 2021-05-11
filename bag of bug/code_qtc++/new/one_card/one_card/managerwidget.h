#ifndef MANAGERWIDGET_H
#define MANAGERWIDGET_H

#include <QWidget>
#include <QPushButton>
#include <QString>
#include <QMessageBox>
#include <iostream>
#include <string>
#include <fstream>
#include "account.h"
using namespace std;
#define filename "D:\\bag of bug\\code_qtc++\\new\\one_card\\one_card\\user_information.txt"
class ManagerWidget : public QWidget
{
    Q_OBJECT
public:
    explicit ManagerWidget(QWidget *parent = nullptr);

    void send_back_slot();
    void send_showpeople_signal();
    void send_managerchange_signal();
    void send_managerchangestatus_signal();
    void send_removeaccount_signal();
signals:
    void back_signal();
    void showpeople_signal();
    void managerchange_signal();
    void managerchangestatus_signal();
    void removeaccount_signal();
private:
    QPushButton b1;
    QPushButton b2;
    QPushButton b3;
    QPushButton b4;
    QPushButton b5;
};
#endif // MANAGERWIDGET_H
