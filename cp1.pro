TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.c

INCLUDEPATH += -I /home/pixy/anaconda3/include/python3.6m

LIBS += -L/home/pixy/anaconda3/lib -lpython3.6m

DISTFILES += \
    pytt.py
