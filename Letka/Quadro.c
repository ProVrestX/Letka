#include "Quadro.h"

const double inf=0.000001;

int getParam(double *a, double *b, double *c){
    printf("Enter coof a, b, c: ");
    int cnt=0;

    while ( (cnt=scanf("%lf %lf %lf",a,b,c)) != 3){
        printf("Try one more\n");
        printf("Enter coof a, b, c: ");
        fflush(stdin);
    }

    return cnt;
}
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
void printOut(typeOut count_x, double x1, double x2){

    switch (count_x){
        case HAVE_ERR:
            printf("Err: a, b or c is no finite");
            break;
        case NO_ROOTS:
            printf("No roofs");
            break;
        case ONE_ROOT:
            printf("1 roof: %lf",x1);
            break;
        case TWO_ROOT:
            printf("2 roofs: %lf,%lf",x1,x2);
            break;
        case IS_LINEAR:
            printf("Linear: %lf",x1);
            break;
        case INF_ROOT:
            printf("So many...");
            break;
        default: break;
    }
}
