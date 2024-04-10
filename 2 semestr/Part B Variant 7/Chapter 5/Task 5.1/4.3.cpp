//	«аписать в новую строку слова исходной строки, в которых
//  нет повтор€ющихс€ букв.

#include "4.3.h"

void make_tasK_4_3()
{
	string text;
	cout << "Enter the text:\n";
	getline(cin, text);
	cout << "Text: " << text << endl;
	
	string separators = { " .,:;!?-()" };
	string result_text;
	vector<size_t> indexes {0};

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

	for (size_t i = 1; i < indexes.size(); ++i)
	{
		for (size_t j = indexes[i - 1]; j < indexes[i]; ++j)
		{
			
		}
	}
}