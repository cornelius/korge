/**********************************************************************
** Copyright (C) 2002 L.J. Potter ljp@llornkcor.com
**  All rights reserved.
**
** This file may be distributed and/or modified under the terms of the
** GNU General Public License version 2 as published by the Free Software
** Foundation and appearing in the file LICENSE.GPL included in the
** packaging of this file.
**
** This file is provided AS IS with NO WARRANTY OF ANY KIND, INCLUDING THE
** WARRANTY OF DESIGN, MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
**
**********************************************************************/

#include "screenshot.h"

#include <qapplication.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <unistd.h>

#include <qpe/resource.h>
#include <qpe/qpeapplication.h>
#include <qpe/timestring.h>
#include <qpe/resource.h>
#include <qpe/config.h>
#include <qpe/applnk.h>
#include <qpe/config.h>

#include <qlineedit.h>
#include <qdir.h>
#include <qfileinfo.h>
#include <qlabel.h>
#include <qpushbutton.h>
#include <qpainter.h>
#include <qcombobox.h>
#include <qspinbox.h>
#include <qslider.h>
#include <qlayout.h>
#include <qframe.h>
#include <qpixmap.h>
#include <qregexp.h>
#include <qstring.h>
#include <qfile.h>
#include <qtimer.h>
#include <qfile.h>
#include <qdatastream.h>
#include <qcheckbox.h>
#include <qmessagebox.h>

#include <libkcal/calformat.h>

static char * snapshot_xpm[] = {
"16 16 10 1",
"   c None",
".  c #000000",
"+  c #00C000",
"@  c #585858",
"#  c #808080",
"$  c #000000",
"%  c #008000",
"&  c #008000",
"*  c #FF0000",
"=  c #FFC0C0",
"                ",
"   ...          ",
" ..+++..@#.     ",
" .$++++++.#.    ",
" .%$$++++++.    ",
" .&%%$$++@***.  ",
" .$&$++$=**@+.  ",
" .+$$+++@*$%%.  ",
" .+++++%+++%%.  ",
" .%%++++..+%%.  ",
" .%%++++..+%%.  ",
" .%%++++..+%%.  ",
" .%%++++..+%%.  ",
" .%%++++..+%%.  ",
" .%%++++..+%%.  ",
"                "};

static const char *SCAP_hostname = "www.handhelds.org";
static const int SCAP_port = 80;


ScreenshotApplet::ScreenshotApplet( QWidget *parent, const char *name )
		: QWidget( parent, name )
{
	setFixedHeight( 18 );
	setFixedWidth( 14 );
	
	m_icon = QPixmap ((const char **) snapshot_xpm );
}

ScreenshotApplet::~ScreenshotApplet()
{
}

void ScreenshotApplet::mousePressEvent( QMouseEvent *)
{
  qDebug("hallo");

  QLabel *sc = new QLabel( KCal::CalFormat::application(), 0 );
  sc->move( 50, 50 );
  sc->setMinimumSize( 100, 100 );
  sc-> show ( );

#if 0
	ScreenshotControl *sc = new ScreenshotControl ( );
	QPoint curPos = mapToGlobal ( QPoint ( 0, 0 ));
	sc-> move ( curPos. x ( ) - ( sc-> sizeHint ( ). width ( ) - width ( )) / 2, 
	            curPos. y ( ) - sc-> sizeHint ( ). height ( ));
	sc-> show ( );
#endif
}

void ScreenshotApplet::paintEvent( QPaintEvent* )
{
	QPainter p ( this );
	p. drawPixmap ( 0, 1, m_icon );
}

