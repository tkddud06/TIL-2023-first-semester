#include <iostream>
#include "5-4-Calculator.h"
#include "5-4-Adder.h"

using namespace std;

void Calculator::run()
{
	cout << "두 개의 수를 입력하세요>>";
	int a, b;
	cin >> a >> b;
	Adder adder(a, b);
	cout << adder.process();
}