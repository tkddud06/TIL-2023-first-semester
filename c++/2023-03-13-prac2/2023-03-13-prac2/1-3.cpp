#include <iostream>
using namespace std;

int main()
{
	char str[100];
	cout << "���ڵ��� �Է��Ͻÿ�(100�� �̸�)" << endl;
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
	cout << "X�� ������ " << n << endl;
	return 0;
}