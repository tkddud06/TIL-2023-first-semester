#include <iostream>
#include "5-4-Calculator.h"
#include "5-4-Adder.h"

using namespace std;

void Calculator::run()
{
	cout << "�� ���� ���� �Է��ϼ���>>";
	int a, b;
	cin >> a >> b;
	Adder adder(a, b);
	cout << adder.process();
}