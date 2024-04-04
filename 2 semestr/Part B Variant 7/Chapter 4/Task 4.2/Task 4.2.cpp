// Объявить шаблон класса «Линейный список». Определить структуру класса и его методы.
//  В классе должны быть конструктор без параметров, конструктор с параметрами,
//  деструктор и всё что необходимо согласно «правилу пяти».

#include "Task 4.2.h"

int main()
{
    forward_list<char> L1(70);
    L1.fill_list();
    L1.output_list();
    L1.pop_similar_element();
    L1.output_list();

    forward_list<char> L2(70);
    L2.fill_list();
    L2.output_list();
    L2.pop_similar_element();
    L2.output_list();

    cout << "\n\n\n\n";
    forward_list<char> L3;
    L3.merge_lists(L1, L2);
    L3.output_list();
    L3.pop_all_similar_elements();
    L3.output_list();
}