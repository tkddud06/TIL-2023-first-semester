#include <iostream>
using namespace std;

class hi {
public:
	int a;
};

int main()
{
	hi first;
	first.a = 1;
	hi* ptr = &first;
	// hi& ref = new hi; // 레퍼런스를 통해서 동적할당은 불가능하다고 나온다.
	hi& ref = *ptr; // 이건 되네?
	cout << ref.a << endl; // 포인터랑 -> 쓰지 않고, 자기 이름처럼 ref를 쓸 수 있다.
	hi* ptr2 = new hi;
	ptr2->a = 22;
	hi& ref2 = *ptr2;
	cout << ref2.a << endl; // 동적할당한 주소도 직접 할당은 불가능해도, 이런식으로는 가능하네.

	(*ptr).a = 30; // 괄호를 생략 시, 오류 발생. '.'이 *보다 우선순위가 높아서 그렇다.
	cout << first.a;



	return 0;
}