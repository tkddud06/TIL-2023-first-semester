#include <iostream>
using namespace std;


class hi {
public:
	int data;
	hi(const hi& c)
	{
		this->data = c.data;
		cout << "��������� ȣ��" << endl;
	}
	hi()
	{
		data = 1;
		cout << "�Ϲ� ������ ȣ��" << endl;
	}
};

hi w;

void test(hi b)
{
	
}

hi* find()
{
	return &w;
}

int main()
{
	hi a;
	hi d = a; // ��������� ȣ��.

	hi f; // �̶��� �Ϲ� ������ ȣ��.
	f = a; // �̰� ��������ڶ��� �ٸ�, ������. ���� �ٸ� ��!


	test(a); // ��������� ȣ��Ǵ°��� ����. �� ���� �Լ������� �Ҹ��� �۵��ǰ���.

	// �̿� �����ͳ� ���۷����� �޴� ���� ��ü�� ����°� �ƴϴϱ�, �Լ��� ���̴� ������ �Ҹ��ڰ� ���°Ű�.

	(*find()).data = 3; // ���۷����� ������ �����ϴ°��� �ƴϴ���, �����ͷε� ����.

	cout << w.data << endl;

	return 0;
}