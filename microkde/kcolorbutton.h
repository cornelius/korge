#ifndef MICROKDE_KCOLORBUTTON_H
#define MICROKDE_KCOLORBUTTON_H

#include <qwidget.h>
#include <qcolor.h>

class KColorButton : public QWidget
{
  public:
    KColorButton( QWidget * ) {}

    void setColor ( const QColor & ) {}
    QColor color() const { return QColor(); }
};

#endif
