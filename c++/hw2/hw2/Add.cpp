#include "Add.h"
// 값을 set해주는 setValue 함수, 계산을 실제로 진행하는 calculate 함수 정의
void Add::setValue(int x, int y)
{
	a = x;
	b = y;
}

int Add::calculate()
{
	return a + b;
}