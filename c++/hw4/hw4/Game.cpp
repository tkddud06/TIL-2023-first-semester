#include "Game.h"
#include <iostream>
using namespace std;


bool Game::end_check() // ������ ���� ����, �׸��� �¸��ڸ� �����ϴ� �Լ� (�������� true, �ƴϸ� false ����)
{
	// �� ��ü�� ���ÿ� �����°� ���� �������� �ʾ���. �� ��ü�� ���ÿ� ���� ���, �ᱹ �޸��� ���Ϳ� ������ ������ ������.
	if (human.collide(&monster) || monster.collide(&food)) // �޸հ� ���Ͱ� �����ų�, ���Ͱ� Ǫ��� ����(�й�)
	{
		print_base(); // ����� �����
		cout << "Human is Looser!!" << endl;
		return true;
	}
	else if(human.collide(&food)) // �޸��� Ǫ��� ����(�¸�)
	{
		print_base(); // ����� �����
		cout << "Human is Winner!!" << endl;
		return true;
	}
	else // ���� �� ��������
	{
		return false;
	}
}

void Game::main_process() // ������ �������� ������ ���
{
	cout << "** Human�� Food �Ա� ������ �����մϴ� **" << endl;
	while (1)
	{
		// ������ ���¸� ����ϰ�, ������ �Է¹��� ��, �޸�, ����, Ǫ�� ������ ���� �Լ��� ȣ���� ������. �׷��ٰ� �¸� Ȥ�� �й� ������ �����Ǹ� �ٷ� ����
		// ����ɶ����� �ݺ�
		print_base();
		human.inputdir();
		human.move();
		monster.move();
		food.move();
		if (end_check()) // ������ ���� ���
		{
			return; 
		}
	}
}
void Game::print_base() // ���� ����ϱ� ���� ��� �κ�
{
	cout << endl;
	for (int i = 0; i < 10; i++) // i�� �� ���
	{
		for (int j = 0; j < 20; j++) // j�� �� ���
		{
			char printed = '-'; // ����� �⺻ ���� -�� ����
			if (monster.getX() == j && monster.getY() == i) // �ش� ��ġ�� ������ ��ġ��� ������ ������� �� ����
			{
				printed = monster.getShape();
			}
			else if (human.getX() == j && human.getY() == i) // �ش� ��ġ�� �޸��� ��ġ��� �޸��� ������� �� ����
			{
				printed = human.getShape();
			}
			else if (food.getX() == j && food.getY() == i) // �ش� ��ġ�� Ǫ���� ��ġ��� Ǫ���� ������� �� ����
			{
				printed = food.getShape();
			}
			cout << printed; // �ش� �� ���
		}
		cout << endl; // �� �ึ�� �� �ѱ�
	}
}