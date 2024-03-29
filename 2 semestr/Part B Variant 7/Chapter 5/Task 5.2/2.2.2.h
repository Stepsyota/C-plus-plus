#pragma once

#include <iostream>
#include <vector>

using namespace std;

void make_task_2_2_2();

vector<vector<int>> create_matrix(int);
vector<vector<int>> sum_matrix(vector<vector<int>>, vector<vector<int>>);
vector<vector<int>> multiply_matrix(vector<vector<int>>, vector<vector<int>>);
vector<vector<int>> calculation_expression(vector<vector<int>>, vector<vector<int>>);
void fill_matrix(vector<vector<int>>&);
void output_matrix(vector<vector<int>>);