#ifndef MICROKDE_KGLOBALSETTINGS_H
#define MICROKDE_KGLOBALSETTINGS_H

#include <qfont.h>
#include <qrect.h>

class KGlobalSettings
{
  public:
    static QFont generalFont();
    static QRect desktopGeometry( QWidget * );
};

#endif
