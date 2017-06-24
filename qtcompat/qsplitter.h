#ifndef QTCOMPAT_QSPLITTER_H
#define QTCOMPAT_QSPLITTER_H

#include <qwidget.h>

class QSplitter : public QWidget
{
  public:
    enum { KeepSize };
  
    QSplitter (int, QWidget *parent=0, const char *name=0) :
      QWidget( parent, name ) {}
    QSplitter( QWidget *parent=0, const char *name=0 ) :
      QWidget( parent, name ) {}

    void setResizeMode( QWidget *, int ) {}
    void setOpaqueResize() {}
    
    void setSizes (const QValueList<int> &) {}
    QValueList<int> sizes() { QValueList<int> ret; return ret; }
};

#endif
