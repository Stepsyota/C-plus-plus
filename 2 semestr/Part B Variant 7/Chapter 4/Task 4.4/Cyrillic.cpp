#include <iostream>
#include "Cyrillic.h"

using namespace std;

//
CyrillicSet::CyrillicSet()
{
	this->size = 0;
	this->capacity = 1;
	this->seq = new char[capacity] {};
}

CyrillicSet::CyrillicSet(int size)
{
	if (size > 64)
	{
		cout << "The maximum of this set is 64. Your size will be forced to 64.\n";
		size = 64;
	}
	this->size = 0;
	this->capacity = size;
	this->seq = new char[capacity] {};

	while (this->size < size)
	{
		insert_element(rand() % 64 + 192);
	}
}

CyrillicSet::CyrillicSet(const CyrillicSet& other)
{
	this->size = other.get_size();
	this->capacity = other.get_capacity();
	this->seq = new char[this->capacity] {};

	for (int i = 0; i < this->size; ++i)
	{
		this->seq[i] = other.get_data(i);
	}
}

void CyrillicSet::operator=(const CyrillicSet& other)
{
	this->size = other.get_size();
	this->capacity = other.get_capacity();
	this->seq = new char[this->capacity] {};

	for (int i = 0; i < this->size; ++i)
	{
		this->seq[i] = other.get_data(i);
	}
}

CyrillicSet::CyrillicSet(CyrillicSet&& other)
{
	this->size = other.get_size();
	this->capacity = other.get_capacity();
	this->seq = new char[this->capacity] {};

	for (int i = 0; i < this->size; ++i)
	{
		this->seq[i] = other.get_data(i);
	}
	other.pop_all_elements();
}

void CyrillicSet::operator=(CyrillicSet&& other)
{
	this->size = other.get_size();
	this->capacity = other.get_capacity();
	this->seq = new char[this->capacity] {};

	for (int i = 0; i < this->size; ++i)
	{
		this->seq[i] = other.get_data(i);
	}
	other.pop_all_elements();
}

CyrillicSet::~CyrillicSet()
{
	delete[] seq;
}
//

CyrillicSet& CyrillicSet::operator &&(const CyrillicSet&)
{

}

CyrillicSet& CyrillicSet::operator ||(const CyrillicSet& other)
{
	for (int i = 0; i < other.get_size(); ++i)
	{
		if (size == 64)
		{
			cout << "The first set is full\n";
			return *this;
		}
		insert_element(other.get_data(i));
	}
	return *this;
}

bool CyrillicSet::empty()
{
	return size == 0;
}

void CyrillicSet::insert_element(char element)
{
	if (empty())
	{
		seq[0] = element;
		size++;
		return;
	}
	if (seq[0] > element)
	{
		push_front(element);
		return;
	}
	for (int i = 0; i < size - 1; ++i)
	{
		if (seq[i] == element || seq[i + 1] == element)
		{
			return;
		}
		if (seq[i] < element && seq[i + 1] > element)
		{
			push_on_index(i + 1, element);
			return;
		}
	}
	push_back(element);
}

void CyrillicSet::output_set()
{
	for (int i = 0; i < size; ++i)
	{
		cout << seq[i] << " ";
	}
	cout << endl;
}

void CyrillicSet::increase_capacity()
{
	capacity *= 2;
	char* new_seq = new char[capacity] {};
	for (int i = 0; i < size; ++i)
	{
		new_seq[i] = seq[i];
	}
	delete[] seq;
	seq = new_seq;
}

int CyrillicSet::get_size() const
{
	return this->size;
}

int CyrillicSet::get_capacity() const
{
	return this->capacity;
}

char CyrillicSet::get_data(int index) const
{
	return this->seq[index];
}

void CyrillicSet::set_size(int size)
{
	if (size < 0 || size > 64)
	{
		return;
	}
	if (size < this->size)
	{

	}
	if (size > this->size)
	{

	}
}

void CyrillicSet::push_front(char element)
{
	push_on_index(0, element);
}

void CyrillicSet::push_on_index(int index, char element)
{
	if (size == capacity)
	{
		increase_capacity();
	}
	for (int i = size; i > index; --i)
	{
		seq[i] = seq[i - 1];
	}
	seq[index] = element;
	size++;
}

void CyrillicSet::push_back(char element)
{
	push_on_index(size, element);
}

void CyrillicSet::pop_all_elements()
{
	this->size = 0;
	this->capacity = 1;
	delete[] seq;
	seq = new char[capacity] {};
}