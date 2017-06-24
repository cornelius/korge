#ifndef SIMPLEALARMDAEMONAPPLET_H
#define SIMPLEALARMDAEMONAPPLET_H

#include <qpe/taskbarappletinterface.h>

class SimpleAlarmDaemon;
class ScreenshotApplet;

class SimpleAlarmDaemonApplet : public TaskbarAppletInterface
{
  public:
    SimpleAlarmDaemonApplet();
    virtual ~SimpleAlarmDaemonApplet();

    QRESULT queryInterface( const QUuid&, QUnknownInterface** );
    Q_REFCOUNT

    virtual QWidget *applet( QWidget *parent );
    virtual int position() const;

  private:
    SimpleAlarmDaemon *mApplet;
    ulong ref;
};

#endif
