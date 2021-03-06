/*
    This file is part of the KDE alarm daemon.
    Copyright (c) 2000 Cornelius Schumacher <schumacher@kde.org>

    This program is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 2 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program; if not, write to the Free Software
    Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.

    As a special exception, permission is given to link this program
    with any edition of Qt, and distribute the resulting executable,
    without including the source code for Qt in the source distribution.
*/

// $Id: alarmdialog.cpp,v 1.14 2003/03/07 22:09:26 waba Exp $

#include <qhbox.h>
#include <qvbox.h>
#include <qlabel.h>
#include <qfile.h>
#include <qspinbox.h>

#include <klocale.h>
#include <kprocess.h>
#include <kaudioplayer.h>
#include <kdebug.h>
#include <knotifyclient.h>

#include <libkcal/event.h>

#include "koeventviewer.h"

#include "alarmdialog.h"
#include "alarmdialog.moc"

AlarmDialog::AlarmDialog(QWidget *parent,const char *name)
  : KDialogBase(parent,name,false,i18n("Alarm"),Ok|User1|User2,User2,false,
                i18n("Suspend"))
{
  QVBox *topBox = new QVBox(this);
  topBox->setSpacing(spacingHint());
  setMainWidget(topBox);

  (void)new QLabel(i18n("The following events triggered alarms:"),topBox);

  mIncidences.setAutoDelete(true);
  
  mEventViewer = new KOEventViewer(topBox);

  QHBox *suspendBox = new QHBox(topBox);
  suspendBox->setSpacing(spacingHint());

  (void)new QLabel(i18n("Suspend duration (minutes):"),suspendBox);
  mSuspendSpin = new QSpinBox(1,60,1,suspendBox);
  mSuspendSpin->setValue(5);  // default suspend duration
  
  showButton(User2, false);
  
  setMinimumSize(300,200);
}

AlarmDialog::~AlarmDialog()
{
}

void AlarmDialog::appendEvent(Event *event)
{
  mEventViewer->appendEvent(event);
  mIncidences.append(event->clone());
}

void AlarmDialog::appendTodo(Todo *todo)
{
  mEventViewer->appendTodo(todo);
  mIncidences.append(todo->clone());
}

void AlarmDialog::clearEvents()
{
  mEventViewer->clearEvents();

  mIncidences.clear();
}

void AlarmDialog::slotOk()
{
  clearEvents();
  accept();
}

void AlarmDialog::slotUser1()
{
  emit suspendSignal(mSuspendSpin->value());
  accept();
}

void AlarmDialog::eventNotification()
{
  bool beeped = false;

  Incidence *in;
  for (in = mIncidences.first(); in; in = mIncidences.next()) {
    QPtrList<Alarm> alarms = in->alarms();
    const Alarm* alarm;
    for (alarm = alarms.first(); alarm; alarm = alarms.next()) {
// TODO: Check whether this should be done for all multiple alarms
      if (alarm->type() == Alarm::Procedure) {
        kdDebug() << "Starting program: '" << alarm->programFile() << "'" << endl;
        KProcess proc;
        proc << QFile::encodeName(alarm->programFile());
        proc.start(KProcess::DontCare);
      }
      else if (alarm->type() == Alarm::Audio) {
        beeped = true;
        KAudioPlayer::play(QFile::encodeName(alarm->audioFile()));
      }
    }
  }
  
  if ( !beeped ) {
    KNotifyClient::beep();
  }
}
