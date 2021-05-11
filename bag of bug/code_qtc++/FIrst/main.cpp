#include "mywidget.h"

#include <QApplication>

// 快捷键
//注释 CTRL+/
//运行 ctrl+R
//编译 ctrl+b
//查找 ctrl+ f
//整行移动 ctrl+ shift +↑↓
//帮助文档 F1
//自动对齐 ctrl+ i
//同名之间.h 和 .cpp 切换 F4



int main(int argc, char *argv[])
{
    // 应用程序对象，在qt中 应用程序对象有且只有一个
    QApplication a(argc, argv);
    // 窗口对象 MyWidget 父类 - >  QWidget
    myWidget w;
    //  窗口对象， 默认不会显示，必须要调用sgiw方法显示窗口
    w.show();
    return a.exec();
}
