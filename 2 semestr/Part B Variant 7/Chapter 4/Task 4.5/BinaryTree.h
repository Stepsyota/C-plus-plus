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
