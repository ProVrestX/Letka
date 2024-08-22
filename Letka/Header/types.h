#ifndef TYPES_H_INCLUDED
#define TYPES_H_INCLUDED

#ifndef TYPEOUT_DEFINED
#define TYPEOUT_DEFINED
typedef enum {
    HAVE_ERR=-1,
    INDEFINITE=0,
    LINEAR=1,
    QUADR=2
} typeEquation;
typedef enum {
    NO_ROOTS=0,
    ONE_ROOT=1,
    TWO_ROOTS=2,
    INF_ROOTS=3
} Count_Roots;
#endif

#ifndef EQUATION_PARAM
#define EQUATION_PARAM
typedef struct {
    double a, b, c;
    typeEquation type_result;
    Count_Roots count_roots;
    double root1, root2;
} Equation_Param;
#endif

#ifndef TEST_STRUCT
#define TEST_STRUCT
typedef struct {
    Equation_Param *equation;
    double root1, root2;
}Test_struct;
#endif

#endif // TYPES_H_INCLUDED
