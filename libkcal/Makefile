#############################################################################
# Makefile for building libkcal.so.1.0.0
# Generated by tmake at 22:46, 2003/04/06
#     Project: kcal
#    Template: lib
#############################################################################

####### Compiler, tools and options

CC	=	gcc
CXX	=	g++
CFLAGS	=	-pipe -Wall -W -O2 -fPIC -DNO_DEBUG
CXXFLAGS=	-pipe -DQWS -fno-exceptions -fno-rtti -Wall -W -O2 -fPIC -DNO_DEBUG
INCPATH	=	-I../microkde -I../qtcompat -Iversit -I../libical/src/libical -I../libical/src/libicalss -I$(QTDIR)/include
LINK	=	g++
LFLAGS	=	-shared -Wl,-soname,libkcal.so.1
LIBS	=	$(SUBLIBS) -L$(QTDIR)/lib -lical -licalss -lqte
AR	=	ar cqs
RANLIB	=	
MOC	=	$(QTDIR)/bin/moc
UIC	=	$(QTDIR)/bin/uic

TAR	=	tar -cf
GZIP	=	gzip -9f

####### Files

HEADERS =	alarm.h \
		attachment.h \
		attendee.h \
		calendar.h \
		calendarlocal.h \
		calfilter.h \
		calformat.h \
		calstorage.h \
		compat.h \
		customproperties.h \
		dummyscheduler.h \
		duration.h \
		event.h \
		exceptions.h \
		filestorage.h \
		freebusy.h \
		icaldrag.h \
		icalformat.h \
		icalformatimpl.h \
		imipscheduler.h \
		incidence.h \
		incidencebase.h \
		journal.h \
		period.h \
		person.h \
		qtopiaformat.h \
		recurrence.h \
		scheduler.h \
		todo.h \
		vcaldrag.h \
		vcalformat.h \
		versit/port.h \
		versit/vcc.h \
		versit/vobject.h
SOURCES =	alarm.cpp \
		attachment.cpp \
		attendee.cpp \
		calendar.cpp \
		calendarlocal.cpp \
		calfilter.cpp \
		calformat.cpp \
		compat.cpp \
		customproperties.cpp \
		dummyscheduler.cpp \
		duration.cpp \
		event.cpp \
		exceptions.cpp \
		filestorage.cpp \
		freebusy.cpp \
		icaldrag.cpp \
		icalformat.cpp \
		icalformatimpl.cpp \
		imipscheduler.cpp \
		incidence.cpp \
		incidencebase.cpp \
		journal.cpp \
		period.cpp \
		person.cpp \
		qtopiaformat.cpp \
		recurrence.cpp \
		scheduler.cpp \
		todo.cpp \
		vcaldrag.cpp \
		vcalformat.cpp \
		versit/vcc.c \
		versit/vobject.c
OBJECTS =	obj/$(PLATFORM)/alarm.o \
		obj/$(PLATFORM)/attachment.o \
		obj/$(PLATFORM)/attendee.o \
		obj/$(PLATFORM)/calendar.o \
		obj/$(PLATFORM)/calendarlocal.o \
		obj/$(PLATFORM)/calfilter.o \
		obj/$(PLATFORM)/calformat.o \
		obj/$(PLATFORM)/compat.o \
		obj/$(PLATFORM)/customproperties.o \
		obj/$(PLATFORM)/dummyscheduler.o \
		obj/$(PLATFORM)/duration.o \
		obj/$(PLATFORM)/event.o \
		obj/$(PLATFORM)/exceptions.o \
		obj/$(PLATFORM)/filestorage.o \
		obj/$(PLATFORM)/freebusy.o \
		obj/$(PLATFORM)/icaldrag.o \
		obj/$(PLATFORM)/icalformat.o \
		obj/$(PLATFORM)/icalformatimpl.o \
		obj/$(PLATFORM)/imipscheduler.o \
		obj/$(PLATFORM)/incidence.o \
		obj/$(PLATFORM)/incidencebase.o \
		obj/$(PLATFORM)/journal.o \
		obj/$(PLATFORM)/period.o \
		obj/$(PLATFORM)/person.o \
		obj/$(PLATFORM)/qtopiaformat.o \
		obj/$(PLATFORM)/recurrence.o \
		obj/$(PLATFORM)/scheduler.o \
		obj/$(PLATFORM)/todo.o \
		obj/$(PLATFORM)/vcaldrag.o \
		obj/$(PLATFORM)/vcalformat.o \
		obj/$(PLATFORM)/vcc.o \
		obj/$(PLATFORM)/vobject.o
