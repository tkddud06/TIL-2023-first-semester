#include <iostream>
using namespace std;

void f(char c = ' ', int line = 1);

void f(char c, int line)
{
	for (int j = 0; j < line; j++)
	{
		for (int i = 0; i < 10; i++)
		{
			cout << c;
		}
		cout << endl;
	}
}

int main()
{
	f();
	f('%');
	f('@', 5);
	return 0;
}