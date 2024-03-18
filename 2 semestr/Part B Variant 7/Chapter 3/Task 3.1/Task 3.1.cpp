//	Компоненты файла f – целые числа, причем четных чисел столько же,
//  сколько нечетных. Получить файл g из чисел исходного файла, в
//  котором записаны 2 четных числа, затем 2 нечетных т.д.

#include <iostream>
#include <fstream>

using namespace std;

void add_element(const char*, int);
void fill_by_elements(const char*, int);
void read_file(const char*);
void add_with_sort(const char*, const char*, int);
void form_files_odd_and_even(const char*, const char*, const char*);

int main()
{
	int size = 0;
	do {
		cout << "Enter the even size: ";
		cin >> size;
	} while (size < 1 || size % 2 != 0);

	const char* file_f = "file_f.txt\0";
	const char* file_g = "file_g.txt\0";

	fill_by_elements(file_f, size);
	read_file(file_f);
	
	add_with_sort(file_f, file_g, size);
	read_file(file_g);
}


void read_file(const char* file_name)
 {
	ifstream file;
	file.open(file_name);
	if (!file)
	{
		cout << "Can`t open" << endl;
		exit(1);
	}
	int element;
	file >> element;                            
	while (!file.fail())
	{
		cout << element << endl;
		file >> element; 
	}
	cout << endl;
	file.close();
}
void add_element(const char* file_name, int element)
{
	ofstream file;
	file.open(file_name);
	if (!file)
	{
		cout << "Can`t open" << endl;
		exit(2);
	}
	file << element << '\n';
	file.close();
}
void fill_by_elements(const char* file_name, int size)
{
	ofstream file;
	file.open(file_name);
	if (!file)
	{
		cout << "Can`t open" << endl;
		exit(3);
	}
	int counter_even_now = 1, counter_odd_now = 1;
	int counter_even = size / 2, counter_odd = size / 2;
	for (int i = 0; i < size; ++i)
	{
		int element = rand() % 100;
		if (counter_even_now > counter_even)
		{
			do {
				element = rand() % 100;
			} while (element % 2 == 0);
		}
		else if (counter_odd_now > counter_odd)
		{
			do {
				element = rand() % 100;
			} while (element % 2 != 0);
		}
		if (element % 2 == 0)
		{
			counter_even_now++;
		}
		else
		{
			counter_odd_now++;
		}
		file << element << '\n';
	}
	file.close();
}
void form_files_odd_and_even(const char* file_main_name, const char* file_odd_name, const char* file_even_name)
{
	ifstream file_main;
	ofstream file_odd;
	ofstream file_even;
	file_main.open(file_main_name);
	file_odd.open(file_odd_name);
	file_even.open(file_even_name);
	int element;
	file_main >> element;
	while (!file_main.fail())
	{
		if (element % 2 == 1)
		{
			file_odd << element << '\n';
		}
		else
		{
			file_even << element << '\n';
		}
		file_main >> element;
	}
	file_main.close();
	file_odd.close();
	file_even.close();
}
void add_with_sort(const char* file_name_f, const char* file_name_g, int size)
{
	ofstream file2;
	file2.open(file_name_g);
	if (!file2)
	{
		cout << "Can`t open" << endl;
		exit(5);
	}

	const char* file_odd_name = "file_odd.txt";
	const char* file_even_name = "file_even.txt";
	
	form_files_odd_and_even(file_name_f, file_odd_name, file_even_name);
	ifstream file_odd;
	ifstream file_even;

	file_odd.open(file_odd_name);
	file_even.open(file_even_name);
	cout << "\nOdd\n";  read_file(file_odd_name);
	cout << "\nEven\n";  read_file(file_even_name);
	int element;
	for (int i = 0; i < size / 4; ++i)
	{
		for (int j = 0; j < 2; ++j)
		{
			file_even >> element;
			file2 << element << '\n';
		}
		for (int j = 0; j < 2; ++j)
		{
			file_odd >> element;
			file2 << element << '\n';
		}
	}

	file_odd.close();
	file_even.close();
	file2.close();
}