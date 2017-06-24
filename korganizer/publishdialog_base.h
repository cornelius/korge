/****************************************************************************
** Form interface generated from reading ui file '/build/kde/cvs/korge/kdepim/korganizer/publishdialog_base.ui'
**
** Created: Sat Mar 29 22:24:27 2003
**      by: The User Interface Compiler ()
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#ifndef PUBLISHDIALOG_BASE_H
#define PUBLISHDIALOG_BASE_H

#include <qvariant.h>
#include <qdialog.h>

class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class QFrame;
class QLabel;
class QLineEdit;
class QListView;
class QListViewItem;
class QPushButton;

class PublishDialog_base : public QDialog
{
    Q_OBJECT

public:
    PublishDialog_base( QWidget* parent = 0, const char* name = 0, bool modal = FALSE, WFlags fl = 0 );
    ~PublishDialog_base();

    QListView* mAddressListView;
    QLabel* TextLabel1;
    QLabel* TextLabel2;
    QLineEdit* mEmailLineEdit;
    QLineEdit* mNameLineEdit;
    QPushButton* PushButton10;
    QPushButton* PushButton12;
    QPushButton* PushButton11;
    QFrame* Line2;
    QPushButton* PushButton9;
    QPushButton* PushButton8;

protected:
    QGridLayout* PublishDialog_baseLayout;
    QHBoxLayout* layout95;

protected slots:
    virtual void languageChange();

    virtual void addItem();
    virtual void removeItem();
    virtual void openAddressbook();
    virtual void updateItem();

};

#endif // PUBLISHDIALOG_BASE_H
