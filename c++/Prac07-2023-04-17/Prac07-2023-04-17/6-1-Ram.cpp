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
	cout << "�޸� ���ŵ�" << endl;
}
char Ram::read(int address)
{
	if (address >= size)
	{
		cout << "�Է¹��� �ּҰ� �޸��� �ּ� ������ ������ϴ�." << endl;
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
		cout << "�Է¹��� �ּҰ� �޸��� �ּ� ������ ������ϴ�." << endl;
	}
	else
	{
		mem[address] = value;
	}
}