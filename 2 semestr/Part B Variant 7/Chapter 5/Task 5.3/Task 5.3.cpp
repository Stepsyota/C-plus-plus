#include "Task 5.3.h"

int main()
{
	bool next_task = 1;
	do
	{
		int choice = 0;
		do
		{
			cout << "Choose a task:\n1. Task 2.4\n2. Task 2.6\n";
			cin >> choice;
		} while (choice < 1 || choice > 2);
		switch (choice)
		{
		case 1:
		{
			cout << "Task 2.4\n";
			make_task_2_4();
			break;
		}
		case 2:
		{
			cout << "Task 2.6\n";
			make_task_2_6();
			break;
		}
		default:
			cout << "Error";
			exit(2);
		}

		int choice_next = 0;
		do
		{
			cout << "Do you want to complete one more task?\n1. Yes\n2. No\n";
			cin >> choice_next;
		} while (choice_next < 0 || choice_next > 2);

		if (choice_next == 1)
		{
			next_task = 1;
		}
		else
		{
			next_task = 0;
		}
	} while (next_task);
	return 0;
}