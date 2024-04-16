#pragma once

#include <iostream>

using namespace std;

template <typename T>
class TreeNode {
public:
    T data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(T, TreeNode<T>*, TreeNode<T>*);
};

template <typename T>
TreeNode<T>::TreeNode(T data, TreeNode<T>* left, TreeNode<T>* right)
{
    this->data = data;
    this->left = left;
    this->right = right;
}

template <typename T>
class BinaryTree {
private:
    TreeNode<T>* root;
public:
    BinaryTree();
    BinaryTree(int);
    BinaryTree(const BinaryTree<T>&);
    void operator = (const BinaryTree<T>&);
    BinaryTree(BinaryTree<T>&&);
    void operator = (BinaryTree<T>&&);
    ~BinaryTree();

    bool empty() const;
    void insert_element(T);
    void insert_element_recursion(TreeNode<T>*, TreeNode<T>*);
    void output_elements_infix(TreeNode<T>*) const;
    void output_elements_infix_recursion(TreeNode<T>*) const;
    void output_elements_prefix(TreeNode<T>*) const;
    void output_elements_prefix_recursion(TreeNode<T>*) const;
    void output_elements_postfix(TreeNode<T>*) const;
    void output_elements_postfix_recursion(TreeNode<T>*) const;
    void search_element(TreeNode<T>*, T);
    void search_recursion(TreeNode<T>*, T, int);
    int find_number_of_tops_on_level(TreeNode<T>*, int);
    int find_heigh(TreeNode<T>*);
};

template <typename T> // Конструктор по умолчанию
BinaryTree<T>::BinaryTree()
{
    root = nullptr;
}

template <typename T>   // Конструктор с параметром
BinaryTree<T>::BinaryTree(int size)
{
    
}

template <typename T>   // Конструктор копирования
BinaryTree<T>::BinaryTree(const BinaryTree<T>& other)
{
    
}

template<typename T>    // Перегрузка оператора = для копирования
void BinaryTree<T>::operator = (const BinaryTree<T>& other)
{
    
}

template <typename T>   // Конструктор перемещения
BinaryTree<T>::BinaryTree(BinaryTree<T>&& other)
{
    
}

template<typename T>    // Перегрузка оператора = для перемещения
void BinaryTree<T>::operator = (BinaryTree<T>&& other)
{
    
}

template <typename T>   // Деструктор
BinaryTree<T>::~BinaryTree()
{
    while (!empty())
    {
        //
    }
}



template <typename T>
bool BinaryTree<T>::empty() const
{
    return root == nullptr;
}

template <typename T>
void BinaryTree<T>::insert_element(T value)
{
    if (root == nullptr)
    {
        root = new TreeNode(value);
        return;
    }
    TreeNode* new_node = new TreeNode(value);
    insert_element_recursion(root, new_node);
}

template <typename T>
void BinaryTree<T>::insert_element_recursion(TreeNode<T>* current_node, TreeNode<T>* new_node)
{
    if (current_node->data > new_node->data)
    {
        if (current_node->left == nullptr)
        {
            current_node->left = new_node;
        }
        else
        {
            insert_element_recursion(current_node->left, new_node);
        }
    }
    else if (current_node->data < new_node->data)
    {
        if (current_node->right == nullptr)
        {
            current_node->right = new_node;
        }
        else
        {
            insert_element_recursion(current_node->right, new_node);
        }
    }
    else
    {
        cout << "Identical keys are not allowed\n";
        return;
    }
}

template <typename T>
void BinaryTree<T>::output_elements_infix(TreeNode<T>* top) const
{
    cout << "Infix:\t\t";
    output_elements_infix_recursion(top);
    cout << endl;
}

template <typename T>
void BinaryTree<T>::output_elements_infix_recursion(TreeNode<T>* top) const
{
    if (top)
    {
        output_elements_infix_recursion(top->left);
        cout << top->data << '\t';
        output_elements_infix_recursion(top->right);
    }
}

template <typename T>
void BinaryTree<T>::output_elements_prefix(TreeNode<T>* top) const
{
    cout << "Prefix:\t\t";
    output_elements_prefix_recursion(top);
    cout << endl;
}

template <typename T>
void BinaryTree<T>::output_elements_prefix_recursion(TreeNode<T>* top) const
{
    if (top)
    {
        cout << top->data << '\t';
        output_elements_prefix_recursion(top->left);
        output_elements_prefix_recursion(top->right);
    }
}

template <typename T>
void BinaryTree<T>::output_elements_postfix(TreeNode<T>* top) const
{
    cout << "Postfix:\t";
    output_elements_postfix_recursion(top);
    cout << endl;
}

template <typename T>
void BinaryTree<T>::output_elements_postfix_recursion(TreeNode<T>* top) const
{
    if (top)
    {
        output_elements_postfix_recursion(top->left);
        output_elements_postfix_recursion(top->right);
        cout << top->data << '\t';
    }
}

template <typename T>
void BinaryTree<T>::search_element(TreeNode<T>* top, T value)
{
    int counter = 0;
    search_recursion(top, value, counter);
}

template <typename T>
void BinaryTree<T>::search_recursion(TreeNode<T>* top, T value, int counter)
{
    if (top)
    {
        if (top->data > value)
        {
            counter++;
            search_recursion(top->left, value, counter);
        }
        else if (top->data < value)
        {
            counter++;
            search_recursion(top->right, value, counter);
        }
        else
        {
            cout << endl << "The element is located on " << counter << " level\n";
        }
    }
    else
    {
        cout << endl << "No this number";
    }
}


template <typename T>
int BinaryTree<T>::find_number_of_tops_on_level(TreeNode<T>* top, int level_counter)
{
    if (top == 0)
        return 0;
    if (level_counter == 0)
        return 1;
    return find_number_of_tops_on_level(top->left, level_counter - 1) + find_number_of_tops_on_level(top->right, level_counter - 1);
}


template <typename T>
int BinaryTree<T>::find_heigh(TreeNode<T>* root)
{
    if (root == nullptr) {
        return 0;
    }
    else if (root->left == nullptr && root->right == nullptr)
    {
        return 0;
    }
    else if (find_heigh(root->left) > find_heigh(root->right))
    {
        return find_heigh(root->left) + 1;
    }
    else
    {
        return find_heigh(root->right) + 1;
    }
}