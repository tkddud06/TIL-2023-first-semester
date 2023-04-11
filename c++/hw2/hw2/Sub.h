#ifndef SUB_H // 중복 include로 인한 오류 방지용
#define SUB_H

class Sub { // 값 저장을 위한 int형 변수 a, b와, 값을 set해주는 setValue 함수, 계산을 실제로 진행하는 calculate 함수 선언
	int a;
	int b;
public:
	void setValue(int x, int y);
	int calculate();
};

#endif