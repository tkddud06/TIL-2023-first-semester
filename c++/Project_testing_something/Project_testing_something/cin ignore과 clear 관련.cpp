#include <iostream>
using namespace std;

int main()
{
	int a;
	double b;
	cin >> a;

	if (cin.fail())
	{
		cout << "에러 발생!";
		cin.clear();
		cin.ignore(256, '\n');
	}
	else
	{
		cout << "에러 없음!" << a;
	}
	cin >> a;
	cin >> a;
	cin >> b;
	cout << a;
	return 0;
	// clear를 해주지 않으면, ignore을 진행해도 flag에 에러가 저장되있어서, cin이 사용불가능하다.
	// ignore을 해주지 않아도, 버퍼가 남아서 그런가 사용 불가능하다.
}