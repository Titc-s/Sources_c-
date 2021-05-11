#ifndef MANAGERLOGIN_H
#define MANAGERLOGIN_H

#include <QWidget>
#include <QPushButton>
#include <QLineEdit>
#include <QMessageBox>
class ManagerLogin : public QWidget
{
    Q_OBJECT
public:
    explicit ManagerLogin(QWidget *parent = nullptr);
public:
    void send_back_slot();
    void check();
signals:
    void switch_signal();
    void back_signal();
private:
        QPushButton b1;
        QPushButton b2;
        QLineEdit password;
};
#endif // MANAGERLOGIN_H
