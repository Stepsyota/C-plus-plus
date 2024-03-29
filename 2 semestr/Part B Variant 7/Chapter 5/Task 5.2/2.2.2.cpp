////Даны вещественные квадратные матрицы А, В порядка n.
////Составить функцию для получения матрицы С = А * В + B * A .
////описывая двумерный массив как указатель на массив указателей.

#include "2.2.2.h"

void make_task_2_2_2()
{
	int n;
	cout << "Enter the size of matrix(n): " << endl;
	cin >> n;

	vector<vector<int>> a;
	vector<vector<int>> b;
	a = create_matrix(n);
	b = create_matrix(n);

	cout << "A: " << endl;
	fill_matrix(a);
	output_matrix(a);

	cout << "B: " << endl;
	fill_matrix(b);
	output_matrix(b);

	cout << "A * B: " << endl;
	vector<vector<int>> c;
	c = create_matrix(n);
	c = multiply_matrix(a, b);
	output_matrix(c);

	cout << "B * A: " << endl;
	vector<vector<int>> d;
	d = create_matrix(n);
	d = multiply_matrix(b, a);
	output_matrix(d);

	cout << "A * B + B * A: " << endl;
	vector<vector<int>> result;
	result = create_matrix(n);
	result = calculation_expression(a, b);
	output_matrix(result);
}

void fill_matrix(vector<vector<int>> &matrix)
{
	int n = matrix[0].size();
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			matrix[i][j] = rand() % 20;
		}
	}
}
vector<vector<int>> calculation_expression(vector<vector<int>> matrix1, vector<vector<int>> matrix2)
{
	int n = matrix1[0].size();
	vector<vector<int>> matrix_result;
	vector<vector<int>> matrix_AB;
	vector<vector<int>> matrix_BA;
	matrix_result = create_matrix(n);
	matrix_AB = create_matrix(n);
	matrix_BA = create_matrix(n);

	matrix_AB = multiply_matrix(matrix1, matrix2);
	matrix_BA = multiply_matrix(matrix2, matrix1);

	matrix_result = sum_matrix(matrix_AB, matrix_BA);
	return matrix_result;
}
vector<vector<int>> multiply_matrix(vector<vector<int>> matrix1, vector<vector<int>> matrix2)
{
	int n = matrix1[0].size();
	vector<vector<int>> matrix_result;
	matrix_result = create_matrix(n);
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			for (int k = 0; k < n; ++k)
			{
				matrix_result[i][j] += (matrix1[i][k] * matrix2[k][j]);
			}
		}
	}
	return matrix_result;
}
vector<vector<int>> sum_matrix(vector<vector<int>> matrix1, vector<vector<int>> matrix2)
{
	int n = matrix1[0].size();
	vector<vector<int>> matrix_result;
	matrix_result = create_matrix(n);
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			matrix_result[i][j] = matrix1[i][j] + matrix2[i][j];
		}
	}
	return matrix_result;
}
vector<vector<int>> create_matrix(int n)
{
	vector<vector<int>> matrix(n);
	for (int i = 0; i < n; ++i)
	{
		matrix[i] = vector<int> (n, 0);
	}
	return matrix;
}
void output_matrix(vector<vector<int>> matrix)
{
	int n = matrix[0].size();
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			cout << matrix[i][j] << "\t";
		}
		cout << endl;
	}
	cout << endl;
}