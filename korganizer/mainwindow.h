#ifndef KORGE_MAINWINDOW_H
#define KORGE_MAINWINDOW_H

#include <qmainwindow.h>
#include <qtimer.h>

#include <libkcal/incidence.h>

#include "simplealarmclient.h"

class QAction;
class CalendarView;

namespace KCal {
class CalendarLocal;
}

using namespace KCal;

class MainWindow : public QMainWindow
{
    Q_OBJECT
  public:
    MainWindow( QWidget *parent = 0, const char *name = 0 );
    ~MainWindow();

  protected slots:  
    void about();

    void processIncidenceSelection( Incidence * );

    void importQtopia();
    
    void slotModifiedChanged( bool );
    
    void save();
    
  protected:
    QString defaultFileName();
    
    void enableIncidenceActions( bool );
    
  private:
    void initActions();
    void setDefaultPreferences();

    CalendarLocal *mCalendar;
    CalendarView *mView;

    QAction *mNewSubTodoAction;
    
    QAction *mShowAction;
    QAction *mEditAction;
    QAction *mDeleteAction;

    SimpleAlarmClient mAlarmClient;

    QTimer mSaveTimer;
};

#endif
