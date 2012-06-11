/*
 * g722_1 - a library for the G.722.1 and Annex C codecs
 *
 * table.c
 *
 * Adapted by Steve Underwood <steveu@coppice.org> from the reference
 * code supplied with ITU G.722.1, which is:
 *
 *   (C) 2004 Polycom, Inc.
 *   All rights reserved.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 */

/*! \file */

#if defined(HAVE_CONFIG_H)
#include <config.h>
#endif

#include <inttypes.h>
#include <stdlib.h>

#include "g722_1/g722_1.h"

#include "defs.h"
#include "tables.h"

const int16_t vector_dimension[NUM_CATEGORIES] =
{
    2,  2,  2,  4,  4,  5,  5,  1
};

const int16_t number_of_vectors[NUM_CATEGORIES] =
{
    10, 10, 10, 5,  5,  4,  4, 20
};
/* The last category isn't really coded with scalar quantization. */

const int16_t max_bin[NUM_CATEGORIES] =
{
    13, 9, 6, 4, 3, 2, 1, 1
};

const int16_t max_bin_plus_one_inverse[NUM_CATEGORIES] =
{
     2341,  3277,  4682,  6554,  8193, 10923, 16385, 16385
};

#if defined(G722_1_USE_FIXED_POINT)
const int16_t int_region_standard_deviation_table[REGION_POWER_TABLE_SIZE] =
{
        0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
        0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
        0,     0,     1,     1,     1,     1,     2,     3,     4,     6,
        8,    11,    16,    23,    32,    45,    64,    91,   128,   181,
      256,   362,   512,   724,  1024,  1448,  2048,  2896,  4096,  5793,
     8192, 11585, 16384, 23170,     0,     0,     0,     0,     0,     0,
        0,     0,     0,     0
};
#else
const float region_standard_deviation_table[REGION_POWER_TABLE_SIZE] =
{
    2.441406247570224e-04,
    3.452669826719395e-04,
    4.882812495545411e-04,
    6.905339654011486e-04,
    9.765624991900746e-04,
    1.381067930916839e-03,
    1.953124998542134e-03,
    2.762135862062757e-03,
    3.906249997408239e-03,
    5.524271724583683e-03,
    7.812499995464418e-03,
    1.104854345008369e-02,
    1.562499999222472e-02,
    2.209708690200003e-02,
    3.124999998704119e-02,
    4.419417380766535e-02,
    6.249999997926591e-02,
    8.838834762266132e-02,
    1.249999999688989e-01,
    1.767766952599839e-01,
    2.499999999585318e-01,
    3.535533905492901e-01,
    4.999999999585318e-01,
    7.071067811572251e-01,
    1.000000000000000e+00,
    1.414213562431740e+00,
    2.000000000165873e+00,
    2.828427125098059e+00,
    4.000000000663491e+00,
    5.656854250665278e+00,
    8.000000001990472e+00,
    1.131370850226887e+01,
    1.600000000530792e+01,
    2.262741700641438e+01,
    3.200000001326981e+01,
    4.525483401658204e+01,
    6.400000003184756e+01,
    9.050966804067060e+01,
    1.280000000743110e+02,
    1.810193360963542e+02,
    2.560000001698536e+02,
    3.620386722227349e+02,
    5.120000003821707e+02,
    7.240773445055215e+02,
    1.024000000849268e+03,
    1.448154689131149e+03,
    2.048000001868390e+03,
    2.896309378502505e+03,
    4.096000004076487e+03,
    5.792618757485434e+03,
    8.192000008832390e+03,
    1.158523751593169e+04,
    1.638400001902361e+04,
    2.317047503378509e+04,
    3.276800004076484e+04,
    4.634095007141347e+04,
    6.553600008696507e+04,
    9.268190015051374e+04,
    1.310720001848009e+05,
    1.853638003164007e+05,
    2.621440003913428e+05,
    3.707276006635486e+05,
    5.242880008261676e+05,
    7.414552013885899e+05
};
#endif

