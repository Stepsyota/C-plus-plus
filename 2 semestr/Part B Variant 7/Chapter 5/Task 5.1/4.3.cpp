//	«аписать в новую строку слова исходной строки, в которых
//  нет повтор€ющихс€ букв.

#include "4.3.h"

void make_task_4_3()
{
	string text; // For example: jacket ball.industry,claymore:interesting;thing!forest?particle-boom(tea)figure
	cout << "Enter the text:\n";
	getline(cin, text);
	cout << "Text: " << text << endl;
	
	string separators = { " .,:;!?-()" };
	string result_text;
	vector<int> indexes {-1};

	for (size_t i = 0; i < text.size(); ++i) // Ќахождение индексов всех разделителей
	{
		for (size_t j = 0; j < separators.size(); ++j)
		{
			if (text[i] == separators[j])
			{
				indexes.push_back(i);
			}
		}
	}
	indexes.push_back(text.size());

	string temp;
	for (size_t i = 1; i < indexes.size(); ++i)
	{
		size_t temp_size = 0;
		for (size_t j = indexes[i - 1] + 1; j < indexes[i]; ++j)
		{
			temp.push_back(text[j]);
			temp_size++;

		}
		if (check_str(temp))
		{
			result_text += temp + ' ';
		}
		temp.clear();
	}
	cout << "Result text: " << result_text << endl;
}

bool check_str(string text)
{
	for (size_t i = 0; i < text.size() - 1; ++i)
	{
		for (size_t j = i + 1; j < text.size(); ++j)
		{
			if (text[i] == text[j])
			{
				return false;
			}
		}
	}
	return true;
}
