#include <iostream>

using namespace std;

class hi
{
private:
	int a;

public:

	static int z;

	void func() const
	{
		// a = 5; // 에러 발생.
		int c;
		c = 5;
		cout << a << c << endl;
	}
};
// const 함수 관련 내용 : https://blog.naver.com/minecraft102938/222355043796


void print(int (&ref)[10]) // 당연하지만, int& ref같은건 안됨. int& ref[10] 의경우는, 참조 배열인거지. 포인터배열 비슷한거 생각하면될듯. 당연히 안되겠지.
// 다만, 지금 해둔것처럼, 배열 레퍼런스가 가능.
{
	for (int i = 0; i < 10; i++)
	{
		cout << ref[i] << endl;
	}
}

int main()
{
	int a, b;
	// int& ref[2] = {a,b};
	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
	print(arr);
	// 찾아보다가 의문 든거 : 레퍼런스가 메모리 상에 반드시 존재해야 하는 경우가 있나?
	cout << endl;
	hi f;
	// cout << hi::z; // hi::z도 안되고, f.z도 안됨. class와 static의 관계에 대해선, 차후에 다시 더 알아보자. 헷갈린다. 그러면 클래스 내부 static은 어떻게 접근하는거지? 내부함수를 통해서만?
	// 아무튼 나중에 추가로 알아보자.
	// 만약, 클래스를 외부 소스에 정의하고, 그를 extern으로 갖고온다면, 내부의 static 변수의 값은 어떻게 될까? 소스를 넘어서도 유지될까?
	// https://junstar92.tistory.com/318 나중에 확인해보자.
	f.func();
	return 0;
}

// 레퍼런스의 함수 리턴 관련.
// 책 내용은 아마 내가 알던 표랑은 별개의 개념인듯? 책은 공간에 관련해서 집중한거고, 블로그 표는 데이터 참조가 어떻게 되는지에 대해 집중한거고. 관련은 있지.
// https://modoocode.com/141 참고.
// 읽어보니, 맞음. 별개의 내용임. 알고는 있어야 하는 내용이니, 확인해둘 것. 지역변수의 참조를 리턴하면, 지역변수가 사라지는 순간, 원본 놈이 사라지고 별명만 남은 셈이니,
// 오류가 나지. 
// const int&이 지역변수 값을 받는 가능한 경우는, 상수를 가리키고 있는 경우. 상수의 별명이 되는 셈인거 같아. (이건 상수의 값을 리턴한거고, 레퍼런스는 상수의 별명이 된거지)
// 그외 경우는, 일반 함수 리턴처럼 값이 복사되는거 아니고서는, 지역 변수의 리퍼런스를 리턴한다던가 하면, 위에서 말한 이유로 오류가 남.
// 이렇게 이해하면 될거 같다.
