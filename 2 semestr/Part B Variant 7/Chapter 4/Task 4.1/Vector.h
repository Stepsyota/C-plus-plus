#pragma once

#include <iostream>

#define size_t unsigned int

using namespace std;

template <typename T>
class vector
{
private:
	T* seq;
	size_t size;
	size_t capacity;

public:
	vector();
	vector(size_t);
	vector(const vector&);
	vector(vector&&);
	~vector();

	void operator =(const vector<T>&);
	void operator = (vector<T>&&);
	T& operator [] (const int);

	size_t get_size() const;
	size_t get_capacity() const;
	void output_array();
};



template<typename T>
size_t vector<T>::get_size() const	// Метод получения size
{
	return this->size;
}

template<typename T>
size_t vector<T>::get_capacity() const	// Метод получения capacity
{
	return this->capacity;
}

template<typename T>
void vector<T>::output_array()	// Метод вывода элементов
{
	for (int i = 0; i < this->size; ++i)
	{
		cout << this->seq[i] << '\t';
	}
	cout << endl;
}

template<typename T>
vector<T>::vector()	// Конструктор по умолчанию
{
	this->size = 1;
	this->capacity = 1;
	this->seq = new T[capacity]{};
}

template<typename T>
vector<T>::vector(size_t size)	// Конструктор с параметром
{
	this->size = size;
	this->capacity = size;
	this->seq = new T[capacity]{ 0 };
	for (int i = 0; i < this->size; ++i)
	{
		this->seq[i] = rand() % 100;
	}
}

template<typename T>
vector<T>::vector(const vector& other) // Конструктор копирования
{
	this->size = other.get_size();
	this->capacity = other.get_capacity();
	this->seq = new T[capacity]{};

	for (int i = 0; i < this->size; ++i)
	{
		this->seq[i] = other.seq[i]; // ?!?
	}
}

template<typename T>
vector<T>::vector(vector&& other) // Конструктор перемещения
{
	this->size = other.get_size();
	this->capacity = other.get_capacity();
	this->seq = new T[capacity]{};

	for (int i = 0; i < this->size; ++i)
	{
		this->seq[i] = other.seq[i];
		other.seq[i] = 0;	// ?!?
	}
	other.size = 0;
	other.capacity = 0;
}

template<typename T>
void vector<T>::operator = (const vector<T>& other) // Перегрузка оператора = для копирования
{
	this->size = other.get_size();
	this->capacity = other.get_capacity();
	this->array = new T[capacity]{};

	for (int i = 0; i < this->size; ++i)
	{
		this->seq[i] = other.seq[i]; // ?!?
	}
}

template<typename T>
void vector<T>::operator = (vector<T>&& other)	// Перегрузка оператора = для перемещения
{
	this->size = other.get_size();
	this->capacity = other.get_capacity();
	this->seq = new T[capacity]{};

	for (int i = 0; i < this->size; ++i)
	{
		this->seq[i] = other.seq[i]; // ?!?
		other.seq[i] = 0;	// ?!?
	}
	other.size = 0;
	other.capacity = 0;
}

template<typename T>
T& vector<T>::operator [] (const int i)	// Перегрузка оператора []
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

template<typename T>
vector<T>::~vector()	// Деструктор
{
	delete[] this->seq;
}