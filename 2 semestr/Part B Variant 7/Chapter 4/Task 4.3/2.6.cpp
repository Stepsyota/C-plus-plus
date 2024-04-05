// Даны натуральное число n, действительные числа a(1), a(2), ..., a(2n).
// Получить a(1)a(2n) + a(2)a(2n−1) + ... + a(n)a(n + 1) .

#include "2.6.h"



void make_task_2_6()
{
    size_t n = 0;
    do
    {
        cout << "Enter n:\n";
        cin >> n;
    } while (n < 1);

    list<double> L;
    L.fill_list(n);
    L.output_list();
    cout << " = " << L.calc_expresion();
    return;
}