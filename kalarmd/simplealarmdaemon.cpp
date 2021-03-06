/*
    This file is part of the KOrganizer alarm daemon.
    Copyright (c) 2002,2003 Cornelius Schumacher <schumacher@kde.org>

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

#include "simplealarmdaemon.h"

#include "alarmdialog.h"

#include <libkcal/calendarlocal.h>

#include <kdebug.h>
#include <klocale.h>
#include <kiconloader.h>
#include <kstandarddirs.h>
#include <kglobal.h>
#include <kconfig.h>

#include <qtimer.h>
#include <qfile.h>
#include <qtextstream.h>
#include <qfileinfo.h>
#include <qapplication.h>
#include <qlayout.h>
#include <qpushbutton.h>
#include <qlabel.h>
#include <qtimer.h>
#include <qtextview.h>

using namespace KCal;

SimpleAlarmDaemonDialog::SimpleAlarmDaemonDialog()
  : QWidget( 0 )
{
  setCaption( i18n("KOrganizer Alarm Daemon") );

  QBoxLayout *topLayout = new QVBoxLayout( this );
  topLayout->setMargin( 2 );
  topLayout->setSpacing( 2 );

  mCurrentTime = new QLabel( this );
  topLayout->addWidget( mCurrentTime );

  updateCurrentTime();

  QPushButton *button = new QPushButton( "Check Alarms", this );
  topLayout->addWidget( button );
  connect( button, SIGNAL( clicked() ), SIGNAL( signalCheckAlarms() ) );

  mLogView = new QTextView( this );
  topLayout->addWidget( mLogView );

  mTimer = new QTimer( this );
  connect( mTimer, SIGNAL( timeout() ), SLOT( updateCurrentTime() ) );
  mTimer->start( 1000 );
}

void SimpleAlarmDaemonDialog::log( const QString &msg )
{
  QString log = "<b>" + QTime::currentTime().toString() + ":</b> " + msg;

  mLogs.append( log );
  if ( mLogs.count() > 20 ) mLogs.remove( mLogs.begin() );

  mLogView->setText( mLogs.join( "\n" ) );
}

void SimpleAlarmDaemonDialog::updateCurrentTime()
{
  mCurrentTime->setText( QDateTime::currentDateTime().toString() );
}


SimpleAlarmDaemon::SimpleAlarmDaemon( QWidget *parent )
  : KSystemTray( parent )
{
  mAlarmDialog = new AlarmDialog( 0 );

  mCalendarDict.setAutoDelete( true );

  setPixmap( BarIcon( "misc" ) );

  mTimer = new QTimer( this );
  connect( mTimer, SIGNAL( timeout() ), SLOT( checkAlarms() ) );

  KConfig *cfg = KGlobal::config();
  cfg->setGroup( "Check" );
  int interval = cfg->readNumEntry( "Interval", 60 );
  kdDebug() << "SimpleAlarmDaemon check interval: " << interval << " seconds."
            << endl;

  mTimer->start( 1000 * interval );  // interval in seconds
}

SimpleAlarmDaemon::~SimpleAlarmDaemon()
{
}

void SimpleAlarmDaemon::closeEvent( QCloseEvent * )
{
  qApp->quit();
}

void SimpleAlarmDaemon::checkAlarms()
{
  kdDebug() << "SimpleAlarmDaemon::checkAlarms()" << endl;

  QString calFile = locateLocal( "data", "simplealarmdaemon/calendars" );

  kdDebug() << "  calendar file: " << calFile << endl;

  QFile file( calFile );
  if ( !file.open( IO_ReadOnly ) ) {
    return;
  }
  
  QTextStream ts( &file );
  QString line = ts.readLine();
  while( !line.isNull() ) {
    checkCalendar( line );
    line = ts.readLine();
  }
  
  file.close();
}

void SimpleAlarmDaemon::checkCalendar( const QString &calFile )
{
  kdDebug() << "checkCalendar(): '" << calFile << "'" << endl;

  KConfig *cfg = KGlobal::config();

  QFileInfo fi( calFile );
  if ( !fi.exists() ) {
    kdDebug() << " File does not exist." << endl;
    return;
  }

  cfg->setGroup( "CalendarsLastModified" );
  QDateTime lastModified = fi.lastModified();

  kdDebug() << "last modified" << lastModified.toString() << endl;

  CalendarLocal *cal = mCalendarDict.find( calFile );
  if ( !cal ) {
    kdDebug() << "NEW" << endl;
    cal = new CalendarLocal;

    KConfig cfg( locate( "config", "korganizerrc" ) );
    cfg.setGroup( "Time & Date" );
    QString tz = cfg.readEntry( "TimeZoneId", "" );
    kdDebug() << "TimeZone: " << tz << endl;
    cal->setTimeZoneId( tz );

    mCalendarDict.insert( calFile, cal );

    emit log( "Loading " + calFile );

    cal->load( calFile );
  } else {
    QDateTime oldLastModified = cfg->readDateTimeEntry( calFile );
  
    if ( !lastModified.isValid() || oldLastModified != lastModified ) {
      kdDebug() << "RELOAD" << endl;

      emit log( "Reloading " + calFile );

      cal->close();
      cal->load( calFile );
    } else {
      kdDebug() << "NO reload" << endl;
    }
  }

  cfg->writeEntry( calFile, lastModified );

  cfg->setGroup( "CalendarsLastChecked" );
  QDateTime oldestDate( QDate( 1970, 1, 1 ) );
  QDateTime lastChecked = cfg->readDateTimeEntry( calFile, &oldestDate );
  QDateTime from = lastChecked.addSecs( 1 );
  QDateTime to = QDateTime::currentDateTime();

  kdDebug() << "Last checked: " << lastChecked.toString() << endl;

  QString msg = "Check: " + from.toString() + " - " + to.toString();
  kdDebug() << msg << endl;
  emit log( msg );

  QValueList<Alarm *> alarms = cal->alarms( from, to );
  
  bool newEvents = false;
  QValueList<Alarm *>::ConstIterator it;
  for( it = alarms.begin(); it != alarms.end(); ++it ) {
    kdDebug() << "ALARM: " << (*it)->parent()->summary() << endl;
    Event *event = cal->event( (*it)->parent()->uid() );
    if ( event ) {
      emit log( "Alarm: " + event->summary() );

      mAlarmDialog->appendEvent( event );
      newEvents = true;
    }
  }
  if ( newEvents ) {
    mAlarmDialog->show();
    mAlarmDialog->eventNotification();
  }

  cfg->writeEntry( calFile, to );

  cfg->sync();
}

#include "simplealarmdaemon.moc"
