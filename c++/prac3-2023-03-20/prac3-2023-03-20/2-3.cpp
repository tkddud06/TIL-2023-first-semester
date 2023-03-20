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

	if (!bigger(a, b, big)) cout << "큰 수는 " << big << endl;
	else cout << "두 수는 같다" << endl;

	b = 3; // a = 3, b = 3

	if (!bigger(a, b, big)) cout << "큰 수는 " << big << endl;
	else cout << "두 수는 같다" << endl;

	a = 7; // a = 7, b = 3

	if (!bigger(a, b, big)) cout << "큰 수는 " << big << endl;
	else cout << "두 수는 같다" << endl;

	return 0;
}