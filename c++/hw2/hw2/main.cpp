#include <iostream>
#include "Add.h"
#include "Div.h"
#include "Mul.h"
#include "Sub.h"
// 각 클래스의 헤더 파일을 인클루드. (링크를 잘 진행하기 위해서)
using namespace std;

int main()
{
	int x, y; // 입력받을 두 정수 저장 변수
	char op; // 연산자 저장 변수

	Add a;
	Sub s;
	Mul m;
	Div d;
	// 연산자에 따른 각 계산을 위한 클래스 변수 미리 선언

	while (true) // 무한 반복문
	{
		cout << "두 정수와 연산자를 입력하세요 : ";
		cin >> x >> y >> op;
		if (op == '+') // 각 연산자에 맞추어 해당하는 클래스 변수의 멤버 함수들 실행
		{
			a.setValue(x, y);
			cout << a.calculate() << endl;
		}
		else if (op == '-')
		{
			s.setValue(x, y);
			cout << s.calculate() << endl;
		}
		else if (op == '*')
		{
			m.setValue(x, y);
			cout << m.calculate() << endl;
		}
		else if (op == '/')
		{
			d.setValue(x, y);
			cout << d.calculate() << endl;
		}
		else // op가 예상치 못한 값 ("+-*/" 외의 것)을 받았을 때 반복문 탈출로서 종료
		{
			break;
		}
	}

	return 0;
}