#include <iostream>
using namespace std;


class hi {
public:
	int data;
	hi(const hi& c)
	{
		this->data = c.data;
		cout << "복사생성자 호출" << endl;
	}
	hi()
	{
		data = 1;
		cout << "일반 생성자 호출" << endl;
	}
};

hi w;

void test(hi b)
{
	
}

hi* find()
{
	return &w;
}

int main()
{
	hi a;
	hi d = a; // 복사생성자 호출.

	hi f; // 이때는 일반 생성자 호출.
	f = a; // 이건 복사생성자랑은 다른, 대입임. 위와 다른 것!


	test(a); // 복사생성자 호출되는것이 맞음. 이 경우는 함수끝날때 소멸자 작동되겠지.

	// 이외 포인터나 레퍼런스로 받는 경우는 객체를 만드는게 아니니까, 함수에 엮이는 생성자 소멸자가 없는거고.

	(*find()).data = 3; // 레퍼런스로 공간을 참조하는것이 아니더라도, 포인터로도 가능.

	cout << w.data << endl;

	return 0;
}