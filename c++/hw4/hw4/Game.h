#include <iostream>
#include "Food.h"
#include "Human.h"
#include "Monster.h"

#ifndef GAME_H
#define GAME_H


class Game {
	// ���� ���࿡ �ʿ��� �� ��ü���� ����
	Human human;
	Monster monster;
	Food food;
	bool end_check(); // ������ ���� ����, �׸��� �¸��ڸ� �����ϴ� �Լ� (�������� true, �ƴϸ� false ����)	
	void print_base(); // ���� ����ϱ� ���� ��� �κ�
public:
	void main_process(); // ������ �������� ������ ���
};


#endif