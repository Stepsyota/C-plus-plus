#pragma once

#include <iostream>
#include "BinaryTree.h"

using namespace std;

void make_task_2_7();
void form_array(int[], int);
void fill_array(int[], int);
void output_array(int[], int);
template <typename T>
void find_element(BinaryTree<T>);
template <typename T>
void output_tree(BinaryTree<T>);
template <typename T>
void find_max(BinaryTree<T>);
int* filter_array(int[], int);