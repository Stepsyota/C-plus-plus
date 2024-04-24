#include <iostream>
#include "Cyrillic.h"

using namespace std;

CyrillicSet::CyrillicSet()
{
	this->size = 0;
	this->capacity = 1;
	this->seq = new char[capacity] {};
}
CyrillicSet::CyrillicSet(int size)
{
	this->size = 0;
	this->capacity = 1;
	this->seq = new char[capacity] {};

	while (this->size < size)
	{
		insert_element(rand() % 64 + 192);
	}
}
CyrillicSet::~CyrillicSet()
{
	delete[] seq;
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
	}
	if (seq[0] > element)
	{
		push_front(element);
		return;
	}
	for (int i = 0; i < size; ++i)
	{
		if (i != size - 1)
		{
			if (seq[i] < element && seq[i + 1] > element)
			{
				push_after(i, element);
				return;
			}
		}
		if (seq[i] < element && i == size - 1)
		{
			push_back(element);
			return;
		}
	}
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

void CyrillicSet::push_front(char element)
{
	push_after(0, element);
}

void CyrillicSet::push_after(int index, char element)
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
	push_after(size, element);
}
