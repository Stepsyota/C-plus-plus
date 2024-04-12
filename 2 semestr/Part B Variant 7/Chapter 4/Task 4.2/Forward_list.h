#pragma once

#include <iostream>
#include <iomanip>
#define size_t unsigned int

using namespace std;

template <typename T>
class Node
{
public:
	T data;
	Node* next;
	Node(T, Node*);
};

template <typename T>
Node<T>::Node(T data, Node* next)
{
	this->data = data;
	this->next = next;
}

template <typename T>
class Forward_list
{
private:
	Node<T>* head, * tail;
	size_t size;
public:
	Forward_list();
	Forward_list(size_t);
	Forward_list(const Forward_list<T>&);
	void operator = (const Forward_list<T>&);
	Forward_list(Forward_list<T>&&);
	void operator = (Forward_list<T>&&);
	~Forward_list();

	size_t get_size() const;
	Node<T>* get_head() const;
	T& operator[](size_t);

	bool empty();
	Node<T>* get_node(size_t);
	void output_list();

	void push_front(T);
	void push_after(Node<T>*, T);
	void push_back(T);
	void fill_list();
	void merge_lists(Forward_list<T>&, Forward_list<T>&);
	void find_element(T);

	void pop_front();
	void pop_after(Node<T>*);
	void pop_similar_element();
	void pop_all_similar_elements();
};

template <typename T>
Forward_list<T>::Forward_list()	// Конструктор по умолчанию
{
	this->head = nullptr;
	this->tail = nullptr;
	this->size = 0;
}

template <typename T>
Forward_list<T>::Forward_list(size_t size)	// Конструктор с параметром
{
	this->head = nullptr;
	this->tail = nullptr;
	this->size = size;
}

template <typename T>
Forward_list<T>::Forward_list(const Forward_list<T>& other)	// Конструктор копирования
{
	this->size = 0;
	this->head = nullptr;
	this->tail = nullptr;
	for (Node<T>* n = other.get_head(); n; n = n->next)
	{
		Node<T>* item = new Node<T>(n->data, nullptr);
		if (!this->head)
		{
			this->head = item;
		}
		else
		{
			this->tail->next = item;
		}
		this->tail = item;
		this->size++;
	}
}

template<typename T>
void Forward_list<T>::operator = (const Forward_list<T>& other) // Перегрузка оператора = для копирования
{
	this->size = 0;
	this->head = nullptr;
	this->tail = nullptr;
	for (Node<T>* n = other.get_head(); n; n = n->next)
	{
		Node<T>* item = new Node<T>(n->data, nullptr);
		if (!this->head)
		{
			this->head = item;
		}
		else
		{
			this->tail->next = item;
		}
		this->tail = item;
		this->size++;
	}
}


template <typename T>
Forward_list<T>::Forward_list(Forward_list<T>&& other)	// Конструктор перемещения
{
	this->size = 0;
	this->head = nullptr;
	this->tail = nullptr;
	for (Node<T>* n = other.get_head(); n; n = n->next)
	{
		Node<T>* item = new Node<T>(n->data, nullptr);
		if (!this->head)
		{
			this->head = item;
		}
		else
		{
			this->tail->next = item;
		}
		this->tail = item;
		this->size++;
	}

	size_t counter = other.get_size();
	for (size_t i = 0; i < counter; ++i)
	{
		other.pop_front();
	}
}

template<typename T>
void Forward_list<T>::operator = (Forward_list<T>&& other) // Перегрузка оператора = для перемещения
{
	this->size = 0;
	this->head = nullptr;
	this->tail = nullptr;
	for (Node<T>* n = other.get_head(); n; n = n->next)
	{
		Node<T>* item = new Node<T>(n->data, nullptr);
		if (!this->head)
		{
			this->head = item;
		}
		else
		{
			this->tail->next = item;
		}
		this->tail = item;
		this->size++;
	}

	size_t counter = other.get_size();
	for (size_t i = 0; i < counter; ++i)
	{
		other.pop_front();
	}
}

