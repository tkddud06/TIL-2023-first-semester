#include <iostream>
#include "print.h"

extern int a; // extern은 가져와서 쓰는 입장에서, 사용.
// 만약 a가 다른 코드에서, 함수 안에 있다면, 에러.
extern void func(); // include되거나 한 코드가 아니라, 그냥 같이 있는 경우에도 갖고와줌.
// 함수는 extern이 기본값이므로, 생략해도 무관하대.
// 만약 func가 두개라던가 하는 경우에는, 에러 발생.
using namespace std;

void func3()
{
	extern int z; // func2.cpp에 선언된 해당 것도, 외부에 선언된 것이므로, 잘 가져와짐.
	extern int d;
	cout << z << endl;
	cout << d << endl;
}
int d = 5; // d가 main 안에 선언되어있을땐 작동 X, 이렇게 전역변수로서 func3의 외부 개념으로 선언되어있을땐 가능.
int main()
{
	print("hello");
	cout << a << endl; // 만약 iostream include 안했으면 사용 불가.
	func();
	func3();
	return 0;
}