INTERFACES =	
UICDECLS =	
UICIMPLS =	
SRCMOC	=	moc/moc_calendar.cpp
OBJMOC	=	obj/$(PLATFORM)/moc_calendar.o
DIST	=	
TARGET	=	libkcal.so.1.0.0
TARGETA	=	$(QPEDIR)/lib/libkcal.a
TARGETD	=	libkcal.so.1.0.0
TARGET0	=	libkcal.so
TARGET1	=	libkcal.so.1
TARGET2	=	libkcal.so.1.0
INTERFACE_DECL_PATH = .

####### Implicit rules

.SUFFIXES: .cpp .cxx .cc .C .c

.cpp.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o $@ $<

.cxx.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o $@ $<

.cc.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o $@ $<

.C.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o $@ $<

.c.o:
	$(CC) -c $(CFLAGS) $(INCPATH) -o $@ $<

####### Build rules


all: $(QPEDIR)/lib/libkcal.so.1.0.0

$(QPEDIR)/lib/libkcal.so.1.0.0: $(OBJECTS) $(OBJMOC) $(SUBLIBS) 
	-rm -f $(TARGET) $(TARGET0) $(TARGET1) $(TARGET2)
	$(LINK) $(LFLAGS) -o $(TARGETD) $(OBJECTS) $(OBJMOC) $(LIBS)
	-ln -s $(TARGET) $(TARGET0)
	-ln -s $(TARGET) $(TARGET1)
	-ln -s $(TARGET) $(TARGET2)
	-rm -f $(QPEDIR)/lib/$(TARGET)
	-rm -f $(QPEDIR)/lib/$(TARGET0)
	-rm -f $(QPEDIR)/lib/$(TARGET1)
	-rm -f $(QPEDIR)/lib/$(TARGET2)
	-mv $(TARGET) $(TARGET0) $(TARGET1) $(TARGET2) $(QPEDIR)/lib/

staticlib: $(TARGETA)

$(TARGETA): $(UICDECLS) $(OBJECTS) $(OBJMOC) 
	-rm -f $(TARGETA)
	$(AR) $(TARGETA) $(OBJECTS) $(OBJMOC)

moc: $(SRCMOC)

tmake: Makefile

Makefile: kcal.pro
	tmake kcal.pro -o Makefile

dist:
	$(TAR) kcal.tar kcal.pro $(SOURCES) $(HEADERS) $(INTERFACES) $(DIST)
	$(GZIP) kcal.tar

clean:
	-rm -f $(OBJECTS) $(OBJMOC) $(SRCMOC) $(UICIMPLS) $(UICDECLS) $(TARGET)
	-rm -f $(TARGET0) $(TARGET1) $(TARGET2) $(TARGETA)
	-rm -f *~ core

####### Sub-libraries


###### Combined headers


####### Compile

obj/$(PLATFORM)/alarm.o: alarm.cpp \
		incidence.h \
		recurrence.h \
		alarm.h \
		customproperties.h \
		duration.h \
		person.h \
		attachment.h \
		incidencebase.h \
		attendee.h \
		todo.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o obj/$(PLATFORM)/alarm.o alarm.cpp

obj/$(PLATFORM)/attachment.o: attachment.cpp \
		attachment.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o obj/$(PLATFORM)/attachment.o attachment.cpp

