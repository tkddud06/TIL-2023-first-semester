#include <iostream>
using namespace std;

// max() 함수 구현
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
//// 기본 클래스 Shape
//// 정수형 너비(width), 정수형 높이(height)가짐
//// 면적(area()) 계산 가상함수 가짐
//
//class Shape {
//public:
//	int width;
//	int height;
//	virtual int area() = 0;
//};
//
//// 파생 클래스 Rectangle
//// Shape 상속
//// 기본 생성자 안가져야 함, 너비와 높이 인자로 받는 생성자 있음
//// area 오버라이딩해서 구현
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
//// 파생클래스 AddSub 만들기
//// 기본생성자 없음, 두 정수 인자로 받는 생성자 구현
//// 두 수 차 구하는 sub 함수 추가
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




////////////////////////////// 5번까지

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
//	Tower myTower; // 1미터
//	Tower seoulTower(100); // 100미터
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
//	Person person; // 이름(name)과 나이(age)속성 가짐
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
//	// width, height 입력 받아서 setDimensions 호출 후
//	// rect 객체 멤버 변수 변경
//	// getwidth, getheight 호출해 너비 높이 출력
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
//	// name, age 출력하는 소멸자
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
//	// person 클래스형 포인터 personPtr 이용해 객체 동적 생성
//	Person* personPtr = new Person;
//
//	personPtr->setPerson("John", 25);
//	cout << personPtr->getName() << " " << personPtr->getAge() << endl;
//	// 동적 객체 소멸
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

// 두 정수 입력받아 합과 차 계산하는 함수 작성
// 참조 호출 사용

