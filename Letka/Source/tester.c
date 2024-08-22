#include "stdio.h"
#include "math.h"

#include "tester.h"
#include "compare.h"

/*!
    @brief Compares the received roots with the expected

    @param result structure with equation data

    @return 1 if roots are equal, 0 if not
*/
int run_tester(Test_struct *result){
    if(result->equation->count_roots == NO_ROOTS) return 0;

    if((compare(result->equation->root1, result->root1) && compare(result->equation->root2, result->root2))
        || (compare(result->equation->root1, result->root2) && compare(result->equation->root2, result->root1))){
            return 1;
    }

    return 0;
}
