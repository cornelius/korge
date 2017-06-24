#ifndef MINIKDE_KPROCESS_H
#define MINIKDE_KPROCESS_H

#include <qobject.h>
//#include <qpe/qprocess.h>

class KProcess : public QObject
{
  public:
    enum RunMode { DontCare, NotifyOnExit, Block };
  
    void clearArguments();
    
    KProcess & operator<<( const QString & );
    
    bool start( RunMode mode = DontCare );

  private:
//    QProcess mProcess;
};

#endif
