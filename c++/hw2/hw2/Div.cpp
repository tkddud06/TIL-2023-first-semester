#include <iostream>
#include "Div.h"
// ���� set���ִ� setValue �Լ�, ����� ������ �����ϴ� calculate �Լ� ����
void Div::setValue(int x, int y)
{
	a = x;
	b = y;
}

int Div::calculate()
{
	if (b == 0) // ���� �䱸���׿� ���� ������ ���õ��� �ʾ�����, Ȥ�ó� 0���� ���� �� ������ ����°� ���� ����, �߰����� ���ǹ� �־��.
	{
		std::cout << "0���δ� ���� �� �����ϴ�." << std::endl;
		return 0;
	}
	else 
	{
	return a / b;
	}
}