//Написать программу для создания массива записей со сведениями о студен -
//тах(ФИО, возраст, курс, пол, успеваемость). Оформить заполнение и вывод
//массива отдельными функциями. Написать функцию, которая по заданному
//массиву определяет средний возраст студентов n курса

#include <iostream>
#include <string>

using namespace std;

struct Student
{
	char name[250];
	int age;
	int course;
	bool gender;
	double grade;
};

void Set_data_student(int n, Student * );
void Output_student(Student*, int, int);
void Find_average_age(Student*, int, int);

int main()
{
	int n;
	cout << "Select the number of students" << endl;
	cin >> n;
	const int size = 1000;
	Student student[size];
	Set_data_student(n, student);
	cout << endl;
	for (int i = 0; i < n; ++i)
	{
		Output_student(student, i, n);
	}
	int choise;
	cout << "Choose a course to calculate the average age" << endl;
	cin >> choise;
	Find_average_age(student, choise, n);
}


void Set_data_student(int n, Student* student)
{
	for (int i = 0; i < n; ++i)
	{	
		do
		{
			cout << "Enter the name of the student " << i + 1 << ": ";
			cin >> student[i].name;
		} while ((*student[i].name >= 'Z' && *student[i].name <= 'a') || (*student[i].name < 'A' || *student[i].name > 'z'));

		student[i].gender = rand() % 2;
		student[i].age = rand() % 20 + 17;
		student[i].course = rand() % 4 + 1;
		student[i].grade = (rand() % 90 + 10) / 10.0;
	}
}

void Output_student(Student* student, int i, int n)
{
	cout << "Full name: " << student[i].name << endl;
	if (student[i].gender == 0)
	{
		cout << "Gender: Female" << endl;
	}
	else
	{
		cout << "Gender: Male" << endl;
	}
	cout << "Age: " << student[i].age << endl;
	cout << "Course: " << student[i].course << endl;
	cout << "Grade: " << student[i].grade << endl;
	cout << "---------------------------" << endl;
}

void Find_average_age(Student* student, int choise, int n)
{
	int Sum = 0, counter = 0;
	double counter_double;
	double Average_age;
	for (int i = 0; i < n; ++i)
	{
		if (student[i].course == choise)
		{
			Sum += student[i].age;
			counter++;
		}
		
	}
	if (counter == 0)
	{
		cout << "There are no students of this course" << endl;
	}
	else
	{
		counter_double = static_cast<double>(counter);
		Average_age = Sum / counter_double;
		cout << "Average age of " << choise << " course: " << Average_age;
	}	
}