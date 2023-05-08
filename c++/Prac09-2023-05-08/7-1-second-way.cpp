#include <iostream>
using namespace std;

class Circle {
	int radius;
public:
	static int count;
	void setRadius(int radius) { this->radius = radius; }
	double getArea() { return 3.14 * radius * radius; }
};

int Circle::count = 0;

int main()
{
	Circle obj[3] = { Circle(), };

	for (int i = 0; i < 3; i++)
	{
		int temp;
		cout << "�� " << i + 1 << "�� ������ >> ";
		cin >> temp;
		obj[i].setRadius(temp);
		if (obj[i].getArea() > 100)
		{
			Circle::count++;
		}
	}
	cout << "������ 100���� ū �� " << Circle::count << "���Դϴ�." << endl;
	return 0;
}