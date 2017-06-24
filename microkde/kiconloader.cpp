#include <qpe/resource.h>

#include "kiconloader.h"

QPixmap KIconLoader::loadIcon( const QString& name, KIcon::Group, int,
                               int, QString *, bool ) const
{
  return Resource::loadPixmap( "korganizer/" + name );
}

QString KIconLoader::iconPath( const QString &, int )
{
  return QString::null;
}

QPixmap BarIcon( const QString &name )
{
  return Resource::loadPixmap( "korganizer/" + name );
}

QPixmap DesktopIcon( const QString &name, int )
{
  return Resource::loadPixmap( "korganizer/" + name );
}

QPixmap SmallIcon( const QString &name )
{
  return Resource::loadPixmap( "korganizer/" + name );
}

QPixmap SmallIconSet( const QString &name )
{
  return Resource::loadPixmap( "korganizer/" + name );
}
