#ifndef DAYS_PAINT_H_
#define DAYS_PAINT_H_

#include <epd2in13.h>
#include <epdpaint.h>

class DaysPaint {
  private:
  public:
  DaysPaint();
  static void PaintDigitToFrameMemory(int digit, int num, epd::Epd *g_epd);
  static void PaintDaysToFrameMemory(int days, epd::Epd *g_epd);
};

#endif