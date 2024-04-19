#include "2.7.h"

template <typename T>
T* filter_array(T array[], int size)
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
    T* filter_array = new T[size - counter];
    int shift = 0;
    for (int i = 0; i < size - counter; ++i)
    {
        filter_array[i] = array[i + shift];
    }
    return filter_array;
}
void make_task_2_7()
{
    int size;
    do {
        cout << "Enter the size of array: \n";
        cin >> size;
    } while (size < 2);

    int* array = new int[size];
    fill_array(array, size);
    cout << "Array:\t"; output_array(array, size);

    BinaryTree<int> Tree;
    for (int i = 0; i < size; ++i)
    {
        Tree.insert_element(array[i]);
    }
    output_tree(Tree);
    find_max_number_of_elements(Tree);
    //Tree.pop_element(Tree.get_root());
    //output_tree(Tree);
    delete[] array;
}

template <typename T>
void find_max_number_of_elements(BinaryTree<T>& Tree)
{
    int max_number = 0, max_level = 0;
    for (int i = 0; i <= Tree.find_heigh(Tree.get_root()); ++i)
    {
        int number_now = Tree.find_number_of_tops_on_level(Tree.get_root(), i);
        if (number_now > max_number)
        {
            max_number = number_now;
            max_level = i;
        }
    }
    cout << "The maximum of elements (" << max_number << ") is located on " << max_level << " level\n";
}

template <typename T>
void fill_array(T array[], int size)
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

template <typename T>
void output_array(T array[], int size)
{
    for (int i = 0; i < size; ++i)
    {
        cout << array[i] << '\t';
    }
    cout << endl;
}

template <typename T>
void find_element(BinaryTree<T>& Tree)
{
    T element_to_search;
    cout << "\nFind element: \n";
    cin >> element_to_search;
    Tree.search_element(element_to_search);
}

template <typename T>
void output_tree(BinaryTree<T>& Tree)
{
    Tree.output_elements_infix();
    Tree.output_elements_prefix();
    Tree.output_elements_postfix();
}