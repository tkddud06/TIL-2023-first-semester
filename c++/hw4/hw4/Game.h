#include <iostream>
#include "Food.h"
#include "Human.h"
#include "Monster.h"

#ifndef GAME_H
#define GAME_H


class Game {
	// 게임 진행에 필요한 각 객체들을 가짐
	Human human;
	Monster monster;
	Food food;
	bool end_check(); // 게임의 종료 여부, 그리고 승리자를 판정하는 함수 (끝났으면 true, 아니면 false 리턴)	
	void print_base(); // 판을 출력하기 위한 담당 부분
public:
	void main_process(); // 게임의 전반적인 진행을 담당
};


#endif