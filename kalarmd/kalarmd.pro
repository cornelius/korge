TEMPLATE	= lib
CONFIG		= qt warn_on release
TARGET		= simplealarmdaemon
OBJECTS_DIR = obj/$(PLATFORM)
MOC_DIR = moc
INCLUDEPATH += ../microkde ../qtcompat ../
LIBS += -lkdepim
LIBS += -lkcal
LIBS += -lmicrokde
LIBS += -lqtcompat
LIBS += -lqpe
DEFINES +=
DESTDIR = $(QPEDIR)/plugins/applets

INTERFACES = \

HEADERS = \
 alarmdialog.h \
 koeventviewer.h \
 simplealarmdaemon.h \
 simplealarmdaemonapplet.h \
 simplealarmdaemonimpl.h

SOURCES = \
 alarmdialog.cpp \
 koeventviewer.cpp \
 simplealarmdaemon.cpp \
 simplealarmdaemonapplet.cpp \
 simplealarmdaemonimpl.cpp

