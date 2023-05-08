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
		cout << "원 " << i + 1 << "의 반지름 >> ";
		cin >> temp;
		obj[i].setRadius(temp);
		if (obj[i].getArea() > 100)
		{
			Circle::count++;
		}
	}
	cout << "면적이 100보다 큰 원 " << Circle::count << "개입니다." << endl;
	return 0;
}