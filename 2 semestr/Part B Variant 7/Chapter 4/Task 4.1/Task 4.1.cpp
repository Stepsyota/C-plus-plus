// Разработать класс «вектор», моделирующий математическое понятие «одномерный массив»
//  произвольного размера с возможностью изменения числа элементов.

#pragma once

#include <iostream>
#include "2.1.h"
#include "Vector.h"

using namespace std;

int main()
{
    make_task_2_1();

    // For check all methods and operators
    Vector<int> v0(5);
    cout << "Enter the size and the capacity and all elements of the sequence:\n";
    cin >> v0;
    cout << v0 << '\n';
    cout << "v0:\t";    v0.output_array();

    Vector<int> v1(7);
    cout << "v1:\t";    v1.output_array();
    v1.fill_random();
    cout << "v1:\t";    v1.output_array();
    cout << "Size v1: " << v1.get_size() << endl;
    cout << "Capacity v1: " << v1.get_capacity() << endl;
    v1.set_capacity(3);
    cout << "v1:\t";	 v1.output_array();
    v1.set_size(2);
    cout << "v1:\t";	 v1.output_array();

    Vector<int> v2(v1);
    cout << "v2:\t";    v2.output_array();

    Vector<int> v3 = v1;
    cout << "v3:\t";    v3.output_array();

    Vector<int> v4 = move(v1);
    cout << "v4:\t";    v4.output_array();
    cout << "v1:\t";    v1.output_array();

    Vector<int> v5;
    v5 = move(v2);
    cout << "v5:\t";    v5.output_array();
    cout << "v2:\t";    v2.output_array();

    v4.set_capacity(2);
    cout << "v4:\t" << "cap: " << v4.get_capacity() << '\t' << "size:" << v4.get_size() << '\n';
    v4.fill_random();
    cout << "v4:\t";    v4.output_array();
    return 0;
}