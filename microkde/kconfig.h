#ifndef MINIKDE_KCONFIG_H
#define MINIKDE_KCONFIG_H

#include <qstring.h>
#include <qstringlist.h>
#include <qvaluelist.h>
#include <qcolor.h>
#include <qfont.h>
#include <qmap.h>
#include <qdatetime.h>

class KConfig
{
  public:
    KConfig( const QString & );
    ~KConfig();
  
    void setGroup( const QString & );
    
    QValueList<int> readIntListEntry( const QString & );
    int readNumEntry( const QString &, int def=0 );
    QString readEntry( const QString &, const QString &def=QString::null );
    QStringList readListEntry( const QString & );
    bool readBoolEntry( const QString &, bool def=false );
    QColor readColorEntry( const QString &, QColor * );
    QFont readFontEntry( const QString &, QFont * );
    QDateTime readDateTimeEntry( const QString &, const QDateTime *pDefault = 0 );
    
    void writeEntry( const QString &, QValueList<int> );
    void writeEntry( const QString &, int );
    void writeEntry( const QString &key , unsigned int value) { writeEntry( key, int( value ) ); }
    void writeEntry( const char *key , unsigned int value) { writeEntry( QString( key ), value ); }
    void writeEntry( const char *key, int value ) { writeEntry( QString( key ), value ); } 
    void writeEntry( const QString &, const QString & );
    void writeEntry( const char *key, const QString &value ) { writeEntry( QString( key ), value ); }
    void writeEntry( const QString &, const QStringList & );
    void writeEntry( const QString &, bool );
    void writeEntry( const char *key, bool value ) { writeEntry( QString( key ), value ); } 
    void writeEntry( const QString &, const QColor & );
    void writeEntry( const QString &, const QFont & );
    void writeEntry( const QString &, const QDateTime & );
    
    void load();
    void sync();

  private:  
    static QString mGroup;
    
    QString mFileName;
    
    QMap<QString,bool> mBoolMap;
    QMap<QString,QString> mStringMap;
    QMap<QString,QDateTime> mDateTimeMap;
    
    bool mDirty;
};

#endif
