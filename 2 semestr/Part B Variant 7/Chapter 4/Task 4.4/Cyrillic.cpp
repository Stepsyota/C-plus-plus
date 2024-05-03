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
	if (size > 64)
	{
		cout << "The maximum size of this set is 64. Your size will be forced to 64.\n";
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

CyrillicSet& CyrillicSet::operator &&(const CyrillicSet& other) const
{
	if (get_size() == 64 && other.get_size() == 64)
	{
		CyrillicSet* TEMP = new CyrillicSet(*this);
		return *TEMP;
	}
	CyrillicSet* TEMP = new CyrillicSet();
	for (int i = 0; i < get_size(); ++i)
	{
		for (int j = 0; j < other.get_size(); ++j)
		{
			if (get_data(i) == other.get_data(j))
			{
				TEMP->insert_element(get_data(i));
			}
		}
	}
	return *TEMP;
}

CyrillicSet& CyrillicSet::operator ||(const CyrillicSet& other) const
{
	CyrillicSet* TEMP = new CyrillicSet(*this);
	for (int i = 0; i < other.get_size(); ++i)
	{
		if (TEMP->get_size() == 64)
		{
			cout << "The first set is full\n";
			return *TEMP;
		}
		TEMP->insert_element(other.get_data(i));
	}
	return *TEMP;
}

CyrillicSet& CyrillicSet::operator /(const CyrillicSet& other) const
{
	CyrillicSet* TEMP = new CyrillicSet(*this);
	for (int i = 0; i < other.get_size(); ++i)
	{
		TEMP->pop_element(other.get_data(i));
	}
	return *TEMP;
}

void CyrillicSet::operator +=(char element)
{
	insert_element(element);
}

void CyrillicSet::operator -=(char element)
{
	pop_element(element);
}

bool CyrillicSet::empty()
{
	return size == 0;
}

void CyrillicSet::insert_element(char element)
{
	if (!check_element(element))
	{
		return;
	}
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

void CyrillicSet::set_capacity(int capacity)
{
	this->capacity = capacity;
	char* new_seq = new char[this->capacity] {};
	for (int i = 0; i < this->size; ++i)
	{
		new_seq[i] = seq[i];
	}
	delete[] seq;
	seq = new_seq;
}

void CyrillicSet::pop_element(int index)
{
	bool pop_element = 0;
	for (int i = 0; i < size; ++i)
	{
		if (i == index)
		{
			pop_element = 1;
			size--;
		}
		if (pop_element)
		{
			seq[i] = seq[i + 1];
		}
	}
}

void CyrillicSet::pop_element(char element)
{
	if (!check_element(element))
	{
		return;
	}
	bool pop_element = 0;
	for (int i = 0; i < size; ++i)
	{
		if (seq[i] == element)
		{
			pop_element = 1;
			size--;
		}
		if (pop_element)
		{
			seq[i] = seq[i + 1];
		}
	}
}

void CyrillicSet::pop_all_elements()
{
	this->size = 0;
	this->capacity = 1;
	delete[] seq;
	seq = new char[capacity] {};
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

bool CyrillicSet::check_element(char element)
{
	if (element < -64 || element > -1)
	{
		cout << "Invalid element: " << element << endl;
		return 0;
	}
	return 1;
}

ostream& operator << (ostream& out, CyrillicSet& Set)
{
	cout << "Set: ";
	Set.output_set();
	return out << "Size: " << Set.get_size() << "\nCapacity: " << Set.get_capacity() << endl;
}

istream& operator >> (istream& in, CyrillicSet& Set)
{
	Set.pop_all_elements();
	int size, capacity;
	do
	{
		in >> size >> capacity;
		if (size > capacity)
		{
			cout << "Error size or capacity\n";
		}
	} while (size > capacity);
	Set.set_capacity(capacity);
	for (size_t i = 0; i < size ; ++i)
	{
		char data;
		in >> data;
		Set.insert_element(data);
	}
	return in;
}