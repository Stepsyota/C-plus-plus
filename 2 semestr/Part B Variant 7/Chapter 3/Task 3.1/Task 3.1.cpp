//	Компоненты файла f – целые числа, причем четных чисел столько же,
//  сколько нечетных. Получить файл g из чисел исходного файла, в
//  котором записаны 2 четных числа, затем 2 нечетных т.д.

#include <iostream>
#include <fstream>

using namespace std;

void add_element(ostream&);
void fill_by_elements(ostream&, int);
void read_file(ifstream&);
void add_with_sort(ifstream&, ostream&);

int main()
{
	int size = 0;
	do {
		cout << "Enter the even size:\n";
		cin >> size;
	} while (size < 1 || size % 2 != 0);

	ofstream ofile_f("file_f.txt");

	if (!ofile_f)
	{
		cout << "Not open" << endl;
		return 1;
	}
	fill_by_elements(ofile_f, size);
	ofile_f.close();


	ifstream ifile_f("file_f.txt");
	if (!ifile_f)
	{
		cout << "error2" << endl;
		return 1;
	}
	read_file(ifile_f);
	ifile_f.close();

	ifile_f.open("file_f.txt");
	if (!ifile_f)
	{
		cout << "Not open" << endl;
		return 1;
	}
	ofstream ofile_g("file_g.txt");
	if (!ofile_g)
	{
		cout << "Not open" << endl;
		return 2;
	}
	add_with_sort(ifile_f, ofile_g);
	ifile_f.close();
	ofile_g.close();

	ifstream ifile_g("file_g.txt");
	if (!ifile_g)
	{
		cout << "Not open" << endl;
		return 3;
	}
	read_file(ifile_g);
	ifile_g.close();
}


void read_file(ifstream& infile)
{
	int element;
	infile >> element;                            
	while (!infile.fail())
	{
		cout << element << endl;
		infile >> element; 
	}
	cout << endl;
}
void add_element(ostream& file, int element)
{
	file << element << '\n';;
}
void fill_by_elements(ostream& file, int size)
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
		add_element(file, element);
	}
}
void add_with_sort(ifstream& file_f, ostream& file_g)
{
	while (!file_f.fail())
	{
		int element;
		file_f >> element;
		add_element(file_g, element);
	}
}