obj/$(PLATFORM)/attendee.o: attendee.cpp \
		attendee.h \
		person.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o obj/$(PLATFORM)/attendee.o attendee.cpp

obj/$(PLATFORM)/calendar.o: calendar.cpp \
		exceptions.h \
		calfilter.h \
		event.h \
		incidence.h \
		recurrence.h \
		alarm.h \
		customproperties.h \
		duration.h \
		person.h \
		attachment.h \
		incidencebase.h \
		attendee.h \
		todo.h \
		calendar.h \
		journal.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o obj/$(PLATFORM)/calendar.o calendar.cpp

obj/$(PLATFORM)/calendarlocal.o: calendarlocal.cpp \
		vcaldrag.h \
		vcalformat.h \
		calformat.h \
		exceptions.h \
		event.h \
		incidence.h \
		recurrence.h \
		alarm.h \
		customproperties.h \
		duration.h \
		person.h \
		attachment.h \
		incidencebase.h \
		attendee.h \
		icalformat.h \
		scheduler.h \
		journal.h \
		filestorage.h \
		calstorage.h \
		calendarlocal.h \
		calendar.h \
		todo.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o obj/$(PLATFORM)/calendarlocal.o calendarlocal.cpp

obj/$(PLATFORM)/calfilter.o: calfilter.cpp \
		calfilter.h \
		event.h \
		incidence.h \
		recurrence.h \
		alarm.h \
		customproperties.h \
		duration.h \
		person.h \
		attachment.h \
		incidencebase.h \
		attendee.h \
		todo.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o obj/$(PLATFORM)/calfilter.o calfilter.cpp

obj/$(PLATFORM)/calformat.o: calformat.cpp \
		calformat.h \
		exceptions.h \
		event.h \
		incidence.h \
		recurrence.h \
		alarm.h \
		customproperties.h \
		duration.h \
		person.h \
		attachment.h \
		incidencebase.h \
		attendee.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o obj/$(PLATFORM)/calformat.o calformat.cpp

obj/$(PLATFORM)/compat.o: compat.cpp \
		compat.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o obj/$(PLATFORM)/compat.o compat.cpp

obj/$(PLATFORM)/customproperties.o: customproperties.cpp \
		customproperties.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o obj/$(PLATFORM)/customproperties.o customproperties.cpp

obj/$(PLATFORM)/dummyscheduler.o: dummyscheduler.cpp \
		event.h \
		incidence.h \
		recurrence.h \
		alarm.h \
		customproperties.h \
		duration.h \
		person.h \
		attachment.h \
		incidencebase.h \
		attendee.h \
		icalformat.h \
		scheduler.h \
		calformat.h \
		exceptions.h \
		dummyscheduler.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o obj/$(PLATFORM)/dummyscheduler.o dummyscheduler.cpp

obj/$(PLATFORM)/duration.o: duration.cpp \
		duration.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o obj/$(PLATFORM)/duration.o duration.cpp

obj/$(PLATFORM)/event.o: event.cpp \
		event.h \
		incidence.h \
		recurrence.h \
		alarm.h \
		customproperties.h \
		duration.h \
		person.h \
		attachment.h \
		incidencebase.h \
		attendee.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o obj/$(PLATFORM)/event.o event.cpp

obj/$(PLATFORM)/exceptions.o: exceptions.cpp \
		calformat.h \
		exceptions.h \
		event.h \
		incidence.h \
		recurrence.h \
		alarm.h \
		customproperties.h \
		duration.h \
		person.h \
		attachment.h \
		incidencebase.h \
		attendee.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o obj/$(PLATFORM)/exceptions.o exceptions.cpp

obj/$(PLATFORM)/filestorage.o: filestorage.cpp \
		calendar.h \
		customproperties.h \
		event.h \
		incidence.h \
		recurrence.h \
		alarm.h \
		duration.h \
		person.h \
		attachment.h \
		incidencebase.h \
		attendee.h \
		todo.h \
		journal.h \
		vcaldrag.h \
		vcalformat.h \
		calformat.h \
		exceptions.h \
		icalformat.h \
		scheduler.h \
		filestorage.h \
		calstorage.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o obj/$(PLATFORM)/filestorage.o filestorage.cpp

