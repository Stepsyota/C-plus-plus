//  По исходному списку определить всех отличников n курса.
//  Сформировать список из этих студентов, удалив их из исходного списка.

#include <iostream>

using namespace std;

struct Student
{
    char full_name[50];
    char date_of_birthday[11];
    double grade;
    int course;

    Student()
    {
        grade = (rand() % 70 + 30) / 10.0;
        course = rand() % 4 + 1;
        int day = rand() % 31 + 1;
        int month = rand() % 12 + 1;
        int year = rand() % 30 + 1975;

        int i = 0;
        date_of_birthday[i] = char(day / 10 + 48); i++;
        date_of_birthday[i] = char(day % 10 + 48); i++;
        date_of_birthday[i] = '.'; i++;
        date_of_birthday[i] = char(month / 10 + 48); i++;
        date_of_birthday[i] = char(month % 10 + 48); i++;
        date_of_birthday[i] = '.'; i++;
        date_of_birthday[i] = char(year / 1000 + 48); i++;
        date_of_birthday[i] = char(year / 100 % 10 + 48); i++;
        date_of_birthday[i] = char(year / 10 % 10 + 48); i++;
        date_of_birthday[i] = char(year % 10 + 48); i++;
        date_of_birthday[i] = '\0';

        char all_names[250] = { "Kanye Omari West | Samuel Frederick Smith | Elizabeth Alexandra Mary Windsor | Dmitriy Aleksandrovich Hvorostovsky | Konstantin Edouardovich Tsiolkovskii | Karnitskaya Evelina Alekseevna | John Fitzgerald Kennedy | Ivan Sergeyevich Turgenev\0" };
        int index[100] = { 0, 15,19, 40,44, 75,79, 113,117, 152,156, 185,189, 211, 215, 239 };
        int start = rand() % 8 * 2;
        int end = start + 1;
        int k = 0;
        for (index[start]; index[start] <= index[end]; ++index[start])
        {
            full_name[k] = all_names[index[start]];
            k++;
        }
        full_name[k] = '\0';
    }
    void output_info()
    {
        cout << "Full name: " << full_name << endl;
        cout << "Grade: " << grade << endl;
        cout << "Course: " << course << endl;
        cout << "Date of birthday: " << date_of_birthday << endl;

    }
};

struct Node
{
    Student student;
    Node* next;

    Node(Node* l)
    {
        next = l;
    }
};

struct LinkedList {
    Node* head, * tail;
    int counter;

    LinkedList()
    {
        head = nullptr;
        tail = nullptr;
        counter = 0;
    }

    ~LinkedList()
    {
        while (!empty())
        {
            delete_front();
        }
    }

    bool empty() const
    {
        return counter == 0;
    }
    int size() const
    {
        return counter;
    }

    void push_front(Node* element = new Node(nullptr))
    {
        element->next = head;
        head = element;
        counter++;
        if (tail == nullptr)
        {
            tail = head;
        }
    }
    void push_back(Node* element = new Node(nullptr))
    {
        if (empty())
        {
            push_front(element);
        }
        else
        {
            insert_after(tail, element);
        }
    }
    void insert_after(Node* l, Node* element = new Node(nullptr))
    {
        Node* temp = l->next;
        l->next = element;
        element->next = temp;
        counter++;
        if (tail == l)
        {
            tail = tail->next;
        }
    }
    void add_element_with_sort(Node* element)
    {
        element->next = nullptr;
        if (size() == 0)
        {
            head = element;
            counter++;
            tail = head;
            return;
        }


        for (int index_compare = 0; head->student.full_name[index_compare] != '\0' && element->student.full_name[index_compare] != '\0'; ++index_compare)
        {
            if (head->student.full_name[index_compare] == element->student.full_name[index_compare])
            {
                continue;
            }
            else if (head->student.full_name[index_compare] > element->student.full_name[index_compare]) //push front
            {
                push_front(element);
                return;
            }
            break;
        }
        Node* l = head->next;
        Node* p = head;
        while (l)
        {
            for (int index_compare = 0; head->student.full_name[index_compare] != '\0' && element->student.full_name[index_compare] != '\0'; ++index_compare)
            {
                if (l->student.full_name[index_compare + 1] == '\0' || element->student.full_name[index_compare + 1] == '\0')
                {
                    insert_after(l, element);
                    return;
                }
                else if (l->student.full_name[index_compare] == element->student.full_name[index_compare]) //compare again with next symbol
                {
                    continue;
                }
                else if (l->student.full_name[index_compare] > element->student.full_name[index_compare]) //insert after pred
                {
                    insert_after(p, element);
                    return;
                }
                break;
            }
            p = p->next;
            l = l->next;
        }
        push_back(element);
        return;
     
    }

    void delete_front()
    {
        Node* next_head = head->next;
        delete head;
        head = next_head;
        counter--;
        if (head == nullptr)
        {
            tail = nullptr;
        }
    }
    void delete_after(Node* elem)
    {
        Node* next_elem = elem->next;
        elem->next = next_elem->next;
        if (tail == next_elem)
        {
            tail = elem;
        }
        delete next_elem;
        counter--;

    }

    void form_two_lists(LinkedList& Filtred_list, int n, int grade)
    {
        Node* l = head;
        Node* pred = head;
        Node* temp;
        while (l)
        {
            if (l->student.grade >= grade && l->student.course == n)
            {
                Node* right_student = new Node(nullptr);
                right_student->student = l->student;
                Filtred_list.add_element_with_sort(right_student);
                if (l == head)
                {
                    if (l == tail)
                    {
                        delete_front();
                        break;
                    }
                    temp = head->next;
                    delete_front();
                    l = temp;
                    pred = l;
                    continue;
                }
                else
                {
                    l = l->next;
                    delete_after(pred);
                    continue;
                }
            }
            if (l == tail)
            {
                break;
            }
            else
            {
                pred = l;
                l = l->next;
            }
        }
    }

