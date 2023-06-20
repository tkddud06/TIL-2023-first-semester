#include <iostream>
using namespace std;

class A {
public:
	virtual void f() { cout << "A" << endl; }
	void func() { f(); }
};

class B : public A {
public:
	void f() { cout << "B" << endl; }
};


int main()
{
	B b;
	A a;
	A* ptr = &b;

	ptr->f();
	ptr->func();
	ptr = &a;


	return 0;
}