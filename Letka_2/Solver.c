#include "stdio.h"
#include "math.h"
#include "Solver.h"

const double inf = 0.000001;

/*!
    \brief Solver quadratic equation
*/
Result solver(double a, double b, double c) {
    Result result_solver = {INDEFINITE,NO_ROOTS,0,0};

    if (isfinite(a) == 0 || isfinite(b) == 0 || isfinite(c) == 0) {     // if have infinity
        result_solver.type_result = HAVE_ERR;
        return result_solver;
    }

    if (fabs(a) < inf) {    // if coof a == 0, linear
        if (fabs(b) < inf) {    // if coof b == 0, not roofs
            if (fabs(c) < inf) {    // if coof c == 0, infinity roofs
                result_solver.count_roofs = INF_ROOTS;
                return result_solver;
            }
            result_solver.count_roofs = NO_ROOTS;
            return result_solver;
        }
        result_solver.type_result = LINEAR;
        result_solver.count_roofs = ONE_ROOT;
        result_solver.x[0] = (-c)/b;
        return result_solver;
    }

    result_solver.type_result = QUADR;      // if quadratic
    double d = b*b-4*a*c;
    if (d < -inf) {     // if D < 0, no roofs
        result_solver.count_roofs = NO_ROOTS;
        return result_solver;
    }
    else if (fabs(d) < inf){     // if D == 0, 1 roof
        result_solver.count_roofs = ONE_ROOT;
        result_solver.x[0] = (-b)/(2*a);
        result_solver.x[1] = result_solver.x[0];
        return result_solver;
    }
    result_solver.count_roofs = TWO_ROOTS;     // if D > 0, 2 roof
    result_solver.x[0] = (-b+sqrt(d))/(2*a);
    result_solver.x[1] = (-b-sqrt(d))/(2*a);
    return result_solver;
}
