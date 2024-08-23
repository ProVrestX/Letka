#include "stdio.h"
#include "stdlib.h"
#include "math.h"
#include "string.h"

#include "types.h"
#include "In_Out.h"
#include "solver.h"
#include "tester.h"
#include "output_tester_result.h"

int main(int argc, char *argv[]) {
    Equation_Param quadr = {0, 0, 0, INDEFINITE, NO_ROOTS, 0, 0};
    Test_struct test_param = {&quadr, 0, 0, 0};
    int testEn = 0, number_test = 0, test_result = 0, cnt_right = 0, cnt_wrong = 0, num_test_wrong = 0;
    int num_right[100] = {}, num_wrong[100] = {};
    char file_line[256]="";
    FILE *file_input = NULL;

    int status = getFlags(argc, argv, &file_input, &testEn);
    if(status == -1) return -1;

    while(1){
        number_test++;
        printf("\n");
        if(getParam(file_input, &test_param, testEn) == -1) break;

        solver(&quadr);

        printOut(&quadr);

        test_result = run_tester(&test_param, testEn);

        if(test_result == -1) {
            num_wrong[cnt_wrong++] = number_test;
            if(num_test_wrong == 0) num_test_wrong = number_test;
            printf("Wrong!\n");
        }
        else if(test_result == 1) {
            num_right[cnt_right++] = number_test;
            printf("Right!\n");
        }

        if(file_input == NULL) break;
    }
    output_tester_result_console(num_right, cnt_right, num_wrong, cnt_wrong);
    //output_tester_result(test_result, num_test_wrong);
    return 0;
}

//******************************************

