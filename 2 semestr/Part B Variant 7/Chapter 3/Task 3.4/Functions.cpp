#include "Functions.h"

void make_student_full_name(Student& student, char first_name[], char last_name[], char patronymic[])
{
	int counter = 0, counter_now = 0;
	for (int i = 0; first_name[i] != '\0'; ++i)
	{
		student.full_name[i] = first_name[i];
		counter_now++;
	}
	student.full_name[counter_now] = ' ';
	counter = counter_now + 1;
	counter_now = counter;
	for (int i = 0; last_name[i] != '\0'; ++i)
	{
		student.full_name[i + counter] = last_name[i];
		counter_now++;
	}
	student.full_name[counter_now] = ' ';
	counter = counter_now + 1;
	counter_now = counter;
	for (int i = 0; patronymic[i] != '\0'; ++i)
	{
		student.full_name[i + counter] = patronymic[i];
		counter_now++;
	}
	student.full_name[counter_now] = '\0';
}
void edit_student_by_ID(const char* file_main_name) // Not finish
{
	int needed_id = -1;
	do
	{
		cout << "Enter the needed id to edit: ";
		cin >> needed_id;
	} while (needed_id < 0 || needed_id > get_size_file(file_main_name));

	int choice = 0;
	cout << "What do you want to change?\n1. First name\n2. Last name\n3. Patronymic\n4. Age\n5. Gender\n6. Course\n7. Grade\n";
	cin >> choice;

	const char* file_edit_name = "file_edit.txt";
	ifstream file(file_main_name);
	ofstream file_edit(file_edit_name);

	if (!file.is_open() && !file_edit.is_open())
	{
		file.close();
		file_edit.close();
		cout << "Can`t open" << endl;
		exit(1);
	}

	Student student;
	file >> student.id;
	while (!file.fail())
	{
		char first_name[80];
		char last_name[80];
		char patronymic[80];
		file >> first_name;
		file >> last_name;
		file >> patronymic;
		file >> student.age;
		file >> student.gender;
		file >> student.course;
		file >> student.grade;
		if (student.id == needed_id)
		{

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
					do
					{
						cout << "Enter info: ";
						cin >> student.age;
					} while (student.age < 0 || student.age > 100);
					break;
				}
				case 5:
				{
					do
					{
						cout << "Enter info: ";
						cin >> student.gender;
					} while (student.gender < 0 || student.gender > 1);
					break;
				}
				case 6:
				{
					do
					{
						cout << "Enter info: ";
						cin >> student.course;
					} while (student.course < 0 || student.course > 4);
					break;
				}
				case 7:
				{
					do
					{
						cout << "Enter info: ";
						cin >> student.grade;
					} while (student.grade < 0 || student.grade > 10);
					break;
				}
				default:
				{
					cout << "Incorrect choice";
					return;
				}
			}
		}
		make_student_full_name(student, first_name, last_name, patronymic);
		add_element_in_another_file(file_edit, student);
		file >> student.id;
	}
	file.close();
	file_edit.close();
	clear_file(file_main_name);
	redefine_two_files(file_main_name, file_edit_name);
}
void delete_student_by_ID(const char* file_main_name) // Not finish
{
	int needed_id = -1;
	do
	{
		cout << "Enter the needed id to delete: ";
		cin >> needed_id;
	} while (needed_id < 0 || needed_id > get_size_file(file_main_name));

	const char* file_edit_name = "file_edit.txt";
	ifstream file(file_main_name);
	ofstream file_edit(file_edit_name);

	if (!file.is_open() && !file_edit.is_open())
	{
		file.close();
		file_edit.close();
		cout << "Can`t open" << endl;
		exit(1);
	}

	Student student;
	file >> student.id;
	while (!file.fail())
	{
		char first_name[80];
		char last_name[80];
		char patronymic[80];
		file >> first_name;
		file >> last_name;
		file >> patronymic;
		file >> student.age;
		file >> student.gender;
		file >> student.course;
		file >> student.grade;
		if (student.id != needed_id)
		{
			make_student_full_name(student, first_name, last_name, patronymic);
			add_element_in_another_file(file_edit, student);
		}
		file >> student.id;
	}
	file.close();
	file_edit.close();
	clear_file(file_main_name);
	redefine_two_files(file_main_name, file_edit_name);
}
void redefine_two_files(const char* file_to_edit_info_name, const char* temp_file_with_main_info_name)
{
	ifstream file_main(temp_file_with_main_info_name);
	ofstream file_edit(file_to_edit_info_name);

	if (!file_main.is_open() || !file_edit.is_open())
	{
		file_main.close();
		file_edit.close();
		cout << "Cant open";
		exit(2);
	}
	Student student;
	file_main >> student.id;
	while (!file_main.fail())
	{
		char first_name[80];
		char last_name[80];
		char patronymic[80];
		file_main >> first_name;
		file_main >> last_name;
		file_main >> patronymic;
		make_student_full_name(student, first_name, last_name, patronymic);
		file_main >> student.age;
		file_main >> student.gender;
		file_main >> student.course;
		file_main >> student.grade;
		add_student_to_the_end(file_to_edit_info_name, student);
		file_main >> student.id;
	}

	file_main.close();
	file_edit.close();
	remove(temp_file_with_main_info_name);
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
void add_student_to_the_end(const char* file_name)
{
	fstream file(file_name, ios::app);
	if (!file.is_open())
	{
		file.close();
		cout << "Can`t open" << endl;
		exit(3);
	}
	Student student;
	student.fill_info(get_size_file(file_name)); // Передача ID студенту в качестве его порядкового номера
	file << student.id << ' ';
	file << student.full_name << ' ';
	file << student.age << ' ';
	file << student.gender << ' ';
	file << student.course << ' ';
	file << student.grade << '\n';
	file.close();
}
void add_student_to_the_end(const char* file_name, Student& student)
{
	fstream file(file_name, ios::app);
	if (!file.is_open())
	{
		file.close();
		cout << "Can`t open" << endl;
		exit(4);
	}
	file << student.id << ' ';
	file << student.full_name << ' ';
	file << student.age << ' ';
	file << student.gender << ' ';
	file << student.course << ' ';
	file << student.grade << '\n';
	file.close();
}
void make_data_base_with_needed_length(const char* file_name, int number)
{
	for (int i = 0; i < number; ++i)
	{
		add_student_to_the_end(file_name);
	}
}
void make_file_with_needed_students(const char* main_file_name, const char* result_file_name, int needed_grade, int needed_course)
{
	ifstream main_file(main_file_name);
	ofstream result_file(result_file_name);
	if (!main_file.is_open() && !result_file.is_open())
	{
		main_file.close();
		result_file.close();
		cout << "Can`t open" << endl;
		exit(5);
	}
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
		make_student_full_name(student, first_name, last_name, patronymic);
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
	main_file.close();
	result_file.close();
}
void read_file(const char* file_name)
{
 	ifstream file(file_name);
	if (!file.is_open())
	{
		cout << "Can`t open" << endl;
		exit(6);
	}
	Student student;
	file >> student.id;
	while (!file.fail())
	{
		char first_name[80];
		char last_name[80];
		char patronymic[80];
		file >> first_name;
		file >> last_name;
		file >> patronymic;
		make_student_full_name(student, first_name, last_name, patronymic);
		file >> student.age;
		file >> student.gender;
		file >> student.course;
		file >> student.grade;
		student.output_info();
		file >> student.id;
	}
	file.close();
}
int get_size_file(const char* file_name)
{
	int size = 0;
	ifstream file(file_name);
	if (!file.is_open())
	{
		cout << "Can`t open" << endl;
		exit(7);
	}
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
	return size;
}
void clear_file(const char* file_name)
{
	ofstream file(file_name);
	if (!file.is_open())
	{
		file.close();
		cout << "Can`t open" << endl;
		exit(8);
	}
	file.clear();
	file.close();
}