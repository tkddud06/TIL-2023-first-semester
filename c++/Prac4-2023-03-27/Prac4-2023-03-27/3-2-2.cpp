#include <iostream>
using namespace std;

// 디폴트 인자를 이용해 3-2 실습 진행 (2번)

int big(int a, int b, int max = 100)
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