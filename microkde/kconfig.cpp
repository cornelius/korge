#include <qfile.h>
#include <qtextstream.h>

#include "kdebug.h"

#include "kconfig.h"

QString KConfig::mGroup = "";
//QString KConfig::mGroup = "General";

KConfig::KConfig( const QString &fileName )
  : mFileName( fileName ), mDirty( false )
{
  kdDebug() << "KConfig::KConfig(): '" << fileName << "'" << endl;

  load();
}


KConfig::~KConfig()
{
  sync();
}

void KConfig::setGroup( const QString &group )
{
  kdDebug() << "KConfig::setGroup(): '" << group << "'" << endl;

  mGroup = group;

  if ( mGroup.right( 1 ) != "/" ) mGroup += "/";
}


QValueList<int> KConfig::readIntListEntry( const QString & )
{
  QValueList<int> l;
  return l;
}

int KConfig::readNumEntry( const QString &, int def )
{
  return def;
}

QString KConfig::readEntry( const QString &key, const QString &def )
{
  QMap<QString,QString>::ConstIterator it = mStringMap.find( mGroup + key );
  
  if ( it == mStringMap.end() ) {
    return def;
  }
  
  return *it;
}

QStringList KConfig::readListEntry( const QString & )
{
  return QStringList();
}

bool KConfig::readBoolEntry( const QString &key, bool def )
{
  QMap<QString,bool>::ConstIterator it = mBoolMap.find( mGroup + key );
  
  if ( it == mBoolMap.end() ) {
    return def;
  }
  
  return *it;
}

QColor KConfig::readColorEntry( const QString &, QColor *def )
{
  if ( def ) return *def;
  return QColor();
}

QFont KConfig::readFontEntry( const QString &, QFont *def )
{
  if ( def ) return *def;
  return QFont();
}

QDateTime KConfig::readDateTimeEntry( const QString &key, const QDateTime *def )
{
  QMap<QString,QDateTime>::ConstIterator it = mDateTimeMap.find( mGroup + key );
  
  if ( it == mDateTimeMap.end() ) {
    if ( def ) return *def;
    else return QDateTime();
  }

  return *it;
}

void KConfig::writeEntry( const QString &, QValueList<int> )
{
}

void KConfig::writeEntry( const QString &, int )
{
}

void KConfig::writeEntry( const QString &key, const QString &value )
{
  mStringMap.insert( mGroup + key, value );

  mDirty = true;
}

void KConfig::writeEntry( const QString &, const QStringList & )
{
}

void KConfig::writeEntry( const QString &key, bool value)
{
  mBoolMap.insert( mGroup + key, value );

  mDirty = true;
}

void KConfig::writeEntry( const QString &, const QColor & )
{
}

void KConfig::writeEntry( const QString &, const QFont & )
{
}

void KConfig::writeEntry( const QString &key, const QDateTime &dt )
{
  mDateTimeMap.insert( mGroup + key, dt );
}

void KConfig::load()
{
  kdDebug() << "KConfig::load(): " << mFileName << endl;

  QFile f( mFileName );
  if ( !f.open( IO_ReadOnly ) ) {
    kdDebug() << "KConfig::load(): Can't open file '" << mFileName << "'"
              << endl;
    return;
  }

  mBoolMap.clear();
  mStringMap.clear();
  
  QTextStream t( &f );
  
  QString line = t.readLine();

  while ( !line.isNull() ) {
    QStringList tokens = QStringList::split( ",", line );
    if ( tokens[0] == "bool" ) {
      bool value = false;
      if ( tokens[2] == "1" ) value = true;      
      mBoolMap.insert( tokens[1], value );
    } else if ( tokens[0] == "QString" ) {
      QString value = tokens[2];
      mStringMap.insert( tokens[1], value );
    } else if ( tokens[0] == "QDateTime" ) {
#if 0
      int year = tokens[2].toInt();
      QDateTime dt( QDate( year,
                           tokens[3].toInt(),
                           tokens[4].toInt() ),
                    QTime( tokens[5].toInt(), tokens[6].toInt(),
                           tokens[7].toInt() ) );
      mDateTimeMap.insert( tokens[1], dt );
#endif
    }
  
    line = t.readLine();
  }
}

void KConfig::sync()
{
  if ( !mDirty ) return;

  kdDebug() << "KConfig::sync(): " << mFileName << endl;

  QFile f( mFileName );
  if ( !f.open( IO_WriteOnly ) ) {
    kdDebug() << "KConfig::sync(): Can't open file '" << mFileName << "'"
              << endl;
    return;
  }

  QTextStream t( &f );
  
  QMap<QString,bool>::ConstIterator itBool;
  for( itBool = mBoolMap.begin(); itBool != mBoolMap.end(); ++itBool ) {
    t << "bool," << itBool.key() << "," << ( *itBool ? "1" : "0"  ) << endl;
  }

  QMap<QString,QString>::ConstIterator itString;
  for( itString = mStringMap.begin(); itString != mStringMap.end(); ++itString ) {
    t << "QString," << itString.key() << "," << (*itString ) << endl;
  }

  QMap<QString,QDateTime>::ConstIterator itDateTime;
  for( itDateTime = mDateTimeMap.begin(); itDateTime != mDateTimeMap.end(); ++itDateTime ) {
    QDateTime dt = *itDateTime;
    t << "QDateTime," << itDateTime.key() << ","
      << dt.date().year() << ","
      << dt.date().month() << ","
      << dt.date().day() << ","
      << dt.time().hour() << ","
      << dt.time().minute() << ","
      << dt.time().second() << endl;
  }

  f.close();

  mDirty = false;
}
