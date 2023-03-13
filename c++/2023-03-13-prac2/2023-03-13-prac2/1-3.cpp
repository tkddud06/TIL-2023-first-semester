#include <iostream>
using namespace std;

int main()
{
	char str[100];
	cout << "문자들을 입력하시오(100개 미만)" << endl;
	cin.getline(str, 100);
	int i = 0;
	int n = 0;
	while (str[i] != '\0')
	{
		if (str[i] == 'x')
		{
			n++;
		}
		i++;
	}
	cout << "X의 개수는 " << n << endl;
	return 0;
}