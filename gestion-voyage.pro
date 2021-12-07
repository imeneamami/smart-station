QT       += core gui
QT       +=sql
QT       += core gui
QT       += core gui sql charts
QT       += core gui  serialport
QT       += core gui printsupport
QT       +=multimedia
QT       +=charts
QT       +=serialport
QT       += network
QT       += printsupport
QT       += core gui sql network
Qt+=serialPort


//QT += serialport


greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    arduino.cpp \
    connexion.cpp \
    employee.cpp \
    mailing.cpp \
    main.cpp \
    menu_voyege.cpp \
    metro.cpp \
    qcustomplot.cpp \
    signup.cpp \
    smtp.cpp \
    voyage.cpp

HEADERS += \
    arduino.h \
    connexion.h \
    employee.h \
    mailing.h \
    menu_voyege.h \
    metro.h \
    qcustomplot.h \
    signup.h \
    smtp.h \
    voyage.h

FORMS += \
    menu_voyege.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
