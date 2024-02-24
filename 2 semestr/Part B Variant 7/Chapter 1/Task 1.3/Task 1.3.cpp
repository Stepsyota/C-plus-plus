//  Напишите функцию, возвращающую ссылку на максимальное число, встречающееся в заданном
//  массиве произвольного размера (аргумент функции), являющееся степенью числа n.
//  Если такого числа нет, то возвратить ссылку на любое из максимальных чисел массива.
//  Замените значение этого элемента нулевым значением.

#include <iostream>

using namespace std;

int& find_max(int*, int, int);
bool check_n(int*, int, int);
void fill_array(int*, int);
void output_array(int*, int);

int& find_max(int *dynamic_array, int size, int n)
{
    int index_max = 0;
    int counter = 0;
    int index_max_temp = 0;
    for (int i = 0; i < size; ++i)
    {
        if (dynamic_array[i] >= index_max && check_n(dynamic_array, i, n))
        {
            index_max = i;
            counter++;
        }
        if (dynamic_array[i] >= dynamic_array[index_max_temp])
        {
            index_max_temp = i;
        }
    }
    if (counter == 0)
    {
        cout << "There is no element that is a power of n" << endl;
        return dynamic_array[index_max_temp];
    }
    else
    {
        cout << "There is an element that is a power of n" << endl;
        return dynamic_array[index_max];
    }
}

bool check_n(int *dynamic_array, int i, int n)
{
    int pow_n = 1;
    while (dynamic_array[i] >= pow_n)
    {
        if (dynamic_array[i] == pow_n)
        {
            return 1;
        }
        pow_n *= n;
    }
    return 0;
}

void fill_array(int *dynamic_array, int size)
{
    for (int i = 0; i < size; ++i)
    {
        dynamic_array[i] = rand() % 50;
    }
}

void output_array(int* dynamic_array, int size)
{
    for (int i = 0; i < size; ++i)
    {
        cout << dynamic_array[i] << ' ';
    }
    cout << endl;
}

void change_element(int* dynamic_array, int size, int& link)
{
    link = 0;
}

int main()
{
    int size = 0;
    int n;

    while (size < 1)
    {
        cout << "Enter size" << endl;
        cin >> size;
    }

    int* dynamic_array = new int[size];

    cout << "Enter n" << endl;
    cin >> n;
    
    fill_array(dynamic_array, size);
    cout << "Array: ";
    output_array(dynamic_array, size);

    int& link = find_max(dynamic_array, size, n);
    cout << "Max element = " << link << endl;
    cout << "Link for this element: " << & link << endl;
    change_element(dynamic_array, size, link);

    cout << "Array after change: ";
    output_array(dynamic_array, size);

    delete[] dynamic_array;
    return 0;
}