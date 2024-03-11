// Даны натуральное число n, действительные числа a(1), a(2), ..., a(2n).
// Получить a(1)a(2n) + a(2)a(2n−1) + ... + a(n)a(n + 1) .

#include <iostream>

using namespace std;

struct Node 
{
    double number;
    Node* next;
    Node* prev;
    
    Node(double data, Node* p, Node* n)
    {
        number = data;
        next = n;
        prev = p;
    } // O(1)
};

struct DoubleLinkedList
{
    Node* sentinel;
    int counter;

    DoubleLinkedList()
    {
        sentinel = new Node(0, nullptr, nullptr);
        //Элементы "стражники" с двух сторон списка. Сделаны для удобства добавления и удаления элементов в список.
        //Сами по себе содержат нули и не выводятся в ходе программы.
        sentinel->prev = sentinel;
        sentinel->next = sentinel;
        counter = 0;
    } // O(1)

    ~DoubleLinkedList()
    {
        while (!empty())
        {
            delete_front();
        }
    } //O(N)
    

    int size() const
    {
        return counter;
    } // O(1)
    bool empty() const
    {
        return size() == 0;
    } // O(1)
    Node* get_node(int index)
    {
        if (index < (size() / 2.0))
        {
            Node* l = sentinel->next;
            for (int i = 0; i < index; ++i)
            {
                l = l->next;
            }
            return l;
        }
        else
        {
            Node* l = sentinel->prev;
            for (int i = size() - 1; i > index; --i)
            {
                l = l->prev;
            }
            return l;
        }
    } // O(N)
    double& operator [](int index)
    {
        return get_node(index)->number;
    } // O(N)


    void push_front(double data)
    {
        insert_after(sentinel, data);
    } // O(1)
    void push_back(double data)
    {
        insert_before(sentinel, data);
    } // O(1)
    void insert_after(Node* elem, double data)
    {
        Node* n = new Node(data, elem, elem->next);
        elem->next->prev = n;
        elem->next = n;
        counter++;
    } // O(1)
    void insert_before(Node* elem, double data)
    {
        Node* n = new Node(data, elem->prev, elem);
        elem->prev->next = n;
        elem->prev = n;
        counter++;
    } // O(1)
    void fill_list(int n)
    {
        for (int i = 0; i < 2 * n; ++i)
        {
            push_front((rand() % 1000) / 100.0);
        }
    } // O(N)


    void delete_front()
    {
        delete_element(sentinel->next);
    } // O(1)
    void delete_back()
    {
        delete_element(sentinel->prev);
    } // O(1)
    void delete_element(Node* elem)
    {
        elem->prev->next = elem->next;
        elem->next->prev = elem->prev;
        delete elem;
        counter--;
    } // O(1)


    void output_list()
    {
        Node* current_node = sentinel->next;
        while (current_node != sentinel)
        {
            cout << current_node->number << '\t';
            current_node = current_node->next;
        }
        cout << endl;
    } // O(N)
    double calc_expresion()
    {
        double result = 0;
        Node* n = sentinel->next;
        Node* p = sentinel->prev;
        int number_of_iterations = size() / 2;
        for (int i = 0; i < number_of_iterations; ++i)
        {
            cout << n->number << " * " << p->number;
            if (i < number_of_iterations - 1)
            {
                cout << " + ";
            }
            result += n->number * p->number;
            n = n->next;
            p = p->prev;
        }
        return result;
    }// O(N)
};


int main()
{
    int n = 0;
    do
    {
        cout << "Enter n:\n";
        cin >> n;
    } while (n < 1);

    DoubleLinkedList L;
    L.fill_list(n); //O(N)
    L.output_list(); //O(N)
    cout << " = " << L.calc_expresion(); //O(N)
    return 0;  
} //O(N)