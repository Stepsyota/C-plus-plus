//  Описать функцию, которая формирует список символов L, включив в
//  него по одному разу элементы, которые входят в один из списков
//  L1 и L2, но в то же время не входят в другой из них.

#include "2.4.h"

void make_task_2_4()
{
	int size = 0;
	do
	{
		cout << "Enter the size L1 and L2: ";
		cin >> size;
	} while (size < 2);

	forward_list<char> L1, L2;
	fill_list(L1, size);
	fill_list(L2, size);

	cout << setw(35) << right << "L1: ";
	output_list(L1);
	cout << setw(35) << right << "L2: ";
	output_list(L2);

	form_list(L1, L2);
	return;
}
void fill_list(forward_list<char>& list, int size)
{
	for (int i = 0; i < size; ++i)
	{
		list.push_front(rand() % 26 + 97);
	}
}
void output_list(forward_list<char> list)
{
	auto current = list.begin();
	auto end = list.end();

	while (current != end)
	{
		cout << *current << '\t';
		current++;
	}
	cout << endl;
}
void delete_similar_element(forward_list<char>& list)
{
	auto current_1 = list.begin();
	auto current_1_prev = list.begin();

	while (current_1 != list.end())
	{
		auto current_2 = next(current_1);
		auto current_2_prev = current_1;
		bool delete_element = 0;
		while (current_2 != list.end())
		{
			if (*current_1 == *current_2 && next(current_1) != list.end())
			{
				current_2 = next(current_2);
				list.erase_after(current_2_prev);
				delete_element = 1;
				continue;
			}
			current_2_prev = current_2;
			current_2 = next(current_2);
		}
		current_1_prev = current_1;
		current_1 = next(current_1);
	}
}
void delete_all_similar_elements(forward_list<char>& list)
{
	auto current_1 = list.begin();
	auto current_1_prev = list.begin();

	while (current_1 != list.end())
	{
		auto current_2 = next(current_1);
		auto current_2_prev = current_1;
		bool delete_element = 0;
		while (current_2 != list.end())
		{
			if (*current_1 == *current_2 && next(current_1) != list.end())
			{
				current_2 = next(current_2);
				list.erase_after(current_2_prev);
				delete_element = 1;
				continue;
			}
			current_2_prev = current_2;
			current_2 = next(current_2);
		}
		if (delete_element)
		{
			if (current_1 == list.begin())
			{
				current_1 = next(current_1);
				current_1_prev = current_1;
				list.pop_front();
				continue;
			}
			else
			{
				current_1 = next(current_1);
				list.erase_after(current_1_prev);
				continue;
			}
		}
		current_1_prev = current_1;
		current_1 = next(current_1);
	}
}
forward_list<char> merge_lists(forward_list<char> list1, forward_list<char> list2)
{
	forward_list<char> result_list;
	auto current = list1.begin();
	auto end = list1.end();

	while (current != end)
	{
		result_list.push_front(*current);
		current++;
	}

	current = list2.begin();
	end = list2.end();

	while (current != end)
	{
		result_list.push_front(*current);
		current++;
	}

	return result_list;
}
void form_list(forward_list<char> list1, forward_list<char> list2)
{
	delete_similar_element(list1);
	delete_similar_element(list2);
	cout << setw(35) << right << "L1 after delete similar elements: ";
	output_list(list1);
	cout << setw(35) << right << "L2 after delete similar elements: ";
	output_list(list2);

	forward_list<char> result_list = merge_lists(list1, list2);
	cout << setw(35) << right << "L after merge L1 and L2: ";
	output_list(result_list);
	delete_all_similar_elements(result_list);
	cout << setw(35) << right << "Result L: ";
	output_list(result_list);
}