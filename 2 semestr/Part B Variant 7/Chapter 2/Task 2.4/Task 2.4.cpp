//  Описать функцию, которая формирует список символов L, включив в
//  него по одному разу элементы, которые входят в один из списков
//  L1 и L2, но в то же время не входят в другой из них.

#include <iostream>
#include <iomanip>

using namespace std;
struct Node
{
	char symbol;
	Node* next;

	Node(char data, Node* l)
	{
		symbol = data;
		next = l;
	}
};

struct LinkedList {
	Node *head, *tail;
	int counter;

	LinkedList()
	{
		head = nullptr;
		tail = nullptr;
		counter = 0;
	}

	~LinkedList()
	{
		while (!empty())
		{
			delete_front();
		}
	}


	Node* get_node(int index)
	{
		Node* l = head;
		for (int i = 0; i < index; ++i)
		{
			l = l->next;
		}
		return l;
	}
	char& operator [](int index)
	{
		return get_node(index)->symbol;
	}

	int size() const
	{
		return counter;
	}

	bool empty() const
	{
		return counter == 0;
	}

	void push_front(int data)
	{
		head = new Node(data, head);
		counter++;
		if (tail == nullptr)
		{
			tail = head;
		}
	}
	void push_back(int data)
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
	void push_after(Node* elem, int symbol)
	{
		elem->next = new Node(symbol, elem->next);
		counter++;
		if (tail == elem)
		{
			tail = tail->next;
		}
	}
	void fill_list(int size)
	{
		for (int i = 0; i < size; ++i)
		{
			push_front(rand() % 26 + 97);
		}
	}

	void delete_front()
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
	void delete_after(Node* elem)
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
	void delete_similar_elements()
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

	void output_list() const
	{
		for (Node* l = head; l; l = l->next)
		{
			cout << l->symbol << '\t';
		}
		cout << endl;
	}
	void merge_lists(LinkedList& L1, LinkedList& L2)
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
};

void form_list(LinkedList&, LinkedList&);

int main()
{
	int size = 0;
	do
	{
		cout << "Enter the size L1 and L2: ";
		cin >> size;
	} while (size < 2);

	LinkedList L1, L2;
	L1.fill_list(size);
	L2.fill_list(size);

	cout << setw(35) << right << "L1: ";
	L1.output_list(); //O(N)
	cout << setw(35) << right << "L2: ";
	L2.output_list(); //O(N)

	form_list(L1, L2);
	return 0;

	//O(N^3)
}

void form_list(LinkedList& L1, LinkedList& L2)
{
	L1.delete_similar_elements(); // O(N^3)
	L2.delete_similar_elements(); // O(N^3)

	cout << setw(35) << right << "L1 after delete similar elements: ";
	L1.output_list(); // O(N)
	cout << setw(35) << right << "L2 after delete similar elements: ";
	L2.output_list(); // O(N)

	LinkedList L;
	L.merge_lists(L1, L2); // O(2(N^2))
	cout << setw(35) << right << "L after merge L1 and L2: ";
	L.output_list(); // O(N)
	L.delete_similar_elements(); // O(N^3)
	cout << setw(35) << right << "Result L: ";
	L.output_list(); // O(N)
}