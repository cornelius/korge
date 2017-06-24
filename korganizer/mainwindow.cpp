#include <stdlib.h>

#include <qaction.h>
#include <qpopupmenu.h>
#include <qmessagebox.h>
#include <qfile.h>

#include <qpe/global.h>
#include <qpe/qpemenubar.h>
#include <qpe/qpetoolbar.h>
#include <qpe/resource.h>
#include <qpe/qpeapplication.h>

#include <libkcal/calendarlocal.h>

#include "calendarview.h"
#include "koviewmanager.h"
#include "kodialogmanager.h"
#include "koprefs.h"
#include "simplealarmclient.h"

using namespace KCal;

#include "mainwindow.h"

MainWindow::MainWindow( QWidget *parent, const char *name ) :
  QMainWindow( parent, name )
{
  kdDebug() << "MainWindow()::MainWindow()" << endl;

  setCaption("KOrganizer/E");
  
  setDefaultPreferences();

  mCalendar = new CalendarLocal();

  mView = new CalendarView( mCalendar, this );
  setCentralWidget( mView );

  QPEApplication::setStylusOperation( mView, QPEApplication::RightOnHold );

  initActions();

  mView->readSettings();

  if( QFile::exists( defaultFileName() ) ) {
    mView->openCalendar( defaultFileName() );
  }
  
  processIncidenceSelection( 0 );
  
  connect( mView, SIGNAL( incidenceSelected( Incidence * ) ),
           SLOT( processIncidenceSelection( Incidence * ) ) );
  connect( mView, SIGNAL( modifiedChanged( bool ) ),
           SLOT( slotModifiedChanged( bool ) ) );

  mAlarmClient.setCalendars( defaultFileName() );

  connect( &mSaveTimer, SIGNAL( timeout() ), SLOT( save() ) );

  kdDebug() << "MainWindow()::MainWindow() done" << endl;
}

MainWindow::~MainWindow()
{
  kdDebug() << "MainWindow()::~MainWindow()" << endl;

  save();

  mView->writeSettings();

  delete mCalendar;
}

