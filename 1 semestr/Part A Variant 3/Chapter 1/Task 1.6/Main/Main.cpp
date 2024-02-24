// Считая, что функции sin и cos применимы только к аргументам в диапазоне 
// [0, Pi / 2], вычислить y = cos(x) для любого заданного вещественного числа x
// (использовать формулы приведения).
#include <iostream>
#define _USE_MATH_DEFINES
#include <math.h>

using namespace std;

int main()
{
    double x, y;
    cout << "Input x: "; cin >> x;

    if (x >= 0 && x <= M_PI_2)
    {
        y = cos(x);
        cout << "cos(" << x << ") = " << y << endl;
    }
    else
    {
        // Если x не находится в диапазоне [0, Pi/2], используем формулы приведения
        if (x > M_PI_2)
        {
            x = M_PI - x;
        }
        // Используем свойство cos(x) = sin(pi/2 - x)
        y = sin(M_PI_2 - x);
        cout << "cos(" << x << ") = " << y << endl;
    }
    return 0;
}