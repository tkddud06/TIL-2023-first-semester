#ifndef SUB_H // �ߺ� include�� ���� ���� ������
#define SUB_H

class Sub { // �� ������ ���� int�� ���� a, b��, ���� set���ִ� setValue �Լ�, ����� ������ �����ϴ� calculate �Լ� ����
	int a;
	int b;
public:
	void setValue(int x, int y);
	int calculate();
};

#endif