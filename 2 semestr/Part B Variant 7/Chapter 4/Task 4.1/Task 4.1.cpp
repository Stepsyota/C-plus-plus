// Разработать класс «вектор», моделирующий математическое понятие «одномерный массив»
//  произвольного размера с возможностью изменения числа элементов.

#pragma once

#include <iostream>
#include "2.1.h"
#include "Vector.h"

using namespace std;

int main()
{
    //make_task_2_1();

    // For check all methods and operators
    Vector<int> v0(1);
    cout << "Enter the size and the capacity and all elements of the sequence:\n";
    cin >> v0;
    Vector<int> v01;
    cout << v01 << '\n';
    cout << v01.empty() << endl;
    cout << "v01:\t";    v01.output_array();
    v01.push_back(100);
    cout << "v01:\t";    v01.output_array();
    v01.push_back(34);
    cout << "v01:\t";    v01.output_array();
    v01.push_back(44);
    cout << "v01:\t";    v01.output_array();
    v01.push_back(102);
    cout << "v01:\t";    v01.output_array();
    v01.push_back(256);
    cout << "v01:\t";    v01.output_array();
    v01.push_back(11);
    cout << "v01:\t";    v01.output_array();
    v01.pop_back();
    cout << "v01:\t";    v01.output_array();
    v01.pop_back();
    cout << "v01:\t";    v01.output_array();
    v01.pop_back();
    cout << "v01:\t";    v01.output_array();


    Vector<int> v02(7);
    v02.fill_random();
    cout << v02.empty() << endl;
    cout << "v02:\t";    v02.output_array();
    cout << v02.get_element_by_index(0) << ' ';
    cout << v02.get_element_by_index(1) << ' ';
    cout << v02.get_element_by_index(2) << ' ';
    cout << v02.get_element_by_index(3) << ' ';
    cout << v02.get_element_by_index(4) << ' ';
    cout << v02.get_element_by_index(5) << ' ';
    cout << v02.get_element_by_index(6) << ' ';
    cout << v02.get_element_by_index(7) << ' ';
    cout << v02.get_element_by_index(8) << ' ';
    v02.change_element_by_index(100, 3);
    cout << "v02:\t";    v02.output_array();
    v02.change_element_by_index(-99, 1);
    cout << "v02:\t";    v02.output_array();
    v02.change_element_by_index(5, 6);
    cout << "v02:\t";    v02.output_array();
    v02.change_element_by_index(1, 7);
    cout << "v02:\t";    v02.output_array();
    v02.change_element_by_index(1, 100);
    cout << "v02:\t";    v02.output_array();
    v02.change_element_by_index(1, -56);
    cout << "v02:\t";    v02.output_array();
    v02.push_after(100, 2);
    cout << "v02:\t";    v02.output_array();
    v02.push_after(50, 1);
    cout << "v02:\t";    v02.output_array();
    v02.push_after(25, 4);
    cout << "v02:\t";    v02.output_array();
    v02.push_after(10, 7);
    cout << "v02:\t";    v02.output_array();
    v02.push_after(5, 9);
    cout << "v02:\t";    v02.output_array();
    v02.pop_back();
    cout << "v02:\t";    v02.output_array();

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