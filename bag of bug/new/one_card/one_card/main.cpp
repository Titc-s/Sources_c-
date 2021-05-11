#include "mywidget.h"

#include <QApplication>
int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    string present_account;
    string present_password;
    MyWidget w;
    w.show();
    return app.exec();
}
