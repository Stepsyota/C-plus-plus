//образованный из чисел, встречающихся в исходной последовательности
//  более одного раза, по убыванию без повторений;

#include <iostream>
#include <math.h>
#include <cstdlib>
#include <ctime>

using namespace std;

bool check_length(int);
void output_array(int*, int);
void shift_element_left(int*, int, int&);
void add_element(int*&, int&, int);
void fill_array(int*&, int, int&, int, int&);
void output_cutted_array(int*, int); 
void sort_array(int*, int);



int main()
{
	int length = 0;
	int size = 1;
	cout << "Enter the length" << endl;
	cin >> length;
	if (check_length(length) == 0)
	{
		cout << "Invalid length";
		return 0;
	}

	int* array = new int[size];

	int choice = 0, indent = 0;
	cout << "Enter the choice:\n1.Random\n2.Keyboard" << endl;
	cin >> choice;
	switch (choice)
	{
	case 1:
	{
		int number = 0, sequence_element_counter = 0;
		cout << "Rand" << endl << "Str: " << '\t';
		srand(time(0));
		for (int i = 0; i < length; ++i)
		{
			number = rand() % 20;
			cout << number << '\t';
			fill_array(array, number, size, sequence_element_counter, indent);
			sequence_element_counter += 1;
		}
		break;
	}
	case 2:
	{
		int number = 0, sequence_element_counter = 0;
		cout << "Keyboard" << endl;
		for (int i = 0; i < length; ++i)
		{
			cin >> number;
			fill_array(array, number, size, sequence_element_counter, indent);
		}
		break;
	}
	default:
		break;
	}

	output_array(array, size);
	output_cutted_array(array, indent);
	sort_array(array, indent);
	cout << endl << "Sort: ";
	output_cutted_array(array, indent);
	delete[] array;
	
	return 0;
}

void sort_array(int* array, int indent)
{
	for (int i = 0; i < indent - 1; ++i)
	{
		for (int j = indent - 1; j > i; --j)
		{
			if (array[i] > array[i + 1])
			{
				swap(array[i], array[i + 1]);
			}
		}		
	}
}
bool check_length(int length)
{
	if (length > pow(10, 9))
	{
		cout << "Invalid length";
		return 0;
	}
	return 1;
}
void output_array(int* array, int size)
{
	cout << endl << "Arr: " << '\t';
	for (int i = 0; i < size; ++i)
	{
		cout << array[i] << '\t';
	}
}
void fill_array(int*& array, int number, int& size, int sequence_element_counter, int& indent)
{
	int repetition_element_counter = 0, index = 0, check = 1;

	if (sequence_element_counter == 0)
	{
		array[0] = number;
	}
	else
	{
		for (int j = 0; j < indent; ++j)
		{
			if (array[j] == number)
			{
				check = 0;
			}
		}
		if (check != 0)
		{
			for (int i = 0; i < size; ++i)
			{
				if (array[i] == number)
				{
					repetition_element_counter += 1;
					index = i;
				}
			}
			if (sequence_element_counter != 0)
			{
				if (repetition_element_counter == 0)
				{
					add_element(array, size, number);
				}
				if (repetition_element_counter > 0)
				{
					shift_element_left(array, index, indent);
				}
			}
		}
	}
}
void add_element(int*& array, int& size, int number)
{
	size += 1;
	int* new_array = new int[size];
	for (int i = 0; i < size - 1; ++i)
	{
		new_array[i] = array[i];
	}
	new_array[size - 1] = number;
	delete[] array;
	array = new_array;
}
void shift_element_left(int* array, int index, int& indent)
{
	swap(array[index], array[indent]);
	indent += 1;
}
void output_cutted_array(int* array, int indent)
{
	cout << endl << "Cut: " << '\t';
	for (int i = 0; i < indent; ++i)
	{
		cout << array[i] << '\t';
	}
}