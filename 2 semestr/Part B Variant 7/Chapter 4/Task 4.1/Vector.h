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
	~Vector();

	size_t get_size();
	size_t get_capacity();
	void output_array();
};