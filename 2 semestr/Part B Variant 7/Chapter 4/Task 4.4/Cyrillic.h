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

	CyrillicSet& operator &&(const CyrillicSet& other) const;	// Пересечение
	CyrillicSet& operator ||(const CyrillicSet& other) const;	// Объединение
	CyrillicSet& operator /(const CyrillicSet& other) const;	// Разность

	bool empty();
	void insert_element(char);
	void output_set();
	void increase_capacity();

	int get_size() const;
	int get_capacity() const;
	char get_data(int) const;

	void set_capacity(int);
	void set_data(int, char);

	void push_front(char);
	void push_back(char);
	void push_on_index(int, char);

	void pop_element(int);
	void pop_element(char);
	void pop_all_elements();
};

ostream& operator << (ostream&, CyrillicSet&);
istream& operator >> (istream&, CyrillicSet&);