#ifndef MUL_H // �ߺ� include�� ���� ���� ������
#define MUL_H

class Mul { // �� ������ ���� int�� ���� a, b��, ���� set���ִ� setValue �Լ�, ����� ������ �����ϴ� calculate �Լ� ����
	int a;
	int b;
public:
	void setValue(int x, int y);
	int calculate();
};

#endif