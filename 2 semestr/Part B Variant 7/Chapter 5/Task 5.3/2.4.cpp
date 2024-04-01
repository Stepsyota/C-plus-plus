//  Описать функцию, которая формирует список символов L, включив в
//  него по одному разу элементы, которые входят в один из списков
//  L1 и L2, но в то же время не входят в другой из них.

#include "2.4.h"

Node::Node(char data, Node * l)
{
	symbol = data;
	next = l;
}

Node* LinkedList::get_node(int index)
{
	Node* l = head;
	for (int i = 0; i < index; ++i)
	{
		l = l->next;
	}
	return l;
}
char& LinkedList::operator [](int index)
{
	return get_node(index)->symbol;
}
int LinkedList::size() const
{
	return counter;
}
bool LinkedList::empty() const
{
	return counter == 0;
}
void LinkedList::push_front(int data)
{
	head = new Node(data, head);
	counter++;
	if (tail == nullptr)
	{
		tail = head;
	}
}
void LinkedList::push_back(int data)
{
	if (empty())
	{
		push_front(data);
	}
	else
	{
		push_after(tail, data);
	}
}
void LinkedList::push_after(Node* elem, int symbol)
{
	elem->next = new Node(symbol, elem->next);
	counter++;
	if (tail == elem)
	{
		tail = tail->next;
	}
}
void LinkedList::fill_list(int size)
{
	for (int i = 0; i < size; ++i)
	{
		push_front(rand() % 26 + 97);
	}
}
void LinkedList::delete_front()
{
	Node* next_head = head->next;
	delete head;
	head = next_head;
	counter--;
	if (head == nullptr)
	{
		tail = nullptr;
	}
}
void LinkedList::delete_after(Node* elem)
{
	Node* next_elem = elem->next;
	elem->next = next_elem->next;
	if (tail = next_elem)
	{
		tail = elem;
	}
	delete next_elem;
	counter--;

}
void LinkedList::delete_similar_elements()
{
	for (int i = 0; i < size() - 1; ++i)
	{
		for (int j = i + 1; j < size(); ++j)
		{
			if (get_node(i)->symbol == get_node(j)->symbol)
				// get node - O(N)
			{
				delete_after(get_node(j - 1));
			}
		}
	}
}
void LinkedList::delete_all_similar_elements()
{
	for (int i = 0; i < size() - 1; ++i)
	{
		for (int j = i + 1; j < size(); ++j)
		{
			if (get_node(i)->symbol == get_node(j)->symbol)
				// get node - O(N)
			{
				delete_after(get_node(i - 1));
				delete_after(get_node(j - 2));
			}
		}
	}
}
void LinkedList::output_list() const
{
	for (Node* l = head; l; l = l->next)
	{
		cout << l->symbol << '\t';
	}
	cout << endl;
}
void LinkedList::merge_lists(LinkedList& L1, LinkedList& L2)
{
for (int i = 0; i < L1.size(); ++i)
{
	push_back(L1[i]);
}
for (int j = 0; j < L2.size(); ++j)
{
	push_back(L2[j]);
}
}

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

	delete_similar_elements(L1);
	delete_similar_elements(L2);

	/*forward_list<char> L3;
	L3 = merge_lists(L1, L2);
	output_list(L3);*/
	cout << setw(35) << right << "L1 after del: ";
	output_list(L1);
	cout << setw(35) << right << "L2 after del: ";
	output_list(L2);
	//form_list(L1, L2);
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
void delete_similar_elements(forward_list<char>& list)
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
				current_2++;
				list.erase_after(current_2_prev);
				delete_element = 1;
				continue;
			}
			current_2_prev = current_2;
			current_2++;
			output_list(list);
		}
		if (delete_element)
		{
			if (current_1 == list.begin())
			{
				current_1++;
				current_1_prev = current_1;
				list.pop_front();
				continue;
			}
			else
			{
				current_1++;
				list.erase_after(current_1_prev);
				continue;
			}
		}
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

void form_list(LinkedList& L1, LinkedList& L2)
{
	L1.delete_similar_elements();
	L2.delete_similar_elements();

	cout << setw(35) << right << "L1 after delete similar elements: ";
	L1.output_list();
	cout << setw(35) << right << "L2 after delete similar elements: ";
	L2.output_list();

	LinkedList L;
	L.merge_lists(L1, L2);
	cout << setw(35) << right << "L after merge L1 and L2: ";
	L.output_list();
	L.delete_all_similar_elements();
	cout << setw(35) << right << "Result L: ";
	L.output_list();
}

auto find_last_element(forward_list<char>list) // ?!?
{
	auto current = list.begin();
	auto end = list.end();
	auto current_next = list.begin();
	while (current_next != end)
	{
		if (current_next != list.begin())
		{
			current++;
		}
		current_next++;
	}
	return current;
}