TEMPLATE	= lib
CONFIG		= warn_on release staticlib
INCLUDEPATH     += ../libical
INCLUDEPATH     += .
DEFINES += HAVE_CONFIG_H
OBJECTS_DIR = obj/$(PLATFORM)
MOC_DIR = moc
DESTDIR=$(QPEDIR)/lib

INTERFACES = \

HEADERS = \
 config.h \
 icalcalendar.h \
 icalclassify.h \
 icalcstp.h \
 icalcstpclient.h \
 icalcstpserver.h \
 icaldirset.h \
 icaldirsetimpl.h \
 icalfileset.h \
 icalfilesetimpl.h \
 icalgauge.h \
 icalgaugeimpl.h \
 icalmessage.h \
 icalset.h \
 icalspanlist.h \
 icalss.h \
 icalssyacc.h \

SOURCES = \
 icalclassify.c \
 icalcstp.c \
 icalcstpclient.c \
 icalcstpserver.c \
 icaldirset.c \
 icalfileset.c \
 icalgauge.c \
 icalmessage.c \
 icalset.c \
 icalspanlist.c \
 icalsslexer.c \
 icalssyacc.c \

