//  Описать функцию, которая формирует список символов L, включив в
//  него по одному разу элементы, которые входят в один из списков
//  L1 и L2, но в то же время не входят в другой из них.

#include "2.4.h"

//void make_task_2_4()
//{
//	int size = 0;
//	do
//	{
//		cout << "Enter the size L1 and L2: ";
//		cin >> size;
//	} while (size < 2);
//
//	LinkedList L1, L2;
//	L1.fill_list(size);
//	L2.fill_list(size);
//
//	cout << setw(35) << right << "L1: ";
//	L1.output_list(); //O(N)
//	cout << setw(35) << right << "L2: ";
//	L2.output_list(); //O(N)
//
//	form_list(L1, L2);
//	return 0;
//
//	//O(N^3)
//}
//void form_list(LinkedList& L1, LinkedList& L2)
//{
//	L1.delete_similar_elements(); // O(N^3)
//	L2.delete_similar_elements(); // O(N^3)
//
//	cout << setw(35) << right << "L1 after delete similar elements: ";
//	L1.output_list(); // O(N)
//	cout << setw(35) << right << "L2 after delete similar elements: ";
//	L2.output_list(); // O(N)
//
//	LinkedList L;
//	L.merge_lists(L1, L2); // O(2(N^2))
//	cout << setw(35) << right << "L after merge L1 and L2: ";
//	L.output_list(); // O(N)
//	L.delete_all_similar_elements(); // O(N^3)
//	cout << setw(35) << right << "Result L: ";
//	L.output_list(); // O(N)
//}