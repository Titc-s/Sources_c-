#include "mainwindow.h"

#include <QApplication>
#include<QTableWidget>
#include<QTableWidgetItem>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QTableWidget *tablewidget = new QTableWidget (10,5);
    tablewidget->resize(400,300);
    QStringList header;
    header<<"account"<<"password"<<"i";
    tablewidget->setHorizontalHeaderLabels(header);
    tablewidget->show();


    MainWindow w;


    w.show();
    return a.exec();
}
