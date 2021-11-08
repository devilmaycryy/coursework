QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    button.cpp \
    cell.cpp \
    developers.cpp \
    exception.cpp \
    field.cpp \
    howplay.cpp \
    human.cpp \
    main.cpp \
    game.cpp \
    monster.cpp \
    nickname.cpp \
    person.cpp

HEADERS += \
    button.h \
    cell.h \
    developers.h \
    exception.h \
    field.h \
    game.h \
    howplay.h \
    human.h \
    monster.h \
    nickname.h \
    person.h

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resource.qrc
