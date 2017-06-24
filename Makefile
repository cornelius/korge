DISTPATH = $(shell pwd)
DISTDIR = $(shell basename $(DISTPATH))

SUBDIRS = libical/src/libical libical/src/libicalss qtcompat microkde \
  libkdepim libkcal kalarmd korganizer

all: tmake
	for i in $(SUBDIRS); do pushd $$i; \
          make -f Makefile$(PLATFORM) || exit 1; popd; \
          done

objects:
	for i in $(SUBDIRS); do mkdir -p $$i/obj/$(PLATFORM); done

clean:
	for i in $(SUBDIRS); do pushd $$i; make clean; \
          rm -f obj/$(PLATFORM)/*; rm -f moc/*; rm Makefile$(PLATFORM); popd; \
          done
        
install:
	cd pics; make install
	cp KOrganizer.png $(QPEDIR)/pics
	cp korganizer/korganizer.desktop $(QPEDIR)/apps/Applications

dist:
	@echo Dont forget to do "make install" before "make dist"
	cd ..; tar czf korge-dist.src.tgz --exclude=obj --exclude=moc $(DISTDIR)
	tar czPf ../korge-dist.i386.tgz  \
		/opt/Qtopia/bin/korganizer \
		/opt/Qtopia/apps/Applications/korganizer.desktop \
		/opt/Qtopia/pics/KOrganizer.png \
		/opt/Qtopia/pics/korganizer

tmake: objects qtcompat/Makefile$(PLATFORM) microkde/Makefile$(PLATFORM) \
       libkcal/Makefile$(PLATFORM) \
       libkdepim/Makefile$(PLATFORM) korganizer/Makefile$(PLATFORM) \
       kalarmd/Makefile$(PLATFORM) \
       libical/src/libical/Makefile$(PLATFORM) \
       libical/src/libicalss/Makefile$(PLATFORM)

qtcompat/Makefile$(PLATFORM): qtcompat/qtcompat.pro
	cd qtcompat; tmake qtcompat.pro -o Makefile$(PLATFORM)

microkde/Makefile$(PLATFORM): microkde/microkde.pro
	cd microkde; tmake microkde.pro -o Makefile$(PLATFORM)

libkcal/Makefile$(PLATFORM): libkcal/kcal.pro
	cd libkcal; tmake kcal.pro -o Makefile$(PLATFORM)

libkdepim/Makefile$(PLATFORM): libkdepim/kdepim.pro
	cd libkdepim; tmake kdepim.pro -o Makefile$(PLATFORM)

kalarmd/Makefile$(PLATFORM): kalarmd/kalarmd.pro
	cd kalarmd; tmake kalarmd.pro -o Makefile$(PLATFORM)

korganizer/Makefile$(PLATFORM): korganizer/korganizer.pro
	cd korganizer; tmake korganizer.pro -o Makefile$(PLATFORM)

libical/src/libical/Makefile$(PLATFORM): libical/src/libical/ical.pro
	cd libical/src/libical; tmake ical.pro -o Makefile$(PLATFORM)

libical/src/libicalss/Makefile$(PLATFORM): libical/src/libicalss/icalss.pro
	cd libical/src/libicalss; tmake icalss.pro -o Makefile$(PLATFORM)
