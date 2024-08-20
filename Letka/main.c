#include "stdio.h"
#include "stdlib.h"
#include "math.h"
#include "In_Out.h"
#include "Solver.h"

int main() {
    double a=0, b=0, c=0;
    double x1=0,x2=0;

    getParam(&a,&b,&c);

    typeOut cnt = solver(a,b,c,&x1,&x2);

    printOut(cnt,x1,x2);
    return 0;
}

//******************************************

