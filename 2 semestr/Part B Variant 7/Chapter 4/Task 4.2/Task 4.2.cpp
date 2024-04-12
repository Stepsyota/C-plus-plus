// Объявить шаблон класса «Линейный список». Определить структуру класса и его методы.
//  В классе должны быть конструктор без параметров, конструктор с параметрами,
//  деструктор и всё что необходимо согласно «правилу пяти».

#include <iostream>
#include "Forward_list.h"
#include "2.4.h"

using namespace std;

int main()
{
    make_task_2_4();

    // For check all constructors and methods
    Forward_list<int> v1(10);
    v1.fill_list();
    cout << "v1:\t";    v1.output_list();
    cout << "Size v1: " << v1.get_size() << endl;
    cout << "Empty v1: " << v1.empty() << endl;
    cout << "Third elem: " << v1.get_node(3) << '\t' << v1.get_node(3)->data << endl;
    cout << "Head: " << v1.get_head() << '\t' << v1.get_head()->data << endl;
    v1.push_front(rand() % 1000 / 100.0);
    cout << "v1:\t";	 v1.output_list();
    v1.push_back(rand() % 1000 / 100.0);
    cout << "v1:\t";	 v1.output_list();
    v1.push_after(v1.get_node(2), rand() % 1000 / 100.0);
    cout << "v1:\t";	 v1.output_list();
    v1.pop_front();
    cout << "v1:\t";	 v1.output_list();
    v1.pop_after(v1.get_node(1));
    cout << "v1:\t";	 v1.output_list();


    Forward_list<int> v2(v1);
    cout << "v2:\t";    v2.output_list();

    Forward_list<int> v3 = move(v1);
    cout << "v3:\t";    v3.output_list();
    cout << "v1:\t";    v1.output_list();

    Forward_list<int> v4;
    v4 = v2;
    cout << "v4:\t";    v4.output_list();
    cout << "v2:\t";    v2.output_list();

    Forward_list<int> v5;
    v5 = move(v2);
    cout << "v5:\t";    v5.output_list();
    cout << "v2:\t";    v2.output_list();

    v5.find_element(97);
}