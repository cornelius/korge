#ifndef MICRO_KCAL_CALENDARRESOURCES_H
#define MICRO_KCAL_CALENDARRESOURCES_H

#include "calendar.h"
#include "resourcecalendar.h"

namespace KCal {

class CalendarResources : public Calendar
{
  public:
    CalendarResourceManager *resourceManager() { return 0; }
};

}

#endif
