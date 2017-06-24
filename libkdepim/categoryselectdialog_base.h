/****************************************************************************
** Form interface generated from reading ui file '/build/kde/cvs/korge/kdepim/libkdepim/categoryselectdialog_base.ui'
**
** Created: Sat Mar 29 21:45:20 2003
**      by: The User Interface Compiler ()
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#ifndef CATEGORYSELECTDIALOG_BASE_H
#define CATEGORYSELECTDIALOG_BASE_H

#include <qvariant.h>
#include <qdialog.h>

class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class QListView;
class QListViewItem;
class QPushButton;

class CategorySelectDialog_base : public QDialog
{
    Q_OBJECT

public:
    CategorySelectDialog_base( QWidget* parent = 0, const char* name = 0, bool modal = FALSE, WFlags fl = 0 );
    ~CategorySelectDialog_base();

    QListView* mCategories;
    QPushButton* mClear;
    QPushButton* mButtonEdit;
    QPushButton* mButtonHelp;
    QPushButton* mApply;
    QPushButton* mButtonOk;
    QPushButton* mButtonCancel;

public slots:
    virtual void clear();
    virtual void slotApply();
    virtual void slotOk();

protected:
    QVBoxLayout* CategorySelectDialog_baseLayout;
    QHBoxLayout* Layout12;
    QHBoxLayout* Layout11;

protected slots:
    virtual void languageChange();
};

#endif // CATEGORYSELECTDIALOG_BASE_H
