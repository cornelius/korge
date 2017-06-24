#include <klocale.h>
/****************************************************************************
** Form implementation generated from reading ui file '/build/kde/cvs/korge/kdepim/libkdepim/categoryselectdialog_base.ui'
**
** Created: Sat Mar 29 21:46:05 2003
**      by: The User Interface Compiler ()
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#include "categoryselectdialog_base.h"

#include <qvariant.h>
#include <qheader.h>
#include <qlistview.h>
#include <qpushbutton.h>
#include <qlayout.h>
#include <qtooltip.h>
#include <qwhatsthis.h>

/* 
 *  Constructs a CategorySelectDialog_base as a child of 'parent', with the 
 *  name 'name' and widget flags set to 'f'.
 *
 *  The dialog will by default be modeless, unless you set 'modal' to
 *  TRUE to construct a modal dialog.
 */
CategorySelectDialog_base::CategorySelectDialog_base( QWidget* parent, const char* name, bool modal, WFlags fl )
    : QDialog( parent, name, modal, fl )

{
    if ( !name )
	setName( "CategorySelectDialog_base" );
    CategorySelectDialog_baseLayout = new QVBoxLayout( this, 11, 6, "CategorySelectDialog_baseLayout"); 

    mCategories = new QListView( this, "mCategories" );
    mCategories->addColumn( tr2i18n( "Category" ) );
    CategorySelectDialog_baseLayout->addWidget( mCategories );

    Layout12 = new QHBoxLayout( 0, 0, 6, "Layout12"); 

    mClear = new QPushButton( this, "mClear" );
    Layout12->addWidget( mClear );
    QSpacerItem* spacer = new QSpacerItem( 20, 20, QSizePolicy::Expanding, QSizePolicy::Minimum );
    Layout12->addItem( spacer );

    mButtonEdit = new QPushButton( this, "mButtonEdit" );
    Layout12->addWidget( mButtonEdit );
    CategorySelectDialog_baseLayout->addLayout( Layout12 );

    Layout11 = new QHBoxLayout( 0, 0, 6, "Layout11"); 

    mButtonHelp = new QPushButton( this, "mButtonHelp" );
    Layout11->addWidget( mButtonHelp );
    QSpacerItem* spacer_2 = new QSpacerItem( 20, 20, QSizePolicy::Expanding, QSizePolicy::Minimum );
    Layout11->addItem( spacer_2 );

    mApply = new QPushButton( this, "mApply" );
    Layout11->addWidget( mApply );

    mButtonOk = new QPushButton( this, "mButtonOk" );
    mButtonOk->setOn( FALSE );
    mButtonOk->setDefault( TRUE );
    Layout11->addWidget( mButtonOk );

    mButtonCancel = new QPushButton( this, "mButtonCancel" );
    Layout11->addWidget( mButtonCancel );
    CategorySelectDialog_baseLayout->addLayout( Layout11 );
    languageChange();
    resize( QSize(387, 385).expandedTo(minimumSizeHint()) );

    // signals and slots connections
    connect( mButtonCancel, SIGNAL( clicked() ), this, SLOT( reject() ) );
    connect( mButtonOk, SIGNAL( clicked() ), this, SLOT( slotOk() ) );
    connect( mClear, SIGNAL( clicked() ), this, SLOT( clear() ) );
    connect( mApply, SIGNAL( clicked() ), this, SLOT( slotApply() ) );

    // tab order
    setTabOrder( mCategories, mClear );
    setTabOrder( mClear, mButtonEdit );
    setTabOrder( mButtonEdit, mButtonHelp );
    setTabOrder( mButtonHelp, mApply );
    setTabOrder( mApply, mButtonOk );
    setTabOrder( mButtonOk, mButtonCancel );
}

/*
 *  Destroys the object and frees any allocated resources
 */
CategorySelectDialog_base::~CategorySelectDialog_base()
{
    // no need to delete child widgets, Qt does it all for us
}

/*
 *  Sets the strings of the subwidgets using the current
 *  language.
 */
void CategorySelectDialog_base::languageChange()
{
    setCaption( tr2i18n( "Select Categories" ) );
    mCategories->header()->setLabel( 0, tr2i18n( "Category" ) );
    mClear->setText( tr2i18n( "&Delete" ) );
    mButtonEdit->setText( tr2i18n( "&Edit Categories" ) );
    mButtonHelp->setText( tr2i18n( "&Help" ) );
    mApply->setText( tr2i18n( "&Apply" ) );
    mButtonOk->setText( tr2i18n( "&OK" ) );
    mButtonCancel->setText( tr2i18n( "&Cancel" ) );
}

void CategorySelectDialog_base::clear()
{
    qWarning( "CategorySelectDialog_base::clear(): Not implemented yet" );
}

void CategorySelectDialog_base::slotApply()
{
    qWarning( "CategorySelectDialog_base::slotApply(): Not implemented yet" );
}

void CategorySelectDialog_base::slotOk()
{
    qWarning( "CategorySelectDialog_base::slotOk(): Not implemented yet" );
}

#include "categoryselectdialog_base.moc"
