/*
    This file is part of the KOrganizer alarm daemon.
    Copyright (c) 2002 Cornelius Schumacher <schumacher@kde.org>

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

#include "simplealarmdaemonimpl.h"

#include <kdebug.h>
#include <klocale.h>

SimpleAlarmDaemonImpl::SimpleAlarmDaemonImpl( QWidget *parent )
  : SimpleAlarmDaemon( parent )
{
  kdDebug() << "SimpleAlarmDaemonImpl" << endl;
}

SimpleAlarmDaemonImpl::~SimpleAlarmDaemonImpl()
{
}

void SimpleAlarmDaemonImpl::mousePressEvent( QMouseEvent * )
{
  if ( !mWid ) {
    mWid = new SimpleAlarmDaemonDialog();
    connect( mWid, SIGNAL( signalCheckAlarms() ), SLOT( checkAlarms() ) );
    connect( this, SIGNAL( log( const QString & ) ),
             mWid, SLOT( log( const QString & ) ) );
  }

  if ( mWid->isHidden() ) {
    mWid->show();
    QPoint pos = mapToGlobal ( QPoint ( 0, 0 ) );
    mWid->move( pos.x() - mWid->width() + width() - 4,
	        pos.y() - mWid->height() - 4 );
    mWid->raise();
  } else {
    mWid->hide();
  }
}

void SimpleAlarmDaemonImpl::argl()
{
  kdDebug() << "Argl" << endl;
}
