#include <klocale.h>
/****************************************************************************
** Form implementation generated from reading ui file '/build/kde/cvs/korge/kdepim/libkdepim/categoryeditdialog_base.ui'
**
** Created: Sat Mar 29 21:46:09 2003
**      by: The User Interface Compiler ()
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#include "categoryeditdialog_base.h"

#include <qvariant.h>
#include <qheader.h>
#include <qlineedit.h>
#include <qlistview.h>
#include <qpushbutton.h>
#include <qlayout.h>
#include <qtooltip.h>
#include <qwhatsthis.h>

/* 
 *  Constructs a CategoryEditDialog_base as a child of 'parent', with the 
 *  name 'name' and widget flags set to 'f'.
 *
 *  The dialog will by default be modeless, unless you set 'modal' to
 *  TRUE to construct a modal dialog.
 */
CategoryEditDialog_base::CategoryEditDialog_base( QWidget* parent, const char* name, bool modal, WFlags fl )
    : QDialog( parent, name, modal, fl )

{
    if ( !name )
	setName( "CategoryEditDialog_base" );
    CategoryEditDialog_baseLayout = new QGridLayout( this, 1, 1, 11, 6, "CategoryEditDialog_baseLayout"); 

    mEdit = new QLineEdit( this, "mEdit" );

    CategoryEditDialog_baseLayout->addMultiCellWidget( mEdit, 1, 1, 0, 1 );

    Layout13 = new QHBoxLayout( 0, 0, 6, "Layout13"); 

    mButtonHelp = new QPushButton( this, "mButtonHelp" );
    mButtonHelp->setAutoDefault( TRUE );
    Layout13->addWidget( mButtonHelp );
    QSpacerItem* spacer = new QSpacerItem( 20, 20, QSizePolicy::Expanding, QSizePolicy::Minimum );
    Layout13->addItem( spacer );

    mApply = new QPushButton( this, "mApply" );
    Layout13->addWidget( mApply );

    mButtonOk = new QPushButton( this, "mButtonOk" );
    mButtonOk->setAutoDefault( TRUE );
    mButtonOk->setDefault( TRUE );
    Layout13->addWidget( mButtonOk );

    mButtonCancel = new QPushButton( this, "mButtonCancel" );
    mButtonCancel->setAutoDefault( TRUE );
    Layout13->addWidget( mButtonCancel );

    CategoryEditDialog_baseLayout->addMultiCellLayout( Layout13, 2, 2, 0, 1 );

    mCategories = new QListView( this, "mCategories" );
    mCategories->addColumn( tr2i18n( "Category" ) );

    CategoryEditDialog_baseLayout->addWidget( mCategories, 0, 0 );

    layout103 = new QVBoxLayout( 0, 0, 6, "layout103"); 

    mButtonAdd = new QPushButton( this, "mButtonAdd" );
    layout103->addWidget( mButtonAdd );

    mButtonModify = new QPushButton( this, "mButtonModify" );
    layout103->addWidget( mButtonModify );

    mButtonRemove = new QPushButton( this, "mButtonRemove" );
    layout103->addWidget( mButtonRemove );
    QSpacerItem* spacer_2 = new QSpacerItem( 20, 20, QSizePolicy::Minimum, QSizePolicy::Expanding );
    layout103->addItem( spacer_2 );

    CategoryEditDialog_baseLayout->addLayout( layout103, 0, 1 );
    languageChange();
    resize( QSize(386, 288).expandedTo(minimumSizeHint()) );

    // signals and slots connections
    connect( mButtonCancel, SIGNAL( clicked() ), this, SLOT( reject() ) );
    connect( mButtonAdd, SIGNAL( clicked() ), this, SLOT( add() ) );
    connect( mButtonModify, SIGNAL( clicked() ), this, SLOT( modify() ) );
    connect( mButtonRemove, SIGNAL( clicked() ), this, SLOT( remove() ) );
    connect( mButtonOk, SIGNAL( clicked() ), this, SLOT( slotOk() ) );
    connect( mApply, SIGNAL( clicked() ), this, SLOT( slotApply() ) );

    // tab order
    setTabOrder( mCategories, mEdit );
    setTabOrder( mEdit, mButtonAdd );
    setTabOrder( mButtonAdd, mButtonModify );
    setTabOrder( mButtonModify, mButtonRemove );
    setTabOrder( mButtonRemove, mButtonHelp );
    setTabOrder( mButtonHelp, mApply );
    setTabOrder( mApply, mButtonOk );
    setTabOrder( mButtonOk, mButtonCancel );
}

/*
 *  Destroys the object and frees any allocated resources
 */
CategoryEditDialog_base::~CategoryEditDialog_base()
{
    // no need to delete child widgets, Qt does it all for us
}

/*
 *  Sets the strings of the subwidgets using the current
 *  language.
 */
void CategoryEditDialog_base::languageChange()
{
    setCaption( tr2i18n( "Edit Categories" ) );
    mButtonHelp->setText( tr2i18n( "&Help" ) );
    mApply->setText( tr2i18n( "&Apply" ) );
    mButtonOk->setText( tr2i18n( "&OK" ) );
    mButtonCancel->setText( tr2i18n( "&Cancel" ) );
    mCategories->header()->setLabel( 0, tr2i18n( "Category" ) );
    mButtonAdd->setText( tr2i18n( "A&dd" ) );
    mButtonModify->setText( tr2i18n( "&Modify" ) );
    mButtonRemove->setText( tr2i18n( "&Remove" ) );
}

void CategoryEditDialog_base::add()
{
    qWarning( "CategoryEditDialog_base::add(): Not implemented yet" );
}

void CategoryEditDialog_base::modify()
{
    qWarning( "CategoryEditDialog_base::modify(): Not implemented yet" );
}

void CategoryEditDialog_base::slotApply()
{
    qWarning( "CategoryEditDialog_base::slotApply(): Not implemented yet" );
}

void CategoryEditDialog_base::remove()
{
    qWarning( "CategoryEditDialog_base::remove(): Not implemented yet" );
}

void CategoryEditDialog_base::slotOk()
{
    qWarning( "CategoryEditDialog_base::slotOk(): Not implemented yet" );
}

#include "categoryeditdialog_base.moc"
