// Объявить шаблон класса «Линейный список». Определить структуру класса и его методы.
//  В классе должны быть конструктор без параметров, конструктор с параметрами,
//  деструктор и всё что необходимо согласно «правилу пяти».

#include "Task 4.2.h"

int main()
{
    //make_task_2_4();

    // For check all constructors and methods
    forward_list<int> v1(10);
    v1.fill_list();
    cout << "v1:\t";    v1.output_list();
    forward_list<int> v2(v1);
    cout << "v2:\t";    v2.output_list();

    forward_list<int> v3 = move(v1);
    cout << "v3:\t";    v3.output_list();
    cout << "v1:\t";    v1.output_list();

    forward_list<int> v4;
    v4 = v2;
    cout << "v4:\t";    v4.output_list();
    cout << "v2:\t";    v2.output_list();

    forward_list<int> v5;
    v5 = move(v2);
    cout << "v5:\t";    v5.output_list();
    cout << "v2:\t";    v2.output_list();

    v5.find_element(97);
}