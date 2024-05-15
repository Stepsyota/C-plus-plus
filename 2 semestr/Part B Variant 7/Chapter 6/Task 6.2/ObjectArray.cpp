#include <iostream>
#include "ObjectArray.h"

using namespace std;

int ObjectArray::get_size() const
{
	return this->size;
}

int ObjectArray::get_capacity() const
{
	return this->capacity;
}

void ObjectArray::output_array() const
{
	cout << "=============================================================================\n";
	if (seq == nullptr)
	{
		cout << "The array is empty\n";
		cout << "=============================================================================\n";
		return;
	}
	for (int i = 0; i < this->size; ++i)
	{
		cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
		cout << "Object: " << i << endl;
		cout << *this->seq[i] << endl;
	}
	cout << "=============================================================================\n";
}

ObjectArray::ObjectArray()
{
	this->size = 0;
	this->capacity = 0;
	this->seq = nullptr;
}

ObjectArray::ObjectArray(const ObjectArray& other)
{
	this->size = other.get_size();
	this->capacity = other.get_capacity();
	this->seq = new ArtObject*[capacity]{};

	for (int i = 0; i < this->size; ++i)
	{
		this->seq[i] = other.seq[i];
	}
}

ObjectArray::ObjectArray(ObjectArray&& other)
{
	this->size = other.get_size();
	this->capacity = other.get_capacity();
	this->seq = new ArtObject*[capacity]{};

	for (int i = 0; i < this->size; ++i)
	{
		this->seq[i] = other.seq[i];
	}
	other.pop_seq();
}

void ObjectArray::operator = (const ObjectArray& other)
{
	this->size = other.get_size();
	this->capacity = other.get_capacity();
	this->seq = new ArtObject*[capacity]{};

	for (int i = 0; i < this->size; ++i)
	{
		this->seq[i] = other.seq[i];
	}
}

void ObjectArray::operator = (ObjectArray&& other)
{
	this->size = other.get_size();
	this->capacity = other.get_capacity();
	this->seq = new ArtObject*[capacity]{};

	for (int i = 0; i < this->size; ++i)
	{
		this->seq[i] = other.seq[i];
	}
	other.pop_seq();
}

ObjectArray::~ObjectArray()
{
	pop_seq();
}

bool ObjectArray::empty() const
{
	return size == 0;
}

void ObjectArray::increase_capacity()
{
	int new_capacity = 2 * capacity;
	ArtObject** new_seq = new ArtObject*[new_capacity];
	for (int i = 0; i < capacity; ++i)
	{
		new_seq[i] = seq[i];
		seq[i] = nullptr;
		delete seq[i];
	}
	delete[] seq;
	capacity = new_capacity;
	seq = new_seq;
}

void ObjectArray::pop_back()
{
	if (!empty())
	{
		size--;
	}
}

void ObjectArray::pop_seq()
{
	if (seq != nullptr)
	{
		delete[] seq;
	}
	seq = nullptr;
	size = 0;
	capacity = 0;
}

void ObjectArray::create_seq()
{
	if (this->seq != nullptr)
	{
		delete[] this->seq;
	}
	this->capacity = 1;
	this->seq = new ArtObject*[this->capacity];
}