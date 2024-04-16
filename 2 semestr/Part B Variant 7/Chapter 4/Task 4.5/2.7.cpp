#include "2.7.h"

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
void make_task_2_7()
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