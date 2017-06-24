#include "kglobalsettings.h"

#include <qapplication.h>

QFont KGlobalSettings::generalFont()
{
  return QFont("helevetica",12);
}

QRect KGlobalSettings::desktopGeometry( QWidget * )
{
  return QApplication::desktop()->rect();
}
