#include "stdio.h"
#include "math.h"

#include "solver.h"
#include "compare.h"


/*!
    @brief Solver quadratic equation

    @param quadr structure with equation data
*/
void solver(Equation_Param *quadr) {
    const double inf = 0.000001;
    double a = quadr->a, b = quadr->b, c = quadr->c;

    if (isfinite(a) == 0 || isfinite(b) == 0 || isfinite(c) == 0) {     // if have infinity
        quadr->type_result = HAVE_ERR;
        return ;
    }

    if (compare(a, 0)) {    // if coof a == 0, linear
        if (compare(b, 0)) {    // if coof b == 0, not roofs

            if (compare(c, 0)) {    // if coof c == 0, infinity roofs
                quadr->count_roots = INF_ROOTS;
                return ;
            }

            quadr->count_roots = NO_ROOTS;
            return ;
        }

        quadr->type_result = LINEAR;
        quadr->count_roots = ONE_ROOT;
        quadr->root1 = -c / b;
        return ;
    }

    quadr->type_result = QUADR;      // if quadratic
    if (compare(b, 0)) {    // if coof b == 0 and a!=0, two toots

        if (compare(c, 0)) {    // if coof c == 0 and a!=0, one root
            quadr->count_roots = ONE_ROOT;
            quadr->root1 = 0;
            return ;
        }

        if(-c * a > 0){
            quadr->count_roots = TWO_ROOTS;
            quadr->root1 = -sqrt(-c / a);
            quadr->root2 = sqrt(-c / a);
        }
        return ;
    }

    if (compare(c, 0)) {    // if coof c == 0 and a!=0, one root
        quadr->count_roots = TWO_ROOTS;
        quadr->root1 = 0;
        quadr->root2 = -b / a;
        return ;
    }

    double d = b*b-4*a*c;
    if (d < -inf) {     // if D < 0, no roofs
        quadr->count_roots = NO_ROOTS;
        return ;
    }

    else if (compare(d, 0)){     // if D == 0, 1 roof
        quadr->count_roots = ONE_ROOT;
        quadr->root1 = -b / (2 * a);
        quadr->root2 = quadr->root1;
        return ;
    }

    quadr->count_roots = TWO_ROOTS;     // if D > 0, 2 roof
    quadr->root1 = (-b - sqrt(d)) / (2 * a);
    quadr->root2 = (-b + sqrt(d)) / (2 * a);
    return ;
}


