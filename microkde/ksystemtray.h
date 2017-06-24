#ifndef MICROKDE_KSYSTEMTRAY_H
#define MICROKDE_KSYSTEMTRAY_H

#include <qlabel.h>

class KSystemTray : public QLabel
{
  public:
    KSystemTray( QWidget *parent = 0 ) : QLabel( parent ) {};
};

#endif
