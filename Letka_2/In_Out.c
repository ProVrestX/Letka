#include "stdio.h"
#include "math.h"
#include "In_Out.h"

/*!
    \brief Input coof a, b and c in a*x2 + b*x + c = 0
*/
int getParam(double *a, double *b, double *c) {
    printf("Enter coof a, b, c: ");
    int cnt=0;

    while ( (cnt=scanf("%lf %lf %lf",a,b,c)) != 3) {
        printf("Try one more\n");
        printf("Enter coof a, b, c: ");
        fflush(stdin);
    }
    printf("\n");
    return cnt;
}

/*!
    \brief Output result solver
*/
void printOut(Result result_solver) {

    switch (result_solver.type_result) {
        case HAVE_ERR:
            printf("Err: a, b or c is no finite");
            break;
        case INDEFINITE:
            if(result_solver.count_roofs == NO_ROOTS) printf("Err, no roofs");
            else printf("So many...");
            break;
        case LINEAR:
            printf("Linear:\n\t%lf",result_solver.x[0]);
            break;
        case QUADR:
            if(result_solver.count_roofs == NO_ROOTS)
                printf("Quardatic, no roofs");
            else if(result_solver.count_roofs == ONE_ROOT)
                printf("Quardatic, 1 roof:\n\t%lf", result_solver.x[0]);
            else
                printf("Quardatic, 2 roof:\n\t%lf,\n\t%lf", result_solver.x[0], result_solver.x[1]);
            break;
        default: break;
    }
    printf("\n");
}
