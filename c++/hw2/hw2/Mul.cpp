#include "Mul.h"
// 값을 set해주는 setValue 함수, 계산을 실제로 진행하는 calculate 함수 정의
void Mul::setValue(int x, int y)
{
	a = x;
	b = y;
}

int Mul::calculate()
{
	return a * b;
}