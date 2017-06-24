#include "kconfig.h"
#include "kdebug.h"

#include <qdatetime.h>

int main()
{
  QDateTime dt = QDateTime::currentDateTime();
  kdDebug() << "Before: " << dt.toString() << endl;
  KConfig cfg( "huhu" );
  cfg.writeEntry( "123", dt );
  QDateTime newDt = cfg.readDateTimeEntry( "123" );
  kdDebug() << "After: " << newDt.toString() << endl;
}
