#include "simplealarmdaemonapplet.h"

#include "simplealarmdaemonimpl.h"

#include "screenshot.h"

#include <kiconloader.h>
#include <kstandarddirs.h>

#include <qpe/global.h>

#include <qlabel.h>

SimpleAlarmDaemonApplet::SimpleAlarmDaemonApplet()
  : mApplet( 0 ), ref( 0 )
{
  KStandardDirs::setAppDir( Global::applicationFileName( "korganizer", "" ) );
}

SimpleAlarmDaemonApplet::~SimpleAlarmDaemonApplet()
{
  delete mApplet;
}

QWidget *SimpleAlarmDaemonApplet::applet( QWidget *parent )
{
  if ( !mApplet ) {
    mApplet = new SimpleAlarmDaemonImpl( parent );
    mApplet->setPixmap( SmallIcon( "alarmdaemon" ) );
  }

  return mApplet;
}

int SimpleAlarmDaemonApplet::position() const
{
  return 6;
}

QRESULT SimpleAlarmDaemonApplet::queryInterface( const QUuid &uuid, QUnknownInterface **iface )
{
  *iface = 0;
  if ( uuid == IID_QUnknown )
      *iface = this;
  else if ( uuid == IID_TaskbarApplet )
      *iface = this;

  if ( *iface )
      (*iface)->addRef();
  return QS_OK;
}

Q_EXPORT_INTERFACE()
{
    Q_CREATE_INSTANCE( SimpleAlarmDaemonApplet )
}
