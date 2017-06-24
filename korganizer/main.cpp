#include <qdatetime.h>

#include <qpe/qpeapplication.h>
#include <qpe/global.h>

#include <kstandarddirs.h>
#include <kglobal.h>
#include <kdebug.h>
#include <kconfig.h>

#include "mainwindow.h"

int main( int argc, char **argv )
{
  QPEApplication a( argc, argv );

  KGlobal::setAppName( "korganizer" );
  KStandardDirs::setAppDir( Global::applicationFileName( "korganizer", "" ) );
    
  MainWindow m;
  a.showMainWidget(&m);

  a.exec();
}
