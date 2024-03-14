//  Описать функцию, которая формирует список символов L, включив в
//  него по одному разу элементы, которые входят в один из списков
//  L1 и L2, но в то же время не входят в другой из них.

//	Выполнить задания 2.4, используя связанную динамическую структуру данных
//  «список» в виде массивов. Оценить асимптотическую сложность алгоритма.

#include <iostream>
#include <iomanip>

using namespace std;


struct LinkedList
{
	int size, counter;
	char* array;
	int* index_array;
	int index_start, index_end;

	LinkedList(int n = 10)
	{
		counter = 0;
		size = n;
		array = new char[size] {};
		index_array = new int[size] {};
		index_start = -1;
		index_end = -1;
		for (int i = 0; i < size - 1; ++i)
		{
			index_array[i] = i + 1;
		}
		index_array[size - 1] = -1;
	}
	~LinkedList()
	{
		delete[] array;
		delete[] index_array;
	}

	int get_size()
	{
		return (index_end - index_start);
	}


	void increase_list()
	{
		int new_size = size * 2;
		char* new_array = new char[new_size];
		int* new_index_array = new int[new_size];

		for (int i = 0; i < size; ++i)
		{
			new_array[i] = array[i];
			new_index_array[i] = index_array[i];
		}
		for (int i = size; i < new_size; ++i)
		{
			new_index_array[i] = i;
		}
		delete[] array;
		delete[] index_array;
		array = new_array;
		index_array = new_index_array;
		size = new_size;
	}
	void add_element(char data)
	{
		if (size <= counter)
		{
			cout << "Need a bigger array" << endl;
			increase_list();
		}
		if (index_start == -1)
		{
			index_start = 0;
		}
		array[counter] = data;
		index_array[counter] = counter;
		counter++;
		index_end = counter;
	}
	void fill_list(int size)
	{
		for (int i = 0; i < size; ++i)
		{
			add_element(rand() % 26 + 97);
		}
	}

	void delete_element(int index_to_delete)
	{
		if (index_to_delete < 0)
		{
			return;
		}
		else if (index_to_delete == index_start)
		{
			index_start++;
		}
		else
		{
			for (int j = index_to_delete; j < index_end; ++j)
			{
				array[j] = array[j + 1];
				index_array[j] = index_array[j + 1];
			}
			index_end--;
			index_array[index_end] = -1;
		}
	}
	void delete_similar_elements()
	{
		for (int i = index_start; i < index_end; ++i)
		{
			for (int j = index_start + 1; j <= index_end; ++j)
			{
				if (array[i] == array[j])
				{
					delete_element(j);
				}
			}
		}
	}
	void delete_all_similar_elements()
	{
		bool compare = 0;
		for (int i = index_start; i < index_end; ++i)
		{
			for (int j = index_end; j > i; --j)
			{
				if (array[i] == array[j])
				{
					delete_element(j);
					compare = 1;
					j++;
				}
			}
			if (compare)
			{
				delete_element(i);
				i--;
			}
			compare = 0;
		}
	}

	void insert_by_index(char data, int index)
	{
		int old_size = get_size();
		if (size <= get_size())
		{
			cout << "Need a bigger array" << endl;
			increase_list();
		}
		if (index >= get_size())
		{
			cout << "Incorrect index" << endl;
			return;
		}
		for (int i = old_size; i > index; --i)
		{
			array[i] = array[i - 1];
			index_array[i] = index_array[i - 1];
		}
		array[index] = data;
		index_array[index] = index;
		index_end++;
	}
	void search_element(char element)
	{
		for (int i = 0; i < counter; ++i)
		{
			if (element == array[i])
			{
				cout << "This element is located in " << i << " index\n";
				return;
			}
		}
		cout << "This element is not founded \n";
	}

	void output_list()
	{
		for (int i = index_start; i < index_end; ++i)
		{
			cout << array[i] << '\t';
		}
		cout << endl;
	}
};
void check(LinkedList&);
void merge_lists(LinkedList&, LinkedList&, LinkedList&, int);
void form_list(LinkedList&, LinkedList&, int);

int main()
{
	int size;
	do
	{
		cout << "Enter the size L1 and L2: ";
		cin >> size;
	} while (size < 2);

	LinkedList L1(size);
	L1.fill_list(size); // O(N)
	cout << setw(35) << right << "L1: \t"; // O(N)
	L1.output_list();

	LinkedList L2(size);
	L2.fill_list(size); // O(N)
	cout << setw(35) << right << "L2: \t";
	L2.output_list(); // O(N)

	form_list(L1, L2, size);

	// For check
	/*L1.output_list();
	L1.insert_by_index('k', 2);
	L1.insert_by_index('m', 1);
	L1.insert_by_index('f', 0);
	L1.output_list();*/

	//L1.output_list();
	//L1.search_element('q');

	return 0;
}


void form_list(LinkedList& L1, LinkedList& L2, int size)
{
	L1.delete_similar_elements(); // O(N^2)
	L2.delete_similar_elements(); // O(N^2)

	cout << endl << setw(35) << right << "L1 after delete similar elements:\t";
	L1.output_list(); // O(N)
	cout << setw(35) << right << "L2 after delete similar elements:\t";
	L2.output_list(); // O(N)

	LinkedList L(L1.get_size() + L2.get_size());
	merge_lists(L, L1, L2, size); // O(2N)
	cout << endl << setw(35) << right << "L after merge L1 and L2:\t";
	L.output_list(); // O(N)
	L.delete_all_similar_elements(); // O(N^2)
	cout << endl;
	cout << setw(35) << right << "Result L:\t";
	L.output_list(); // O(N)
	// O(3(N^2)) ???
}
void merge_lists(LinkedList& L, LinkedList& L1, LinkedList& L2, int size)
{
	L.index_start = L1.index_start;
	for (int i = L1.index_start; i < L1.get_size(); ++i)
	{
		L.array[i] = L1.array[i];
		L.index_array[i] = L1.index_array[i];
		L.counter++;
	}
	for (int j = L2.index_start; j < L2.get_size(); ++j)
	{
		L.array[j + L1.get_size()] = L2.array[j];
		L.index_array[j + L1.get_size()] = L2.index_array[j] + L1.get_size() + 1;
		L.counter++;
	}
	L.index_end = L1.get_size() + L2.get_size();
}