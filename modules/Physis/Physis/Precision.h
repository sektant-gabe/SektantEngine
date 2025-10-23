#pragma once
#include <cfloat>

namespace SKT {

#if MORE_PRECISON

// The Engine can be compiled in single or double precision versions

// (Default) Defines SINGLE precision mode for any code that needs it compiled.
#define SINGLE_PRECISION

// Defines  a REAL NUMBER precision.
using real = float;

// Defines the max value for the real number.
#define REAL_MAX FLT_MAX

// Defines the precision of the sqrt operator.
#define real_sqrt sqrtf

// Defines the precision of the absolute magnitude operator.
#define real_abs fabsf

// Defines the precision of the sine operator.
#define real_sin sinf

// Defines the precision of the cosine operator.
#define real_cos cosf

// Defines the precision of the exponent operator.
#define real_exp expf

// Defines the precision of the power operator.
#define real_pow powf

// Defines the precision of the floating point modulo operator.
#define real_fmod fmodf

// Defines the number e on which 1+e  == 1
#define real_epsilon FLT_EPSILON

#define constexpr R_PI 3.14159f

#else

#define DOUBLE_PRECISION
using real = double;
#define REAL_MAX DBL_MAX
#define real_sqrt sqrt
#define real_abs fabs
#define real_sin sin
#define real_cos cos
#define real_exp exp
#define real_pow pow
#define real_fmod fmod
#define real_epsilon DBL_EPSILON
#define R_PI 3.14159265358979
#endif
}// namespace SKT
