/****************************************************************************
** Form implementation generated from reading ui file 'filteredit_base.ui'
**
** Created: Sun Apr 6 11:35:55 2003
**      by:  The User Interface Compiler (uic)
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/
#include "filteredit_base.h"

#include <qbuttongroup.h>
#include <qcheckbox.h>
#include <qframe.h>
#include <qlistbox.h>
#include <qpushbutton.h>
#include <qradiobutton.h>
#include <qlayout.h>
#include <qvariant.h>
#include <qtooltip.h>
#include <qwhatsthis.h>

/* 
 *  Constructs a FilterEdit_base which is a child of 'parent', with the 
 *  name 'name' and widget flags set to 'f' 
 */
FilterEdit_base::FilterEdit_base( QWidget* parent,  const char* name, WFlags fl )
    : QWidget( parent, name, fl )
{
    if ( !name )
	setName( "FilterEdit_base" );
    resize( 289, 188 ); 
    setCaption( tr( "FilterEditor" ) );
    FilterEdit_baseLayout = new QVBoxLayout( this ); 
    FilterEdit_baseLayout->setSpacing( 0 );
    FilterEdit_baseLayout->setMargin( 0 );

    mCriteriaFrame = new QFrame( this, "mCriteriaFrame" );
    mCriteriaFrame->setFrameShape( QFrame::StyledPanel );
    mCriteriaFrame->setFrameShadow( QFrame::Raised );
    mCriteriaFrameLayout = new QVBoxLayout( mCriteriaFrame ); 
    mCriteriaFrameLayout->setSpacing( 6 );
    mCriteriaFrameLayout->setMargin( 11 );

    ButtonGroup1 = new QButtonGroup( mCriteriaFrame, "ButtonGroup1" );
    ButtonGroup1->setTitle( tr( "Categories" ) );
    ButtonGroup1->setColumnLayout(0, Qt::Vertical );
    ButtonGroup1->layout()->setSpacing( 0 );
    ButtonGroup1->layout()->setMargin( 0 );
    ButtonGroup1Layout = new QGridLayout( ButtonGroup1->layout() );
    ButtonGroup1Layout->setAlignment( Qt::AlignTop );
    ButtonGroup1Layout->setSpacing( 6 );
    ButtonGroup1Layout->setMargin( 11 );

    mCatHideCheck = new QRadioButton( ButtonGroup1, "mCatHideCheck" );
    mCatHideCheck->setText( tr( "Show all but selected" ) );

    ButtonGroup1Layout->addWidget( mCatHideCheck, 1, 0 );

    mCatShowCheck = new QRadioButton( ButtonGroup1, "mCatShowCheck" );
    mCatShowCheck->setText( tr( "Show only selected" ) );

    ButtonGroup1Layout->addWidget( mCatShowCheck, 0, 0 );

    mCatList = new QListBox( ButtonGroup1, "mCatList" );

    ButtonGroup1Layout->addMultiCellWidget( mCatList, 0, 2, 1, 1 );

    mCatEditButton = new QPushButton( ButtonGroup1, "mCatEditButton" );
    mCatEditButton->setText( tr( "Edit Selection..." ) );

    ButtonGroup1Layout->addWidget( mCatEditButton, 2, 0 );
    mCriteriaFrameLayout->addWidget( ButtonGroup1 );

    mRecurringCheck = new QCheckBox( mCriteriaFrame, "mRecurringCheck" );
    mRecurringCheck->setText( tr( "Hide recurring events" ) );
    mCriteriaFrameLayout->addWidget( mRecurringCheck );

    mCompletedCheck = new QCheckBox( mCriteriaFrame, "mCompletedCheck" );
    mCompletedCheck->setText( tr( "Hide completed to-dos" ) );
    mCriteriaFrameLayout->addWidget( mCompletedCheck );
    QSpacerItem* spacer = new QSpacerItem( 20, 20, QSizePolicy::Minimum, QSizePolicy::Expanding );
    mCriteriaFrameLayout->addItem( spacer );
    FilterEdit_baseLayout->addWidget( mCriteriaFrame );

    // signals and slots connections
}

/*  
 *  Destroys the object and frees any allocated resources
 */
FilterEdit_base::~FilterEdit_base()
{
    // no need to delete child widgets, Qt does it all for us
}

void FilterEdit_base::updateFilter()
{
    qWarning( "FilterEdit_base::updateFilter(): Not implemented yet!" );
}