#if defined(G722_1_USE_FIXED_POINT)
const int16_t standard_deviation_inverse_table[REGION_POWER_TABLE_SIZE] =
{
    32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767,
    32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767,
    32767, 32767, 32767, 32767, 32767, 23170, 16384, 11585,  8192,  5793,
     4096,  2896,  2048,  1448,  1024,   724,   512,   362,   256,   181,
      128,    91,    64,    45,    32,    23,    16,    11,     8,     6,
        4,     3,     2,     1,     1,     1,     1,     0,     0,     0,
        0,     0,     0,     0
};
#else
const float standard_deviation_inverse_table[REGION_POWER_TABLE_SIZE] =
{
    4.096000004076488e+03,
    2.896309378502504e+03,
    2.048000001868390e+03,
    1.448154689131149e+03,
    1.024000000849268e+03,
    7.240773445055215e+02,
    5.120000003821708e+02,
    3.620386722227349e+02,
    2.560000001698537e+02,
    1.810193360963542e+02,
    1.280000000743110e+02,
    9.050966804067060e+01,
    6.400000003184756e+01,
    4.525483401658203e+01,
    3.200000001326982e+01,
    2.262741700641438e+01,
    1.600000000530793e+01,
    1.131370850226887e+01,
    8.000000001990474e+00,
    5.656854250665277e+00,
    4.000000000663491e+00,
    2.828427125098059e+00,
    2.000000000165873e+00,
    1.414213562431740e+00,
    1.000000000000000e+00,
    7.071067811572251e-01,
    4.999999999585318e-01,
    3.535533905492901e-01,
    2.499999999585318e-01,
    1.767766952599838e-01,
    1.249999999688989e-01,
    8.838834762266132e-02,
    6.249999997926592e-02,
    4.419417380766535e-02,
    3.124999998704120e-02,
    2.209708690200002e-02,
    1.562499999222472e-02,
    1.104854345008369e-02,
    7.812499995464418e-03,
    5.524271724583683e-03,
    3.906249997408239e-03,
    2.762135862062757e-03,
    1.953124998542134e-03,
    1.381067930916839e-03,
    9.765624991900747e-04,
    6.905339654011486e-04,
    4.882812495545411e-04,
    3.452669826719394e-04,
    2.441406247570224e-04,
    1.726334913216520e-04,
    1.220703123683871e-04,
    8.631674565366727e-05,
    6.103515617913153e-05,
    4.315837282325419e-05,
    3.051757808703478e-05,
    2.157918640983742e-05,
    1.525878904225187e-05,
    1.078959320402385e-05,
    7.629394520493171e-06,
    5.394796601564505e-06,
    3.814697259930213e-06,
    2.697398300558537e-06,
    1.907348629806920e-06,
    1.348699150167414e-06
};
#endif

#if defined(G722_1_USE_FIXED_POINT)
const int16_t step_size_inverse_table[NUM_CATEGORIES] =
{
    23167,
    16384,
    11585,
     8192,
     5793,
     4096,
     2896,
     2896
};
#else
/* The last category isn't really coded with scalar quantization. */
const float step_size[NUM_CATEGORIES] =
{
    0.3536f,
    0.5f,
    0.7071f,
    1.0f,
    1.4142f,
    2.0f,
    2.8284f,
    2.8284f
};

const float step_size_inverse_table[NUM_CATEGORIES] =
{
    2.82805443e+00,
    2.00000000e+00,
    1.41422713e+00,
    1.00000000e+00,
    7.07113564e-01,
    5.00000000e-01,
    3.53556782e-01,
    3.53556782e-01
};
#endif

#if defined(G722_1_USE_FIXED_POINT)
const int16_t int_dead_zone[NUM_CATEGORIES] =
{
     2457,  2703,  2949,  3195 , 3440,  3686,  4096,  4096
};

const int16_t int_dead_zone_low_bits[NUM_CATEGORIES] =
{
    2, 1, 0, 0, 3, 2, 0, 0
};
#else
const float dead_zone[NUM_CATEGORIES] =
{
    0.3f,
    0.33f,
    0.36f,
    0.39f,
    0.42f,
    0.45f,
    0.5f,
    0.5f
};
#endif

