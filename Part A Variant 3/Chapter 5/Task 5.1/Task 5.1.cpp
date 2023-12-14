// В программах не использовать глобальные переменные.
// Выполнить задание 1.1, оформив его через функцию.

#include <iostream>
#define _USE_MATH_DEFINES
#include <math.h>

using namespace std;

double calc_numer(double a)
{
    return (sin(M_PI * pow(a, 2)) + log(pow(a,2)));
}

double calc_denom(double a)
{
    return sin(M_PI * pow(a, 2)) + sin(a) + log(pow(a, 2)) + pow(a,2) + pow(M_E, cos(a));
}

int main()
{
    double x;
    cout << "Input x: "; cin >> x;
    double y;
    y = calc_numer(x) / calc_denom(x);
    cout << "y = " << y;
    return 0;
}