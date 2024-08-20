#ifndef SOLVER_H_INCLUDED
#define SOLVER_H_INCLUDED

#include "stdio.h"
#include "math.h"

#ifndef TYPEOUT_DEFINED
#define TYPEOUT_DEFINED
typedef enum {
    HAVE_ERR=-1,
    NO_ROOTS=0,
    ONE_ROOT=1,
    TWO_ROOT=2,
    IS_LINEAR=3,
    INF_ROOT=10
} typeOut;
#endif

typeOut solver(double a, double b, double c, double *x1, double *x2);

#endif // SOLVER_H_INCLUDED
