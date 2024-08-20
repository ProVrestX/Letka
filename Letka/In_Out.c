#include "In_Out.h"



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

void printOut(typeOut count_x, double x1, double x2){

    switch (count_x){
        case HAVE_ERR:
            printf("Err: a, b or c is no finite");
            break;
        case NO_ROOTS:
            printf("No roofs");
            break;
        case ONE_ROOT:
            printf("1 roof:\n\t %lf",x1);
            break;
        case TWO_ROOT:
            printf("2 roofs:\n\t %lf,\n\t %lf",x1,x2);
            break;
        case IS_LINEAR:
            printf("Linear:\n\t\ %lf",x1);
            break;
        case INF_ROOT:
            printf("So many...");
            break;
        default: break;
    }
}
