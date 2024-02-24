#include <iostream>
#include <math.h>
using namespace std;

void output_array(const int, int *);
void fill_array(const int, int *);

int main()
{
    const int size = 4;
    int array[size][size];
    fill_array(size, *array);
    output_array(size, *array);
}

void fill_array(const int size, int* array)
{
    int number_of_passes = ceil(size / 2.0);
    int current_pass = 0;
    int current_number = 1;

    while (current_pass <= number_of_passes)
    {
        //Filling the line down
        for (int i = (current_pass + 1) * (size - 1); i <= (size * size - 1) - current_pass * (size + 1); i += size)
        {
            *(array + i) = current_number;
            current_number++;
        }

        //Filling the line left
        for (int i = size * size - 2 - current_pass * (size + 1); i >= size * size - size - current_pass * (size - 1); --i)
        {
            *(array + i) = current_number;
            current_number++;
        }
 
        //Filling the line up
        for (int i = (size * size - 2 * size) - current_pass * (size - 1); i >= current_pass * (size + 1); i -= size)
        {
            *(array + i) = current_number;
            current_number++;
        }

        //Filling the line right
        for (int i = current_pass * (size + 1) + 1; i <= size + current_pass * (size - 1) - 2; ++i)
        {
            *(array + i) = current_number;
            current_number++;
        }
        ++current_pass;
    }
}

void output_array(const int size, int* array)
{
    for (int i = 0; i < size * size; ++i)
    {
        cout << *(array + i) << '\t';
        if ((i + 1) % size == 0)
        {
            cout << endl;
        }
    }
}