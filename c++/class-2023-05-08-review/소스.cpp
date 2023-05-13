#include <iostream>
using namespace std;

class hi {
public:
	int a;
	void set(hi& thi, int a)
	{
		thi.a = a;
	}
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

	hi* p = new hi; // int 등은 자동 초기화가 안 되지만, 객체의 경우 디폴트 생성자를 거치기 때문에, 디폴트 생성자가 정의되어있다면, 자동 초기화 가능. 그렇지 않다면 똑같은 거고.
	// cout << p->a;

	hi* arr[3] = { new hi[5] {hi(),hi()}, new hi(), new hi[3]}; // malloc이랑 동일하게 생각하면 됨.
	delete arr[0];
	delete arr[1];
	delete arr[2];
	hi* tese = new hi;
	tese->set(*tese,first.a); // this는 자동으로 hi* this가 컴파일러에 의해 매개변수로 선언되는 셈이라길래, 이런식으로 해봤는데 가능하네. tese가 포인터가 아니라면 그냥 넣으면 되겠지.
	cout << tese->a;
	delete tese;

	hi* parray = new hi[3];
	hi* parray2 = parray + 1;
	parray2->a = 22;
	cout << parray2->a;
	// delete parray2; // 움직이다 만 포인터 기준으로 delete시키면, 바로 에러 발생.
	delete parray;




	return 0;
}