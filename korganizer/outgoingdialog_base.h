/****************************************************************************
** Form interface generated from reading ui file '/build/kde/cvs/korge/kdepim/korganizer/outgoingdialog_base.ui'
**
** Created: Sat Mar 29 22:24:26 2003
**      by: The User Interface Compiler ()
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#ifndef OUTGOINGDIALOG_BASE_H
#define OUTGOINGDIALOG_BASE_H

#include <qvariant.h>
#include <qdialog.h>

class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class QListView;
class QListViewItem;
class QPushButton;

class OutgoingDialog_base : public QDialog
{
    Q_OBJECT

public:
    OutgoingDialog_base( QWidget* parent = 0, const char* name = 0, bool modal = FALSE, WFlags fl = 0 );
    ~OutgoingDialog_base();

    QListView* mMessageListView;
    QPushButton* PushButton5;
    QPushButton* PushButton7;
    QPushButton* PushButton6;

protected:
    QGridLayout* OutgoingDialog_baseLayout;

protected slots:
    virtual void languageChange();

    virtual void send();
    virtual void deleteItem();

};

#endif // OUTGOINGDIALOG_BASE_H
