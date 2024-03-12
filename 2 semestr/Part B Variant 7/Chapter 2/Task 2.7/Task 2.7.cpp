//  По заданной последовательности различных целых чисел
//  построить соответствующее бинарное дерево поиска T 
//  как динамическую структуру данных. Выполнить следующие
//  задания и вывести элементы дерева на экран. Оценить
//  асимптотическую сложность алгоритма.

//  Определить номер уровня, в котором содержится
//  максимальное количество вершин.

#include <iostream>
using namespace std;


struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int value)
    {
        data = value;
        left = nullptr;
        right = nullptr;
    }
};

struct BinaryTree {
    TreeNode* root;

    BinaryTree()
    {
        root = nullptr;
    }

    void insert_element(int value)
    {
        if (root == nullptr)
        {
            root = new TreeNode(value);
            return;
        }
        TreeNode* new_node = new TreeNode(value);
        insert_element_recursion(root, new_node);
    }
    void insert_element_recursion(TreeNode* current_node, TreeNode* new_node)
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

    void output_elements_infix(TreeNode* top) const
    {
        cout << "Infix:\t\t";
        output_elements_infix_recursion(top);
        cout << endl;
    }
    void output_elements_infix_recursion(TreeNode* top) const
    {
        if (top)
        {
            output_elements_infix_recursion(top->left);
            cout << top->data << '\t';
            output_elements_infix_recursion(top->right);
        }
    }

    void output_elements_prefix(TreeNode* top) const
    {
        cout << "Prefix:\t\t";
        output_elements_prefix_recursion(top);
        cout << endl;
    }
    void output_elements_prefix_recursion(TreeNode* top) const
    {
        if (top)
        {
            cout << top->data << '\t';
            output_elements_prefix_recursion(top->left);
            output_elements_prefix_recursion(top->right);
        }
    }

    void output_elements_postfix(TreeNode* top) const
    {
        cout << "Postfix:\t";
        output_elements_postfix_recursion(top);
        cout << endl;
    }
    void output_elements_postfix_recursion(TreeNode* top) const
    {
        if (top)
        {
            output_elements_postfix_recursion(top->left);
            output_elements_postfix_recursion(top->right);
            cout << top->data << '\t';
        }
    }

    void search_element(TreeNode*top, int value)
    {
        int counter = 0;
        search_recursion(top, value, counter);
    }

    void search_recursion(TreeNode* top, int value, int counter)
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
    int find_number_of_tops_on_level(TreeNode* top, int level_counter)
    {
        if (top == 0)
            return 0;
        if (level_counter == 0)
            return 1;
        return find_number_of_tops_on_level(top->left, level_counter - 1) + find_number_of_tops_on_level(top->right, level_counter - 1);
    }

    int find_heigh(TreeNode* root)
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
};
void form_array(int[], int);
void fill_array(int [], int);
void output_array(int [], int);
void find_element(BinaryTree);
void output_tree(BinaryTree);
void find_max(BinaryTree);

int* filter_array(int array[], int size)
{
    int counter = 0;
    for (int i = 0; i < size - 1; ++i)
    {
        for (int j = i + 1; j < size; ++j)
        {
            if (array[i] == array[j])
            {
                counter++;
            }
        }
    }
    int* filter_array = new int[size - counter];
    int shift = 0;
    for (int i = 0; i < size - counter; ++i)
    {
        filter_array[i] = array[i + shift];
    }
    return filter_array;
}
int main()
{
    int size;
    do {
        cout << "Enter the size of array: \n";
        cin >> size;
    } while (size < 2);
    
    int* array = new int[size];
    form_array(array, size); // O(N^2)

    BinaryTree T;
    for (int i = 0; i < size; ++i) // O(N^2)
    {
        T.insert_element(array[i]);
    }
    T.output_elements_infix(T.root);
    T.output_elements_postfix(T.root);
    T.output_elements_prefix(T.root);
    find_max(T); // O(N^2)
    delete[] array;

    // O(N^2)
}

void find_max(BinaryTree T)
{
    int max_number = 0, max_level = 0;
    for (int i = 0; i <= T.find_heigh(T.root); ++i) // O(N)
    { 
        int number_now = T.find_number_of_tops_on_level(T.root, i); // O(2N)
        if (number_now > max_number)
        {
            max_number = number_now;
            max_level = i;
        }
    }
    cout << "The maximum of elements (" << max_number << ") is located on " << max_level << " level\n";
}
void form_array(int array[], int size)
{
    fill_array(array, size); // O(N^2)
    cout << "Array: \t\t";
    output_array(array, size); // O(N)
}
void output_tree(BinaryTree T)
{
    cout << "Infix: \t\t";
    T.output_elements_infix_recursion(T.root); cout << endl;
    cout << "Prefix: \t";
    T.output_elements_prefix_recursion(T.root); cout << endl;
    cout << "Postfix: \t";
    T.output_elements_postfix_recursion(T.root); cout << endl;
}
void fill_array(int array[], int size)
{
    int counter = 0, index = 0;
    while (index < size)
    {
        int element = rand() % size + 1;
        for (int i = 0; i < index; ++i)
        {
            if (element == array[i])
            {
                counter++;
            }
        }
        if (counter == 0)
        {
            array[index] = element;
            index++;
        }
        else
        {
            counter = 0;
            continue;
        }
    }
}
void output_array(int array[], int size)
{
    for (int i = 0; i < size; ++i)
    {
        cout << array[i] << '\t';
    }
    cout << endl;
}
void find_element(BinaryTree T)
{
    int search_elem;
    cout << "\nFind element: \n";
    cin >> search_elem;
    T.search_element(T.root, search_elem);
}