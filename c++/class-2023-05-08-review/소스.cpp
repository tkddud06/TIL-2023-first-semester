#include <iostream>
using namespace std;

class hi {
public:
	int a;
};

int main()
{
	hi first;
	first.a = 1;
	hi* ptr = &first;
	// hi& ref = new hi; // ���۷����� ���ؼ� �����Ҵ��� �Ұ����ϴٰ� ���´�.
	hi& ref = *ptr; // �̰� �ǳ�?
	cout << ref.a << endl; // �����Ͷ� -> ���� �ʰ�, �ڱ� �̸�ó�� ref�� �� �� �ִ�.
	hi* ptr2 = new hi;
	ptr2->a = 22;
	hi& ref2 = *ptr2;
	cout << ref2.a << endl; // �����Ҵ��� �ּҵ� ���� �Ҵ��� �Ұ����ص�, �̷������δ� �����ϳ�.

	(*ptr).a = 30; // ��ȣ�� ���� ��, ���� �߻�. '.'�� *���� �켱������ ���Ƽ� �׷���.
	cout << first.a;



	return 0;
}