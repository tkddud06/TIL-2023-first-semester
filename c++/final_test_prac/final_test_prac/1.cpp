#include <iostream>
#include <string>
#include <map>
using namespace std;

class acc {
public:
	acc()
	{
		c = 0;
	}
	int c;
	//virtual int add(int a, int b);
	//friend int sss(int c, int d);
	//static int sta(int a);
	//int vvv() const;
	virtual void print()
	{
		cout << "hi" << endl;
	}

};

class acc2 : public acc {
public:
	void print()
	{
		cout << "hello"; // 만약 없을 시, 동적 바인딩 시 기본클래스꺼 출력.
	}
};

//inline int sub(int a, int b);
//
//
//int sss(int c, int d);

int main()
{
	const char* ptr[] =
	{
		"hello",
		"nice"
	};

	map<int, string> a;

	acc *p = new acc;
	acc f;
	cout << f.c;
	delete p;

	acc2 vv;
	acc* pt = &vv;
	pt->print();
	return 0;
}