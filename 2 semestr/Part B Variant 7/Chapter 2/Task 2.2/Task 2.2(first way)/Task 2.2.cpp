//Даны вещественные квадратные матрицы А, В порядка n.
//Составить функцию для получения матрицы С = А * В + B * A .
//описывая двумерный массив как одномерный, с расчетом смещения
//элемента массива по линейной формуле;
#include <iostream>

using namespace std;

int* create_matrix(int);
int* sum_matrix(int*, int*, int);
int* multiply_matrix(int*, int*, int);
int* calculation_expression(int*, int*, int);
void fill_matrix(int*, int);
void delete_matrix(int*);
void output_matrix(int*, int);

int main()
{
	int n;
	cout << "Enter the size of matrix(n): " << endl;
	cin >> n;
	int* a;
	int* b;
	a = create_matrix(n);
	b = create_matrix(n);

	cout << "A: " << endl;
	fill_matrix(a, n);
	output_matrix(a, n);

	cout << "B: " << endl;
	fill_matrix(b, n);
	output_matrix(b, n);

	cout << "A * B: " << endl;
	int* c;
	c = create_matrix(n);
	c = multiply_matrix(a, b, n);
	output_matrix(c, n);

	cout << "B * A: " << endl;
	int* d;
	d = create_matrix(n);
	d = multiply_matrix(b, a, n);
	output_matrix(d, n);

	cout << "A * B + B * A: " << endl;
	int* result;
	result = create_matrix(n);
	result = calculation_expression(a, b, n);
	output_matrix(result, n);

	delete_matrix(a);
	delete_matrix(b);
	delete_matrix(c);
	delete_matrix(d);
	delete_matrix(result);
}

void fill_matrix(int* matrix, int n)
{
	for (int i = 0; i < n * n; ++i)
	{
		matrix[i] = rand() % 20;
	}
}
int* calculation_expression(int* matrix1, int* matrix2, int n)
{
	int* matrix_result;
	int* matrix_AB;
	int* matrix_BA;
	matrix_result = create_matrix(n);
	matrix_AB = create_matrix(n);
	matrix_BA = create_matrix(n);

	matrix_AB = multiply_matrix(matrix1, matrix2, n);
	matrix_BA = multiply_matrix(matrix2, matrix1, n);

	matrix_result = sum_matrix(matrix_AB, matrix_BA, n);
	delete_matrix(matrix_AB);
	delete_matrix(matrix_BA);
	return matrix_result;
}
int* multiply_matrix(int* matrix1, int* matrix2, int n)
{
	int* matrix_result;
	matrix_result = create_matrix(n);

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
int* sum_matrix(int* matrix1, int* matrix2, int n)
{
	int* matrix_result;
	matrix_result = create_matrix(n);
	for (int i = 0; i < n * n; ++i)
	{
		matrix_result[i] = matrix1[i] + matrix2[i];
	}
	return matrix_result;
}
int* create_matrix(int n)
{
	int* matrix;
	matrix = new int[n * n] {0};
	return matrix;
}
void delete_matrix(int* matrix)
{
	delete[] matrix;
}
void output_matrix(int* matrix, int n)
{
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