#include "Solver.h"

const double inf=0.000001;

typeOut solver(double a, double b, double c, double *x1, double *x2){
    if ((isfinite(a)==0 || isfinite(b)==0 || isfinite(c))==0) return HAVE_ERR;

    if (fabs(a)<inf){

        if (fabs(b)<inf){
            if (fabs(c)<inf) return INF_ROOT;
            return NO_ROOTS;
        }

        *x1=(-c)/b;
        return IS_LINEAR;
    }

    double d=b*b-4*a*c;
    if (d<-inf) return NO_ROOTS;

    else if (fabs(d)<inf){
        *x1=(-b)/(2*a);
        *x2=*x1;
        return ONE_ROOT;
    }

    *x1=(-b+sqrt(d))/(2*a);
    *x2=(-b-sqrt(d))/(2*a);
    return TWO_ROOT;
}
