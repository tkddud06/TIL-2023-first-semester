#include <iostream>
#include <vector>
using namespace std;

int main()
{
	vector<int> a = { 1,2,3,4,5 };
	cout << "capacity : " << a.capacity() << endl;
	a.push_back(6);
	for (int i = 0; i < a.size(); i++)
	{
		cout << a[i] << endl;
	}
	cout << "capacity : " << a.capacity() << endl;
	a.push_back(7);
	cout << "capacity : " << a.capacity() << endl;
	a.push_back(8);
	cout << "capacity : " << a.capacity() << endl;
	a.pop_back();
	a.pop_back();
	a.pop_back();
	a.pop_back();
	cout << "capacity : " << a.capacity() << endl;
	cout << a.back() << endl;
	//a[7] = 9;
	//cout << a[7]; // capacity�� ����ص�, �����͸� ���� ������ ���Ƿ� ���� �����ϸ�, ���� �߻�

	a[1] = 10;
	cout << a[1]; // �̹� �����Ͱ� �Ҵ�� ������ ����.
	return 0;
}

// https://rebro.kr/37
// ���� ���� ����. ����.

// c++ ������ ������� �� �𸣰ڴµ�, ���ͷ����Ϳ�
// �׸��� 2���� ���Ϳ� ���ؼ� �߰� ������ ����.