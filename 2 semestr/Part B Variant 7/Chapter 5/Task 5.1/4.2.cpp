// Ќайти все простые числа, не превосход€щие заданного натурального
//  числа N, двоична€ запись которых представл€ет собой симметричную
//  последовательность нулей и единиц(начинающуюс€ единицей!).

#include "4.2.h"

void make_task_4_2()
{
	size_t number = 0;
	cout << "Enter the number:\n";
	cin >> number;

	size_t current = 0;
	while (current <= number)
	{
		string number_bin;
		size_t temp_current = current;

		// «апись числа в двоичный вид в обратной форме
		do
		{
			size_t remain = temp_current % 2;
			number_bin.push_back(char('0' + remain));
			temp_current = temp_current / 2;
		} while (temp_current > 0);
		
		// ѕереворот записи числа в пр€мой вид
		size_t size_str = number_bin.size();
		for (size_t i = 0; i < size_str / 2; ++i)
		{
			swap(number_bin[i], number_bin[size_str - i - 1]);
		}

		bool symmetry = 1;
		if (number_bin[0] != '1') // ѕервый элемент отличен от 1
		{
			current++;
			continue;
		}

		for (size_t i = 0; i < size_str / 2; ++i) // ѕроверка на симметрию
		{
			if (number_bin[i] == number_bin[size_str - i - 1])
			{
				continue;
			}
			else
			{
				symmetry = 0;
				break;
			}
		}

		if (symmetry && check_prime_number(current))
		{
			cout << "The number " << current << " is symmetry and prime. His binary form: "
				 << number_bin << endl;
		}
		/*else
		{
			{
				cout << "The number " << current << " is not symmetry or not prime. His binary form: "
					<< number_bin << endl;
			}
		}*/
		current++;
	}
}

bool check_prime_number(size_t current)
{
	for (size_t i = 2; i < current; ++i)
	{
		if (current % i == 0)
		{
			return false;
		}
	}
	return true;
}