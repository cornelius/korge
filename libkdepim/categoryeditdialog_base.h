/****************************************************************************
** Form interface generated from reading ui file '/build/kde/cvs/korge/kdepim/libkdepim/categoryeditdialog_base.ui'
**
** Created: Sat Mar 29 21:45:20 2003
**      by: The User Interface Compiler ()
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#ifndef CATEGORYEDITDIALOG_BASE_H
#define CATEGORYEDITDIALOG_BASE_H

#include <qvariant.h>
#include <qdialog.h>

class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class QLineEdit;
class QListView;
class QListViewItem;
class QPushButton;

class CategoryEditDialog_base : public QDialog
{
    Q_OBJECT

public:
    CategoryEditDialog_base( QWidget* parent = 0, const char* name = 0, bool modal = FALSE, WFlags fl = 0 );
    ~CategoryEditDialog_base();

    QLineEdit* mEdit;
    QPushButton* mButtonHelp;
    QPushButton* mApply;
    QPushButton* mButtonOk;
    QPushButton* mButtonCancel;
    QListView* mCategories;
    QPushButton* mButtonAdd;
    QPushButton* mButtonModify;
    QPushButton* mButtonRemove;

public slots:
    virtual void add();
    virtual void modify();
    virtual void slotApply();
    virtual void remove();
    virtual void slotOk();

protected:
    QGridLayout* CategoryEditDialog_baseLayout;
    QHBoxLayout* Layout13;
    QVBoxLayout* layout103;

protected slots:
    virtual void languageChange();
};

#endif // CATEGORYEDITDIALOG_BASE_H
