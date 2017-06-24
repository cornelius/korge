#ifndef MICROKDE_KDIRWATCH_H
#define MICROKDE_KDIRWATCH_H

#include <qobject.h>

class KDirWatch : public QObject
{
  public:
    KDirWatch() {}

    void addDir( const QString & ) {}
};

#endif
