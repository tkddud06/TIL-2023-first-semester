#include <iostream>

using namespace std;

bool bigger(int a, int b, int& big)
{
	if (a == b)
	{
		return true;
	}
	else
	{
		if (a > b)
		{
			big = a;
		}
		else
		{
			big = b;
		}
		return false;
	}
}

int main()
{
	int a = 3, b = 5;
	int big;

	if (!bigger(a, b, big)) cout << "ū ���� " << big << endl;
	else cout << "�� ���� ����" << endl;

	b = 3; // a = 3, b = 3

	if (!bigger(a, b, big)) cout << "ū ���� " << big << endl;
	else cout << "�� ���� ����" << endl;

	a = 7; // a = 7, b = 3

	if (!bigger(a, b, big)) cout << "ū ���� " << big << endl;
	else cout << "�� ���� ����" << endl;

	return 0;
}