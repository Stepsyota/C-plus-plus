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
void edit_student_by_ID(const char* file_main_name)
{
	int needed_id = -1;
	do
	{
		cout << "Enter the needed id to edit: ";
		cin >> needed_id;
	} while (needed_id < 0 || needed_id > get_size_file(file_main_name));

	int choice = 0;
	cout << "What do you want to change?\n1. Full name\n2. Age\n3. Gender\n4. Course\n5. Grade\n";
	cin >> choice;

	const char* file_edit_name = "file_edit.bin";
	ifstream file(file_main_name, ios::binary);
	ofstream file_edit(file_edit_name, ios::binary);

	if (!file.is_open() && !file_edit.is_open())
	{
		file.close();
		file_edit.close();
		cout << "Can`t open" << endl;
		exit(1);
	}

	Student student;
	file.read(reinterpret_cast<char*>(&student.id), sizeof(int));
	while (!file.fail())
	{
		file.read(student.full_name, sizeof(char[90]));
		file.read(reinterpret_cast<char*>(&student.age), sizeof(int));
		file.read(reinterpret_cast<char*>(&student.gender), sizeof(bool));
		file.read(reinterpret_cast<char*>(&student.course), sizeof(int));
		file.read(reinterpret_cast<char*>(&student.grade), sizeof(double));
		if (student.id == needed_id)
		{

			switch (choice)
			{
			case 1:
			{
				char first_name[30];
				char last_name[30];
				char patronymic[30];
				cout << "Enter info: ";
				cin >> first_name;
				cin >> last_name;
				cin >> patronymic;
				make_student_full_name(student, first_name, last_name, patronymic);
				break;
			}
			case 2:
			{
				do
				{
					cout << "Enter info: ";
					cin >> student.age;
				} while (student.age < 0 || student.age > 100);
				break;
			}
			case 3:
			{
				do
				{
					cout << "Enter info: ";
					cin >> student.gender;
				} while (student.gender < 0 || student.gender > 1);
				break;
			}
			case 4:
			{
				do
				{
					cout << "Enter info: ";
					cin >> student.course;
				} while (student.course < 0 || student.course > 4);
				break;
			}
			case 5:
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
		add_element_in_another_file(file_edit, student);
		file.read(reinterpret_cast<char*>(&student.id), sizeof(int));
	}
	file.close();
	file_edit.close();
	clear_file(file_main_name);
	redefine_two_files(file_main_name, file_edit_name);
}
void delete_student_by_ID(const char* file_main_name)
{
	int needed_id = -1;
	do
	{
		cout << "Enter the needed id to delete: ";
		cin >> needed_id;
	} while (needed_id < 0 || needed_id > get_size_file(file_main_name));

	const char* file_edit_name = "file_edit.bin";
	ifstream file(file_main_name, ios::binary);
	ofstream file_edit(file_edit_name, ios::binary);

	if (!file.is_open() && !file_edit.is_open())
	{
		file.close();
		file_edit.close();
		cout << "Can`t open" << endl;
		exit(1);
	}

	Student student;
	file.read(reinterpret_cast<char*>(&student.id), sizeof(int));
	while (!file.fail())
	{
		file.read(student.full_name, sizeof(char[90]));
		file.read(reinterpret_cast<char*>(&student.age), sizeof(int));
		file.read(reinterpret_cast<char*>(&student.gender), sizeof(bool));
		file.read(reinterpret_cast<char*>(&student.course), sizeof(int));
		file.read(reinterpret_cast<char*>(&student.grade), sizeof(double));
		if (student.id != needed_id)
		{
			add_element_in_another_file(file_edit, student);
		}
		file.read(reinterpret_cast<char*>(&student.id), sizeof(int));
	}
	file.close();
	file_edit.close();
	clear_file(file_main_name);
	redefine_two_files(file_main_name, file_edit_name);
}
void redefine_two_files(const char* file_old_name, const char* file_new_name)
{
	remove(file_old_name);
	if (rename(file_new_name, file_old_name) != 0)
	{
		cout << "Error with rename file";
		exit(9);
	}
}
void add_element_in_another_file(ofstream& file, Student& student)
{
	file.write(reinterpret_cast<char*>(&student.id), sizeof(int));
	file.write(student.full_name, sizeof(char[90]));
	file.write(reinterpret_cast<char*>(&student.age), sizeof(int));
	file.write(reinterpret_cast<char*>(&student.gender), sizeof(bool));
	file.write(reinterpret_cast<char*>(&student.course), sizeof(int));
	file.write(reinterpret_cast<char*>(&student.grade), sizeof(double));
}
void add_student_to_the_end(const char* file_name)
{
	fstream file(file_name, ios::app, ios::binary);
	if (!file.is_open())
	{
		file.close();
		cout << "Can`t open" << endl;
		exit(3);
	}
	Student student;
	student.fill_info(get_size_file(file_name)); // Передача ID студенту в качестве его порядкового номера
	file.write(reinterpret_cast<char*>(&student.id), sizeof(int));
	file.write(student.full_name, sizeof(char[90]));
	file.write(reinterpret_cast<char*>(&student.age), sizeof(int));
	file.write(reinterpret_cast<char*>(&student.gender), sizeof(bool));
	file.write(reinterpret_cast<char*>(&student.course), sizeof(int));
	file.write(reinterpret_cast<char*>(&student.grade), sizeof(double));
	file.close();
}
void add_student_to_the_end(const char* file_name, Student& student)
{
	fstream file(file_name, ios::app, ios::binary);
	if (!file.is_open())
	{
		file.close();
		cout << "Can`t open" << endl;
		exit(4);
	}
	file.write(reinterpret_cast<char*>(&student.id), sizeof(int));
	file.write(student.full_name, sizeof(char[90]));
	file.write(reinterpret_cast<char*>(&student.age), sizeof(int));
	file.write(reinterpret_cast<char*>(&student.gender), sizeof(bool));
	file.write(reinterpret_cast<char*>(&student.course), sizeof(int));
	file.write(reinterpret_cast<char*>(&student.grade), sizeof(double));
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
	ifstream main_file(main_file_name, ios::binary);
	ofstream result_file(result_file_name, ios::binary);
	if (!main_file.is_open() && !result_file.is_open())
	{
		main_file.close();
		result_file.close();
		cout << "Can`t open" << endl;
		exit(5);
	}
	Student student;
	main_file.read(reinterpret_cast<char*>(&student.id), sizeof(int));
	while (!main_file.fail())
	{
		main_file.read(student.full_name, sizeof(char[90]));
		main_file.read(reinterpret_cast<char*>(&student.age), sizeof(int));
		main_file.read(reinterpret_cast<char*>(&student.gender), sizeof(bool));
		main_file.read(reinterpret_cast<char*>(&student.course), sizeof(int));
		main_file.read(reinterpret_cast<char*>(&student.grade), sizeof(double));
		if (student.grade >= needed_grade && student.course == needed_course)
		{
			add_element_in_another_file(result_file, student);
		}
		main_file.read(reinterpret_cast<char*>(&student.id), sizeof(int));
	}
	main_file.close();
	result_file.close();
}
void read_file(const char* file_name)
{
	ifstream file(file_name, ios::binary);
	if (!file.is_open())
	{
		cout << "Can`t open" << endl;
		exit(6);
	}
	Student student;
	file.read(reinterpret_cast<char*>(&student.id), sizeof(int));
	while (!file.fail())
	{
		file.read(student.full_name, sizeof(char[90]));
		file.read(reinterpret_cast<char*>(&student.age), sizeof(int));
		file.read(reinterpret_cast<char*>(&student.gender), sizeof(bool));
		file.read(reinterpret_cast<char*>(&student.course), sizeof(int));
		file.read(reinterpret_cast<char*>(&student.grade), sizeof(double));
		student.output_info();
		file.read(reinterpret_cast<char*>(&student.id), sizeof(int));
	}
	file.close();
}
int get_size_file(const char* file_name)
{
	int size = 0;
	ifstream file(file_name, ios::binary);
	if (!file.is_open())
	{
		cout << "Can`t open" << endl;
		exit(7);
	}
	Student student;

	file.read(reinterpret_cast<char*>(&student.id), sizeof(int));
	while (!file.fail())
	{
		file.read(student.full_name, sizeof(char[90]));
		file.read(reinterpret_cast<char*>(&student.age), sizeof(int));
		file.read(reinterpret_cast<char*>(&student.gender), sizeof(bool));
		file.read(reinterpret_cast<char*>(&student.course), sizeof(int));
		file.read(reinterpret_cast<char*>(&student.grade), sizeof(double));
		file.read(reinterpret_cast<char*>(&student.id), sizeof(int));
		size++;
	}
	file.close();
	return size;
}
void clear_file(const char* file_name)
{
	ofstream file(file_name, ios::binary);
	if (!file.is_open())
	{
		file.close();
		cout << "Can`t open" << endl;
		exit(8);
	}
	file.clear();
	file.close();
}