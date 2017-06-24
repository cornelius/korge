#ifndef MINIKDE_KLOCALE_H
#define MINIKDE_KLOCALE_H

#include <qstring.h>
#include <qdatetime.h>

class KCalendarSystem;

QString i18n(const char *text);
QString i18n(const char *hint, const char *text);
QString i18n(const char *text1, const char *textn, int num);

// Qt3's uic generates i18n( "msg", "comment" ) calls which conflict
// with our i18n method. we use uic -tr tr2i18n to redirect
// to the right i18n() function
inline QString tr2i18n(const char* message, const char* =0) {
  return i18n( message);
}

class KLocale
{
  public:
    KLocale();

    QString translate( const char *index ) const;
    QString translate( const char *index, const char *fallback) const;

    QString formatDate(const QDate &pDate, bool shortFormat = false) const;
    QString formatTime(const QTime &pTime, bool includeSecs = false) const;
    QString formatDateTime(const QDateTime &pDateTime) const;
    QString formatDateTime(const QDateTime &pDateTime,
                           bool shortFormat,
                           bool includeSecs = false) const;

    QDate readDate(const QString &str, bool* ok = 0) const;
    QDate readDate( const QString &intstr, const QString &fmt, bool* ok = 0) const;
    QTime readTime(const QString &str, bool* ok = 0) const;

    bool use12Clock() const;
    bool weekStartsMonday() const;
    int weekStartDay() const;
    
    QString weekDayName(int,bool=false) const;
    QString monthName(int,bool=false) const;

    QString country() const;

    QString dateFormat() const;
    QString dateFormatShort() const;
    QString timeFormat() const;

    void insertCatalogue ( const QString & );

    KCalendarSystem *calendar();

  private:
    QTime readTime(const QString &str, bool seconds, bool *ok) const;
    QDate readDate(const QString &str, bool shortFormat, bool *ok) const;

    KCalendarSystem *mCalendarSystem;
};

#endif
