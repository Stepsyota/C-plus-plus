//  Описать функцию, которая формирует список символов L, включив в
//  него по одному разу элементы, которые входят в один из списков
//  L1 и L2, но в то же время не входят в другой из них.

#include "2.4.h"

void make_task_2_4()
{
	size_t size = 0;
	do
	{
		cout << "Enter the size L1 and L2: ";
		cin >> size;
	} while (size < 2);

	forward_list<char> L1(size), L2(size);
	L1.fill_list();
	L2.fill_list();

	cout << setw(35) << right << "L1: ";
	L1.output_list();
	cout << setw(35) << right << "L2: ";
	L2.output_list();

	form_list(L1, L2);
	return;
}
void form_list(forward_list<char>& L1, forward_list<char>& L2)
{
	L1.pop_similar_element();
	L2.pop_similar_element();

	cout << setw(35) << right << "L1 after delete similar elements: ";
	L1.output_list();
	cout << setw(35) << right << "L2 after delete similar elements: ";
	L2.output_list();

	forward_list<char> L;
	L.merge_lists(L1, L2);
	cout << setw(35) << right << "L after merge L1 and L2: ";
	L.output_list();
	L.pop_all_similar_elements();
	cout << setw(35) << right << "Result L: ";
	L.output_list();
}