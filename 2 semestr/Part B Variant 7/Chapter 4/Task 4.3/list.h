#pragma once

#include <iostream>
#define size_t unsigned int
using namespace std;

template <typename T>
class Node
{
public:
    T data;
    Node<T>* next;
    Node<T>* prev;
    Node(T, Node<T>*, Node<T>*);
};

template <typename T>   // Конструктор узла
Node<T>::Node(T data, Node<T>* prev, Node<T>* next)
{
    this->data = data;
    this->next = next;
    this->prev = prev;
}

template <typename T>
class list
{
private:
    Node<T>* sentinel;
    size_t size;
public:
    list();
    list(size_t);
    list(const list<T>&);
    void operator = (const list<T>&);
    list(list<T>&&);
    void operator = (list<T>&&);
    ~list();

    size_t get_size() const;
    Node<T>* get_sentinel() const;
    bool empty() const;
    
    Node<T>* get_node(size_t);
    T& operator [](size_t);

    void push_front(T);
    void push_back(T);

    void insert_after(Node<T>*, T);
    void insert_before(Node<T>*, T);
    void fill_list(size_t);
    void find_element(T);

    void pop_front();
    void pop_back();
    void pop_element(Node<T>*);

    void output_list() const;
    T calc_expresion();
};

template <typename T> // Конструктор по умолчанию
list<T>::list()
{
    sentinel = new Node<T>(T(0), nullptr, nullptr);
    //Элементы "стражники" с двух сторон списка. Сделаны для удобства добавления и удаления элементов в список.
    //Сами по себе содержат нули и не выводятся в ходе программы.
    sentinel->prev = sentinel;
    sentinel->next = sentinel;
    size = 0;
}

template <typename T>   // Конструктор с параметром
list<T>::list(size_t size)
{
    sentinel = new Node<T>(T(0), nullptr, nullptr);
    //Элементы "стражники" с двух сторон списка. Сделаны для удобства добавления и удаления элементов в список.
    //Сами по себе содержат нули и не выводятся в ходе программы.
    sentinel->prev = sentinel;
    sentinel->next = sentinel;
    this->size = size;
}

template <typename T>   // Конструктор копирования
list<T>::list(const list<T>& other)
{
    sentinel = new Node<T>(T(0), nullptr, nullptr);
    sentinel->prev = sentinel;
    sentinel->next = sentinel;
    size = 0;

    Node<T>* current_node = other.get_sentinel()->next;
    while (current_node != other.get_sentinel())
    {
        push_back(current_node->data);
        current_node = current_node->next;
    }
}

template<typename T>    // Перегрузка оператора = для копирования
void list<T>::operator = (const list<T>& other)
{
    sentinel = new Node<T>(T(0), nullptr, nullptr);
    sentinel->prev = sentinel;
    sentinel->next = sentinel;
    size = 0;

    Node<T>* current_node = other.get_sentinel()->next;
    while (current_node != other.get_sentinel())
    {
        push_back(current_node->data);
        current_node = current_node->next;
    }
}

template <typename T>   // Конструктор перемещения
list<T>::list(list<T>&& other)
{
    sentinel = new Node<T>(T(0), nullptr, nullptr);
    sentinel->prev = sentinel;
    sentinel->next = sentinel;
    size = 0;

    Node<T>* current_node = other.get_sentinel()->next;
    while (current_node != other.get_sentinel())
    {
        push_back(current_node->data);
        current_node = current_node->next;
    }

    size_t counter = other.get_size();
    for (size_t i = 0; i < counter; ++i)
    {
        other.pop_front();
    }
}

template<typename T>    // Перегрузка оператора = для перемещения
void list<T>::operator = (list<T>&& other) 
{
    sentinel = new Node<T>(T(0), nullptr, nullptr);
    sentinel->prev = sentinel;
    sentinel->next = sentinel;
    size = 0;

    Node<T>* current_node = other.get_sentinel()->next;
    while (current_node != other.get_sentinel())
    {
        push_back(current_node->data);
        current_node = current_node->next;
    }

    size_t counter = other.get_size();
    for (size_t i = 0; i < counter; ++i)
    {
        other.pop_front();
    }
}

