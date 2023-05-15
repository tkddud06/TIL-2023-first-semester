#include <iostream>
using namespace std;

class Circle {
private:
	int radius;
public:
	Circle() { radius = 1; }
	Circle(int radius) { this->radius = radius; }
	double getArea() { return 3.14 * radius * radius; }
};

void swap(Circle& a, Circle& b)
{
	Circle temp = a;
	a = b;
	b = temp;
}

int main()
{
	Circle A(2);
	Circle B(3);
	// 임의의 값을 대입해서 면적들을 구해보면, 정상적으로 swap 함수가 작동함을 확인할 수 있다.
	cout << "A의 면적 = " << A.getArea() << "  B의 면적 = " << B.getArea() << endl;
	swap(A, B);
	cout << "A의 면적 = " << A.getArea() << "  B의 면적 = " << B.getArea() << endl;
	return 0;
}