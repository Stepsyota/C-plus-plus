#pragma once

#include <iostream>

using namespace std;

template <typename T>
class TreeNode 
{
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
class BinaryTree 
{
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

    TreeNode<T>* get_root() const;
    bool empty() const;
    void copy_tree(TreeNode<T>*);

    void pop_element(T);
    TreeNode<T>* pop_node(TreeNode<T>*, T);
    void pop_all_elements(TreeNode<T>*);

    void search_element(T);
    TreeNode<T>* search_min_node(TreeNode<T>*);

    int find_number_of_tops_on_level(TreeNode<T>*, int);
    int find_heigh(TreeNode<T>*);

    void insert_element(T);

    void output_elements_infix() const;
    void output_elements_prefix() const;
    void output_elements_postfix() const;

private:
    void search_recursion(TreeNode<T>*, T, int);

    void insert_element_recursion(TreeNode<T>*, TreeNode<T>*);

    void output_elements_infix_recursion(TreeNode<T>*) const;
    void output_elements_prefix_recursion(TreeNode<T>*) const;
    void output_elements_postfix_recursion(TreeNode<T>*) const;
};

template <typename T> // Конструктор по умолчанию
BinaryTree<T>::BinaryTree()
{
    root = nullptr;

}

template <typename T>   // Конструктор с параметром
BinaryTree<T>::BinaryTree(int size)
{
    root = nullptr;
    for (int i = 0; i < size; ++i)
    {
        T element = T(rand() % 30);
        cout << "Element " << i << " is " << element << endl;
        insert_element(element);
    }
}

template <typename T>   // Конструктор копирования
BinaryTree<T>::BinaryTree(const BinaryTree<T>& other)
{
    copy_tree(other.get_root());
}

template<typename T>    // Перегрузка оператора = для копирования
void BinaryTree<T>::operator = (const BinaryTree<T>& other)
{
    copy_tree(other.get_root());
}

template <typename T>   // Конструктор перемещения
BinaryTree<T>::BinaryTree(BinaryTree<T>&& other)
{
    copy_tree(other.get_root());
    pop_all_elements(other.get_root());
}

template<typename T>    // Перегрузка оператора = для перемещения
void BinaryTree<T>::operator = (BinaryTree<T>&& other)
{
    copy_tree(other.get_root());
    pop_all_elements(other.get_root());
}

template <typename T>   // Деструктор
BinaryTree<T>::~BinaryTree()
{
    pop_all_elements(root);
}

template <typename T>
TreeNode<T>* BinaryTree<T>::get_root() const
{
    return root;
}

template <typename T>
bool BinaryTree<T>::empty() const
{
    return root == nullptr;
}

template <typename T>
void BinaryTree<T>::copy_tree(TreeNode<T>* current_node)
{
    if (current_node)
    {
        insert_element(current_node->data);
        copy_tree(current_node->left);
        copy_tree(current_node->right);
    }

}

template <typename T>
void BinaryTree<T>::pop_element(T value)
{
    if (empty())
    {
        cout << "The tree is empty\n";
        return;
    }
    pop_node(root, value);
}

template <typename T>
TreeNode<T>* BinaryTree<T>::pop_node(TreeNode<T>* current_node, T value)
{
    if (current_node->data == value)
    {
        if (current_node->left == nullptr && current_node->right == nullptr)
        {
            return nullptr; 
        }

        if (current_node->left == nullptr)
        {
            return current_node->right;
        }

        if (current_node->right == nullptr)
        {
            return current_node->left;
        }

        TreeNode<T>* min_node = search_min_node(current_node->right);
        current_node->data = min_node->data;
        current_node->right = pop_node(current_node->right, min_node->data);
        return current_node;
    }

    if (value < current_node->data)
    {
        if (current_node->left == nullptr)
        {
            cout << "Element is`not found\n";
            return current_node;
        }
        current_node->left = pop_node(current_node->left, value);
        return current_node;
    }

    if (value > current_node->data)
    {
        if (current_node->right == nullptr)
        {
            cout << "Element is`not found\n";
            return current_node;
        }
        current_node->right = pop_node(current_node->right, value);
        return current_node;
    }
}

template <typename T>
void BinaryTree<T>::pop_all_elements(TreeNode<T>* top)
{
    if (top)
    {
        pop_all_elements(top->left);
        pop_all_elements(top->right);

        top->data = 0;
        top->left = nullptr;
        top->right = nullptr;
    }
    if (top == root)
    {
        root = nullptr;
    }
}

template <typename T>
void BinaryTree<T>::insert_element(T value)
{
    if (empty())
    {
        root = new TreeNode<T>(value, nullptr, nullptr);
        return;
    }
    TreeNode<T>* new_node = new TreeNode<T>(value, nullptr, nullptr);
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
void BinaryTree<T>::output_elements_infix() const
{
    cout << "Infix:\t\t";
    output_elements_infix_recursion(root);
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
void BinaryTree<T>::output_elements_prefix() const
{
    cout << "Prefix:\t\t";
    output_elements_prefix_recursion(root);
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
void BinaryTree<T>::output_elements_postfix() const
{
    cout << "Postfix:\t";
    output_elements_postfix_recursion(root);
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
void BinaryTree<T>::search_element(T value)
{
    int counter = 0;
    search_recursion(root, value, counter);
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
            cout << endl << "The element " << value <<" is located on " << counter << " level\n";
        }
    }
    else
    {
        cout << endl << "No this number";
    }
}

template <typename T>
TreeNode<T>* BinaryTree<T>::search_min_node(TreeNode<T>* current_node)
{
    if (current_node->left == nullptr)
    {
        return current_node;
    }
    search_min_node(current_node->left);
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