void MainWindow::initActions()
{
  QPEMenuBar *menuBar = new QPEMenuBar( this );
//  QPEToolBar *toolBar = new QPEToolBar( this );
  
  QPopupMenu *viewMenu = new QPopupMenu( menuBar );
  
  QAction *action;
  QIconSet icon;
  
  icon = Resource::loadIconSet( "korganizer/whatsnext" );  
  action = new QAction( "view_whatsnext", icon, "What's Next", 0, viewMenu );
  action->addTo( viewMenu );
  connect( action, SIGNAL( activated() ),
           mView->viewManager(), SLOT( showWhatsNextView() ) );

  icon = Resource::loadIconSet( "korganizer/list" );  
  action = new QAction( "view_list", icon, "List", 0, viewMenu );
  action->addTo( viewMenu );
  connect( action, SIGNAL( activated() ),
           mView->viewManager(), SLOT( showListView() ) );

  icon = Resource::loadIconSet( "korganizer/xdays" );  
  action = new QAction( "view_xdays", icon, "Next Days", 0, viewMenu );
  action->addTo( viewMenu );
  connect( action, SIGNAL( activated() ),
           mView->viewManager(), SLOT( showNextXView() ) );

  icon = Resource::loadIconSet( "korganizer/day" );  
  action = new QAction( "view_day", icon, "Day", 0, viewMenu );
  action->addTo( viewMenu );
//  action->addTo( toolBar );
  connect( action, SIGNAL( activated() ),
           mView->viewManager(), SLOT( showDayView() ) );

  icon = Resource::loadIconSet( "korganizer/workweek" );  
  action = new QAction( "view_workweek", icon, "Work Week", 0, viewMenu );
  action->addTo( viewMenu );
  connect( action, SIGNAL( activated() ),
           mView->viewManager(), SLOT( showWorkWeekView() ) );

  icon = Resource::loadIconSet( "korganizer/week" );  
  action = new QAction( "view_week", icon, "Week", 0, viewMenu );
  action->addTo( viewMenu );
  connect( action, SIGNAL( activated() ),
           mView->viewManager(), SLOT( showWeekView() ) );

  icon = Resource::loadIconSet( "korganizer/month" );  
  action = new QAction( "view_month", icon, "Month", 0, viewMenu );
  action->addTo( viewMenu );
  connect( action, SIGNAL( activated() ),
           mView->viewManager(), SLOT( showMonthView() ) );

  icon = Resource::loadIconSet( "korganizer/todo" );  
  action = new QAction( "view_todo", icon, "Todo", 0, viewMenu );
  action->addTo( viewMenu );
  connect( action, SIGNAL( activated() ),
           mView->viewManager(), SLOT( showTodoView() ) );

  icon = Resource::loadIconSet( "korganizer/journal" );  
  action = new QAction( "view_journal", icon, "Journal", 0, viewMenu );
  action->addTo( viewMenu );
  connect( action, SIGNAL( activated() ),
           mView->viewManager(), SLOT( showJournalView() ) );

#if 0
  action = new QAction( "view_timespan", "Time Span", 0, viewMenu );
  action->addTo( viewMenu );
  connect( action, SIGNAL( activated() ),
           mView->viewManager(), SLOT( showTimeSpanView() ) );
#endif

  menuBar->insertItem( "View", viewMenu );


#if 0
  QPopupMenu *navigationMenu = new QPopupMenu( menuBar );
  
  action = new QAction( "go_previous", "Go Backward", 0, navigationMenu );
  action->addTo( navigationMenu );
  connect( action, SIGNAL( activated() ),
           mView, SLOT( goPrevious() ) );

  action = new QAction( "go_next", "Go Forward", 0, navigationMenu );
  action->addTo( navigationMenu );
  connect( action, SIGNAL( activated() ),
           mView, SLOT( goNext() ) );

  menuBar->insertItem( "Go", navigationMenu );
#endif


  QPopupMenu *actionMenu = new QPopupMenu( menuBar );

  icon = Resource::loadIconSet( "korganizer/newevent" );  
  action = new QAction( "new_event", icon, "New Event...", 0, actionMenu );
  action->addTo( actionMenu );
  connect( action, SIGNAL( activated() ),
           mView, SLOT( newEvent() ) );

  icon = Resource::loadIconSet( "korganizer/newtodo" );  
  action = new QAction( "new_todo", icon, "New Todo...", 0, actionMenu );
  action->addTo( actionMenu );
  connect( action, SIGNAL( activated() ),
           mView, SLOT( newTodo() ) );

  mNewSubTodoAction = new QAction( "new_subtodo", "New Sub-Todo...", 0,
                                   actionMenu );
  mNewSubTodoAction->addTo( actionMenu );
  connect( mNewSubTodoAction, SIGNAL( activated() ),
           mView, SLOT( newSubTodo() ) );

  actionMenu->insertSeparator();

  mShowAction = new QAction( "show_incidence", "Show...", 0, actionMenu );
  mShowAction->addTo( actionMenu );
  connect( mShowAction, SIGNAL( activated() ),
           mView, SLOT( showIncidence() ) );

  mEditAction = new QAction( "edit_incidence", "Edit...", 0, actionMenu );
  mEditAction->addTo( actionMenu );
  connect( mEditAction, SIGNAL( activated() ),
           mView, SLOT( editIncidence() ) );

  mDeleteAction = new QAction( "delete_incidence", "Delete...", 0, actionMenu );
  mDeleteAction->addTo( actionMenu );
  connect( mDeleteAction, SIGNAL( activated() ),
           mView, SLOT( deleteIncidence() ) );

  actionMenu->insertSeparator();

  action = new QAction( "purge_completed", i18n("Purge Completed"), 0,
                        actionMenu );
  action->addTo( actionMenu );
  connect( action, SIGNAL( activated() ), mView, SLOT( purgeCompleted() ) );

  icon = Resource::loadIconSet( "korganizer/search" );  
  action = new QAction( "search", icon, "Search...", 0, actionMenu );
  action->addTo( actionMenu );
  connect( action, SIGNAL( activated() ),
           mView->dialogManager(), SLOT( showSearchDialog() ) );

  icon = Resource::loadIconSet( "korganizer/today" );  
  action = new QAction( "go_today", icon, "Go to Today", 0, actionMenu );
  action->addTo( actionMenu );
  connect( action, SIGNAL( activated() ),
           mView, SLOT( goToday() ) );

#if 0
  actionMenu->insertSeparator();

  action = new QAction( "configure", "Configure...", 0, actionMenu );
  action->addTo( actionMenu );
  connect( action, SIGNAL( activated() ),
           mView, SLOT( edit_options() ) );
#endif

  actionMenu->insertSeparator();
  action = new QAction( "import_qtopia", "Import Qtopia Calendar", 0,
                        actionMenu );
  action->addTo( actionMenu );
  connect( action, SIGNAL( activated() ), SLOT( importQtopia() ) );

  menuBar->insertItem( "Actions", actionMenu );


  QPopupMenu *helpMenu = new QPopupMenu( menuBar );
  
  icon = Resource::loadIconSet( "korganizer/korganizer" );  
  action = new QAction( "about", icon, "About...", 0, helpMenu );
  action->addTo( helpMenu );
  connect( action, SIGNAL( activated() ),
           SLOT( about() ) );

  menuBar->insertItem( "Help", helpMenu );  

  menuBar->insertSeparator();

  QPixmap pix;
#if 0
  pix = Resource::loadPixmap( "korganizer/list" );  
  menuBar->insertItem( pix, mView->viewManager(), SLOT( showListView() ) );
#endif
  pix = Resource::loadPixmap( "korganizer/day" );  
  menuBar->insertItem( pix, mView->viewManager(), SLOT( showDayView() ) );

  pix = Resource::loadPixmap( "korganizer/workweek" );  
  menuBar->insertItem( pix, mView->viewManager(), SLOT( showWorkWeekView() ) );

  pix = Resource::loadPixmap( "korganizer/month" );
  menuBar->insertItem( pix, mView->viewManager(), SLOT( showMonthView() ) );

  pix = Resource::loadPixmap( "korganizer/todo" );
  menuBar->insertItem( pix, mView->viewManager(), SLOT( showTodoView() ) );

  pix = Resource::loadPixmap( "korganizer/newevent" );  
  menuBar->insertItem( pix, mView, SLOT( newEvent() ) );

  pix = Resource::loadPixmap( "korganizer/newtodo" );  
  menuBar->insertItem( pix, mView, SLOT( newTodo() ) );
}

