#pragma once

#include "../Task 6.1/ArtObject.h"

using namespace std;

class Node
{
public:
	ArtObject* object;
	Node* next;
	Node(ArtObject*, Node*);
};


class ObjectForwardList
{
private:
	Node* head, * tail;
	int size;
public:
	ObjectForwardList();
	ObjectForwardList(const ObjectForwardList&);
	ObjectForwardList(ObjectForwardList&&);
	~ObjectForwardList();

	void operator = (const ObjectForwardList&);
	void operator = (ObjectForwardList&&);

	int get_size() const;
	Node* get_head() const;

	bool empty();
	void output_list();

	template <class T>
	void push_front(T* new_object)
	{
		ArtObject* object = new_object;
		head = new Node(object, head);
		this->size++;
		if (this->tail == nullptr)
		{
			this->tail = this->head;
		}
	}
	template <class T>
	void push_after(T* new_object, int index)
	{
		Node* element = get_node(index);
		ArtObject* object = new_object;
		if (empty())
		{
			head = new Node(object, head);
			this->size++;
			if (this->tail == nullptr)
			{
				this->tail = this->head;
			}
		}
		else
		{
			element->next = new Node(object, element->next);
			this->size++;
			if (this->tail == element)
			{
				this->tail = this->tail->next;
			}
		}
	}
	template <class T>
	void push_back(T* new_object)
	{
		ArtObject* object = new_object;
		if (empty())
		{
			head = new Node(object, head);
			this->size++;
			if (this->tail == nullptr)
			{
				this->tail = this->head;
			}
		}
		else
		{
			this->tail->next = new Node(object, tail->next);
			this->size++;
			this->tail = this->tail->next;
		}
	}

	void pop_front();
	void clear();
	void pop_forward_list();

	void copy_list(const ObjectForwardList&);
	Node* get_node(int);
};