//образованный из чисел, встречающихся в исходной последовательности
//  более одного раза, по убыванию без повторений;

#include "2.1.h"

bool check_size(int);
bool check_choise(int);

void make_task_2_1()
{
	int size;
	cout << "Enter the size:\n";
	cin >> size;


	int choise;
	cout << "Choose a way:\n1. Rand\n2. Keyboard" << endl;
	cin >> choise;

	if (!check_choise && !check_size)
	{
		cout << "Error";
		return;
	}

	int max_size = pow(10, 4) + 1;
	int* index_array = new int[max_size] {0};
	int element;


	switch (choise)
	{
	case 1:
	{
		for (int i = 0; i < size; ++i)
		{
			element = rand() % size;
			cout << element << ' ';
			++index_array[element];
		}
		break;
	}
	case 2:
	{
		cout << "Enter numbers:\n";
		for (int i = 0; i < size; ++i)
		{
			cin >> element;
			++index_array[element];
		}
		break;
	}
	default:
	{
		cout << "Error";
		return;
	}
	}


	cout << endl;
	for (int i = max_size - 1; i > 0; --i)
	{
		if (index_array[i] > 1)
		{
			cout << i << ' ';
		}
	}

	delete[] index_array;
	return;
}

bool check_size(int size)
{
	if (size < 1 || size > pow(10, 9))
	{
		cout << "Error";
		return 0;
	}
	return 1;
}
bool check_choise(int choise)
{
	if (choise < 1 || choise > 2)
	{
		cout << "Error";
		return 0;
	}
}