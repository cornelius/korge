#############################################################################
# Makefile for building libkdepim.so.1.0.0
# Generated by tmake at 22:46, 2003/04/06
#     Project: kdepim
#    Template: lib
#############################################################################

####### Compiler, tools and options

CC	=	gcc
CXX	=	g++
CFLAGS	=	-pipe -Wall -W -O2 -fPIC -DNO_DEBUG
CXXFLAGS=	-pipe -DQWS -fno-exceptions -fno-rtti -Wall -W -O2 -fPIC -DNO_DEBUG
INCPATH	=	-I../microkde -I../qtcompat -I. -I.. -I$(QTDIR)/include
LINK	=	g++
LFLAGS	=	-shared -Wl,-soname,libkdepim.so.1
LIBS	=	$(SUBLIBS) -L$(QTDIR)/lib -lmicrokde -lqte
AR	=	ar cqs
RANLIB	=	
MOC	=	$(QTDIR)/bin/moc
UIC	=	$(QTDIR)/bin/uic

TAR	=	tar -cf
GZIP	=	gzip -9f

####### Files

HEADERS =	categoryeditdialog.h \
		categoryeditdialog_base.h \
		categoryselectdialog.h \
		categoryselectdialog_base.h \
		kdateedit.h \
		kinputdialog.h \
		kpimprefs.h \
		kprefs.h \
		kprefsdialog.h
SOURCES =	categoryeditdialog.cpp \
		categoryeditdialog_base.cpp \
		categoryselectdialog.cpp \
		categoryselectdialog_base.cpp \
		kdateedit.cpp \
		kinputdialog.cpp \
		kpimprefs.cpp \
		kprefs.cpp \
		kprefsdialog.cpp
OBJECTS =	obj/$(PLATFORM)/categoryeditdialog.o \
		obj/$(PLATFORM)/categoryeditdialog_base.o \
		obj/$(PLATFORM)/categoryselectdialog.o \
		obj/$(PLATFORM)/categoryselectdialog_base.o \
		obj/$(PLATFORM)/kdateedit.o \
		obj/$(PLATFORM)/kinputdialog.o \
		obj/$(PLATFORM)/kpimprefs.o \
		obj/$(PLATFORM)/kprefs.o \
		obj/$(PLATFORM)/kprefsdialog.o
INTERFACES =	
UICDECLS =	
UICIMPLS =	
SRCMOC	=	moc/moc_categoryeditdialog.cpp \
		moc/moc_categoryeditdialog_base.cpp \
		moc/moc_categoryselectdialog.cpp \
		moc/moc_categoryselectdialog_base.cpp \
		moc/moc_kdateedit.cpp \
		moc/moc_kprefsdialog.cpp
OBJMOC	=	obj/$(PLATFORM)/moc_categoryeditdialog.o \
		obj/$(PLATFORM)/moc_categoryeditdialog_base.o \
		obj/$(PLATFORM)/moc_categoryselectdialog.o \
		obj/$(PLATFORM)/moc_categoryselectdialog_base.o \
		obj/$(PLATFORM)/moc_kdateedit.o \
		obj/$(PLATFORM)/moc_kprefsdialog.o
DIST	=	
TARGET	=	libkdepim.so.1.0.0
TARGETA	=	$(QPEDIR)/lib/libkdepim.a
TARGETD	=	libkdepim.so.1.0.0
TARGET0	=	libkdepim.so
TARGET1	=	libkdepim.so.1
TARGET2	=	libkdepim.so.1.0
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


all: $(QPEDIR)/lib/libkdepim.so.1.0.0

$(QPEDIR)/lib/libkdepim.so.1.0.0: $(OBJECTS) $(OBJMOC) $(SUBLIBS) 
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

Makefile: kdepim.pro
	tmake kdepim.pro -o Makefile

dist:
	$(TAR) kdepim.tar kdepim.pro $(SOURCES) $(HEADERS) $(INTERFACES) $(DIST)
	$(GZIP) kdepim.tar

clean:
	-rm -f $(OBJECTS) $(OBJMOC) $(SRCMOC) $(UICIMPLS) $(UICDECLS) $(TARGET)
	-rm -f $(TARGET0) $(TARGET1) $(TARGET2) $(TARGETA)
	-rm -f *~ core

####### Sub-libraries


###### Combined headers


####### Compile

obj/$(PLATFORM)/categoryeditdialog.o: categoryeditdialog.cpp \
		kpimprefs.h \
		kprefs.h \
		categoryeditdialog.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o obj/$(PLATFORM)/categoryeditdialog.o categoryeditdialog.cpp

