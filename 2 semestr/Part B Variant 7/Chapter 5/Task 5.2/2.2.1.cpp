//Даны вещественные квадратные матрицы А, В порядка n.
//Составить функцию для получения матрицы С = А * В + B * A .
//описывая двумерный массив как одномерный, с расчетом смещения
//элемента массива по линейной формуле;

#include "2.2.1.h"

void make_task_2_2_1()
{
	int n;
	cout << "Enter the size of matrix(n): " << endl;
	cin >> n;
	vector <int> a (n * n, 0);
	vector <int> b (n * n, 0);

	cout << "A: " << endl;
	fill_matrix(a);
	output_matrix(a);

	cout << "B: " << endl;
	fill_matrix(b);
	output_matrix(b);

	cout << "A * B: " << endl;
	vector<int> c (n * n, 0);
	c = multiply_matrix(a, b);
	output_matrix(c);

	cout << "B * A: " << endl;
	vector<int> d (n * n, 0);
	d = multiply_matrix(b, a);
	output_matrix(d);

	cout << "A * B + B * A: " << endl;
	vector<int> result (n * n, 0);
	result = calculation_expression(a, b);
	output_matrix(result);
}

void fill_matrix(vector<int> &matrix)
{
	int n = sqrt(matrix.size());
	for (int i = 0; i < n * n; ++i)
	{
		matrix[i] = rand() % 20;
	}
}
vector<int> calculation_expression(vector<int> matrix1, vector<int> matrix2)
{
	int n = sqrt(matrix1.size());
	vector<int> matrix_result (n * n, 0);
	vector<int> matrix_AB (n * n, 0);
	vector<int> matrix_BA (n * n, 0);

	matrix_AB = multiply_matrix(matrix1, matrix2);
	matrix_BA = multiply_matrix(matrix2, matrix1);

	matrix_result = sum_matrix(matrix_AB, matrix_BA);
	return matrix_result;
}
vector<int> multiply_matrix(vector<int> matrix1, vector<int> matrix2)
{
	int n = sqrt(matrix1.size());
	vector<int> matrix_result (n * n, 0);
	for (int i = 0; i < n * n; ++i)
	{
		int j = i / n;
		for (int k = 0; k < n; ++k)
		{
			matrix_result[i] += (matrix1[j * n + k] * matrix2[k * n + (i % n)]);
		}
	}
	return matrix_result;
}
vector<int> sum_matrix(vector<int> matrix1, vector<int> matrix2)
{
	int n = sqrt(matrix1.size());
	vector<int> matrix_result (n * n, 0);
	for (int i = 0; i < n * n; ++i)
	{
		matrix_result[i] = matrix1[i] + matrix2[i];
	}
	return matrix_result;
}
void output_matrix(vector<int> &matrix)
{
	int n = sqrt(matrix.size());
	for (int i = 0; i < n * n; ++i)
	{
		if (i != 0 && i % n == 0)
		{
			cout << endl;
		}
		cout << matrix[i] << "\t";
	}
	cout << endl << endl;
}