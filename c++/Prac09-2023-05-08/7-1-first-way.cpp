#include <iostream>
using namespace std;

class Circle {
	int radius;
public:
	void setRadius(int radius) { this->radius = radius; }
	double getArea() { return 3.14 * radius * radius; }
};

int main()
{
	Circle obj[3] = {Circle(),};
	int count = 0;
	for (int i = 0; i < 3; i++)
	{
		int temp;
		cout << "�� " << i + 1 << "�� ������ >> ";
		cin >> temp;
		obj[i].setRadius(temp);
		if (obj[i].getArea() > 100)
		{
			count++;
		}
	}
	cout << "������ 100���� ū �� " << count << "���Դϴ�." << endl;
	return 0;
}