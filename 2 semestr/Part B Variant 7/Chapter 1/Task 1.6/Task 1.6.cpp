//  Дан массив чисел произвольной длины. Отсортировать массив,
//  используя сортировку слияниями. Создать шаблоны и перегрузки
//  функций для сортировки, вывода результатов, заполнения массивов.
//  Выполнить сортировки массивов для данных разных типов : целых,
//  вещественных, символьных, С-строк, используя написанные функции.

#include <iostream>

using namespace std;

template<typename T> void merge_array(T[], int, int);
template<typename T> void sort_array(T[], int, int);
template<typename T> void fill_array(T[], int);
template<typename T> void output_array(T[], int);

void output_array(char* [], int, int);
void fill_array(char* [], int, int);
void merge_array(char*[], int, int, int);
void sort_array(char*[], int, int, int, int);

int main()
{
    int size = 0, index_compare = 0, length_str = 0;
    do
    {
        cout << "Enter size:\n";
        cin >> size;
    } while (size < 1);


    do
    {
        cout << "Enter the length of C-stings:\n";
        cin >> length_str;
    } while (length_str < 2);

    do
    {
        cout << "Enter the index of compare C-strings:\n";
        cin >> index_compare;
    } while (index_compare < 0);

    double* array1 = new double[size];
    fill_array(array1, size);
    output_array(array1, size);
    sort_array(array1, 0, size);
    output_array(array1, size);
    delete[] array1;

    cout << endl;

    int* array2 = new int[size];
    fill_array(array2, size);
    output_array(array2, size);
    sort_array(array2, 0, size);
    output_array(array2, size);
    delete[] array2;

    cout << endl;

    char* array3 = new char[size];
    fill_array(array3, size);
    output_array(array3, size);
    sort_array(array3, 0, size);
    output_array(array3, size);
    delete[] array3;

    cout << endl;

    char** array4 = new char*[size];
    fill_array(array4, size, length_str);
    output_array(array4, size, length_str);
    sort_array(array4, 0, size, size, index_compare);
    output_array(array4, size, length_str);
    delete[] array4;

    return 0;
}

template<typename T> void merge_array(T array[], int start, int end)
{
    int left = start, 
        mid = left + (end - left) / 2,
        right = mid,
        counter = 0;

    T* merged_array = new T[end - start];
    while (left < mid && right < end)
    {
        if (array[left] <= array[right])
        {

            merged_array[counter] = array[left];
            left++;
        }
        else
        {
            merged_array[counter] = array[right];
            right++;
        }
        counter++;
    }
    
    while (left < mid)
    {
        merged_array[counter] = array[left];
        left++;
        counter++;
    }

    while (right < end)
    {
        merged_array[counter] = array[right];
        right++;
        counter++;
    }

    for (int i = 0; i < counter; ++i)
    {
        array[start + i] = merged_array[i];
    }

    delete[] merged_array;
}
template<typename T> void sort_array(T array[], int start, int end)
{
    if (end <= start)
    {
        return;
    }
    else if (end - start == 2)
    {
        if (array[start] > array[start + 1])
        {
            swap(array[start], array[start + 1]);
        }
        return;
    }
    else if (end - start == 1)
    {
        return;
    }

    sort_array(array, start, start + (end - start) / 2);
    sort_array(array, start + (end - start) / 2, end);
    merge_array(array, start, end);
}
template<typename T> void fill_array(T array[], int size)
{
    for (int i = 0; i < size; ++i)
    { 
        if (is_same<T, double>::value)
        {
            T element = rand() % 100 / 10.0;
            array[i] = element;
            continue;
        }
        else if (is_same<T, char>::value)
        {
            T element = rand() % 26 + 97;
            array[i] = element;
            continue;
        }
        else if (is_same<T, int>::value)
        {
            T element = rand() % 200;
            array[i] = element;
            continue;
        }       
    }
}
template<typename T> void output_array(T array[], int size)
{
    for (int i = 0; i < size; ++i)
    {
        cout << array[i] << '\t';
    }
    cout << endl;
}


void merge_array(char* array[], int start, int end,  int size, int index_compare = 0)
{
    int left = start,
        mid = left + (end - left) / 2,
        right = mid,
        counter = 0;

    char** merged_array = new char*[end - start];
    while (left < mid && right < end)
    {
        for (index_compare; index_compare < size; ++index_compare)
        {
            if (array[left][index_compare] == array[right][index_compare])
            {
                continue;
            }
            if (array[left][index_compare] < array[right][index_compare])
            {

                merged_array[counter] = array[left];
                left++;
                counter++;
                break;
            }
            else if (array[left][index_compare] > array[right][index_compare])
            {
                merged_array[counter] = array[right];
                right++;
                counter++;
                break;
            }
        }
        index_compare = 0;
    }

    while (left < mid)
    {
        merged_array[counter] = array[left];
        left++;
        counter++;
    }

    while (right < end)
    {
        merged_array[counter] = array[right];
        right++;
        counter++;
    }

    for (int i = 0; i < counter; ++i)
    {
        array[start + i] = merged_array[i];
    }

    delete[] merged_array;
}
void sort_array(char* array[], int start, int end, int size, int index_compare = 0)
{
    if (end <= start)
    {
        return;
    }
    else if (end - start == 2)
    {
        for (index_compare; index_compare < size; index_compare++)
        {
            if (array[start][index_compare] == array[start + 1][index_compare])
            {
                continue;
            }
            else if (array[start][index_compare] > array[start + 1][index_compare])
            {
                swap(array[start], array[start + 1]);
                
            }
            return;
        }   
    }
    else if (end - start == 1)
    {
        return;
    }

    sort_array(array, start, start + (end - start) / 2, size, index_compare);
    sort_array(array, start + (end - start) / 2, end, size, index_compare);
    merge_array(array, start, end, size, index_compare);
}
void fill_array(char* array[], int size, int length_str)
{
    for (int i = 0; i < size; ++i)
    {
        char* element = new char[5];
        for (int k = 0; k < length_str; ++k)
        {
            element[k] = rand() % 26 + 97;
        }
        array[i] = element;  
    }
}
void output_array(char* array[], int size, int length_str)
{
    for (int i = 0; i < size; ++i)
    {
        for (int k = 0; k < length_str; ++k)
        {
            cout << array[i][k];
        }
        cout << '\t';
    }
    cout << endl;
}