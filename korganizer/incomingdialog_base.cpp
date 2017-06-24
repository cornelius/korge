#include <klocale.h>
/****************************************************************************
** Form implementation generated from reading ui file '/build/kde/cvs/korge/kdepim/korganizer/incomingdialog_base.ui'
**
** Created: Sat Mar 29 22:31:27 2003
**      by: The User Interface Compiler ()
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#include "incomingdialog_base.h"

#include <qvariant.h>
#include <qheader.h>
#include <qlistview.h>
#include <qpushbutton.h>
#include <qlayout.h>
#include <qtooltip.h>
#include <qwhatsthis.h>

/* 
 *  Constructs a IncomingDialog_base as a child of 'parent', with the 
 *  name 'name' and widget flags set to 'f'.
 *
 *  The dialog will by default be modeless, unless you set 'modal' to
 *  TRUE to construct a modal dialog.
 */
IncomingDialog_base::IncomingDialog_base( QWidget* parent, const char* name, bool modal, WFlags fl )
    : QDialog( parent, name, modal, fl )

{
    if ( !name )
	setName( "IncomingDialog_base" );
    IncomingDialog_baseLayout = new QGridLayout( this, 1, 1, 11, 6, "IncomingDialog_baseLayout"); 

    PushButton4 = new QPushButton( this, "PushButton4" );

    IncomingDialog_baseLayout->addWidget( PushButton4, 0, 1 );

    PushButton7 = new QPushButton( this, "PushButton7" );
    PushButton7->setDefault( TRUE );

    IncomingDialog_baseLayout->addWidget( PushButton7, 5, 1 );

    mMessageListView = new QListView( this, "mMessageListView" );
    mMessageListView->addColumn( tr2i18n( "Summary" ) );
    mMessageListView->addColumn( tr2i18n( "Start Date" ) );
    mMessageListView->addColumn( tr2i18n( "Start Time" ) );
    mMessageListView->addColumn( tr2i18n( "End Date" ) );
    mMessageListView->addColumn( tr2i18n( "End Time" ) );
    mMessageListView->addColumn( tr2i18n( "Organizer" ) );
    mMessageListView->addColumn( tr2i18n( "Method" ) );
    mMessageListView->addColumn( tr2i18n( "Status" ) );
    mMessageListView->setAllColumnsShowFocus( FALSE );

    IncomingDialog_baseLayout->addMultiCellWidget( mMessageListView, 0, 5, 0, 0 );

    PushButton7_2 = new QPushButton( this, "PushButton7_2" );

    IncomingDialog_baseLayout->addWidget( PushButton7_2, 3, 1 );

    PushButton8 = new QPushButton( this, "PushButton8" );

    IncomingDialog_baseLayout->addWidget( PushButton8, 1, 1 );

    PushButton9 = new QPushButton( this, "PushButton9" );

    IncomingDialog_baseLayout->addWidget( PushButton9, 2, 1 );
    QSpacerItem* spacer = new QSpacerItem( 20, 70, QSizePolicy::Minimum, QSizePolicy::Expanding );
    IncomingDialog_baseLayout->addItem( spacer, 4, 1 );
    languageChange();
    resize( QSize(525, 262).expandedTo(minimumSizeHint()) );

    // signals and slots connections
    connect( PushButton7, SIGNAL( clicked() ), this, SLOT( accept() ) );
    connect( PushButton4, SIGNAL( clicked() ), this, SLOT( retrieve() ) );
    connect( PushButton7_2, SIGNAL( clicked() ), this, SLOT( acceptAllMessages() ) );

    // tab order
    setTabOrder( PushButton7, PushButton4 );
    setTabOrder( PushButton4, PushButton7_2 );
    setTabOrder( PushButton7_2, mMessageListView );
    setTabOrder( mMessageListView, PushButton8 );
    setTabOrder( PushButton8, PushButton9 );
}

/*
 *  Destroys the object and frees any allocated resources
 */
IncomingDialog_base::~IncomingDialog_base()
{
    // no need to delete child widgets, Qt does it all for us
}

/*
 *  Sets the strings of the subwidgets using the current
 *  language.
 */
void IncomingDialog_base::languageChange()
{
    setCaption( tr2i18n( "Scheduler - Incoming Messages" ) );
    PushButton4->setText( tr2i18n( "Retrieve &Messages" ) );
    PushButton7->setText( tr2i18n( "&Close" ) );
    mMessageListView->header()->setLabel( 0, tr2i18n( "Summary" ) );
    mMessageListView->header()->setLabel( 1, tr2i18n( "Start Date" ) );
    mMessageListView->header()->setLabel( 2, tr2i18n( "Start Time" ) );
    mMessageListView->header()->setLabel( 3, tr2i18n( "End Date" ) );
    mMessageListView->header()->setLabel( 4, tr2i18n( "End Time" ) );
    mMessageListView->header()->setLabel( 5, tr2i18n( "Organizer" ) );
    mMessageListView->header()->setLabel( 6, tr2i18n( "Method" ) );
    mMessageListView->header()->setLabel( 7, tr2i18n( "Status" ) );
    PushButton7_2->setText( tr2i18n( "Accept A&ll" ) );
    PushButton8->setText( tr2i18n( "&Accept" ) );
    PushButton9->setText( tr2i18n( "&Reject" ) );
}

void IncomingDialog_base::acceptAllMessages()
{
    qWarning( "IncomingDialog_base::acceptAllMessages(): Not implemented yet" );
}

void IncomingDialog_base::acceptMessage()
{
    qWarning( "IncomingDialog_base::acceptMessage(): Not implemented yet" );
}

void IncomingDialog_base::rejectMessage()
{
    qWarning( "IncomingDialog_base::rejectMessage(): Not implemented yet" );
}

void IncomingDialog_base::retrieve()
{
    qWarning( "IncomingDialog_base::retrieve(): Not implemented yet" );
}

#include "incomingdialog_base.moc"