obj/$(PLATFORM)/freebusy.o: freebusy.cpp \
		freebusy.h \
		period.h \
		duration.h \
		calendar.h \
		customproperties.h \
		event.h \
		incidence.h \
		recurrence.h \
		alarm.h \
		person.h \
		attachment.h \
		incidencebase.h \
		attendee.h \
		todo.h \
		journal.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o obj/$(PLATFORM)/freebusy.o freebusy.cpp

obj/$(PLATFORM)/icaldrag.o: icaldrag.cpp \
		icaldrag.h \
		calendar.h \
		customproperties.h \
		event.h \
		incidence.h \
		recurrence.h \
		alarm.h \
		duration.h \
		person.h \
		attachment.h \
		incidencebase.h \
		attendee.h \
		todo.h \
		journal.h \
		icalformat.h \
		scheduler.h \
		calformat.h \
		exceptions.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o obj/$(PLATFORM)/icaldrag.o icaldrag.cpp

obj/$(PLATFORM)/icalformat.o: icalformat.cpp \
		calendar.h \
		customproperties.h \
		event.h \
		incidence.h \
		recurrence.h \
		alarm.h \
		duration.h \
		person.h \
		attachment.h \
		incidencebase.h \
		attendee.h \
		todo.h \
		journal.h \
		calendarlocal.h \
		icalformat.h \
		scheduler.h \
		calformat.h \
		exceptions.h \
		icalformatimpl.h \
		freebusy.h \
		period.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o obj/$(PLATFORM)/icalformat.o icalformat.cpp

obj/$(PLATFORM)/icalformatimpl.o: icalformatimpl.cpp \
		calendar.h \
		customproperties.h \
		event.h \
		incidence.h \
		recurrence.h \
		alarm.h \
		duration.h \
		person.h \
		attachment.h \
		incidencebase.h \
		attendee.h \
		todo.h \
		journal.h \
		icalformat.h \
		scheduler.h \
		calformat.h \
		exceptions.h \
		icalformatimpl.h \
		freebusy.h \
		period.h \
		compat.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o obj/$(PLATFORM)/icalformatimpl.o icalformatimpl.cpp

obj/$(PLATFORM)/imipscheduler.o: imipscheduler.cpp \
		event.h \
		incidence.h \
		recurrence.h \
		alarm.h \
		customproperties.h \
		duration.h \
		person.h \
		attachment.h \
		incidencebase.h \
		attendee.h \
		icalformat.h \
		scheduler.h \
		calformat.h \
		exceptions.h \
		imipscheduler.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o obj/$(PLATFORM)/imipscheduler.o imipscheduler.cpp

obj/$(PLATFORM)/incidence.o: incidence.cpp \
		calformat.h \
		exceptions.h \
		event.h \
		incidence.h \
		recurrence.h \
		alarm.h \
		customproperties.h \
		duration.h \
		person.h \
		attachment.h \
		incidencebase.h \
		attendee.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o obj/$(PLATFORM)/incidence.o incidence.cpp

obj/$(PLATFORM)/incidencebase.o: incidencebase.cpp \
		calformat.h \
		exceptions.h \
		event.h \
		incidence.h \
		recurrence.h \
		alarm.h \
		customproperties.h \
		duration.h \
		person.h \
		attachment.h \
		incidencebase.h \
		attendee.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o obj/$(PLATFORM)/incidencebase.o incidencebase.cpp

obj/$(PLATFORM)/journal.o: journal.cpp \
		journal.h \
		incidence.h \
		recurrence.h \
		alarm.h \
		customproperties.h \
		duration.h \
		person.h \
		attachment.h \
		incidencebase.h \
		attendee.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o obj/$(PLATFORM)/journal.o journal.cpp

obj/$(PLATFORM)/period.o: period.cpp \
		period.h \
		duration.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o obj/$(PLATFORM)/period.o period.cpp

