#include <iostream>
using namespace std;

struct s
{
	int a;
	int b;
};

template<class T>
void myswap(T& a, T& b)
{
	T temp;
	temp = a;
	a = b;
	b = temp;
}

template <class T>
inline T pluss(T a, T b)
{
	return a + b;
}

template <class T1, class T2>
T2 cast(T1 a)
{
	return T2(a);
}

int main()
{
	s a= { 1, 2 };
	s b = { 3, 4 };
	myswap(a.a, b.a); // a와 a, a.a와 a.b, b.a와 b.b, a.a와 b.a, a.a와 b.b등 모든 교환 가능
	// &는 포인터와 사실상 작동이 거의 같고, a.a를 넘긴다면 a.a의 공간을 참조하게 될테니.
	// a.a의 별명이 될테니 옮기는것도 되겠지. 뭐 구조체도 당연 되고.
	cout << a.a << " " << a.b << endl;
	cout << b.a << " " << b.b << endl;
	cout << pluss<double>(1.3, 2) << endl; // plus로 하면 모호하다는 오류 나는데, 이름공간 문제래. (1.2, 3) 이런식으로 달라질 때는, template 자체를 2개 선언하던지, 넘겨줄때 <int>혹은 <double>등으로 고정시켜줘야됨. 함수이름뒤에 쓰면된다.
	// 아마 std 안에도 plus란 이름을 사용하는게 있나봄. 나중에 찾아보자.
	cout << cast<int, double>(1.3) << endl; // 해당 케이스처럼 반환을 따로 template로 명시하거나 하는 경우는, 형식 적어주는거 필수. T2를 받아야 한다 생각하면됨.
	return 0;
}

// https://thrillfighter.tistory.com/408 템플릿 관련 내용 정리
// 수업시간엔 다루지 않았지만, 템플릿 특수화라는, 마치 함수 오버로딩 같은 개념도 있나봄.
// 나중에 확인해보자.