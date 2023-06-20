#include "Monster.h"
#include <cstdlib> // ���� �Լ��� ����

void Monster::move() // �̵��Ͽ� ���ο� ��ġ�� x, y ����
{
	int direction; // ������ ��Ÿ���� ����

	// distance��ŭ �̵��ϱ�
	// �������� ���� �������� �̵�
	// ���� �̵��� �� ���� ������ �������� ���� ���, �̵��� �� ���� ������ �ٽ� ������ ���ϰ� �̵�.

	int chk = 1; // ���������� �̵��� ���� Ȯ���ϱ� ���� üĿ ����
	while (chk) // üĿ�� 0�� �Ǿ��� ��(���������� �̵��� �Ϸ� �Ǿ��� ��)���� �ݺ�
	{
		direction = rand() % 4; // 0,1,2,3 4���� ������ �������� ����
		// 0 : ������ 1 : �Ʒ� 2 : ���� 3: ��

		switch (direction)
		{
		case 0: // ������
			if (getX() + distance > 19) // ���� ���� ��� ���, �ٽ� ������ �����ϵ��� ��
			{
				break;
			}
			else
			{
				chk = 0;
				this->x += distance; // ���������� ��ĭ �̵���
				break;
			}
		case 1: // �Ʒ�
			if (getY() + distance > 9) // ���� ���� ��� ���, �ٽ� ������ �����ϵ��� ��
			{
				break;
			}
			else
			{
				chk = 0;
				this->y += distance; // �Ʒ������� ��ĭ �̵���
				break;
			}
		case 2: // ����
			if (getX() - distance < 0) // ���� ���� ��� ���, �ٽ� ������ �����ϵ��� ��
			{
				break;
			}
			else
			{
				chk = 0;
				this->x -= distance; // �������� ��ĭ �̵���
				break;
			}
		case 3: // ��
			if (getY() - distance < 0) // ���� ���� ��� ���, �ٽ� ������ �����ϵ��� ��
			{
				break;
			}
			else
			{
				chk = 0;
				this->y -= distance; // �������� ��ĭ �̵���
				break;
			}
		}

	}
}
