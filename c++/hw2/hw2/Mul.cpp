#include "Mul.h"
// ���� set���ִ� setValue �Լ�, ����� ������ �����ϴ� calculate �Լ� ����
void Mul::setValue(int x, int y)
{
	a = x;
	b = y;
}

int Mul::calculate()
{
	return a * b;
}