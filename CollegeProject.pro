QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += src/mainwindow.cpp \
    src/college.cpp \
    src/main.cpp \
    src/souvenirdialog.cpp

HEADERS += src/mainwindow.h \
    src/college.h \
    src/souvenirdialog.h

FORMS += forms/mainwindow.ui \
    src/souvenirdialog.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
