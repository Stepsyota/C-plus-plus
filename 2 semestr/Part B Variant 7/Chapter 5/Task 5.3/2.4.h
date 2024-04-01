#pragma once

#include <iostream>
#include <iomanip>
#include <forward_list>

using namespace std;

struct Node
{
	char symbol;
	Node* next;

	Node(char, Node*);
};

struct LinkedList {
	Node* head, * tail;
	int counter;
	Node* get_node(int);
	char& operator [](int);
	int size() const;
	bool empty() const;
	void push_front(int);
	void push_back(int);
	void push_after(Node*, int);
	void fill_list(int);
	void delete_front();
	void delete_after(Node*);
	void delete_similar_elements();
	void delete_all_similar_elements();
	void output_list() const;
	void merge_lists(LinkedList&, LinkedList&);
};

void form_list(LinkedList&, LinkedList&);

void make_task_2_4();
void fill_list(forward_list<char>&, int);
void output_list(forward_list<char>);
void delete_similar_elements(forward_list<char>&);
forward_list<char> merge_lists(forward_list<char>, forward_list<char>);
auto find_last_element(forward_list<char>); // ?!?