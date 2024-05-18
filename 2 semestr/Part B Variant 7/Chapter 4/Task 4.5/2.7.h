#pragma once

#include <iostream>
#include "BinaryTree.h"
#include "BinaryTree.cpp"

using namespace std;

void make_task_2_7();

template <typename T>
T* filter_array(T[], int);

template <typename T>
void find_max_number_of_elements(BinaryTree<T>&);

template <typename T>
void fill_array(T[], int);

template <typename T>
void output_array(T[], int);

template <typename T>
void find_element(BinaryTree<T>&);

template <typename T>
void output_tree(BinaryTree<T>&);