void MainWindow::setDefaultPreferences()
{
  KOPrefs *p = KOPrefs::instance();
  
  p->mFullViewMonth = true;
  p->mTimeBarFont = QFont("helvetica",8);
  p->mMonthViewFont = QFont("helvetica",8);
  p->mAgendaViewFont = QFont("helvetica",10);
  p->mHolidayColor = QColor("#FF0000");
  p->mHighlightColor = QColor("#0000FF");
  p->mCompactDialogs = true;
  p->mVerticalScreen = true;
  p->mConfirm = true;
  p->mEnableQuickTodo = false;
}

void MainWindow::about()
{
  QMessageBox::information( this, "About KOrganizer/E",
      "KOrganizer/E 1.0.8 (Beta)\n"
      "(c) 2002,2003 Cornelius Schumacher\n"
      "Email: schumacher@kde.org" );
}

QString MainWindow::defaultFileName()
{
  return Global::applicationFileName( "korganizer", "mycalendar.ics" );
}

void MainWindow::processIncidenceSelection( Incidence *incidence )
{
  if ( !incidence ) {
    enableIncidenceActions( false );
    
    mNewSubTodoAction->setEnabled( false );

    return;
  }
  
  enableIncidenceActions( true );
  
  if ( incidence->type() == "Event" ) {
    mShowAction->setText( i18n("Show Event...") );
    mEditAction->setText( i18n("Edit Event...") );
    mDeleteAction->setText( i18n("Delete Event...") );

    mNewSubTodoAction->setEnabled( false );
  } else if ( incidence->type() == "Todo" ) {
    mShowAction->setText( i18n("Show Todo...") );
    mEditAction->setText( i18n("Edit Todo...") );
    mDeleteAction->setText( i18n("Delete Todo...") );

    mNewSubTodoAction->setEnabled( true );
  } else {
    mShowAction->setText( i18n("Show...") );
    mShowAction->setText( i18n("Edit...") );
    mShowAction->setText( i18n("Delete...") );

    mNewSubTodoAction->setEnabled( false );
  }
}

void MainWindow::enableIncidenceActions( bool enabled )
{
  mShowAction->setEnabled( enabled );
  mEditAction->setEnabled( enabled );
  mDeleteAction->setEnabled( enabled );
}

void MainWindow::importQtopia()
{
  QString datebook = Global::applicationFileName( "datebook", "datebook.xml");
  QString todolist = Global::applicationFileName( "todolist", "todolist.xml");
  QString categories = QString( getenv( "HOME" ) ) + "Settings/Categories.xml";
  mView->importQtopia( categories, datebook, todolist );
}

void MainWindow::slotModifiedChanged( bool changed )
{
  kdDebug() << "slotModifiedChanged: " << ( changed ? "true" : "false" )
            << endl;

  mSaveTimer.start( 1000 * 60, true ); // 1 minute
}

void MainWindow::save()
{
  kdDebug() << "MainWindow::save()" << endl;

  mView->saveCalendar( defaultFileName() );
}
