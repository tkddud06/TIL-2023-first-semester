#include "Add.h"
// ���� set���ִ� setValue �Լ�, ����� ������ �����ϴ� calculate �Լ� ����
void Add::setValue(int x, int y)
{
	a = x;
	b = y;
}

int Add::calculate()
{
	return a + b;
}