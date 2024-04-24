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
	~CyrillicSet();

	bool empty();
	void insert_element(char);
	void output_set();
	void increase_capacity();

	void push_front(char);
	void push_back(char);
	void push_after(int, char);
};