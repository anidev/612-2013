#ifndef COLOR_RANGE_H
#define COLOR_RANGE_H

#include <nivision.h>

enum colortype {
    RGB,HSL,HSV
};

static const colortype threshold_type=HSL;
static const int color1_low=152;
static const int color1_high=183;
static const int color2_low=126;
static const int color2_high=255;
static const int color3_low=21;
static const int color3_high=51;

static const MeasurementType criteria_type=IMAQ_MT_AREA;
static const int criteria_min=500;
static const int criteria_max=65535;

static const int cam_width=320;
static const int cam_height=240;

#endif
