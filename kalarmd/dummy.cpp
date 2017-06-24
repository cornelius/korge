#include "dummy.h"

#include <libkcal/event.h>
#include <kprocess.h>

Dummy::Dummy()
{
  KCal::Event e;
  KProcess proc;
#if 1
  proc.start(KProcess::DontCare);
#endif
}
