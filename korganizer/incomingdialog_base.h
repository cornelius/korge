/****************************************************************************
** Form interface generated from reading ui file '/build/kde/cvs/korge/kdepim/korganizer/incomingdialog_base.ui'
**
** Created: Sat Mar 29 22:24:26 2003
**      by: The User Interface Compiler ()
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#ifndef INCOMINGDIALOG_BASE_H
#define INCOMINGDIALOG_BASE_H

#include <qvariant.h>
#include <qdialog.h>

class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class QListView;
class QListViewItem;
class QPushButton;

class IncomingDialog_base : public QDialog
{
    Q_OBJECT

public:
    IncomingDialog_base( QWidget* parent = 0, const char* name = 0, bool modal = FALSE, WFlags fl = 0 );
    ~IncomingDialog_base();

    QPushButton* PushButton4;
    QPushButton* PushButton7;
    QListView* mMessageListView;
    QPushButton* PushButton7_2;
    QPushButton* PushButton8;
    QPushButton* PushButton9;

protected:
    QGridLayout* IncomingDialog_baseLayout;

protected slots:
    virtual void languageChange();

    virtual void acceptAllMessages();
    virtual void acceptMessage();
    virtual void rejectMessage();
    virtual void retrieve();

};

#endif // INCOMINGDIALOG_BASE_H
