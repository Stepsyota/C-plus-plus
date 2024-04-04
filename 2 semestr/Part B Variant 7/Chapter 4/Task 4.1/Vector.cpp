#include "Vector.h"

template<typename T>
size_t Vector<T>::get_size()
{
	return this->size;
}

template<typename T>
size_t Vector<T>::get_capacity()
{
	return this->capacity;
}

template<typename T>
void Vector<T>::output_array()
{
	for (int i = 0; i < this->size; ++i)
	{
		cout << this->seq[i] << '\t';
	}
	cout << endl;
}

template<typename T>
Vector<T>::Vector()
{
	this->size = 1;
	this->capacity = 1;
	this->array = new int[capacity] {0};
}

template<typename T>
Vector<T>::Vector(size_t size)
{
	this->size = size;
	this->capacity = size;
	this->seq = new int[capacity] {0};
	for (int i = 0; i < this->size; ++i)
	{
		this->seq[i] = rand() % 100;
	}
}

template<typename T>
Vector<T>::Vector(const Vector& other)
{
	this->size = other.get_size();
	this->capacity = other.get_capacity();
	this->seq = new int[capacity] {};

	//for (int i = 0; i < this->size; ++i)
	//{
	//	this->seq[i] = other.seq[i]; // ?!?
	//}
}

//template<typename T>
//Vector<T>& Vector<T>::operator=(const Vector<T>& other)
//{
//	this->size = other.get_size();
//	this->capacity = other.get_capacity();
//	this->array = new int[capacity] {};
//
//	for (int i = 0; i < this->size; ++i)
//	{
//		this->array[i] = other.array[i]; // ?!?
//	}
//}

template<typename T>
Vector<T>::~Vector()
{
	delete[] this->seq;
}