template <typename T>
Forward_list<T>::~Forward_list()
{
	while (!empty())
	{
		pop_front();
	}
}

template <typename T>
void Forward_list<T>::output_list()
{
	for (Node<T>* l = this->head; l; l = l->next)
	{
		cout << l->data << '\t';
	}
	cout << endl;
}

template <typename T>
size_t Forward_list<T>::get_size() const
{
	return this->size;
}

template <typename T>
Node<T>* Forward_list<T>::get_head() const
{
	return this->head;
}

template <typename T>
T& Forward_list<T>::operator[](size_t index)
{
	return get_node(index)->data;
}

template <typename T>
bool Forward_list<T>::empty()
{
	return this->size == 0;
}

template <typename T>
Node<T>* Forward_list<T>::get_node(size_t index)
{
	Node<T>* l = this->head;
	for (size_t i = 0; i < index; ++i)
	{
		l = l->next;
	}
	return l;
}

template <typename T>
void Forward_list<T>::push_front(T data)
{
	head = new Node<T>(data, head);
	this->size++;
	if (this->tail == nullptr)
	{
		this->tail = this->head;
	}
}

template <typename T>
void Forward_list<T>::push_after(Node<T>* element, T data)
{
	element->next = new Node < T>(data, element->next);
	this->size++;
	if (this->tail == element)
	{
		this->tail = this->tail->next;
	}
}

template <typename T>
void Forward_list<T>::push_back(T data)
{
	if (empty())
	{
		push_front(data);
	}
	else
	{
		push_after(this->tail, data);
	}
}

template <typename T>
void Forward_list<T>::fill_list()
{
	for (size_t i = 0; i < this->size; ++i)
	{
		push_front(rand() % 26 + 97);
		this->size--;
	}
}

template <typename T>
void Forward_list<T>::merge_lists(Forward_list<T>& list1, Forward_list<T>& list2)
{
	for (size_t i = 0; i < list1.get_size(); ++i)
	{
		push_back(list1[i]);
	}
	for (size_t i = 0; i < list2.get_size(); ++i)
	{
		push_back(list2[i]);
	}
}

template <typename T>
void Forward_list<T>::find_element(T element)
{
	size_t place = 0;
	for (Node<T>* l = this->head; l; l = l->next)
	{
		if (l->data == element)
		{
			cout << "Element " << element << " is find on a " << place << " place\nHis adress: \t" << l;
			cout << endl << "Data:\t" << l->data;
			return;
		}
		place++;
	}
	cout << "Element isnt find";
	return;
}

template <typename T>
void Forward_list<T>::pop_front()
{
	Node<T>* next_head = this->head->next;
	delete head;
	this->head = next_head;
	this->size--;
	if (head == nullptr)
	{
		tail = nullptr;
	}
}

template <typename T>
void Forward_list<T>::pop_after(Node<T>* element)
{
	Node<T>* next_element = element->next;
	element->next = next_element->next;
	if (this->tail == next_element)
	{
		this->tail = element;
	}
	delete next_element;
	this->size--;
}

template <typename T>
void Forward_list<T>::pop_similar_element()
{
	for (size_t i = 0; i < this->size - 1; ++i)
	{
		for (size_t j = i + 1; j < this->size; ++j)
		{
			if (get_node(i)->data == get_node(j)->data)
			{
				pop_after(get_node(j - 1));
				j--;
			}
		}
	}
}

template <typename T>
void Forward_list<T>::pop_all_similar_elements()
{
	for (size_t i = 0; i < this->size - 1; ++i)
	{
		bool compare = 0;
		for (size_t j = i + 1; j < this->size; ++j)
		{
			if (get_node(i)->data == get_node(j)->data)
			{
				pop_after(get_node(j - 1));
				j--;
				compare = 1;
			}
		}
		if (compare)
		{
			if (i == 0)
			{
				pop_front();
			}
			else
			{
				pop_after(get_node(i - 1));
			}
			i--;
		}
	}
}