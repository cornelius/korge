/*
    This file is part of KOrganizer.
    Copyright (c) 2001 Cornelius Schumacher <schumacher@kde.org>

    This program is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 2 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program; if not, write to the Free Software
    Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.
*/

#include <qlayout.h>
#include <qtextbrowser.h>
#include <qtextcodec.h>
#include <qfileinfo.h>
#include <qlabel.h>

#include <kglobal.h>
#include <klocale.h>
#include <kdebug.h>
#include <kiconloader.h>
#include <kmessagebox.h>

#include <libkcal/calendar.h>

#ifndef KORG_NOPRINTER
#include "calprinter.h"
#endif
#include "koglobals.h"
#include "koprefs.h"
#include "koeventviewerdialog.h"

#include "kowhatsnextview.h"
using namespace KOrg;
#include "kowhatsnextview.moc"

void WhatsNextTextBrowser::setSource(const QString& n)
{
  kdDebug() << "WhatsNextTextBrowser::setSource(): " << n << endl;

  if (n.startsWith("event:")) {
    emit showIncidence(n);
    return;
  } else if (n.startsWith("todo:")) {
    emit showIncidence(n);
    return;
  } else {
    QTextBrowser::setSource(n);
  }
}

KOWhatsNextView::KOWhatsNextView(Calendar *calendar, QWidget *parent,
                                 const char *name)
  : KOrg::BaseView(calendar, parent, name)
{
  QLabel *dateLabel =
      new QLabel(KGlobal::locale()->formatDate(QDate::currentDate()),this);
  dateLabel->setMargin(2);
  dateLabel->setAlignment(AlignCenter);

  mView = new WhatsNextTextBrowser(this);
  connect(mView,SIGNAL(showIncidence(const QString &)),SLOT(showIncidence(const QString &)));

  mEventViewer = 0;

  QBoxLayout *topLayout = new QVBoxLayout(this);
  topLayout->addWidget(dateLabel);
  topLayout->addWidget(mView);
}

KOWhatsNextView::~KOWhatsNextView()
{
}

int KOWhatsNextView::maxDatesHint()
{
  return 0;
}

int KOWhatsNextView::currentDateCount()
{
  return 0;
}

QPtrList<Incidence> KOWhatsNextView::selectedIncidences()
{
  QPtrList<Incidence> eventList;

  return eventList;
}


void KOWhatsNextView::printPreview(CalPrinter *calPrinter, const QDate &fd,
                               const QDate &td)
{
#ifndef KORG_NOPRINTER
  calPrinter->preview(CalPrinter::Day, fd, td);
#endif
}

