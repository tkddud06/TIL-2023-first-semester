#include <iostream>
#include "Add.h"
#include "Div.h"
#include "Mul.h"
#include "Sub.h"
// �� Ŭ������ ��� ������ ��Ŭ���. (��ũ�� �� �����ϱ� ���ؼ�)
using namespace std;

int main()
{
	int x, y; // �Է¹��� �� ���� ���� ����
	char op; // ������ ���� ����

	Add a;
	Sub s;
	Mul m;
	Div d;
	// �����ڿ� ���� �� ����� ���� Ŭ���� ���� �̸� ����

	while (true) // ���� �ݺ���
	{
		cout << "�� ������ �����ڸ� �Է��ϼ��� : ";
		cin >> x >> y >> op;
		if (op == '+') // �� �����ڿ� ���߾� �ش��ϴ� Ŭ���� ������ ��� �Լ��� ����
		{
			a.setValue(x, y);
			cout << a.calculate() << endl;
		}
		else if (op == '-')
		{
			s.setValue(x, y);
			cout << s.calculate() << endl;
		}
		else if (op == '*')
		{
			m.setValue(x, y);
			cout << m.calculate() << endl;
		}
		else if (op == '/')
		{
			d.setValue(x, y);
			cout << d.calculate() << endl;
		}
		else // op�� ����ġ ���� �� ("+-*/" ���� ��)�� �޾��� �� �ݺ��� Ż��μ� ����
		{
			break;
		}
	}

	return 0;
}