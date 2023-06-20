#include <iostream>
#include "Human.h"
using namespace std;

void Human::inputdir()
{
	int chk = 1; // ���� �Է��� Ȯ���ϱ� ���� üĿ ����
	while (chk)
	{
		cout << "����(a), �Ʒ�(s), ��(d), ������(f) >> ";
		cin >> direction; // ������ �Է¹޴´�
		if (direction != 'a' && direction != 's' && direction != 'd' && direction != 'f') // �ٸ� ���� �Է��� ���
		{
			cout << "�߸� �Է��ϼ̽��ϴ�. �ٽ� �Է��� �ֽʽÿ�." << endl;
			cin.clear(); // ���� �÷��׸� �����
			cin.ignore(1000, '\n'); // ���۸� �����
		}
		else
			chk = 0; // ���� �Է½ÿ� üĿ�� 0���� ����� ���Ϲ� ����
	}
}


void Human::move() // �̵��Ͽ� ���ο� ��ġ�� x, y ����
{
	// distance��ŭ �̵��ϱ�
	// �Է°��� �������� �̵� (�޸��� ���, ����ڰ� ���ϴ� ���⿡ ���߾� �̵���
	// ���� �̵��� �� ���� ���, �̵����� �ʴ´�.

	int chk = 1; // ���������� �̵��� ���� Ȯ���ϱ� ���� üĿ ����
	while (chk) // üĿ�� 0�� �Ǿ��� ��(���������� �̵��� �Ϸ� �Ǿ��� ��)���� �ݺ�
	{

		switch (direction)
		{
		case 'a': // �������� �̵�
			chk = 0;
			if (getX() - distance < 0) // ���� ���� ��� ���, �̵����� �ʰ� �ѱ�
			{
				break;
			}
			else
			{
				this->x -= distance; // �������� ��ĭ �̵���
				break;
			}
		case 's': // �Ʒ�
			chk = 0;
			if (getY() + distance > 9) // ���� ���� ��� ���, �̵����� �ʰ� �ѱ�
			{
				break;
			}
			else
			{
				this->y += distance; // �Ʒ��� ��ĭ �̵���
				break;
			}
			break;
		case 'd': // ��
			chk = 0;
			if (getY() - distance < 0) // ���� ���� ��� ���, �̵����� �ʰ� �ѱ�
			{
				break;
			}
			else
			{
				this->y -= distance; // ���� ��ĭ �̵���
				break;
			}
			break;
		case 'f': // ������
			chk = 0;
			if (getX() + distance > 19) // ���� ���� ��� ���, �̵����� �ʰ� �ѱ�
			{
				break;
			}
			else
			{
				this->x += distance; // ���������� ��ĭ �̵���
				break;
			}
			break;
		}
	}
}
