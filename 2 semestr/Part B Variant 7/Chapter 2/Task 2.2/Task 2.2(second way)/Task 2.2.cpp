//Даны вещественные квадратные матрицы А, В порядка n.
//Составить функцию для получения матрицы С = А * В + B * A .
//описывая двумерный массив как указатель на массив указателей.
#include <iostream>

using namespace std;

int** create_matrix(int);
int** sum_matrix(int**, int**, int);
int** multiply_matrix(int**, int**, int);
int** calculation_expression(int**, int**, int);
void fill_matrix(int**, int);
void delete_matrix(int**, int);
void output_matrix(int**, int);

int main()
{
	int n;
	cout << "Enter the size of matrix(n): " << endl;
	cin >> n;
	int** a;
	int** b;
	a = create_matrix(n);
	b = create_matrix(n);
	
	cout << "A: " << endl;
	fill_matrix(a, n);
	output_matrix(a, n);

	cout << "B: " << endl;
	fill_matrix(b, n);
	output_matrix(b, n);

	cout << "A * B: " << endl;
	int** c;
	c = create_matrix(n);
	c = multiply_matrix(a, b, n);
	output_matrix(c, n);

	cout << "B * A: " << endl;
	int** d;
	d = create_matrix(n);
	d = multiply_matrix(b, a, n);
	output_matrix(d, n);

	cout << "A * B + B * A: " << endl;
	int** result;
	result = create_matrix(n);
	result = calculation_expression(a, b, n);
	output_matrix(result, n);
	
	delete_matrix(a, n);
	delete_matrix(b, n);
	delete_matrix(c, n);
	delete_matrix(d, n);
	delete_matrix(result, n);
}

void fill_matrix(int** matrix, int n)
{
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			matrix[i][j] = rand() % 20;
		}
	}
}
int** calculation_expression(int** matrix1, int** matrix2, int n)
{
	int** matrix_result;
	int** matrix_AB;
	int** matrix_BA;
	matrix_result = create_matrix(n);
	matrix_AB = create_matrix(n);
	matrix_BA = create_matrix(n);

	matrix_AB = multiply_matrix(matrix1, matrix2, n);
	matrix_BA = multiply_matrix(matrix2, matrix1, n);

	matrix_result = sum_matrix(matrix_AB, matrix_BA, n);
	delete_matrix(matrix_AB, n);
	delete_matrix(matrix_BA, n);
	return matrix_result;
}
int** multiply_matrix(int** matrix1, int** matrix2, int n)
{
	int** matrix_result;
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
int** sum_matrix(int** matrix1, int** matrix2, int n)
{
	int** matrix_result;
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
int** create_matrix(int n)
{
	int** matrix;
	matrix = new int* [n] {0};
	for (int i = 0; i < n; ++i)
	{
		matrix[i] = new int[n] {0};
	}
	return matrix;
}
void delete_matrix(int** matrix, int n)
{
	for (int i = 0; i < n; ++i)
	{
		delete[] matrix[i];
	}
	delete[] matrix;
}
void output_matrix(int** matrix, int n)
{
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