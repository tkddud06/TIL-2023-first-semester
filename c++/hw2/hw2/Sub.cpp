#include "Sub.h"
// ���� set���ִ� setValue �Լ�, ����� ������ �����ϴ� calculate �Լ� ����
void Sub::setValue(int x, int y)
{
	a = x;
	b = y;
}

int Sub::calculate()
{
	return a - b;
}