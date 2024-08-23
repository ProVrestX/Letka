#include "stdio.h"
#include "math.h"

#include "compare.h"


/*!
    @brief Function to compare two numbers

    @param num1 First number to compare
    @param num2 Second number to compare

    @return 1 if the numbers are equal, 0 if not
*/
int compare(double num1, double num2) {
    const double inf = 0.000001;
    if(fabs(num1 - num2) <= inf) return 1;
    return 0;
}
