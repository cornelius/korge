TEMPLATE	= lib
CONFIG		= warn_on release staticlib
INCLUDEPATH     += .
OBJECTS_DIR = obj/$(PLATFORM)
MOC_DIR = moc
DESTDIR=$(QPEDIR)/lib

INTERFACES = \

HEADERS = \
 ical.h \
 icalattendee.h \
 icalcomponent.h \
 icalderivedparameter.h \
 icalderivedproperty.h \
 icalderivedvalue.h \
 icalduration.h \
 icalenums.h \
 icalerror.h \
 icallangbind.h \
 icalmemory.h \
 icalmime.h \
 icalparameter.h \
 icalparameterimpl.h \
 icalparser.h \
 icalperiod.h \
 icalproperty.h \
 icalrecur.h \
 icalrestriction.h \
 icaltime.h \
 icaltypes.h \
 icalvalue.h \
 icalvalueimpl.h \
 icalversion.h \
 icalyacc.h \
 pvl.h \
 sspm.h \

SOURCES = \
 icalattendee.c \
 icalcomponent.c \
 icalderivedparameter.c \
 icalderivedproperty.c \
 icalderivedvalue.c \
 icalduration.c \
 icalenums.c \
 icalerror.c \
 icallangbind.c \
 icallexer.c \
 icalmemory.c \
 icalmime.c \
 icalparameter.c \
 icalparser.c \
 icalperiod.c \
 icalproperty.c \
 icalrecur.c \
 icalrestriction.c \
 icaltime.c \
 icaltypes.c \
 icalvalue.c \
 icalyacc.c \
 pvl.c \
 sspm.c \
 vsnprintf.c \

