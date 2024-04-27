#pragma once

#include <iostream>

using namespace std;

class CyrillicSet
{
private:
	char* seq;
	int size;
	int capacity;
public:
	CyrillicSet();
	CyrillicSet(int);
	CyrillicSet(const CyrillicSet&);
	void operator =(const CyrillicSet&);
	CyrillicSet(CyrillicSet&&);
	void operator =(CyrillicSet&&);
	~CyrillicSet();

	CyrillicSet& operator &&(const CyrillicSet& other); // Пересечение
	CyrillicSet& operator ||(const CyrillicSet& other);	// Объединение

	bool empty();
	void insert_element(char);
	void output_set();
	void increase_capacity();

	int get_size() const;
	int get_capacity() const;
	char get_data(int) const;
	void set_size(int);

	void push_front(char);
	void push_back(char);
	void push_on_index(int, char);

	void pop_all_elements();
};