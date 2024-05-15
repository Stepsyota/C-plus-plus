#pragma once

#include "../Task 6.1/ArtObject.h"

using namespace std;

class ObjectArray
{
private:
	ArtObject** seq;
	int size;
	int capacity;

public:
	ObjectArray();
	ObjectArray(const ObjectArray&);
	ObjectArray(ObjectArray&&);
	~ObjectArray();

	void operator =(const ObjectArray&);
	void operator = (ObjectArray&&);

	int get_size() const;
	int get_capacity() const;
	void output_array() const;

	bool empty() const;

	template <class T>
	void push_back(T new_element)
	{
		ArtObject* element = new T(new_element);
		if (seq == nullptr)
		{
			create_seq();
		}
		if (size == capacity)
		{
			increase_capacity();
		}
		seq[size] = element;
		size++;
	}

	template <class T>
	void push_after(T new_element, int index)
	{
		ArtObject* element = new T(new_element);
		if (seq == nullptr)
		{
			create_seq();
		}
		if (index > size)
		{
			cout << "Error index\n";
			return;
		}
		if (size == capacity)
		{
			increase_capacity();
		}
		if (index == size)
		{
			seq[size] = element;
			size++;
			return;
		}

		for (int i = size + 1; i > index; --i)
		{
			seq[i] = seq[i - 1];
		}
		seq[index] = element;
		size++;
	}
	void pop_back();

	void increase_capacity();
	void pop_seq();
	void create_seq();
};