#if !defined(G722_1_USE_FIXED_POINT)
const float region_power_table[REGION_POWER_TABLE_SIZE] =
{
    5.96046448e-08,
    1.19209290e-07,
    2.38418579e-07,
    4.76837158e-07,
    9.53674316e-07,
    1.90734863e-06,
    3.81469727e-06,
    7.62939453e-06,
    1.52587891e-05,
    3.05175781e-05,
    6.10351562e-05,
    1.22070312e-04,
    2.44140625e-04,
    4.88281250e-04,
    9.76562500e-04,
    1.95312500e-03,
    3.90625000e-03,
    7.81250000e-03,
    1.56250000e-02,
    3.12500000e-02,
    6.25000000e-02,
    1.25000000e-01,
    2.50000000e-01,
    5.00000000e-01,
    1.00000000e+00,
    2.00000000e+00,
    4.00000000e+00,
    8.00000000e+00,
    1.60000000e+01,
    3.20000000e+01,
    6.40000000e+01,
    1.28000000e+02,
    2.56000000e+02,
    5.12000000e+02,
    1.02400000e+03,
    2.04800000e+03,
    4.09600000e+03,
    8.19200000e+03,
    1.63840000e+04,
    3.27680000e+04,
    6.55360000e+04,
    1.31072000e+05,
    2.62144000e+05,
    5.24288000e+05,
    1.04857600e+06,
    2.09715200e+06,
    4.19430400e+06,
    8.38860800e+06,
    1.67772160e+07,
    3.35544320e+07,
    6.71088640e+07,
    1.34217728e+08,
    2.68435456e+08,
    5.36870912e+08,
    1.07374182e+09,
    2.14748365e+09,
    4.29496730e+09,
    8.58993459e+09,
    1.71798692e+10,
    3.43597384e+10,
    6.87194767e+10,
    1.37438953e+11,
    2.74877907e+11,
    5.49755814e+11
};

const float region_power_table_boundary[REGION_POWER_TABLE_SIZE - 1] =
{
    8.42936956e-08,
    1.68587391e-07,
    3.37174782e-07,
    6.74349565e-07,
    1.34869913e-06,
    2.69739826e-06,
    5.39479652e-06,
    1.07895930e-05,
    2.15791861e-05,
    4.31583721e-05,
    8.63167443e-05,
    1.72633489e-04,
    3.45266977e-04,
    6.90533954e-04,
    1.38106791e-03,
    2.76213582e-03,
    5.52427163e-03,
    1.10485433e-02,
    2.20970865e-02,
    4.41941731e-02,
    8.83883461e-02,
    1.76776692e-01,
    3.53553385e-01,
    7.07106769e-01,
    1.41421354e+00,
    2.82842708e+00,
    5.65685415e+00,
    1.13137083e+01,
    2.26274166e+01,
    4.52548332e+01,
    9.05096664e+01,
    1.81019333e+02,
    3.62038666e+02,
    7.24077332e+02,
    1.44815466e+03,
    2.89630933e+03,
    5.79261865e+03,
    1.15852373e+04,
    2.31704746e+04,
    4.63409492e+04,
    9.26818984e+04,
    1.85363797e+05,
    3.70727594e+05,
    7.41455188e+05,
    1.48291038e+06,
    2.96582075e+06,
    5.93164150e+06,
    1.18632830e+07,
    2.37265660e+07,
    4.74531320e+07,
    9.49062640e+07,
    1.89812528e+08,
    3.79625056e+08,
    7.59250112e+08,
    1.51850022e+09,
    3.03700045e+09,
    6.07400090e+09,
    1.21480018e+10,
    2.42960036e+10,
    4.85920072e+10,
    9.71840143e+10,
    1.94368029e+11,
    3.88736057e+11
};
#endif

/*- End of file ------------------------------------------------------------*/
