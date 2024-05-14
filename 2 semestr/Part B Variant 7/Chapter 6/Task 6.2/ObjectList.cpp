#pragma once

#include <iostream>
#include "../Task 6.1/ArtObject.h"

using namespace std;

class ObjectList
{
private:
	ArtObject* seq;
	int size;
	int capacity;

public:
	ObjectList();
	ObjectList(int);
	ObjectList(const ObjectList&);
	ObjectList(ObjectList&&);
	~ObjectList();

	void operator =(const ObjectList&);
	void operator = (ObjectList&&);
	ArtObject& operator [] (const int);


	int get_size() const;
	int get_capacity() const;
	void output_array();
	void fill_random();
	void set_capacity(int);
	void set_size(int);

	ArtObject get_element_by_index(int);
	void change_element_by_index(ArtObject, int);
	void increase_capacity();
	bool empty() const;
	void push_back(ArtObject);
	void push_after(ArtObject, int);
	void pop_back();
};

template<typename ArtObject>
ostream& operator << (ostream&, ObjectList&);
template<typename ArtObject>
istream& operator >> (istream&, ObjectList&);


int ObjectList::get_size() const	// Метод получения size
{
	return this->size;
}

int ObjectList::get_capacity() const	// Метод получения capacity
{
	return this->capacity;
}

void ObjectList::output_array()	// Метод вывода элементов
{
	for (int i = 0; i < this->size; ++i)
	{
		cout << this->seq[i] << '\t';
	}
	cout << endl;
}

ObjectList::ObjectList()	// Конструктор по умолчанию
{
	this->size = 0;
	this->capacity = 1;
	this->seq = new ArtObject[capacity]{};
}

ObjectList::ObjectList(int size) // Конструктор с параметрами для задания элементу определеного значения
{
	this->size = size;
	this->capacity = size;
	this->seq = new ArtObject[capacity]{};
	for (int i = 0; i < this->size; ++i)
	{
		this->seq[i] = ArtObject();
	}
}

ObjectList::ObjectList(const ObjectList& other) // Конструктор копирования
{
	this->size = other.get_size();
	this->capacity = other.get_capacity();
	this->seq = new ArtObject[capacity]{};

	for (int i = 0; i < this->size; ++i)
	{
		this->seq[i] = other.seq[i]; // ?!?
	}
}

ObjectList::ObjectList(ObjectList&& other) // Конструктор перемещения
{
	this->size = other.get_size();
	this->capacity = other.get_capacity();
	this->seq = new ArtObject[capacity]{};

	for (int i = 0; i < this->size; ++i)
	{
		this->seq[i] = other.seq[i];
		other.seq[i] = 0;
	}
	other.size = 0;
	other.capacity = 0;
}

void ObjectList::operator = (const ObjectList& other) // Перегрузка оператора = для копирования
{
	this->size = other.get_size();
	this->capacity = other.get_capacity();
	this->array = new ArtObject[capacity]{};

	for (int i = 0; i < this->size; ++i)
	{
		this->seq[i] = other.seq[i]; // ?!?
	}
}

void ObjectList::operator = (ObjectList&& other)	// Перегрузка оператора = для перемещения
{
	this->size = other.get_size();
	this->capacity = other.get_capacity();
	this->seq = new ArtObject[capacity]{};

	for (int i = 0; i < this->size; ++i)
	{
		this->seq[i] = other.seq[i];
		other.seq[i] = 0;
	}
	other.size = 0;
	other.capacity = 0;
}

ArtObject& ObjectList::operator [] (const int i)	// Перегрузка оператора []
{
	if (i < 0)
	{
		return this->seq[0];
	}
	if (i >= this->size)
	{
		return this->seq[this->size - 1];
	}
	return this->seq[i];
}

ostream& operator << (ostream& out, ObjectList& ObjectList)	// Перегрузка оператора <<
{
	cout << "Sequence: ";
	ObjectList.output_array();
	return out << "Size: " << ObjectList.get_size() << "\nCapacity: " << ObjectList.get_capacity() << endl;
}

istream& operator >> (istream& in, ObjectList& ObjectList)	// Перегрузка оператора >>
{
	int size, capacity;
	do
	{
		in >> size >> capacity;
	} while (size > capacity);
	ObjectList.set_capacity(capacity);
	for (int i = 0; i < size; ++i)
	{
		ArtObject element;
		in >> element;
		ObjectList.push_back(element);
	}
	return in;
}

ObjectList::~ObjectList()	// Деструктор
{
	delete[] this->seq;
}

void ObjectList::fill_random() // Заполнение вектора случайными значениями
{
	for (int i = 0; i < this->capacity; ++i)
	{
		this->seq[i] = ArtObject(rand() % 100);
	}
	this->size = this->capacity;
}

void ObjectList::set_capacity(int new_capacity) // Задание произвольной размерности вектора
{
	ArtObject* new_seq = new ArtObject[new_capacity]{};
	if (this->size > new_capacity)
	{
		this->size = new_capacity;
	}
	if (this->capacity > new_capacity)
	{
		for (int i = 0; i < size; ++i)
		{
			new_seq[i] = this->seq[i];
		}
	}
	else
	{
		for (int i = 0; i < size; ++i)
		{
			new_seq[i] = this->seq[i];
		}
	}

	if (this->capacity != 0)
	{
		delete[] this->seq;
	}
	this->capacity = new_capacity;
	this->seq = new_seq;
}

void ObjectList::set_size(int new_size) // Задание произвольного длины вектора
{
	if (new_size > this->capacity)
	{
		set_capacity(new_size);
	}
	this->size = new_size;
}

ArtObject ObjectList::get_element_by_index(int index)
{
	if (index >= size)
	{
		cout << "Error index\n";
		return ArtObject(0);
	}
	else
	{
		return seq[index];
	}
}

void ObjectList::change_element_by_index(ArtObject element, int index)
{
	if (index >= size)
	{
		cout << "Error index\n";
		return;
	}
	seq[index] = element;
}


bool ObjectList::empty() const
{
	return size == 0;
}

void ObjectList::push_back(ArtObject element)
{
	if (size == capacity)
	{
		increase_capacity();
		seq[size] = element;
		size++;
	}
	else
	{
		seq[size] = element;
		size++;
	}
}

void ObjectList::increase_capacity()
{
	capacity = 2 * capacity;
	ArtObject* new_seq = new ArtObject[capacity];
	for (int i = 0; i < size; ++i)
	{
		new_seq[i] = seq[i];
	}
	delete[] seq;
	seq = new_seq;
}

void ObjectList::push_after(ArtObject element, int index)
{
	if (index > size)
	{
		cout << "Error index\n";
		return;
	}
	else if (index == size)
	{
		push_back(element);
		return;
	}
	if (size == capacity)
	{
		increase_capacity();
	}
	for (int i = size + 1; i > index; --i)
	{
		seq[i] = seq[i - 1];
	}
	seq[index] = element;
	size++;
}

void ObjectList::pop_back()
{
	if (!empty())
	{
		seq[size] = 0;
		size--;
	}
}