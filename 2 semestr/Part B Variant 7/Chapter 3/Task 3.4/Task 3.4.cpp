//	Написать программу для работы с базой данных, содержащей записи
//  со сведениями о студентах: ФИО, возраст, пол, курс, успеваемость,
//  в которой должны выполняться следующие действия: создание файла,
//  просмотр файла. Выполнить задания для текстового файла. Размер
//  файлов <= 64GiB.

//	По исходному файлу определить всех отличников n курса.
//	Сформировать файл из этих студентов.

#include "Task 3.4.h"
using namespace std;

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

	make_data_base_with_needed_length(data_base_name, number);
	read_file(data_base_name);

	make_file_with_needed_students(data_base_name, result_data_name, needed_grade, needed_course);
	cout << "===========================================================\n";
	cout << "Result data base of students: \n";
	read_file(result_data_name);


	edit_student_by_ID(data_base_name);
	read_file(data_base_name);
	//delete_student_by_ID(data_base_name);
	//read_file(data_base_name);
	clear_file(data_base_name);
	clear_file(result_data_name);
	return 0;
}