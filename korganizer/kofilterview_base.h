/****************************************************************************
** Form interface generated from reading ui file 'kofilterview_base.ui'
**
** Created: Sun Apr 6 11:33:10 2003
**      by:  The User Interface Compiler (uic)
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/
#ifndef KOFILTERVIEW_BASE_H
#define KOFILTERVIEW_BASE_H

#include <qvariant.h>
#include <qwidget.h>
class QVBoxLayout; 
class QHBoxLayout; 
class QGridLayout; 
class QCheckBox;
class QComboBox;
class QFrame;
class QPushButton;

class KOFilterView_base : public QWidget
{ 
    Q_OBJECT

public:
    KOFilterView_base( QWidget* parent = 0, const char* name = 0, WFlags fl = 0 );
    ~KOFilterView_base();

    QFrame* Frame11;
    QCheckBox* mEnabledCheck;
    QComboBox* mSelectionCombo;
    QPushButton* mEditButton;

protected:
    QVBoxLayout* KOFilterView_baseLayout;
    QVBoxLayout* Frame11Layout;
};

#endif // KOFILTERVIEW_BASE_H
