#ifndef ADD_H // �ߺ� include�� ���� ���� ������
#define ADD_H

class Add { // �� ������ ���� int�� ���� a, b��, ���� set���ִ� setValue �Լ�, ����� ������ �����ϴ� calculate �Լ� ����
	int a;
	int b;
public:
	void setValue(int x, int y);
	int calculate();
};

#endif