#include <iostream>
using namespace std;

// �����ε��� �̿��� 3-2 �ǽ� ���� (1��)

int big(int a, int b)
{
	int result;
	if (a > b)
	{
		result = a;
	}
	else
	{
		result = b;
	}

	if (result > 100)
	{
		result = 100;
	}
	return result;
}

int big(int a, int b, int max)
{
	int result;
	if (a > b)
	{
		result = a;
	}
	else
	{
		result = b;
	}

	if (result > max)
	{
		result = max;
	}
	return result;
}

int main()
{
	int x = big(3, 5);
	int y = big(300, 60);
	int z = big(30, 60, 50);
	cout << x << ' ' << y << ' ' << z << endl;
	return 0;
}