#include <klocale.h>
/****************************************************************************
** Form implementation generated from reading ui file '/build/kde/cvs/korge/kdepim/korganizer/publishdialog_base.ui'
**
** Created: Sat Mar 29 22:31:35 2003
**      by: The User Interface Compiler ()
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#include "publishdialog_base.h"

#include <qvariant.h>
#include <qframe.h>
#include <qheader.h>
#include <qlabel.h>
#include <qlineedit.h>
#include <qlistview.h>
#include <qpushbutton.h>
#include <qlayout.h>
#include <qtooltip.h>
#include <qwhatsthis.h>

/* 
 *  Constructs a PublishDialog_base as a child of 'parent', with the 
 *  name 'name' and widget flags set to 'f'.
 *
 *  The dialog will by default be modeless, unless you set 'modal' to
 *  TRUE to construct a modal dialog.
 */
PublishDialog_base::PublishDialog_base( QWidget* parent, const char* name, bool modal, WFlags fl )
    : QDialog( parent, name, modal, fl )

{
    if ( !name )
	setName( "PublishDialog_base" );
    PublishDialog_baseLayout = new QGridLayout( this, 1, 1, 11, 6, "PublishDialog_baseLayout"); 

    mAddressListView = new QListView( this, "mAddressListView" );
    mAddressListView->addColumn( tr2i18n( "Name" ) );
    mAddressListView->addColumn( tr2i18n( "Email" ) );

    PublishDialog_baseLayout->addMultiCellWidget( mAddressListView, 0, 3, 0, 1 );

    TextLabel1 = new QLabel( this, "TextLabel1" );

    PublishDialog_baseLayout->addWidget( TextLabel1, 4, 0 );

    TextLabel2 = new QLabel( this, "TextLabel2" );

    PublishDialog_baseLayout->addWidget( TextLabel2, 5, 0 );

    mEmailLineEdit = new QLineEdit( this, "mEmailLineEdit" );

    PublishDialog_baseLayout->addWidget( mEmailLineEdit, 5, 1 );

    mNameLineEdit = new QLineEdit( this, "mNameLineEdit" );

    PublishDialog_baseLayout->addWidget( mNameLineEdit, 4, 1 );

    PushButton10 = new QPushButton( this, "PushButton10" );

    PublishDialog_baseLayout->addWidget( PushButton10, 0, 2 );

    PushButton12 = new QPushButton( this, "PushButton12" );

    PublishDialog_baseLayout->addWidget( PushButton12, 2, 2 );

    PushButton11 = new QPushButton( this, "PushButton11" );

    PublishDialog_baseLayout->addWidget( PushButton11, 1, 2 );
    QSpacerItem* spacer = new QSpacerItem( 20, 241, QSizePolicy::Minimum, QSizePolicy::Expanding );
    PublishDialog_baseLayout->addMultiCell( spacer, 3, 5, 2, 2 );

    Line2 = new QFrame( this, "Line2" );
    Line2->setFrameShape( QFrame::HLine );
    Line2->setFrameShadow( QFrame::Sunken );
    Line2->setFrameShape( QFrame::HLine );

    PublishDialog_baseLayout->addMultiCellWidget( Line2, 6, 6, 0, 2 );

    layout95 = new QHBoxLayout( 0, 0, 6, "layout95"); 
    QSpacerItem* spacer_2 = new QSpacerItem( 20, 20, QSizePolicy::Expanding, QSizePolicy::Minimum );
    layout95->addItem( spacer_2 );

    PushButton9 = new QPushButton( this, "PushButton9" );
    PushButton9->setDefault( TRUE );
    layout95->addWidget( PushButton9 );

    PushButton8 = new QPushButton( this, "PushButton8" );
    layout95->addWidget( PushButton8 );

    PublishDialog_baseLayout->addMultiCellLayout( layout95, 7, 7, 0, 2 );
    languageChange();
    resize( QSize(420, 379).expandedTo(minimumSizeHint()) );

    // signals and slots connections
    connect( PushButton10, SIGNAL( clicked() ), this, SLOT( addItem() ) );
    connect( PushButton11, SIGNAL( clicked() ), this, SLOT( removeItem() ) );
    connect( PushButton12, SIGNAL( clicked() ), this, SLOT( openAddressbook() ) );
    connect( PushButton9, SIGNAL( clicked() ), this, SLOT( accept() ) );
    connect( mNameLineEdit, SIGNAL( textChanged(const QString&) ), this, SLOT( updateItem() ) );
    connect( mEmailLineEdit, SIGNAL( textChanged(const QString&) ), this, SLOT( updateItem() ) );
    connect( PushButton8, SIGNAL( clicked() ), this, SLOT( reject() ) );

    // tab order
    setTabOrder( mAddressListView, mNameLineEdit );
    setTabOrder( mNameLineEdit, mEmailLineEdit );
    setTabOrder( mEmailLineEdit, PushButton10 );
    setTabOrder( PushButton10, PushButton11 );
    setTabOrder( PushButton11, PushButton12 );
    setTabOrder( PushButton12, PushButton9 );
    setTabOrder( PushButton9, PushButton8 );
}

/*
 *  Destroys the object and frees any allocated resources
 */
PublishDialog_base::~PublishDialog_base()
{
    // no need to delete child widgets, Qt does it all for us
}

/*
 *  Sets the strings of the subwidgets using the current
 *  language.
 */
void PublishDialog_base::languageChange()
{
    setCaption( tr2i18n( "Form1" ) );
    mAddressListView->header()->setLabel( 0, tr2i18n( "Name" ) );
    mAddressListView->header()->setLabel( 1, tr2i18n( "Email" ) );
    TextLabel1->setText( tr2i18n( "Name:" ) );
    TextLabel2->setText( tr2i18n( "Email:" ) );
    PushButton10->setText( tr2i18n( "&New" ) );
    PushButton12->setText( tr2i18n( "&Addressbook" ) );
    PushButton11->setText( tr2i18n( "&Remove" ) );
    PushButton9->setText( tr2i18n( "&OK" ) );
    PushButton8->setText( tr2i18n( "&Cancel" ) );
}

void PublishDialog_base::addItem()
{
    qWarning( "PublishDialog_base::addItem(): Not implemented yet" );
}

void PublishDialog_base::removeItem()
{
    qWarning( "PublishDialog_base::removeItem(): Not implemented yet" );
}

void PublishDialog_base::openAddressbook()
{
    qWarning( "PublishDialog_base::openAddressbook(): Not implemented yet" );
}

void PublishDialog_base::updateItem()
{
    qWarning( "PublishDialog_base::updateItem(): Not implemented yet" );
}

#include "publishdialog_base.moc"
