/****************************************************************************
** Form implementation generated from reading ui file 'kofilterview_base.ui'
**
** Created: Sun Apr 6 11:35:57 2003
**      by:  The User Interface Compiler (uic)
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/
#include "kofilterview_base.h"

#include <qcheckbox.h>
#include <qcombobox.h>
#include <qframe.h>
#include <qpushbutton.h>
#include <qlayout.h>
#include <qvariant.h>
#include <qtooltip.h>
#include <qwhatsthis.h>

/* 
 *  Constructs a KOFilterView_base which is a child of 'parent', with the 
 *  name 'name' and widget flags set to 'f' 
 */
KOFilterView_base::KOFilterView_base( QWidget* parent,  const char* name, WFlags fl )
    : QWidget( parent, name, fl )
{
    if ( !name )
	setName( "KOFilterView_base" );
    resize( 166, 122 ); 
    setCaption( tr( "Form2" ) );
    KOFilterView_baseLayout = new QVBoxLayout( this ); 
    KOFilterView_baseLayout->setSpacing( 2 );
    KOFilterView_baseLayout->setMargin( 2 );

    Frame11 = new QFrame( this, "Frame11" );
    Frame11->setFrameShadow( QFrame::Raised );
    Frame11->setFrameShape( QFrame::StyledPanel );
    Frame11Layout = new QVBoxLayout( Frame11 ); 
    Frame11Layout->setSpacing( 6 );
    Frame11Layout->setMargin( 11 );

    mEnabledCheck = new QCheckBox( Frame11, "mEnabledCheck" );
    mEnabledCheck->setText( tr( "Filter enabled" ) );
    Frame11Layout->addWidget( mEnabledCheck );

    mSelectionCombo = new QComboBox( FALSE, Frame11, "mSelectionCombo" );
    Frame11Layout->addWidget( mSelectionCombo );
    KOFilterView_baseLayout->addWidget( Frame11 );

    mEditButton = new QPushButton( this, "mEditButton" );
    mEditButton->setText( tr( "Edit Filters" ) );
    KOFilterView_baseLayout->addWidget( mEditButton );
}

/*  
 *  Destroys the object and frees any allocated resources
 */
KOFilterView_base::~KOFilterView_base()
{
    // no need to delete child widgets, Qt does it all for us
}

