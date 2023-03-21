#include <stdio.h>

const aa;

static ii;

int main()
{
	const a;
	// a = 3; // 에러
	printf("%d", aa); // 해당 경우에는, 전역변수의 특징에 따라, aa가 0으로 초기화 됨.
	// printf("%d", a); // 초기화 안된거 쓴다고 에러
	// 결론 : 초기화 안해도 선언은 할 수 있는데, 걍 쓰레기 됨.

	static i;
	printf("%d", ii);
	printf("%d", i); // 자동으로 0으로 초기화 됨
	i = 3;
	ii = 2;
	printf("%d", i);
	// 결론 : 초기화 안하면, 자동으로 0으로 초기화 됨. 
	// statc 특징 중 하나는, 외부에서 직접 변수에 접근할 수 없어, 은닉성 있다는 점도 있대. 참고.
	// https://blog.naver.com/dhrtpdnjs/222974544617
	return 0;
}