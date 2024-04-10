//	Из заданного текста удалить символы, которые образуют
//  максимальную серию(подряд идущих одинаковых символов).

#include "4.1.h"

void make_task_4_1()
{
	string text;
	cout << "Enter the text:\n";
	getline(cin, text);
	cout << "Text: " << text << endl;
	size_t index_start = 0;
	size_t current = 0;
	size_t size_now = 1;
	size_t size_common = 1;
	bool compare_now = 0;

	for (size_t i = 0; i < text.size() - 1; ++i)
	{
		if (!compare_now)
		{
			if (size_common < size_now)
			{
				size_common = size_now;
				index_start = current;
				
			}
			size_now = 1;
		}

		if (text[i] == text[i + 1])
		{
			if (!compare_now)
			{
				current = i;
			}
			size_now++;
			compare_now = 1;
		}
		else
		{
			compare_now = 0;
		}
	}

	if (size_common < size_now) // Необходимо, если макс. серия расположена в самом конце
	{
		size_common = size_now;
		index_start = current;

	}
	cout << "Index start: " << index_start << endl
		 << "Size: " << size_common << endl;

	text.erase(index_start, size_common);

	cout << "Text after delete: " << text << endl;
}