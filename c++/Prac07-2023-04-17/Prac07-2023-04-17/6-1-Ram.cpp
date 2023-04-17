#include <iostream>
#include "6-1-Ram.h"
using namespace std;

Ram::Ram()
{
	size = 100 * 1024;
	for (int i = 0; i < size; i++)
	{
		mem[i] = 0;
	}
}
Ram::~Ram()
{
	cout << "메모리 제거됨" << endl;
}
char Ram::read(int address)
{
	if (address >= size)
	{
		cout << "입력받은 주소가 메모리의 주소 범위를 벗어났습니다." << endl;
		return 0;
	}
	else
	{ 
		return mem[address];
	}
}
void Ram::write(int address, char value)
{
	if (address >= size)
	{
		cout << "입력받은 주소가 메모리의 주소 범위를 벗어났습니다." << endl;
	}
	else
	{
		mem[address] = value;
	}
}