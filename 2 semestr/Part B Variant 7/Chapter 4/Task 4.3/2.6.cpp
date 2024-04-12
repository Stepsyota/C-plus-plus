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

    List<double> L;
    L.fill_list(2 * n);
    L.output_list();
    calc_expression(L);
    return;
}

template <typename T>
void calc_expression(List<T>& list)
{
    T result = 0;
    Node<T>* n = list.get_node(0);
    Node<T>* p = list.get_node(list.get_size());
    size_t number_of_iterations = list.get_size() / 2;
    for (size_t i = 0; i < number_of_iterations; ++i)
    {
        cout << n->data << " * " << p->data;
        if (i < number_of_iterations - 1)
        {
            cout << " + ";
        }
        result += n->data * p->data;
        n = n->next;
        p = p->prev;
    }
    cout << " = " << result << endl;
}