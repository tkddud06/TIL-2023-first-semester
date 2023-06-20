#include "Food.h"
#include <cstdlib> // ���� �Լ��� ����


void Food::move() // �̵��� �� ���ο� ��ġ�� x, y ����
{


	static int movement_count = 0; // ������ Ƚ���� üũ�ϱ� ���� ����
	static int not_movement_count = 0; // �������� ���� Ƚ���� üũ�ϱ� ���� ����

	int move_chk; // 0 �� 1 �� �ϳ���, �������� ���� ���ϴ� ����. 0�� ����, 1�� �̵�


	if (movement_count + not_movement_count == 5) // ���ļ� 5ȸ�� �ð��� ���� �Ķ��,
	{
		movement_count = 0;
		not_movement_count = 0;
	} // ���� Ƚ�� �ʱ�ȭ

	if (movement_count == 2) // 2�� �������ٸ�
	{
		move_chk = 0; // ������ ���ߵ���
	}
	else if (not_movement_count == 3) // 3�� �����־��ٸ�
	{
		move_chk = 1; // ������ �����̵���
	}
	else // �� ��Ȳ�� ��� ������ �ʾƼ�, ���� �������� �ϸ� �� ���
	{
		move_chk = rand() % 2;
	}

	if (move_chk == 0) // 0�϶� ���� ī��Ʈ, 1�϶� �̵� ī��Ʈ�� 1�� ���Ѵ�
	{
		not_movement_count++;
	}
	else
	{
		movement_count++;
	}

	// distance��ŭ �̵��ϱ�
	// �������� ���� �������� �̵�
	// ���� �̵��� �� ���� ������ �������� ���� ���, �̵��� �� ���� ������ �ٽ� ������ ���ϰ� �̵�.


	if (move_chk) // �������� �ϴ� ��Ȳ������ �۵�
	{
		int direction; // ������ ��Ÿ���� ����

		int chk = 1; // ���������� �̵��� ���� Ȯ���ϱ� ���� üĿ ����
		while (chk) // üĿ�� 0�� �Ǿ��� ��(���������� �̵��� �Ϸ� �Ǿ��� ��)���� �ݺ�
		{
			direction = rand() % 4; // 0,1,2,3 4���� ������ �������� ����
			// 0 : ������, 1 : �Ʒ�, 2 : ����, 3: ��

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
}