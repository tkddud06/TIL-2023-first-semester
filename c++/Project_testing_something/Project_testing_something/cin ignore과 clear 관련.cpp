#include <iostream>
using namespace std;

int main()
{
	int a;
	double b;
	cin >> a;

	if (cin.fail())
	{
		cout << "���� �߻�!";
		cin.clear();
		cin.ignore(256, '\n');
	}
	else
	{
		cout << "���� ����!" << a;
	}
	cin >> a;
	cin >> a;
	cin >> b;
	cout << a;
	return 0;
	// clear�� ������ ������, ignore�� �����ص� flag�� ������ ������־, cin�� ���Ұ����ϴ�.
	// ignore�� ������ �ʾƵ�, ���۰� ���Ƽ� �׷��� ��� �Ұ����ϴ�.
}