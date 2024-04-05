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
	void fill_random();
	void set_capacity(size_t);
	void set_size(size_t);
};

template<typename T>
ostream& operator << (ostream&, vector<T>&);
template<typename T>
istream& operator >> (istream&, vector<T>&);


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
vector<T>::vector(size_t size) // Конструктор с параметрами для задания элементу определеного значения
{	
	this->size = size;
	this->capacity = size;
	this->seq = new T[capacity]{ 0 };
	for (int i = 0; i < this->size; ++i)
	{
		this->seq[i] = T(0);
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
		this->seq[i] = other.seq[i];
		other.seq[i] = 0;
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
ostream& operator << (ostream& out, vector<T>& vector)	// Перегрузка оператора <<
{
	cout << "Sequence: ";
	vector.output_array();
	return out << "Size: " << vector.get_size() << "\nCapacity: " << vector.get_capacity();
}

template<typename T>
istream& operator >> (istream& in, vector<T>& vector)	// Перегрузка оператора >>
{
	size_t size, capacity;
	in >> size >> capacity;
	vector.set_size(size);
	vector.set_capacity(capacity);
	for (size_t i = 0; i < vector.get_size(); ++i)
	{
		in >> vector[i];
	}
	return in;
}
 
template<typename T>
vector<T>::~vector()	// Деструктор
{
	delete[] this->seq;
}

template<typename T>
void vector<T>::fill_random() // Заполнение вектора случайными значениями
{
	for (int i = 0; i < this->capacity; ++i)
	{
		this->seq[i] = T(rand() % 100);
	}
	this->size = this->capacity;
}


template<typename T>
void vector<T>::set_capacity(size_t new_capacity) // Задание произвольной размерности вектора
{
	T* new_seq = new T[new_capacity] {};
	if (this->capacity > new_capacity)
	{
		for (size_t i = 0; i < new_capacity; ++i)
		{
			new_seq[i] = this->seq[i];
		}
	}
	else
	{
		for (size_t i = 0; i < this->capacity; ++i)
		{
			new_seq[i] = this->seq[i];
		}
	}

	if (this->size > new_capacity)
	{
		this->size = new_capacity;
	}
	this->capacity = new_capacity;
	delete[] this->seq;
	this->seq = new_seq;
}

template<typename T>
void vector<T>::set_size(size_t new_size) // Задание произвольного длины вектора
{
	if (new_size > this->capacity)
	{
		set_capacity(new_size);
	}
	this->size = new_size;
}