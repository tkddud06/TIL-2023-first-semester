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
	// ������ ���� �����ؼ� �������� ���غ���, ���������� swap �Լ��� �۵����� Ȯ���� �� �ִ�.
	cout << "A�� ���� = " << A.getArea() << "  B�� ���� = " << B.getArea() << endl;
	swap(A, B);
	cout << "A�� ���� = " << A.getArea() << "  B�� ���� = " << B.getArea() << endl;
	return 0;
}