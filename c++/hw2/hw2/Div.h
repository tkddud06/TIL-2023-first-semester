#ifndef DIV_H // �ߺ� include�� ���� ���� ������
#define DIV_H

class Div { // �� ������ ���� int�� ���� a, b��, ���� set���ִ� setValue �Լ�, ����� ������ �����ϴ� calculate �Լ� ����
	int a;
	int b;
public:
	void setValue(int x, int y);
	int calculate();
};

#endif