#ifndef COLOR_RANGE_H
#define COLOR_RANGE_H

#include <nivision.h>

enum colortype {
    RGB,HSL,HSV
};

static const colortype threshold_type = HSL;
//color 1
static const unsigned int color1_low  = 152;
static const unsigned int color1_high = 183;
//color 2
static const unsigned int color2_low  = 126;
static const unsigned int color2_high = 255;
//color 3
static const unsigned int color3_low  = 21;
static const unsigned int color3_high = 51;

static const MeasurementType criteria_type = IMAQ_MT_AREA;
static const unsigned int criteria_min = 500;
static const unsigned int criteria_max = 65535;

#endif
