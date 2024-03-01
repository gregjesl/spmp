#include "sgp.h"
#include "framework/test.h"
#include "tle_data.h"

int main(void)
{
    const char *tle_data[2] = {
      "1 88888U          80275.98708465  .00073094  13844-3  66816-4 0    87",
      "2 88888  72.8435 115.9689 0086731  52.6988 110.5714 16.05824518  1058" };

    double vel[3], pos[3], test_vel[3], test_pos[3]; /* Satellite position and velocity vectors */

    tle_t tle; /* Pointer to two-line elements set for satellite */

    /* Data for the prediction type and time period */
    double   ts = 0.;    /* Time since TLE epoch to start predictions */
    double   tf = 1440.; /* Time over which predictions are required  */
    double delt = 360.;  /* Time interval between predictions         */

    double tsince; /* Time since epoch (in minutes) */

    double sat_params[N_SAT_PARAMS], test_sat_params[N_SAT_PARAMS];

    /* Select the sgp or sdp TLE set for use below */
    TEST_FALSE(parse_elements( tle_data[0], tle_data[ 1], &tle));

    SGP_init( sat_params, &tle);
    spmp_sgp_init(test_sat_params, &tle);

    for( tsince = ts; tsince <= tf; tsince += delt)
    {
        SGP(tsince, &tle, sat_params, pos, vel);
        spmp_sgp(tsince, &tle, test_sat_params, test_pos, test_vel);
        for(size_t i = 0; i < 3; i++) {
          TEST_EQUAL(pos[i], test_pos[i]);
          TEST_EQUAL(vel[i], test_vel[i]);
        }
    }
}