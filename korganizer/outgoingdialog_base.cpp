#include <klocale.h>
/****************************************************************************
** Form implementation generated from reading ui file '/build/kde/cvs/korge/kdepim/korganizer/outgoingdialog_base.ui'
**
** Created: Sat Mar 29 22:31:21 2003
**      by: The User Interface Compiler ()
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#include "outgoingdialog_base.h"

#include <qvariant.h>
#include <qheader.h>
#include <qlistview.h>
#include <qpushbutton.h>
#include <qlayout.h>
#include <qtooltip.h>
#include <qwhatsthis.h>

/* 
 *  Constructs a OutgoingDialog_base as a child of 'parent', with the 
 *  name 'name' and widget flags set to 'f'.
 *
 *  The dialog will by default be modeless, unless you set 'modal' to
 *  TRUE to construct a modal dialog.
 */
OutgoingDialog_base::OutgoingDialog_base( QWidget* parent, const char* name, bool modal, WFlags fl )
    : QDialog( parent, name, modal, fl )

{
    if ( !name )
	setName( "OutgoingDialog_base" );
    OutgoingDialog_baseLayout = new QGridLayout( this, 1, 1, 11, 6, "OutgoingDialog_baseLayout"); 

    mMessageListView = new QListView( this, "mMessageListView" );
    mMessageListView->addColumn( tr2i18n( "Summary" ) );
    mMessageListView->addColumn( tr2i18n( "Start Date" ) );
    mMessageListView->addColumn( tr2i18n( "Start Time" ) );
    mMessageListView->addColumn( tr2i18n( "End Date" ) );
    mMessageListView->addColumn( tr2i18n( "End Time" ) );
    mMessageListView->addColumn( tr2i18n( "Method" ) );
    mMessageListView->setFrameShape( QListView::StyledPanel );
    mMessageListView->setFrameShadow( QListView::Sunken );
    mMessageListView->setAllColumnsShowFocus( TRUE );

    OutgoingDialog_baseLayout->addMultiCellWidget( mMessageListView, 0, 3, 0, 0 );

    PushButton5 = new QPushButton( this, "PushButton5" );
    PushButton5->setDefault( FALSE );

    OutgoingDialog_baseLayout->addWidget( PushButton5, 0, 1 );

    PushButton7 = new QPushButton( this, "PushButton7" );

    OutgoingDialog_baseLayout->addWidget( PushButton7, 1, 1 );

    PushButton6 = new QPushButton( this, "PushButton6" );
    PushButton6->setDefault( TRUE );

    OutgoingDialog_baseLayout->addWidget( PushButton6, 3, 1 );
    QSpacerItem* spacer = new QSpacerItem( 20, 20, QSizePolicy::Minimum, QSizePolicy::Expanding );
    OutgoingDialog_baseLayout->addItem( spacer, 2, 1 );
    languageChange();
    resize( QSize(582, 274).expandedTo(minimumSizeHint()) );

    // signals and slots connections
    connect( PushButton6, SIGNAL( clicked() ), this, SLOT( accept() ) );
    connect( PushButton5, SIGNAL( clicked() ), this, SLOT( send() ) );
    connect( PushButton7, SIGNAL( clicked() ), this, SLOT( deleteItem() ) );
}

/*
 *  Destroys the object and frees any allocated resources
 */
OutgoingDialog_base::~OutgoingDialog_base()
{
    // no need to delete child widgets, Qt does it all for us
}

/*
 *  Sets the strings of the subwidgets using the current
 *  language.
 */
void OutgoingDialog_base::languageChange()
{
    setCaption( tr2i18n( "Scheduler - Outgoing Messages" ) );
    mMessageListView->header()->setLabel( 0, tr2i18n( "Summary" ) );
    mMessageListView->header()->setLabel( 1, tr2i18n( "Start Date" ) );
    mMessageListView->header()->setLabel( 2, tr2i18n( "Start Time" ) );
    mMessageListView->header()->setLabel( 3, tr2i18n( "End Date" ) );
    mMessageListView->header()->setLabel( 4, tr2i18n( "End Time" ) );
    mMessageListView->header()->setLabel( 5, tr2i18n( "Method" ) );
    PushButton5->setText( tr2i18n( "&Send Messages" ) );
    PushButton7->setText( tr2i18n( "&Remove" ) );
    PushButton6->setText( tr2i18n( "&Close" ) );
}

void OutgoingDialog_base::send()
{
    qWarning( "OutgoingDialog_base::send(): Not implemented yet" );
}

void OutgoingDialog_base::deleteItem()
{
    qWarning( "OutgoingDialog_base::deleteItem(): Not implemented yet" );
}

#include "outgoingdialog_base.moc"
