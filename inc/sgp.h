#ifndef SPMP_SGP_H
#define SPMP_SGP_H

#include "norad.h"
#include "norad_in.h"

void spmp_sgp_init( double *params, const tle_t *tle);
int spmp_sgp( const double tsince, const tle_t *tle, const double *params,
                                     double *pos, double *vel);

#endif