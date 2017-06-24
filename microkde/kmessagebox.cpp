#include "kmessagebox.h"
#include "klocale.h"

#include <qmessagebox.h>

void KMessageBox::sorry( QWidget *parent, 
         const QString &text,
         const QString &caption, bool )
{
  QString cap = caption;

  if (cap.isEmpty()) {
    cap = i18n("Sorry");
  }

  QMessageBox::warning( parent, cap, text );
}

int KMessageBox::warningContinueCancel( QWidget *parent, 
              const QString &text,
              const QString &caption,
              const QString &buttonContinue, 
              const QString &dontAskAgainName,
              bool notify )
{
  QString cap = caption;

  if (cap.isEmpty()) {
    cap = i18n("Warning");
  }

  int result = QMessageBox::warning( parent, cap, text, i18n("Ok"),
                                     i18n("Cancel") );

  if ( result == 0 ) return KMessageBox::Continue;
  return KMessageBox::Cancel;
}

int KMessageBox::warningYesNoCancel( QWidget *parent, 
              const QString &text,
              const QString &caption,
              const QString &buttonYes, 
              const QString &buttonNo )
{
  QString cap = caption;

  if (cap.isEmpty()) {
    cap = i18n("Warning");
  }

  int result = QMessageBox::warning( parent, cap, text, i18n("Yes"), i18n("No"),
                                     i18n("Cancel") );

  if ( result == 0 ) return KMessageBox::Yes;
  else if ( result == 1 ) return KMessageBox::No;
  return KMessageBox::Cancel;
}

int KMessageBox::questionYesNo(QWidget *parent, 
                         const QString &text,
                         const QString &caption)
{
  QString cap = caption;

  if (cap.isEmpty()) {
    cap = i18n("Question");
  }

  int result = QMessageBox::warning( parent, cap, text, i18n("Yes"),
                                     i18n("No") );

  if ( result == 0 ) return KMessageBox::Yes;
  else return KMessageBox::No;
}

void KMessageBox::error( QWidget *parent, 
         const QString &text, 
         const QString &caption, bool notify )
{
  QString cap = caption;

  if (cap.isEmpty()) {
    cap = i18n("Error");
  }

  QMessageBox::critical( parent, cap, text );
}

void KMessageBox::information( QWidget *parent, 
                          const QString &text, 
                          const QString &caption,
                          const QString &, 
                          bool )
{
  QString cap = caption;

  if (cap.isEmpty()) {
    cap = i18n("Information");
  }

  QMessageBox::information( parent, cap, text );
}