obj/$(PLATFORM)/person.o: person.cpp \
		person.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o obj/$(PLATFORM)/person.o person.cpp

obj/$(PLATFORM)/qtopiaformat.o: qtopiaformat.cpp \
		calendar.h \
		customproperties.h \
		event.h \
		incidence.h \
		recurrence.h \
		alarm.h \
		duration.h \
		person.h \
		attachment.h \
		incidencebase.h \
		attendee.h \
		todo.h \
		journal.h \
		calendarlocal.h \
		qtopiaformat.h \
		scheduler.h \
		calformat.h \
		exceptions.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o obj/$(PLATFORM)/qtopiaformat.o qtopiaformat.cpp

obj/$(PLATFORM)/recurrence.o: recurrence.cpp \
		incidence.h \
		recurrence.h \
		alarm.h \
		customproperties.h \
		duration.h \
		person.h \
		attachment.h \
		incidencebase.h \
		attendee.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o obj/$(PLATFORM)/recurrence.o recurrence.cpp

obj/$(PLATFORM)/scheduler.o: scheduler.cpp \
		event.h \
		incidence.h \
		recurrence.h \
		alarm.h \
		customproperties.h \
		duration.h \
		person.h \
		attachment.h \
		incidencebase.h \
		attendee.h \
		todo.h \
		freebusy.h \
		period.h \
		calendar.h \
		journal.h \
		icalformat.h \
		scheduler.h \
		calformat.h \
		exceptions.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o obj/$(PLATFORM)/scheduler.o scheduler.cpp

obj/$(PLATFORM)/todo.o: todo.cpp \
		todo.h \
		incidence.h \
		recurrence.h \
		alarm.h \
		customproperties.h \
		duration.h \
		person.h \
		attachment.h \
		incidencebase.h \
		attendee.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o obj/$(PLATFORM)/todo.o todo.cpp

obj/$(PLATFORM)/vcaldrag.o: vcaldrag.cpp \
		vcaldrag.h \
		vcalformat.h \
		calformat.h \
		exceptions.h \
		event.h \
		incidence.h \
		recurrence.h \
		alarm.h \
		customproperties.h \
		duration.h \
		person.h \
		attachment.h \
		incidencebase.h \
		attendee.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o obj/$(PLATFORM)/vcaldrag.o vcaldrag.cpp

obj/$(PLATFORM)/vcalformat.o: vcalformat.cpp \
		vcaldrag.h \
		calendar.h \
		customproperties.h \
		event.h \
		incidence.h \
		recurrence.h \
		alarm.h \
		duration.h \
		person.h \
		attachment.h \
		incidencebase.h \
		attendee.h \
		todo.h \
		journal.h \
		vcalformat.h \
		calformat.h \
		exceptions.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o obj/$(PLATFORM)/vcalformat.o vcalformat.cpp

obj/$(PLATFORM)/vcc.o: versit/vcc.c \
		versit/vcc.h \
		versit/vobject.h \
		versit/port.h
	$(CC) -c $(CFLAGS) $(INCPATH) -o obj/$(PLATFORM)/vcc.o versit/vcc.c

obj/$(PLATFORM)/vobject.o: versit/vobject.c \
		versit/vobject.h \
		versit/port.h
	$(CC) -c $(CFLAGS) $(INCPATH) -o obj/$(PLATFORM)/vobject.o versit/vobject.c

obj/$(PLATFORM)/moc_calendar.o: moc/moc_calendar.cpp \
		calendar.h \
		customproperties.h \
		event.h \
		incidence.h \
		recurrence.h \
		alarm.h \
		duration.h \
		person.h \
		attachment.h \
		incidencebase.h \
		attendee.h \
		todo.h \
		journal.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o obj/$(PLATFORM)/moc_calendar.o moc/moc_calendar.cpp

moc/moc_calendar.cpp: calendar.h
	$(MOC) calendar.h -o moc/moc_calendar.cpp

