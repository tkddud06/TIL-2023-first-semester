#include <iostream>
using namespace std;

struct s
{
	int a;
	int b;
};

template<class T>
void myswap(T& a, T& b)
{
	T temp;
	temp = a;
	a = b;
	b = temp;
}

template <class T>
inline T pluss(T a, T b)
{
	return a + b;
}

template <class T1, class T2>
T2 cast(T1 a)
{
	return T2(a);
}

int main()
{
	s a= { 1, 2 };
	s b = { 3, 4 };
	myswap(a.a, b.a); // a�� a, a.a�� a.b, b.a�� b.b, a.a�� b.a, a.a�� b.b�� ��� ��ȯ ����
	// &�� �����Ϳ� ��ǻ� �۵��� ���� ����, a.a�� �ѱ�ٸ� a.a�� ������ �����ϰ� ���״�.
	// a.a�� ������ ���״� �ű�°͵� �ǰ���. �� ����ü�� �翬 �ǰ�.
	cout << a.a << " " << a.b << endl;
	cout << b.a << " " << b.b << endl;
	cout << pluss<double>(1.3, 2) << endl; // plus�� �ϸ� ��ȣ�ϴٴ� ���� ���µ�, �̸����� ������. (1.2, 3) �̷������� �޶��� ����, template ��ü�� 2�� �����ϴ���, �Ѱ��ٶ� <int>Ȥ�� <double>������ ����������ߵ�. �Լ��̸��ڿ� ����ȴ�.
	// �Ƹ� std �ȿ��� plus�� �̸��� ����ϴ°� �ֳ���. ���߿� ã�ƺ���.
	cout << cast<int, double>(1.3) << endl; // �ش� ���̽�ó�� ��ȯ�� ���� template�� ����ϰų� �ϴ� ����, ���� �����ִ°� �ʼ�. T2�� �޾ƾ� �Ѵ� �����ϸ��.
	return 0;
}

// https://thrillfighter.tistory.com/408 ���ø� ���� ���� ����
// �����ð��� �ٷ��� �ʾ�����, ���ø� Ư��ȭ���, ��ġ �Լ� �����ε� ���� ���䵵 �ֳ���.
// ���߿� Ȯ���غ���.