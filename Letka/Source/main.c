#include "stdio.h"
#include "stdlib.h"
#include "math.h"
#include "string.h"

#include "types.h"
#include "In_Out.h"
#include "solver.h"
#include "tester.h"

int main(int argc, char *argv[]) {
    Equation_Param quadr = {0, 0, 0, INDEFINITE, NO_ROOTS, 0, 0};
    Test_struct test_param = {&quadr, 0, 0};
    int count_test = 1, testEn = 0;
    FILE *file_input = NULL;

    int status = getFlags(argc, argv, &file_input, &count_test, &testEn);
    if(status == -1) return -1;

    for(count_test; count_test > 0; count_test--){
        printf("\n");
        getParam(file_input, &test_param, testEn);

        solver(&quadr);

        printOut(&quadr);

        if(testEn) {
            int res = run_tester(&test_param);
            printf(">result: %d\n", res);
        }
    }

    return 0;
}

//******************************************

