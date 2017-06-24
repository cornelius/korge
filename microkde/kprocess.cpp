#include "kprocess.h"

void KProcess::clearArguments()
{
//  mProcess.clearArguments();
}
    
KProcess & KProcess::operator<<( const QString &arg )
{
//  mProcess.addArgument( arg );

  return *this;
}
    
bool KProcess::start( KProcess::RunMode )
{
//  return mProcess.start();
  return false;
}
