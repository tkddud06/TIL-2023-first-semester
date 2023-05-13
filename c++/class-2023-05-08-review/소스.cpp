#include <iostream>
using namespace std;

class hi {
public:
	int a;
	void set(hi& thi, int a)
	{
		thi.a = a;
	}
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

	hi* p = new hi; // int ���� �ڵ� �ʱ�ȭ�� �� ������, ��ü�� ��� ����Ʈ �����ڸ� ��ġ�� ������, ����Ʈ �����ڰ� ���ǵǾ��ִٸ�, �ڵ� �ʱ�ȭ ����. �׷��� �ʴٸ� �Ȱ��� �Ű�.
	// cout << p->a;

	hi* arr[3] = { new hi[5] {hi(),hi()}, new hi(), new hi[3]}; // malloc�̶� �����ϰ� �����ϸ� ��.
	delete arr[0];
	delete arr[1];
	delete arr[2];
	hi* tese = new hi;
	tese->set(*tese,first.a); // this�� �ڵ����� hi* this�� �����Ϸ��� ���� �Ű������� ����Ǵ� ���̶�淡, �̷������� �غôµ� �����ϳ�. tese�� �����Ͱ� �ƴ϶�� �׳� ������ �ǰ���.
	cout << tese->a;
	delete tese;

	hi* parray = new hi[3];
	hi* parray2 = parray + 1;
	parray2->a = 22;
	cout << parray2->a;
	// delete parray2; // �����̴� �� ������ �������� delete��Ű��, �ٷ� ���� �߻�.
	delete parray;




	return 0;
}