#include "stdio.h"
#include "math.h"

typedef enum {
    HAVE_ERR=-1,
    NO_ROOTS=0,
    ONE_ROOT=1,
    TWO_ROOT=2,
    IS_LINEAR=3,
    INF_ROOT=10
} typeOut;



int getParam(double *a, double *b, double *c);
typeOut solver(double a, double b, double c, double *x1, double *x2);
void printOut(typeOut count_x, double x1, double x2);
