// Найдите сумму первых n натуральных чисел, которые являются числами Фибоначчи.

#include <iostream>
using namespace std;

int main()
{
    int n, zapas;
    int fib = 0;
    int pred = 1;
    int sum = 0;

    cout << "Enter the quantity of Fibonacci numbers: ";
    cin >> n;

    if (n <= 1)
    {
        cout << "Enter the quantity of Fibonacci numbers greater than 1:";
        return 0;
    }

    for (int i = 2; i <= n; i++)
    {
        zapas = fib;
        fib = fib + pred;
        pred = zapas;
        sum = sum + fib;
    }
    cout << "The amount " << n << " numbers = " << sum;
    return 0;
}