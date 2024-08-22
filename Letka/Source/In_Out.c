#include "stdio.h"
#include "math.h"

#include "In_Out.h"


/*!
    @brief Check for flags from console

    @param argc count arguments from console
    @param args arguments from console
    @param file_input file to receive data
    @param testEn Enable test

    @return -1 if have error, 0 if count arguments == 1, 1 if successful
*/
int getFlags(int argc, char *args[], FILE **file_input, int *count_test, int *testEn){
    if(argc == 1) return 0;

    int pos_arg = 1;
    while(pos_arg < argc){

        if(strcmp(args[pos_arg], "-test") == 0 && *testEn == 0){
            *testEn = 1;
            printf("Test enabled");
        }

        else if(strcmp(args[pos_arg], "-file") == 0 && *file_input == NULL){
            pos_arg++;

            if(pos_arg >= argc || args[pos_arg][0] == '-') {
                printf("No file name\n");
                printf(" -file <name>");
                return -1;
            }

            *file_input = fopen(args[pos_arg], "r");
            if(*file_input == NULL) {
                printf("Can`t open file \"%s\"", args[pos_arg]);
                return -1;
            }

            printf("Open file \"%s\"", args[pos_arg]);
            fscanf(*file_input, "%d", count_test);
        }

        pos_arg++;
        printf("\n");
    }

    if(*file_input != NULL && *testEn == 0) {
        printf("Can`t start tester from file without '-test'");
        return -1;
    }

    return 1;
}

/*!
    @brief Input equation data to solve

    @param file_input file to receive data (if NULL, the input from console)
    @param quadr structure with equation data
    @param testEn Enable test
*/
void getParam(FILE *file_input, Test_struct *quadr, int testEn) {

    if(file_input == NULL) {
        printf("Enter coof a, b, c: ");

        while (scanf("%lf %lf %lf", &quadr->equation->a, &quadr->equation->b, &quadr->equation->c) != 3) {
            printf("Try one more\n");
            printf("Enter coof a, b, c: ");
            while(getchar() != '\n');
        }

        if(testEn){
            while(getchar() != '\n');
            printf("Enter roots x1, x2: ");
            while (scanf("%lf %lf", &quadr->root1, &quadr->root2) != 2) {
                printf("Try one more\n");
                printf("nter roots x1, x2: ");
                while(getchar() != '\n');
            }
        }

        printf("\n");
        return ;
    }

    else {
        fscanf(file_input, "%lf %lf %lf", &quadr->equation->a, &quadr->equation->b, &quadr->equation->c);
        if(testEn) fscanf(file_input, "%lf %lf", &quadr->root1, &quadr->root2);
        return ;
    }
}

/*!
    @brief Print result solver

    @param result_solver structure with equation data
*/
void printOut(Equation_Param *result_solver) {

    switch (result_solver->type_result) {

        case HAVE_ERR:
            printf("Err: a, b or c is no finite");
            break;

        case INDEFINITE:
            if(result_solver->count_roots == NO_ROOTS) printf("Err, no roofs");
            else printf("So many...");
            break;

        case LINEAR:
            printf("Linear:\n\t%lf",result_solver->root1);
            break;

        case QUADR:
            if(result_solver->count_roots == NO_ROOTS)
                printf("Quardatic, no roofs");
            else if(result_solver->count_roots == ONE_ROOT)
                printf("Quardatic, 1 roof:\n\t%lf", result_solver->root1);
            else
                printf("Quardatic, 2 roof:\n\t%lf,\n\t%lf", result_solver->root1, result_solver->root2);
            break;

        default: break;
    }

    printf("\n");
}
