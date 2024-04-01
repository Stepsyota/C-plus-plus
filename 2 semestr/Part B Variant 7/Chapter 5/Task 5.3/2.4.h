#pragma once

#include <iostream>
#include <iomanip>
#include <forward_list>

using namespace std;

void make_task_2_4();
void fill_list(forward_list<char>&, int);
void output_list(forward_list<char>);
void delete_similar_elements(forward_list<char>&);
forward_list<char> merge_lists(forward_list<char>, forward_list<char>);
void form_list(forward_list<char>, forward_list<char>);