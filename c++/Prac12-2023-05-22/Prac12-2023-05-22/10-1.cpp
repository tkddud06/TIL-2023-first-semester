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
	NamedCircle(int radius = 0, string name="") : Circle(radius) { this->name = name; }
	void show() { cout << "반지름이 " << radius << "인 " << name << endl; }
};


int main()
{
	NamedCircle waffle(3, "waffle");
	waffle.show();
	return 0;
}