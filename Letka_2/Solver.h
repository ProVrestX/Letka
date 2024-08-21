#ifndef SOLVER_H_INCLUDED
#define SOLVER_H_INCLUDED

#ifndef TYPEOUT_DEFINED
#define TYPEOUT_DEFINED
typedef enum {
    HAVE_ERR=-1,
    INDEFINITE=0,
    LINEAR=1,
    QUADR=2
} typeOut;
typedef enum {
    NO_ROOTS=0,
    ONE_ROOT=1,
    TWO_ROOTS=2,
    INF_ROOTS=3
} Count_Roofs;
/*typedef enum {
    HAVE_ERR=-1,
    NO_ROOTS=0,
    ONE_ROOT=1,
    TWO_ROOT=2,
    IS_LINEAR=3,
    INF_ROOT=10
} typeOut;*/
#endif

#ifndef RESULT_DEFINED
#define RESULT_DEFINED
typedef struct{
    typeOut type_result;
    Count_Roofs count_roofs;
    double x[2];
} Result;
#endif

Result solver(double a, double b, double c);

#endif // SOLVER_H_INCLUDED
