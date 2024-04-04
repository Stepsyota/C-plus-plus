// Разработать класс «вектор», моделирующий математическое понятие «одномерный массив»
//  произвольного размера с возможностью изменения числа элементов.

#include "Task 4.1.h"

int main()
{
    vector<int> v1(7);
    cout << "v1:\t";    v1.output_array();
    v1.fill_random();
    cout << "v1:\t";    v1.output_array();

    vector<int> v2(v1);
    cout << "v2:\t";    v2.output_array();

    vector<int> v3 = v1;
    cout << "v3:\t";    v3.output_array();

    vector<int> v4 = move(v1);
    cout << "v4:\t";    v4.output_array();
    cout << "v1:\t";    v1.output_array();

    vector<int> v5;
    v5 = move(v2);
    cout << "v5:\t";    v5.output_array();
    cout << "v2:\t";    v2.output_array();
    //cout << "\n\n\n";
    //make_task_2_1();
}