template <typename T>   // Деструктор
list<T>::~list()
{
    while (!empty())
    {
        pop_front();
    }
}

template <typename T>
size_t list<T>::get_size() const
{
    return size;
}

template <typename T>
Node<T>* list<T>::get_sentinel() const
{
    return sentinel;
}

template <typename T>
bool list<T>::empty() const
{
    return size == 0;
}

template <typename T>
Node<T>* list<T>::get_node(size_t index)
{
    if (index < (size / 2.0))
    {
        Node<T>* l = sentinel->next;
        for (size_t i = 0; i < index; ++i)
        {
            l = l->next;
        }
        return l;
    }
    else
    {
        Node<T>* l = sentinel->prev;
        for (size_t i = size - 1; i > index; --i)
        {
            l = l->prev;
        }
        return l;
    }
}

template <typename T>   // Перегрузка оператора []
T& list<T>::operator [](size_t index)   
{
    return get_node(index)->data;
}

template <typename T>
void list<T>::push_front(T data)
{
    insert_after(sentinel, data);
}

template <typename T>   
void list<T>::push_back(T data)
{
    insert_before(sentinel, data);
}

template <typename T>
void list<T>::insert_after(Node<T>* elem, T data)
{
    Node<T>* n = new Node<T>(data, elem, elem->next);
    elem->next->prev = n;
    elem->next = n;
    size++;
}

template <typename T>
void list<T>::insert_before(Node<T>* elem, T data)
{
    Node<T>* n = new Node<T>(data, elem->prev, elem);
    elem->prev->next = n;
    elem->prev = n;
    size++;
}

template <typename T>
void list<T>::fill_list(size_t n)
{
    for (size_t i = 0; i < 2 * n; ++i)
    {
        push_front(T((rand() % 1000) / 100.0));
    }
}

template <typename T>
void list<T>::find_element(T element)
{
    size_t place = 0;
    Node<T>* l = sentinel->next;
    Node<T>* n = sentinel->prev;
    while (l != sentinel && n != sentinel)
    {
        if (l->data == element)
        {
            cout << "Element " << element << " is find on a " << place << " place\nHis adress: \t" << l;
            cout << endl << "Data:\t" << l->data;
            return;
        }
        if (n->data == element)
        {
            cout << "Element " << element << " is find on a " << size - place - 1 << " place\nHis adress: \t" << l;
            cout << endl << "Data:\t" << n->data;
            return;
        }
        place++;
        l = l->next;
        n = n->prev;
    }
    cout << "Element isnt find";
    return;
}

template <typename T>
void list<T>::pop_front()
{
    pop_element(sentinel->next);
}

template <typename T>
void list<T>::pop_back()
{
    pop_element(sentinel->prev);
}

template <typename T>
void list<T>::pop_element(Node<T>* elem)
{
    elem->prev->next = elem->next;
    elem->next->prev = elem->prev;
    delete elem;
    size--;
}

template <typename T>
void list<T>::output_list() const
{
    Node<T>* current_node = sentinel->next;
    while (current_node != sentinel)
    {
        cout << current_node->data << '\t';
        current_node = current_node->next;
    }
    cout << endl;
}

template <typename T>
T list<T>::calc_expresion()
{
    T result = 0;
    Node<T>* n = sentinel->next;
    Node<T>* p = sentinel->prev;
    size_t number_of_iterations = size / 2;
    for (size_t i = 0; i < number_of_iterations; ++i)
    {
        cout << n->data << " * " << p->data;
        if (i < number_of_iterations - 1)
        {
            cout << " + ";
        }
        result += n->data * p->data;
        n = n->next;
        p = p->prev;
    }
    return result;
}