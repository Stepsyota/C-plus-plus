// Даны натуральное число n, действительные числа a(1), a(2), ..., a(2n).
// Получить a(1)a(2n) + a(2)a(2n−1) + ... + a(n)a(n + 1) .

#include "2.6.h"

using namespace std;

void make_task_2_6()
{
    int n = 0;
    do
    {
        cout << "Enter n:\n";
        cin >> n;
    } while (n < 1);

    list<double> L;
    fill_list(L, n * 2);
    cout << "List:\t"; output_list(L);
    calculate_amount(L);
}
void calculate_amount(list<double> list)
{
    auto current_forward = list.begin();
    auto current_back = list.rbegin();
    auto end_forward = list.end();
    auto end_back = list.rend();

    double amount = 0;
    cout << "Calculation:\n";
    for (int i = 0; i < list.size() / 2; ++i)
    {
        if (i + 1 != list.size() / 2)
        {
            cout << *current_forward << " * " << *current_back << " + ";
        }
        else
        {
            cout << *current_forward << " * " << *current_back << " = ";
        }
        amount += (*current_forward * *current_back);
        current_forward++;
        current_back++;
    }
    cout << amount << '\n';
}
void fill_list(list<double>& list, int n)
{
    for (int i = 0; i < n; ++i)
    {
        list.push_back((rand() % 100 + 1) / 10.0);
    }
}
void output_list(list<double> list)
{
    auto current = list.begin();
    auto end = list.end();

    while (current != end)
    {
        cout << *current << '\t';
        current++;
    }
    cout << endl;
}