/**********************************************************************
** Copyright (C) 2000 Trolltech AS.  All rights reserved.
**
** This file is part of Qtopia Environment.
**
** This file may be distributed and/or modified under the terms of the
** GNU General Public License version 2 as published by the Free Software
** Foundation and appearing in the file LICENSE.GPL included in the
** packaging of this file.
**
** This file is provided AS IS with NO WARRANTY OF ANY KIND, INCLUDING THE
** WARRANTY OF DESIGN, MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
**
** See http://www.trolltech.com/gpl/ for GPL licensing information.
**
** Contact info@trolltech.com if any conditions of this licensing are
** not clear to you.
**
**********************************************************************/
#include "screenshot.h"
#include "screenshotappletimpl.h"


ScreenshotAppletImpl::ScreenshotAppletImpl()
    : screenshot(0), ref(0)
{
}

ScreenshotAppletImpl::~ScreenshotAppletImpl()
{
    delete screenshot;
}

QWidget *ScreenshotAppletImpl::applet( QWidget *parent )
{
    if ( !screenshot )
  screenshot = new ScreenshotApplet( parent );
    return screenshot;
}

int ScreenshotAppletImpl::position() const
{
    return 6;
}

QRESULT ScreenshotAppletImpl::queryInterface( const QUuid &uuid, QUnknownInterface **iface )
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
    Q_CREATE_INSTANCE( ScreenshotAppletImpl )
}


