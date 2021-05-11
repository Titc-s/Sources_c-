QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    changepassword.cpp \
    loginaccount.cpp \
    loginwidget.cpp \
    main.cpp \
    managerchange.cpp \
    managerchangestatus.cpp \
    managerlogin.cpp \
    managerwidget.cpp \
    mywidget.cpp \
    recharge.cpp \
    registerwidget.cpp \
    removeaccount.cpp \
    showpeople.cpp

HEADERS += \
    changepassword.h \
    loginaccount.h \
    loginwidget.h \
    managerchange.h \
    managerchangestatus.h \
    managerlogin.h \
    managerwidget.h \
    mywidget.h \
    recharge.h \
    registerwidget.h \
    removeaccount.h \
    showpeople.h

TRANSLATIONS += \
    one_card_zh_CN.ts

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    pic/balance.jpg \
    pic/bill.jpg \
    pic/card.jpg \
    pic/chips.jpg \
    pic/cola.jpg \
    pic/inf.jpg \
    pic/potato.jpg \
    pic/report the lose.jpg \
    pic/tomato.jpg \
    pic/vegetables.jpg
