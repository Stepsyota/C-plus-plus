#include <iostream>
#include "ObjectForwList.h"

using namespace std;

Node::Node(ArtObject* object, Node* next)
{
	this->object = object;
	this->next = next;
}

ObjectForwardList::ObjectForwardList()
{
	this->head = nullptr;
	this->tail = nullptr;
	this->size = 0;
}

ObjectForwardList::ObjectForwardList(const ObjectForwardList& other)
{
	this->size = 0;
	this->head = nullptr;
	this->tail = nullptr;
	for (Node* n = other.get_head(); n; n = n->next)
	{
		Node* item = new Node(n->object, nullptr);
		if (!this->head)
		{
			this->head = item;
		}
		else
		{
			this->tail->next = item;
		}
		this->tail = item;
		this->size++;
	}
}

void ObjectForwardList::operator = (const ObjectForwardList& other)
{
	this->size = 0;
	this->head = nullptr;
	this->tail = nullptr;
	for (Node* n = other.get_head(); n; n = n->next)
	{
		Node* item = new Node(n->object, nullptr);
		if (!this->head)
		{
			this->head = item;
		}
		else
		{
			this->tail->next = item;
		}
		this->tail = item;
		this->size++;
	}
}

ObjectForwardList::ObjectForwardList(ObjectForwardList&& other)
{
	this->size = 0;
	this->head = nullptr;
	this->tail = nullptr;
	for (Node* n = other.get_head(); n; n = n->next)
	{
		Node* item = new Node(n->object, nullptr);
		if (!this->head)
		{
			this->head = item;
		}
		else
		{
			this->tail->next = item;
		}
		this->tail = item;
		this->size++;
	}

	other.clear();
}

void ObjectForwardList::operator = (ObjectForwardList&& other)
{
	this->size = 0;
	this->head = nullptr;
	this->tail = nullptr;
	for (Node* n = other.get_head(); n; n = n->next)
	{
		Node* item = new Node(n->object, nullptr);
		if (!this->head)
		{
			this->head = item;
		}
		else
		{
			this->tail->next = item;
		}
		this->tail = item;
		this->size++;
	}

	other.clear();
}

ObjectForwardList::~ObjectForwardList()
{
	while (!empty())
	{
		clear();
	}
}

bool ObjectForwardList::empty()
{
	return this->size == 0;
}

void ObjectForwardList::output_list()
{
	for (Node* l = this->head; l; l = l->next)
	{
		l->object->print();
	}
	cout << endl;
}

int ObjectForwardList::get_size() const
{
	return this->size;
}

Node* ObjectForwardList::get_head() const
{
	return this->head;
}

void ObjectForwardList::pop_front()
{
	Node* next_head = this->head->next;
	head->object->pop_object();
	delete head;
	this->head = next_head;
	this->size--;
	if (head == nullptr)
	{
		tail = nullptr;
	}
}

Node* ObjectForwardList::get_node(int index)
{
	Node* l = this->head;
	for (int i = 0; i < index; ++i)
	{
		l = l->next;
	}
	return l;
}

void ObjectForwardList::pop_forward_list()
{
	while (!empty())
	{
		pop_front();
	}

	this->head = nullptr;
	this->tail = nullptr;
	this->size = 0;
}

void ObjectForwardList::clear()
{
	while (!empty())
	{
		Node* next_head = this->head->next;
		delete head;
		this->head = next_head;
		this->size--;
		if (head == nullptr)
		{
			tail = nullptr;
		}
	}
}

void ObjectForwardList::copy_list(const ObjectForwardList& other)
{
	this->size = 0;
	this->head = nullptr;
	this->tail = nullptr;
	for (Node* n = other.get_head(); n; n = n->next)
	{
		ArtObject* new_object(n->object);
		Node* item = new Node(new_object, nullptr);
		if (!this->head)
		{
			this->head = item;
		}
		else
		{
			this->tail->next = item;
		}
		this->tail = item;
		this->size++;
	}
}