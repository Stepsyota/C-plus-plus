//	Написать программу для работы с базой данных, содержащей записи
//  со сведениями о студентах: ФИО, возраст, пол, курс, успеваемость,
//  в которой должны выполняться следующие действия: создание файла,
//  просмотр файла. Выполнить задания для текстового файла. Размер
//  файлов <= 64GiB.

//	По исходному файлу определить всех отличников n курса.
//	Сформировать файл из этих студентов.

#include <iostream>
#include <fstream>

using namespace std;

struct Student
{
	char full_name[60];
	int age;
	bool gender;
	double grade;
	int course;
	int id;

	void fill_info(int counter = 0)
	{
		grade = (rand() % 70 + 30) / 10.0;
		course = rand() % 4 + 1;
		int day = rand() % 31 + 1;
		int month = rand() % 12 + 1;
		int year = rand() % 30 + 1975;

		gender = rand() % 2;
		age = rand() % 28 + 17;

		char all_names[250] = { "Kanye Omari West | Samuel Frederick Smith | Elizabeth Alexandra Mary | Dmitriy Aleksandrovich Hvorostovsky | Konstantin Edouardovich Tsiolkovskii | Karnitskaya Evelina Alekseevna | John Fitzgerald Kennedy | Ivan Sergeyevich Turgenev\0" };
		int index[100] = { 0, 15,19, 40,44, 67,71, 105,109, 144,148, 177,181, 203, 207, 231 };
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
	void output_info()
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
};

void add_element(ofstream&, const char*, int);
void add_element_in_another_file(ofstream&, Student&);
void add_element_to_the_end(const char*);
void fill_by_elements(const char*, int);
void read_file(const char*);
void fill_file_by_needed_grade(const char*, const char*, int, int);
int get_size_data(const char*);

int main()
{
	int number = 0;
	do {
		cout << "Enter the number of students: ";
		cin >> number;
	} while (number < 1);

	int needed_grade = 0;
	do
	{
		cout << "Enter the needed grade: ";
		cin >> needed_grade;
	} while (needed_grade < 1);

	int needed_course = 0;
	do
	{
		cout << "Enter the needed course: ";
		cin >> needed_course;
	} while (needed_course < 1 || needed_course > 4);

	const char* data_base_name = "data_base.txt\0";
	const char* result_data_name = "result_data.txt\0";

	fill_by_elements(data_base_name, number);
	read_file(data_base_name);

	fill_file_by_needed_grade(data_base_name, result_data_name, needed_grade, needed_course);
	cout << "===========================================================\n";
	cout << "Result data base of students: \n";
	read_file(result_data_name);

	remove(data_base_name);
	remove(result_data_name);
	return 0;
}

void fill_file_by_needed_grade(const char* main_file_name, const char* result_file_name,  int needed_grade, int needed_course)
{
	ifstream main_file(main_file_name);
	ofstream result_file(result_file_name);
	if (main_file.is_open() && result_file.is_open())
	{
		Student student;
		char first_name[30];
		char last_name[30];
		char patronymic[30];
		main_file >> student.id;
		while (!main_file.fail())
		{
			main_file >> first_name;
			main_file >> last_name;
			main_file >> patronymic;
			int counter = 0, counter_now = 0;
			for (int i = 0; first_name[i] != '\0'; ++i)
			{
				student.full_name[i] = first_name[i];
				counter_now++;
			}
			student.full_name[counter_now] = ' ';
			counter = counter_now + 1;
			for (int i = 0; last_name[i] != '\0'; ++i)
			{
				student.full_name[i + counter] = last_name[i];
				counter_now++;
			}
			student.full_name[counter_now] = ' ';
			counter = counter_now + 1;
			for (int i = 0; patronymic[i] != '\0'; ++i)
			{
				student.full_name[i + counter] = patronymic[i];
				counter_now++;
			}
			counter = counter_now + 1;
			student.full_name[counter] = '\0';
			main_file >> student.age;
			main_file >> student.gender;
			main_file >> student.course;
			main_file >> student.grade;
			if (student.grade >= needed_grade && student.course == needed_course)
			{
				add_element_in_another_file(result_file, student);
			}
			main_file >> student.id;
		}
		main_file.close(); //Нужно ли закрывать?
		result_file.close();
	}
	else
	{
		main_file.close();
		result_file.close();
		cout << "Can`t open" << endl;
		exit(1);
	}
}
void read_file(const char* file_name)
{
	ifstream file(file_name);
	if (file.is_open())
	{
		Student student;
		char first_name[30];
		char last_name[30];
		char patronymic[30];
		file >> student.id;
		while (!file.fail())
		{
			file >> first_name;
			file >>	last_name;
			file >> patronymic;
			int counter = 0, counter_now = 0;
			for (int i = 0; first_name[i] != '\0'; ++i)
			{
				student.full_name[i] = first_name[i];
				counter_now++;
			}
			student.full_name[counter_now] = ' ';
			counter = counter_now + 1;
			for (int i = 0; last_name[i] != '\0'; ++i)
			{
				student.full_name[i + counter] = last_name[i];
				counter_now++;
			}
			student.full_name[counter_now] = ' ';
			counter = counter_now + 1;
			for (int i = 0; patronymic[i] != '\0'; ++i)
			{
				student.full_name[i + counter] = patronymic[i];
				counter_now++;
			}
			counter = counter_now + 1;
			student.full_name[counter] = '\0';
			file >> student.age;
			file >> student.gender;
			file >> student.course;
			file >> student.grade;
			student.output_info();
			file >> student.id;
		}
		file.close(); //Нужно ли закрывать?
	}
	else
	{
		file.close();
		cout << "Can`t open" << endl;
		exit(1);
	}

}

void fill_by_elements(const char* file_name, int number)
{
	for (int i = 0; i < number; ++i)
	{
		add_element_to_the_end(file_name);
	}
}
void add_element_to_the_end(const char* file_name)
{
	fstream file(file_name, ios::app); //ate not working ?!?
	Student student;
	student.fill_info(get_size_data(file_name));
	// Передача ID студенту в качестве его порядкового номера
	
	file << student.id << ' ';
	file << student.full_name << ' ';
	file << student.age << ' ';
	file << student.gender << ' ';
	file << student.course << ' ';
	file << student.grade << '\n';
	file.close();
}

void add_element_in_another_file(ofstream& file, Student& student)
{
	file << student.id << ' ';
	file << student.full_name << ' ';
	file << student.age << ' ';
	file << student.gender << ' ';
	file << student.course << ' ';
	file << student.grade << '\n';
	
}
void add_element(ofstream& file, const char* file_name, int number)
{
	Student student;
	student.fill_info(get_size_data(file_name)); // Передача ID студенту в качестве его порядкового номера
	file << student.id << ' ';
	file << student.full_name << ' ';
	file << student.age << ' ';
	file << student.gender << ' ';
	file << student.course << ' ';
	file << student.grade << '\n';	
}
int get_size_data(const char* file_name)
{
	int size = 0;
	ifstream file(file_name);
	if (file.is_open())
	{
		Student student;
		char first_name[30];
		char last_name[30];
		char patronymic[30];
		file >> student.id;
		while (!file.fail())
		{
			file >> first_name;
			file >> last_name;
			file >> patronymic;
			file >> student.age;
			file >> student.gender;
			file >> student.course;
			file >> student.grade;
			file >> student.id;
			size++;
		}
		file.close();
	}
	else
	{
		cout << "Can`t open" << endl;
		exit(1);
	}
	return size;
}

void edit_student_by_ID(const char* file_name, int needed_id) // Not finish
{
	fstream file(file_name);
	Student student;
	char first_name[30];
	char last_name[30];
	char patronymic[30];
	file >> student.id;
	while (!file.fail())
	{
		if (student.id == needed_id)
		{
			int choice = 0;
			cout << "What you want to change?\n1.First name\n2. Last name\n 3. Patronymic\n4. Age\n5. Gender\n6. Course\n7. Grade";
			cin >> choice;
			switch (choice)
			{
				case 1:
				{
					cout << "Enter info: ";
					cin >> first_name;
					break;
				}
				case 2:
				{
					cout << "Enter info: ";
					cin >> last_name;
					break;
				}
				case 3:
				{
					cout << "Enter info: ";
					cin >> patronymic;
					break;
				}
				case 4:
				{
					cout << "Enter info: ";
					cin >> student.age;
					break;
				}
				case 5:
				{
					cout << "Enter info: ";
					cin >> student.gender;
					break;
				}
				case 6:
				{
					cout << "Enter info: ";
					cin >> student.course;
					break;
				}
				case 7:
				{
					cout << "Enter info: ";
					cin >> student.grade;
					break;
				}
				default:
				{
					cout << "Incorrect choice";
					return;
				}
					
			}
		}
		file >> first_name;
		file >> last_name;
		file >> patronymic;
		file >> student.age;
		file >> student.gender;
		file >> student.course;
		file >> student.grade;
		
	}
	file.close();
}