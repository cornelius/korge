#ifndef MICROKDE_KTEXTEDIT_H
#define MICROKDE_KTEXTEDIT_H

#include <qmultilineedit.h>

class KTextEdit : public QMultiLineEdit
{
  public:
    KTextEdit( QWidget *parent ) : QMultiLineEdit( parent ) {}
};

#endif
