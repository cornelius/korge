#ifndef MICROKDE_KLINEEDITDLG_H
#define MICROKDE_KLINEEDITDLG_H

#include "kdialogbase.h"

class KLineEditDlg : public KDialogBase
{
  public:
    KLineEditDlg( const QString &, const QString &, QWidget *parent ) :
      KDialogBase( parent ) {}

    QString text() { return QString::null; }
};

#endif
