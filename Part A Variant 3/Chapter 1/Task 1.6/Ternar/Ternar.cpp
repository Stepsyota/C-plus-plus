// Считая, что функции sin и cos применимы только к аргументам в диапазоне 
// [0, Pi / 2], вычислить y = cos(x) для любого заданного вещественного числа x
// (использовать формулы приведения).

#include <iostream>
#define _USE_MATH_DEFINES
#include <math.h>

using namespace std;

int main()
{
    double x, y, result;
    cout << "Input x: "; cin >> x;

    x = (x >= 0 && x <= M_PI_2) ? x = x : (x > M_PI_2) ? x = M_PI - x : x = x;
    y = cos(x);
    cout << "cos(" << x << ") = " << y << endl;
    return 0;
}