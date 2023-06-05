#include <iostream>
#include <string>
using namespace std;

class Shape {
protected:
	string name;
	int x;
	int y;
public:
	Shape(string s, int x, int y) { name = s; this->x = x; this->y = y; }
	string getName() { return name; }
	virtual int getArea() = 0;
};

class Oval : public Shape {
public:
	Oval(string s, int x, int y) : Shape(s, x, y) {}
	int getArea() { return 3.14 * x * y; }
};

class Rect : public Shape {
public:
	Rect(string s, int x, int y) : Shape(s, x, y) {}
	int getArea() { return x * y; }
};

class Trianglar : public Shape {
public:
	Trianglar(string s, int x, int y) : Shape(s, x, y) {}
	int getArea() { return x * y / 2; }
};

int main()
{
	Shape* p[3];

	p[0] = new Oval("ºó´ë¶±", 10, 20);
	p[1] = new Rect("Âû¶±", 30, 40);
	p[2] = new Trianglar("Åä½ºÆ®", 30, 40);

	for (int i = 0; i < 3; i++)
	{
		cout << p[i]->getName() << " ³ĞÀÌ´Â " << p[i]->getArea() << endl;
	}
	for (int i = 0; i < 3; i++)
	{
		delete p[i];
	}
	return 0;
}