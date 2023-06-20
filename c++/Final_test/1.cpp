#include <iostream>
using namespace std;

// max() �Լ� ����
template <class T>
T max(T list[], int n)
{
	T highest = list[0];
	for (int i = 0; i < n; i++)
	{
		if (highest < list[i])
		{
			highest = list[i];
		}
	}
	return highest;
}


int main()
{
	int x[] = { 3,4,1,5,2 };
	char c[] = { 'e','a','c','d','b','f' };

	cout << max(x, 5) << " " << max(c, 6);
}


//#include <iostream>
//using namespace std;
//
//// �⺻ Ŭ���� Shape
//// ������ �ʺ�(width), ������ ����(height)����
//// ����(area()) ��� �����Լ� ����
//
//class Shape {
//public:
//	int width;
//	int height;
//	virtual int area() = 0;
//};
//
//// �Ļ� Ŭ���� Rectangle
//// Shape ���
//// �⺻ ������ �Ȱ����� ��, �ʺ�� ���� ���ڷ� �޴� ������ ����
//// area �������̵��ؼ� ����
//
//class Rectangle : public Shape {
//public:
//	Rectangle(int x, int y)
//	{
//		width = x;
//		height = y;
//	}
//	int area()
//	{
//		return width * height;
//	}
//};
//
//
//int main()
//{
//	Rectangle rect(5, 3);
//	cout << rect.width << " " << rect.height << " " << rect.area();
//}


//#include <iostream>
//#include <string>
//using namespace std;
//
//class Point {
//	int x, y;
//public:
//	Point(int x, int y) { this->x = x; this->y = y; }
//	int getx() { return x; }
//	int gety() { return y; }
//protected:
//	void move(int x, int y) { this->x = x; this->y = y; }
//};
//
//class ColorPoint : public Point {
//	string color;
//public:
//	ColorPoint(int a, int b, string s) : Point(a,b) 
//	{
//		color = s;
//	}
//	void setPoint(int a, int b)
//	{
//		move(a, b);
//	}
//	void setColor(string s)
//	{
//		color = s;
//	}
//	void show()
//	{
//		cout << color << " " << getx() << " " << gety();
//	}
//};
//
//int main()
//{
//	ColorPoint cp(5, 5, "RED");
//	cp.setPoint(10, 20);
//	cp.setColor("BLUE");
//	cp.show();
//}

//#include <iostream>
//using namespace std;
//
//class Add{
//protected:
//	int x;
//	int y;
//public:
//	Add(int x, int y)
//	{
//		this->x = x; this->y = y;
//	}
//	int add() { return x + y; }
//};
//
//// �Ļ�Ŭ���� AddSub �����
//// �⺻������ ����, �� ���� ���ڷ� �޴� ������ ����
//// �� �� �� ���ϴ� sub �Լ� �߰�
//
//class AddSub : public Add {
//public:
//	AddSub(int a, int b) : Add(a,b) {}
//	int sub() { return x - y; }
//};
//
//int main()
//{
//	AddSub ob(12, 15);
//
//	cout << ob.add() << " " << ob.sub();
//}

//#include <iostream> // 6
//using namespace std;
//
//void SumDiff(int a, int b, int& sum, int& diff)
//{
//	sum = a + b;
//	diff = a - b;
//}
//
//int main()
//{
//	int a, b;
//	int sum = 0;
//	int diff = 0;
//	cin >> a >> b;
//	SumDiff(a, b, sum, diff);
//	cout << sum << " " << diff;
//	return 0;
//}




////////////////////////////// 5������

//#include <iostream>
//using namespace std;
//
//class Tower
//{
//	int height;
//public:
//	Tower(int m = 1)
//	{
//		height = m;
//	}
//	int getHeight() { return height; }
//};
//
//int main()
//{
//	Tower myTower; // 1����
//	Tower seoulTower(100); // 100����
//	cout << myTower.getHeight() << endl;
//	cout << seoulTower.getHeight() << endl;
//	return 0;
//}

//#include <iostream>
//#include <string>
//using namespace std;
//
//class Person {
//	string name;
//public:
//	int age;
//	void setName(string s) { name = s; }
//	void setAge(int a) { age = a; }
//	string getName() { return name; }
//};
//
//int main()
//{
//	Person person; // �̸�(name)�� ����(age)�Ӽ� ����
//	person.setName("John");
//	person.setAge(25);
//	cout << person.getName() << endl;
//	cout << person.age << endl;
//	return 0;
//}

//#include <iostream>
//using namespace std;
//
//class Rectangle {
//private:
//	int width;
//	int height;
//public:
//	void setDimensions(int w, int h)
//	{
//		width = w;
//		height = h;
//	}
//	int getWidth()
//	{
//		return width;
//	}
//	int getHeight()
//	{
//		return height;
//	}
//};
//
//void SetGet(Rectangle* r)
//{
//	// width, height �Է� �޾Ƽ� setDimensions ȣ�� ��
//	// rect ��ü ��� ���� ����
//	// getwidth, getheight ȣ���� �ʺ� ���� ���
//	int w, h;
//	cin >> w >> h;
//	r->setDimensions(w, h);
//	cout << r->getWidth() << " " << r->getHeight();
//}
//
//int main()
//{
//	Rectangle rect;
//	Rectangle* recPtr = &rect;
//	SetGet(recPtr);
//	return 0;
//}

//#include <string>
//
//#include <iostream>
//using namespace std;
//
//class Person {
//private:
//	string name;
//	int age;
//public:
//	Person() {
//		name = "None";
//		age = 0;
//		cout << name << " " << age << endl;
//	}
//
//	// name, age ����ϴ� �Ҹ���
//	~Person()
//	{
//		cout << name << " " << age << endl;
//	}
//
//	string getName()
//	{
//		return name;
//	}
//
//	int getAge()
//	{
//		return age;
//	}
//
//	void setPerson(string n, int a)
//	{
//		name = n;
//		age = a;
//	}
//};
//
//int main()
//{
//	// person Ŭ������ ������ personPtr �̿��� ��ü ���� ����
//	Person* personPtr = new Person;
//
//	personPtr->setPerson("John", 25);
//	cout << personPtr->getName() << " " << personPtr->getAge() << endl;
//	// ���� ��ü �Ҹ�
//
//	delete personPtr;
//}


//#include <iostream>
//using namespace std;
//
//class Calculator{
//public:
//	int add(int a, int b)
//	{
//		return a + b;
//	}
//	int add(int a, int b, int c)
//	{
//		return a + b + c;
//	}
//	double add(double a, double b)
//	{
//		return a + b;
//	}
//};
//
//int main()
//{
//	Calculator calculator;
//
//	cout << calculator.add(3, 4) << endl;
//	cout << calculator.add(1, 2, 3) << endl;
//	cout << calculator.add(2.5, 3.7) << endl;
//}

// �� ���� �Է¹޾� �հ� �� ����ϴ� �Լ� �ۼ�
// ���� ȣ�� ���

