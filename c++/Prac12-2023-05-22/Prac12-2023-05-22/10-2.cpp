#include <iostream>
#include <string>
using namespace std;
class Circle {
protected:
	int radius;
public:
	Circle(int radius = 0) { this->radius = radius; }
};

class NamedCircle : public Circle {
	string name;
public:
	NamedCircle(int radius = 0, string name = "") : Circle(radius) { this->name = name; }
	string get_name() { return name; }
	void set_namedcircle(int radius, string name) { this->radius = radius; this->name = name; }
	double get_area() { return 3.14 * radius * radius; }
};


int main()
{
	NamedCircle pizza[5];
	int num;
	string name;
	int max_index = 0;
	cout << "5���� ���� �������� ���� �̸��� �Է��ϼ���." << endl;
	for (int i = 0; i < 5; i++)
	{
		cout << i + 1 << " >> ";
		cin >> num;
		cin >> name;
		pizza[i].set_namedcircle(num, name);
		if (pizza[i].get_area() > pizza[max_index].get_area())
		{
			max_index = i;
		}
	}
	cout << "���� ������ ū ���ڴ� " << pizza[max_index].get_name() << "�Դϴ�." << endl;
	return 0;
}