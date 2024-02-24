//Получить текст, в котором слова исходного текста упорядочены по алфавиту.
#include <iostream>

using namespace std;

void check_text(char[], const int);
void fill_index_of_all_words(char[], char [], int [], int *, int, const int);
bool check_letter(char[], int);
bool check_separator(char[], char[], int);
void sort_text(char[], char[], int [], int, int, const int);
void add_sort_text(char [], char [], int [], int, const int);
int find_length_str(char[], char[], const int);
void print_sorted_text(char[], const int);

int main()
{
    const int size = 70;
    char text[size] = {' '};
    char sorted_text[size] = {};
    char separators[] = { char(32), '.', ',', ':', ';', '!', '?', '-', '(', ')','\0' };
    //Man,cobra!Hello:Friend;   Good! News?brom.aurum-plumbum
    int index_of_words[size] = {0};
    int counter_of_words = 0;
    int length_str = 0;

    cout << "Enter the text" << endl;
    check_text(text, size);
    length_str = find_length_str(text, separators, size);

    fill_index_of_all_words(text, separators, index_of_words, &counter_of_words, length_str, size);
    sort_text(text, sorted_text, index_of_words, counter_of_words, length_str,  size);
    print_sorted_text(sorted_text, size);
    
    return 0;
}

void print_sorted_text(char sorted_text[], const int size)
{
    for (int i = 0; i < size; ++i)
    {
        cout << sorted_text[i];
    }
}
void check_text(char text[], const int size)
{
    while (cin.getline(text, size))
    {
        if (strcmp(text, ""))
        {
            break;
        }
    }
}

bool check_letter(char text[], int index_start)
{
    return (static_cast<int>(text[index_start]) >= 65 && static_cast<int>(text[index_start]) <= 90 ||
        static_cast<int>(text[index_start]) >= 97 && static_cast<int>(text[index_start]) <= 122);
}

bool check_separator(char text[], char separators[], int index_end)
{
    for (int separator_now = 0; separators[separator_now] != '\0'; ++separator_now)
    {
        if (text[index_end] == separators[separator_now])
        {
            return 1;
        }
    }
    return 0;
}

void add_index_of_words(int index_of_words[], int *counter_index, int *counter_of_words, int index_start, int index_end)
{
    index_of_words[*counter_index] = index_start;
    *counter_index += 1;

    index_of_words[*counter_index] = index_end;
    *counter_index += 1;

    *counter_of_words += 1;
}

void fill_index_of_all_words(char text[], char separators[], int index_of_words[], int* counter_of_words, int length_str, const int size)
{
    int counter_index = 0;
    for (int index_start = 0; index_start < size; ++index_start)
    {
        if (check_letter(text, index_start) == 1)
        {
            for (int index_end = index_start; index_end < size; ++index_end)
            {
                if (check_separator(text, separators, index_end) || index_end == length_str)
                {
                    add_index_of_words(index_of_words, &counter_index, counter_of_words, index_start, index_end);
                    index_start = index_end;
                    break;
                }
            }
        }
    }
}

int find_length_str(char text[], char separators[], const int size)
{
    for (int i = size - 1; i >= 0; --i)
    {
        if (check_separator(text, separators, i) || check_letter(text, i))
        {
            return i + 1;
        }
    }
}

void sort_text(char text[], char sorted_text[], int index_of_words[], int counter_of_words, int length_str, const int size)
{
    for (int j = 0; j < counter_of_words - 1; ++j)
    {
        for (int i = 0; i < counter_of_words * 2 - 2; i += 2)
        {
            if (static_cast<int>(text[index_of_words[i]]) > static_cast<int>(text[index_of_words[i + 2]]))
            {
                swap(index_of_words[i], index_of_words[i + 2]);
                swap(index_of_words[i + 1], index_of_words[i + 3]);
            }
        }
    }
    add_sort_text(text, sorted_text, index_of_words, counter_of_words, size);
}

void add_sort_text(char text[], char sorted_text[], int index_of_words[], int counter_of_words, const int size)
{   
    int j = 0; // index sorted text
    for (int l = 0; l < counter_of_words * 2; l += 2) // amount of loop in index
    {
        for (int k = index_of_words[l]; k < index_of_words[l + 1]; ++k) // fill word
        {
            sorted_text[j] = text[k];
            j += 1;
        }
        sorted_text[j] = ' ';
        j += 1;
    }
}