#include "stdio.h"
#include "stdlib.h"
#include "math.h"
#include "In_Out.h"
#include "Solver.h"

int main() {
    double a = 0, b = 0, c = 0;

    getParam(&a,&b,&c);

    Result cnt = solver(a, b, c);

    printOut(cnt);
    return 0;
}

//******************************************

