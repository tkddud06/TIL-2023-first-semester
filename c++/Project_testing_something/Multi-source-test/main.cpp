// #pragma once // ���� ���°� ���ǹ�. �ش� cpp�� ����� ����ߵ�.
#include <iostream>
#include "print.h"
#include "print.h" // �ش� ����� pragma once �ȵ������� ����. pragma �߰����� �Ŀ���, ������� ���� ����. �Ƹ� print.cpp�� �Ϻ� �����ϰų� �ؼ�, �νĽ����ָ� �Ǵµ�. �ƴ� �� �ƿ� ��� �Ǵµ�? ���� �� �𸣰ڴ� ������
// ������ ���� ��Ȳ�� ��Ȯ�� �Ǵ��� �������, pragma once Ȥ�� ifndef ó���� �Ǿ��ְ�, �� ���� �κа� ������ ����� �κе鿡 include�� ���� �������شٸ� ������ �� ��.
extern int a; // extern�� �����ͼ� ���� ���忡��, ���.
// ���� a�� �ٸ� �ڵ忡��, �Լ� �ȿ� �ִٸ�, ����.
extern void func(); // include�ǰų� �� �ڵ尡 �ƴ϶�, �׳� ���� �ִ� ��쿡�� �������.
// �Լ��� extern�� �⺻���̹Ƿ�, �����ص� �����ϴ�.
// ���� func�� �ΰ������ �ϴ� ��쿡��, ���� �߻�.
using namespace std;

void func3()
{
	extern int z; // func2.cpp�� ����� �ش� �͵�, �ܺο� ����� ���̹Ƿ�, �� ��������.
	extern int d;
	cout << z << endl;
	cout << d << endl;
}
int d = 5; // d�� main �ȿ� ����Ǿ������� �۵� X, �̷��� ���������μ� func3�� �ܺ� �������� ����Ǿ������� ����.
int main()
{
	print("hello");
	cout << a << endl; // ���� iostream include �������� ��� �Ұ�.
	func();
	func3();
	return 0;
}