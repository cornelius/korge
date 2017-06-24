/****************************************************************************
** Form interface generated from reading ui file 'filteredit_base.ui'
**
** Created: Sun Apr 6 11:33:10 2003
**      by:  The User Interface Compiler (uic)
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/
#ifndef FILTEREDIT_BASE_H
#define FILTEREDIT_BASE_H

#include <qvariant.h>
#include <qwidget.h>
class QVBoxLayout; 
class QHBoxLayout; 
class QGridLayout; 
class QButtonGroup;
class QCheckBox;
class QFrame;
class QListBox;
class QListBoxItem;
class QPushButton;
class QRadioButton;

class FilterEdit_base : public QWidget
{ 
    Q_OBJECT

public:
    FilterEdit_base( QWidget* parent = 0, const char* name = 0, WFlags fl = 0 );
    ~FilterEdit_base();

    QFrame* mCriteriaFrame;
    QButtonGroup* ButtonGroup1;
    QRadioButton* mCatHideCheck;
    QRadioButton* mCatShowCheck;
    QListBox* mCatList;
    QPushButton* mCatEditButton;
    QCheckBox* mRecurringCheck;
    QCheckBox* mCompletedCheck;

public slots:
    virtual void updateFilter();

protected:
    QVBoxLayout* FilterEdit_baseLayout;
    QVBoxLayout* mCriteriaFrameLayout;
    QGridLayout* ButtonGroup1Layout;
};

#endif // FILTEREDIT_BASE_H
