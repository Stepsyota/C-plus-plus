#include "Student.h"

void Student::fill_info(int counter = 0)
{
	grade = (rand() % 70 + 30) / 10.0;
	course = rand() % 4 + 1;
	gender = rand() % 2;
	age = rand() % 28 + 17;

	char all_names[250] = { "Kanye Omari West | Samuel Frederick Smith | Elizabeth Alexandra Mary | Dmitriy Aleksandrovich Hvorostovsky | Konstantin Edouardovich Tsiolkovskii | Karnitskaya Evelina Alekseevna | John Fitzgerald Kennedy | Ivan Sergeyevich Turgenev\0" };
	int index[16] = { 0, 15,19, 40,44, 67,71, 105,109, 144,148, 177,181, 203, 207, 231 };
	int start = rand() % 8 * 2;
	int end = start + 1;
	int k = 0;
	for (index[start]; index[start] <= index[end]; ++index[start])
	{
		full_name[k] = all_names[index[start]];
		k++;
	}
	full_name[k] = '\0';

	id = counter;
}

void Student::output_info()
{
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
	cout << "ID: " << id << endl;
	cout << "Full name: " << full_name << endl;
	cout << "Age: " << age << endl;
	cout << "Gender: ";
	if (gender)
	{
		cout << "Man\n";
	}
	else
	{
		cout << "Woman\n";
	}
	cout << "Course: " << course << endl;
	cout << "Grade: " << grade << endl;
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n";
}