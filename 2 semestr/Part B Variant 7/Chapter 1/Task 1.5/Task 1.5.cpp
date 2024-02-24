#include <iostream>
#include <math.h>
#include <iomanip>

#include "Methode.h"
using namespace std;


int main()
{
    double a = 0.4, b = 1.2;
    double epsilon = pow(10, -6);
    double s1 = 1, s2 = 4, delta_s = 0.5;
    double t1 = 0.4, t2 = 1.2, delta_t = 0.2;

    output_upper_part_table();
    output_line();
    double (*Func)(double, double, double){ calc_func };
    methode(Func, a, b, s1, s2, delta_s, t1, t2, delta_t, epsilon);
    output_line();
    return 0;
}