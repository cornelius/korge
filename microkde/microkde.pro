TEMPLATE	= lib
CONFIG		= qt warn_on release
INCLUDEPATH     += $(QPEDIR)/include . ../qtcompat
DEPENDPATH      += $(QPEDIR)/include
LIBS            += -lqpe -lqtcompat
TARGET		= microkde
OBJECTS_DIR = obj/$(PLATFORM)
MOC_DIR = moc
DESTDIR=$(QPEDIR)/lib

INTERFACES = \

HEADERS = \
 kapplication.h \
 kaudioplayer.h \
 kcalendarsystem.h \
 kcalendarsystemgregorian.h \
 kcolorbutton.h \
 kcolordialog.h \
 kcombobox.h \
 kconfig.h \
 kdatepicker.h \
 kdatetbl.h \
 kdebug.h \
 kdialog.h \
 kdialogbase.h \
 kdirwatch.h \
 keditlistbox.h \
 kemailsettings.h \
 kfiledialog.h \
 kfontdialog.h \
 kglobal.h \
 kglobalsettings.h \
 kiconloader.h \
 kio/job.h \
 klineedit.h \
 klineeditdlg.h \
 klistview.h \
 klocale.h \
 kmessagebox.h \
 knotifyclient.h \
 knumvalidator.h \
 kprinter.h \
 kprocess.h \
 krestrictedline.h \
 krun.h \
 kseparator.h \
 ksimpleconfig.h \
 kstandarddirs.h \
 kstaticdeleter.h \
 ksystemtray.h \
 ktempfile.h \
 ktextedit.h \
 kunload.h \
 kurlrequester.h \


SOURCES = \
 kapplication.cpp \
 kcalendarsystem.cpp \
 kcalendarsystemgregorian.cpp \
 kcolordialog.cpp \
 kconfig.cpp \
 kdatepicker.cpp \
 kdatetbl.cpp \
 kdialogbase.cpp \
 keditlistbox.cpp \
 kemailsettings.cpp \
 kfontdialog.cpp \
 kglobal.cpp \
 kglobalsettings.cpp \
 kiconloader.cpp \
 klocale.cpp \
 kmessagebox.cpp \
 knumvalidator.cpp \
 kprocess.cpp \
 krun.cpp \
 kstandarddirs.cpp \
 ktempfile.cpp \
 kurlrequester.cpp \

