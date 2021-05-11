#ifndef MANAGERCHANGESTATUS_H
#define MANAGERCHANGESTATUS_H

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
class ManagerChangeStatus : public QWidget
{
    Q_OBJECT
public:
    explicit ManagerChangeStatus(QWidget *parent = nullptr);
    void send_back_slot();
    void change_password();
signals:
    void back_signal();
private:
    QPushButton b1;
    QPushButton b2;
    QLineEdit account;
    QLineEdit password;
};
#endif // MANAGERCHANGESTATUS_H
