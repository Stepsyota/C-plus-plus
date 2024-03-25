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
	} while (size < 3 || size % 2 != 0);

	const char* file_f = "file_f.bin\0";
	const char* file_g = "file_g.bin\0";

	fill_by_elements(file_f, size);
	cout << "File f:\t"; read_file(file_f);

	add_with_sort(file_f, file_g, size);
	cout << "File g:\t"; read_file(file_g);
}


void read_file(const char* file_name)
{
	ifstream file(file_name, ios:: binary);
	if (file.is_open())
	{
		int element;
		file.read(reinterpret_cast <char*> (&element), sizeof(int));
		while (!file.fail())
		{
			cout << element << '\t';
			file.read(reinterpret_cast <char*> (&element), sizeof(int));
		}
		cout << endl;
		file.close();
	}
	else
	{
		cout << "Can`t open" << endl;
		exit(1);
	}

}
void add_element(const char* file_name, int element)
{
	ofstream file(file_name, ios:: binary);
	if (file.is_open())
	{
		file.write(reinterpret_cast <char*> (&element), sizeof(int));
		file.close();
	}
	else
	{
		cout << "Can`t open" << endl;
		exit(2);
	}
}
void fill_by_elements(const char* file_name, int size)
{
	ofstream file(file_name, ios:: binary);
	if (file.is_open())
	{
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
			file.write(reinterpret_cast <char*> (&element), sizeof(int));
		}
		file.close();
	}
	else
	{
		cout << "Can`t open" << endl;
		exit(3);
	}
}
void form_files_odd_and_even(const char* file_main_name, const char* file_odd_name, const char* file_even_name)
{
	ifstream file_main(file_main_name, ios::binary);
	ofstream file_odd(file_odd_name, ios::binary);
	ofstream file_even(file_even_name, ios::binary);
	if (file_main.is_open() && file_odd.is_open() && file_even.is_open())
	{
		int element;
		file_main.read(reinterpret_cast <char*> (&element), sizeof(int));
		while (!file_main.fail())
		{
			if (element % 2 == 1)
			{
				file_odd.write(reinterpret_cast <char*> (&element), sizeof(int));
			}
			else
			{
				file_even.write(reinterpret_cast <char*> (&element), sizeof(int));
			}
			file_main.read(reinterpret_cast <char*> (&element), sizeof(int));
		}
		file_main.close();
		file_odd.close();
		file_even.close();
	}
	else
	{
		file_main.close();
		file_odd.close();
		file_even.close();
		cout << "Can`t open" << endl;
		exit(4);
	}
}
void add_with_sort(const char* file_name_f, const char* file_name_g, int size)
{
	ofstream file_g(file_name_g, ios::binary);
	if (!file_g.is_open())
	{
		cout << "Can`t open" << endl;
		exit(5);
	}

	const char* file_odd_name = "file_odd.bin";
	const char* file_even_name = "file_even.bin";

	form_files_odd_and_even(file_name_f, file_odd_name, file_even_name);
	ifstream file_odd(file_odd_name, ios::binary);
	ifstream file_even(file_even_name, ios::binary);

	if (!file_odd.is_open() && !file_even.is_open())
	{
		file_odd.close();
		file_even.close();
		file_g.close();
		cout << "Can`t open" << endl;
		exit(6);
	}

	cout << "Odd:\t";  read_file(file_odd_name);
	cout << "Even:\t";  read_file(file_even_name);
	int element;
	int number_of_iter_outer = 0, number_of_iter_inner = 2;
	if (size % 4 == 0)
	{
		number_of_iter_outer = size / 4;
	}
	else
	{
		number_of_iter_outer = size / 4 + 1;
	}

	for (int i = 0; i < number_of_iter_outer; ++i)
	{
		if (size % 4 != 0 && i == number_of_iter_outer - 1)
		{
			number_of_iter_inner = 1;
		}
		for (int j = 0; j < number_of_iter_inner; ++j)
		{
			file_even.read(reinterpret_cast <char*> (&element), sizeof(int));
			file_g.write(reinterpret_cast <char*> (&element), sizeof(int));
		}
		for (int j = 0; j < number_of_iter_inner; ++j)
		{
			file_odd.read(reinterpret_cast <char*> (&element), sizeof(int));
			file_g.write(reinterpret_cast <char*> (&element), sizeof(int));
		}
	}

	file_odd.close();
	file_even.close();
	file_g.close();
	remove(file_odd_name);
	remove(file_even_name);
}