obj/$(PLATFORM)/categoryeditdialog_base.o: categoryeditdialog_base.cpp \
		categoryeditdialog_base.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o obj/$(PLATFORM)/categoryeditdialog_base.o categoryeditdialog_base.cpp

obj/$(PLATFORM)/categoryselectdialog.o: categoryselectdialog.cpp \
		categoryselectdialog.h \
		kpimprefs.h \
		kprefs.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o obj/$(PLATFORM)/categoryselectdialog.o categoryselectdialog.cpp

obj/$(PLATFORM)/categoryselectdialog_base.o: categoryselectdialog_base.cpp \
		categoryselectdialog_base.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o obj/$(PLATFORM)/categoryselectdialog_base.o categoryselectdialog_base.cpp

obj/$(PLATFORM)/kdateedit.o: kdateedit.cpp \
		kdateedit.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o obj/$(PLATFORM)/kdateedit.o kdateedit.cpp

obj/$(PLATFORM)/kinputdialog.o: kinputdialog.cpp \
		kinputdialog.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o obj/$(PLATFORM)/kinputdialog.o kinputdialog.cpp

obj/$(PLATFORM)/kpimprefs.o: kpimprefs.cpp \
		kpimprefs.h \
		kprefs.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o obj/$(PLATFORM)/kpimprefs.o kpimprefs.cpp

obj/$(PLATFORM)/kprefs.o: kprefs.cpp \
		kprefs.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o obj/$(PLATFORM)/kprefs.o kprefs.cpp

obj/$(PLATFORM)/kprefsdialog.o: kprefsdialog.cpp \
		kprefs.h \
		kprefsdialog.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o obj/$(PLATFORM)/kprefsdialog.o kprefsdialog.cpp

obj/$(PLATFORM)/moc_categoryeditdialog.o: moc/moc_categoryeditdialog.cpp \
		categoryeditdialog.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o obj/$(PLATFORM)/moc_categoryeditdialog.o moc/moc_categoryeditdialog.cpp

obj/$(PLATFORM)/moc_categoryeditdialog_base.o: moc/moc_categoryeditdialog_base.cpp \
		categoryeditdialog_base.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o obj/$(PLATFORM)/moc_categoryeditdialog_base.o moc/moc_categoryeditdialog_base.cpp

obj/$(PLATFORM)/moc_categoryselectdialog.o: moc/moc_categoryselectdialog.cpp \
		categoryselectdialog.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o obj/$(PLATFORM)/moc_categoryselectdialog.o moc/moc_categoryselectdialog.cpp

obj/$(PLATFORM)/moc_categoryselectdialog_base.o: moc/moc_categoryselectdialog_base.cpp \
		categoryselectdialog_base.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o obj/$(PLATFORM)/moc_categoryselectdialog_base.o moc/moc_categoryselectdialog_base.cpp

obj/$(PLATFORM)/moc_kdateedit.o: moc/moc_kdateedit.cpp \
		kdateedit.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o obj/$(PLATFORM)/moc_kdateedit.o moc/moc_kdateedit.cpp

obj/$(PLATFORM)/moc_kprefsdialog.o: moc/moc_kprefsdialog.cpp \
		kprefsdialog.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o obj/$(PLATFORM)/moc_kprefsdialog.o moc/moc_kprefsdialog.cpp

moc/moc_categoryeditdialog.cpp: categoryeditdialog.h
	$(MOC) categoryeditdialog.h -o moc/moc_categoryeditdialog.cpp

moc/moc_categoryeditdialog_base.cpp: categoryeditdialog_base.h
	$(MOC) categoryeditdialog_base.h -o moc/moc_categoryeditdialog_base.cpp

moc/moc_categoryselectdialog.cpp: categoryselectdialog.h
	$(MOC) categoryselectdialog.h -o moc/moc_categoryselectdialog.cpp

moc/moc_categoryselectdialog_base.cpp: categoryselectdialog_base.h
	$(MOC) categoryselectdialog_base.h -o moc/moc_categoryselectdialog_base.cpp

moc/moc_kdateedit.cpp: kdateedit.h
	$(MOC) kdateedit.h -o moc/moc_kdateedit.cpp

moc/moc_kprefsdialog.cpp: kprefsdialog.h
	$(MOC) kprefsdialog.h -o moc/moc_kprefsdialog.cpp

