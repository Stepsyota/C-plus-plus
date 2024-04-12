#pragma once

#include <iostream>

#define size_t unsigned int

using namespace std;



template <typename T>
class Vector
{
private:
	T* seq;
	size_t size;
	size_t capacity;

public:
	Vector();
	Vector(size_t);
	Vector(const Vector&);
	Vector(Vector&&);
	~Vector();

	void operator =(const Vector<T>&);
	void operator = (Vector<T>&&);
	T& operator [] (const int);


	size_t get_size() const;
	size_t get_capacity() const;
	void output_array();
	void fill_random();
	void set_capacity(size_t);
	void set_size(size_t);
};

template<typename T>
ostream& operator << (ostream&, Vector<T>&);
template<typename T>
istream& operator >> (istream&, Vector<T>&);


template<typename T>
size_t Vector<T>::get_size() const	// Метод получения size
{
	return this->size;
}

template<typename T>
size_t Vector<T>::get_capacity() const	// Метод получения capacity
{
	return this->capacity;
}

template<typename T>
void Vector<T>::output_array()	// Метод вывода элементов
{
	for (int i = 0; i < this->size; ++i)
	{
		cout << this->seq[i] << '\t';
	}
	cout << endl;
}

template<typename T>
Vector<T>::Vector()	// Конструктор по умолчанию
{
	this->size = 1;
	this->capacity = 1;
	this->seq = new T[capacity]{};
}

template<typename T>
Vector<T>::Vector(size_t size) // Конструктор с параметрами для задания элементу определеного значения
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
Vector<T>::Vector(const Vector& other) // Конструктор копирования
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
Vector<T>::Vector(Vector&& other) // Конструктор перемещения
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
void Vector<T>::operator = (const Vector<T>& other) // Перегрузка оператора = для копирования
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
void Vector<T>::operator = (Vector<T>&& other)	// Перегрузка оператора = для перемещения
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
T& Vector<T>::operator [] (const int i)	// Перегрузка оператора []
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
ostream& operator << (ostream& out, Vector<T>& Vector)	// Перегрузка оператора <<
{
	cout << "Sequence: ";
	Vector.output_array();
	return out << "Size: " << Vector.get_size() << "\nCapacity: " << Vector.get_capacity();
}

template<typename T>
istream& operator >> (istream& in, Vector<T>& Vector)	// Перегрузка оператора >>
{
	size_t size, capacity;
	in >> size >> capacity;
	Vector.set_size(size);
	Vector.set_capacity(capacity);
	for (size_t i = 0; i < Vector.get_size(); ++i)
	{
		in >> Vector[i];
	}
	return in;
}
 
template<typename T>
Vector<T>::~Vector()	// Деструктор
{
	delete[] this->seq;
}

template<typename T>
void Vector<T>::fill_random() // Заполнение вектора случайными значениями
{
	for (int i = 0; i < this->capacity; ++i)
	{
		this->seq[i] = T(rand() % 100);
	}
	this->size = this->capacity;
}


template<typename T>
void Vector<T>::set_capacity(size_t new_capacity) // Задание произвольной размерности вектора
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
void Vector<T>::set_size(size_t new_size) // Задание произвольного длины вектора
{
	if (new_size > this->capacity)
	{
		set_capacity(new_size);
	}
	this->size = new_size;
}