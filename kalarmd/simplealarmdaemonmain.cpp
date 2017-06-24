#include "simplealarmdaemon.h"

#include <qpe/qpeapplication.h>
#include <qlabel.h>

int main( int argc, char **argv )
{
  QPEApplication app( argc, argv );
  
  SimpleAlarmDaemon alarmDaemon;
  
  app.setMainWidget( &alarmDaemon );
  
//  alarmDaemon.show();

  return app.exec();
}
