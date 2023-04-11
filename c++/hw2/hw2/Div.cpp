#include <iostream>
#include "Div.h"
// 값을 set해주는 setValue 함수, 계산을 실제로 진행하는 calculate 함수 정의
void Div::setValue(int x, int y)
{
	a = x;
	b = y;
}

int Div::calculate()
{
	if (b == 0) // 과제 요구사항에 관련 내용이 제시되진 않았지만, 혹시나 0으로 나눌 때 오류가 생기는걸 막기 위해, 추가적인 조건문 넣어둠.
	{
		std::cout << "0으로는 나눌 수 없습니다." << std::endl;
		return 0;
	}
	else 
	{
	return a / b;
	}
}