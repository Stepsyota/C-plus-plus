// На поле (k, l) расположен ферзь. Угрожает ли он полю (m, n)?
#include <iostream>
using namespace std;

int main()
{
	int x1, y1, x2, y2;
	cout << "k = "; cin >> x1;
	cout << "l = "; cin >> y1;
	cout << "m = "; cin >> x2;
	cout << "n = "; cin >> y2;

	if (x1 <= 0 || x1 > 8 && y1 <= 0 && y1 > 8 && x2 <= 0 || x2 > 8 && y2 <= 0 && y2 > 8)
	{
		cout << "Incorrect. Field coordinates from 1 to 8";
		return 0;
	}
	if (x1 == x2 && y1 == y2)
	{
		cout << "The start and the end point are the same";
		return 0;
	}
	if (x1 == x2 || x1 == y2 || y1 == x2 || y1 == y2 || //vert i goriz
		x2 - x1 == y2 - y1 || x2 - x1 == y1 - y2 || y2 - y1 == x1 - x2) // diag
	{
		cout << "Queen can attack";
	}
	else
	{
		cout << "Queen cant attack";
	}
	return 0;
}