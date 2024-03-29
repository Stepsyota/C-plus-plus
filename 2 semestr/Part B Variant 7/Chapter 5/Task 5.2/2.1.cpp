//образованный из чисел, встречающихся в исходной последовательности
//  более одного раза, по убыванию без повторений;

#include "2.1.h"

void make_task_2_1()
{
	int size = 0;
	do
	{
		cout << "Enter the size:\n";
		cin >> size;
	} while (size < 1);
	
	int choice = 0;
	do
	{
		cout << "Choose a way:\n1. Rand\n2. Keyboard" << endl;
		cin >> choice;
	} while (choice < 1 || choice > 2);
	

	int max_size = pow(10, 4) + 1;
	vector <int> index_array(max_size, 0);

	int element;


	switch (choice)
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
			cout << "Error with task 2.1";
			exit(1);
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
	cout << endl;
}