void KOWhatsNextView::updateView()
{
  KIconLoader kil("korganizer");
  QString *ipath = new QString();
  kil.loadIcon("korganizer",KIcon::NoGroup,32,KIcon::DefaultState,ipath);
  
  mText = "<table width=\"100%\">\n";
  mText += "<tr bgcolor=\"#3679AD\"><td><h1>";
  mText += "<img src=\"";
  mText += *ipath;
  mText += "\">";
  mText += "<font color=\"white\"> " + i18n("What's next?") + "</font></h1>";
  mText += "</td></tr>\n<tr><td>";
  
  QPtrList<Event> events = calendar()->events( QDate::currentDate(), true );
  if (events.count() > 0) {
    mText += "<p></p>";
    kil.loadIcon("appointment",KIcon::NoGroup,22,KIcon::DefaultState,ipath);
    mText += "<h2><img src=\"";
    mText += *ipath;
    mText += "\">";    
    mText += i18n("Events:") + "</h2>\n";
    mText += "<table>\n";
    Event *ev = events.first();
    while(ev) {
      if (!ev->recurrence()->doesRecur() || ev->recursOn( QDate::currentDate())) {
        appendEvent(ev);
      }
      ev = events.next();
    }
    mText += "</table>\n";
  }

  mTodos.clear();
  QPtrList<Todo> todos = calendar()->todos();
  if (todos.count() > 0) {
    kil.loadIcon("todo",KIcon::NoGroup,22,KIcon::DefaultState,ipath);
    mText += "<h2><img src=\"";
    mText += *ipath;
    mText += "\">";
    mText += i18n("To-Do:") + "</h2>\n";
    mText += "<ul>\n";
    Todo *todo = todos.first();
    while(todo) {
      if ( todo->hasDueDate() && todo->dtDue().date() == QDate::currentDate() )
		  appendTodo(todo);
      todo = todos.next();
    }
    bool gotone = false;
    int priority = 1;
    while (!gotone && priority<6) {
      todo = todos.first();
      while(todo) {
	if (!todo->isCompleted() && (todo->priority() == priority) ) {
	  appendTodo(todo);
	  gotone = true;
	}
	todo = todos.next();
      }
      priority++;
      kdDebug() << "adding the todos..." << endl;
    }
    mText += "</ul>\n";
  }

  int replys = 0;
  events = calendar()->events(QDate::currentDate(), QDate(2975,12,6));
  if (events.count() > 0) {
    Event *ev = events.first();
    while(ev) {
      Attendee *me = ev->attendeeByMails(KOPrefs::instance()->mAdditionalMails,KOPrefs::instance()->email());
      if (me!=0) {
        if (me->status()==Attendee::NeedsAction && me->RSVP()) {
          if (replys == 0) {
            mText += "<p></p>";
            kil.loadIcon("reply",KIcon::NoGroup,22,KIcon::DefaultState,ipath);
            mText += "<h2><img src=\"";
            mText += *ipath;
            mText += "\">";    
            mText += i18n("Events and To-Dos that need a reply:") + "</h2>\n";
            mText += "<table>\n";
          }
          replys++;
          appendEvent(ev,true);
        }
      }
      ev = events.next();
    }
  }
  todos = calendar()->todos();
  if (todos.count() > 0) {
    Todo *to = todos.first();
    while(to) {
      Attendee *me = to->attendeeByMails(KOPrefs::instance()->mAdditionalMails,KOPrefs::instance()->email());
      if (me!=0) {
        if (me->status()==Attendee::NeedsAction && me->RSVP()) {
          if (replys == 0) {
            mText += "<p></p>";
            kil.loadIcon("reply",KIcon::NoGroup,22,KIcon::DefaultState,ipath);
            mText += "<h2><img src=\"";
            mText += *ipath;
            mText += "\">";    
            mText += i18n("Events and To-Dos that need a reply:") + "</h2>\n";
            mText += "<table>\n";
          }
          replys++;
          appendEvent(to);
        }
      }
      kdDebug () << "check for todo-replys..." << endl;
      to = todos.next();
    }
  }
  if (replys > 0 ) mText += "</table>\n";


  mText += "</td></tr>\n</table>\n";

  kdDebug() << "KOWhatsNextView::updateView: text: " << mText << endl;
  mView->setText(mText);
}

void KOWhatsNextView::showDates(const QDate &, const QDate &)
{
  updateView();
}

void KOWhatsNextView::showEvents(QPtrList<Event>)
{
}

void KOWhatsNextView::changeEventDisplay(Event *, int action)
{
  switch(action) {
    case KOGlobals::EVENTADDED:
      break;
    case KOGlobals::EVENTEDITED:
      break;
    case KOGlobals::EVENTDELETED:
      break;
    default:
      kdDebug() << "KOWhatsNextView::changeEventDisplay(): Illegal action " << action << endl;
  }
}

void KOWhatsNextView::appendEvent(Incidence *ev, bool reply)
{
  kdDebug() << "KOWhatsNextView::appendEvent(): " << ev->uid() << endl;

  mText += "<tr><td><b>";
  if (!ev->doesFloat()) {
    if (ev->type()=="Event") {
      Event *event = static_cast<Event *>(ev);
      if (reply) mText += "on " + event->dtStartDateStr() + ": ";
      mText += event->dtStartTimeStr() + " - " + event->dtEndTimeStr();
    }
  }
  mText += "</b></td><td><a ";
  if (ev->type()=="Event") mText += "href=\"event:";
  if (ev->type()=="Todo") mText += "href=\"todo:";
  mText += ev->uid() + "\">";
  mText += ev->summary();
  mText += "</a></td></tr>\n";
}

void KOWhatsNextView::appendTodo(Incidence *ev)
{
  if ( mTodos.find( ev ) != mTodos.end() ) return;

  mTodos.append( ev );

  mText += "<li><a href=\"todo:" + ev->uid() + "\">";
  mText += ev->summary();
  mText += "</a></li>\n";
}

void KOWhatsNextView::createEventViewer()
{
  if (!mEventViewer) {
    mEventViewer = new KOEventViewerDialog(this);
  }
}

// TODO: Create this function in CalendarView and remove it from here
void KOWhatsNextView::showIncidence(const QString &uid)
{
  kdDebug() << "KOWhatsNextView::showIncidence(): " << uid << endl;

  if (uid.startsWith("event://")) {
    Event *event = calendar()->event(uid.mid(8));
    if (!event) return;
    createEventViewer();
    mEventViewer->setEvent(event);
  } else if (uid.startsWith("todo://")) {
    Todo *todo = calendar()->todo(uid.mid(7));
    if (!todo) return;
    createEventViewer();
    mEventViewer->setTodo(todo);
  }
  mEventViewer->show();
  mEventViewer->raise();
}