    void sort_students_by_course()
    {
        Node* l = head;
        Node* k = head;
        Node* temp = new Node(nullptr);
        for (int i = 0; i < size() - 1; i++)
        {
            for (int j = 0; j < size() - i - 1; j++)
            {
                if (k->student.course > k->next->student.course)
                {
                    swap(k->student, k->next->student);
                }
                k = k->next;
            }
            k = head;
        }
    }
    void find_student_by_course(int course)
    {
        int counter = 0;
        cout << "Finded students: \n";
        for (Node* l = head; l; l = l->next)
        {
            if (l->student.course == course)
            {
                l->student.output_info();
                cout << endl;
            }
            counter++;
        }
        cout << "This is " << counter << " students\n";
    }
    void copy_list(LinkedList& List1)
    {
        for (Node* l = List1.head; l; l = l->next)
        {
            Node* element = new Node(nullptr);
            element->student = l->student;
            add_element_with_sort(element);
        }
    }
    void separate_list(LinkedList& List1, LinkedList& List2)
    {
        int size1 = 0, size2 = 0;
        cout << "The size of the main list now is " << size() << endl;
        while (size1 + size2 != size())
        {
            cout << "Enter the size List1: ";
            cin >> size1;
            cout << "Enter the size List2: ";
            cin >> size2;
        }

        Node* l = head;

        for (int i = 0; i < size1; ++i)
        {
            Node* element = new Node(nullptr);
            element->student = l->student;
            List1.add_element_with_sort(element);
            l = l->next;
            delete_front();
        }
        for (int j = 0; j < size2; ++j)
        {
            Node* element = new Node(nullptr);
            element->student = l->student;
            List2.add_element_with_sort(element);
            l = l->next;
            delete_front();
        }
    }
    void merge_two_lists(LinkedList& List1, LinkedList& List2)
    {
        Node* l = List1.head;
        for (int i = 0; i < List1.size(); ++i)
        {
            Node* element = new Node(nullptr);
            element->student = l->student;
            add_element_with_sort(element);
            l = l->next;
        }
        l = List2.head;
        for (int i = 0; i < List2.size(); ++i)
        {
            Node* element = new Node(nullptr);
            element->student = l->student;
            add_element_with_sort(element);
            l = l->next;
        }
    }

    void output_list() const
    {
        cout << endl << "----------------------------------------" << endl;
        for (Node* l = head; l; l = l->next)
        {
            l->student.output_info();
            cout << "----------------------------------------" << endl;
        }
    }
};


void input_info(int&, int&, int&);
void make_task(LinkedList&, LinkedList&, int, int);
void fill_list_by_students(LinkedList&, int);

int main()
{
    int size = 0, n = 0, grade = 0;
    input_info(size, n, grade);

    LinkedList List_of_students;
    fill_list_by_students(List_of_students, size); // O(N^2)
    List_of_students.output_list(); //O(N)

    LinkedList Filtred_list;
    make_task(Filtred_list, List_of_students, n, grade); //O(N)

    /////////////////// For check

    //cout << "\n\n\n\n\n\n\n\n\n\n\nMerge\n";
    //LinkedList Merged_list;
    //List_of_students.output_list();
    //Filtred_list.output_list();
    // cout << "+++++++++++++++++++++++++++++\n";
    //Merged_list.merge_two_lists(List_of_students, Filtred_list);
    //Merged_list.output_list();

    //cout << "\n\n\n\n\n\n\n\n\n\nCopy\n";
    //LinkedList Copy_list;
    //List_of_students.output_list();
    //Copy_list.copy_list(List_of_students);
    //cout << "+++++++++++++++++++++++++++++\n";
    //Copy_list.output_list();
    
    //cout << "\n\n\n\n\n\n\n\n\n\n\nSort\n";
    //LinkedList Sort_list;
    //List_of_students.output_list();
    //Sort_list.copy_list(List_of_students);
    //cout << "+++++++++++++++++++++++++++++\n";
    //Sort_list.sort_students_by_course();
    //Sort_list.output_list();

    //cout << "\n\n\n\n\n\n\n\n\n\n\nSeparate\n";
    //LinkedList List1;
    //LinkedList List2;
    //List_of_students.output_list();
    //cout << "+++++++++++++++++++++++++++++\n";
    //List_of_students.separate_list(List1, List2);
    //List1.output_list();
    //List2.output_list();
    //List_of_students.output_list();
    return 0;
}

void input_info(int& size, int& n, int& grade)
{
    do
    {
        cout << "Enter the number of students: ";
        cin >> size;
    } while (size < 1);

    do
    {
        cout << "Enter the course: ";
        cin >> n;
    } while (n < 1 || n > 4);

    do
    {
        cout << "Enter the needed grade: ";
        cin >> grade;
    } while (grade < 1 || grade > 10);
}
void make_task(LinkedList& Filtred_list, LinkedList& List, int n, int grade)
{
    List.form_two_lists(Filtred_list, n, grade); //O(N)
    cout << endl << "List with deleted students" << endl;
    List.output_list(); //O(N)

    cout << endl << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\nList of needed students:";
    Filtred_list.output_list(); //O(N)
}
void fill_list_by_students(LinkedList& List, int size)
{
    for (int i = 0; i < size; ++i) 
    {
        Node* element = new Node(nullptr);
        List.add_element_with_sort(element); 
    }
}