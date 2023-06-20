#include "Game.h"
#include <iostream>
using namespace std;


bool Game::end_check() // 게임의 종료 여부, 그리고 승리자를 판정하는 함수 (끝났으면 true, 아니면 false 리턴)
{
	// 세 개체가 동시에 만나는건 따로 판정하지 않았음. 세 개체가 동시에 만날 경우, 결국 휴먼이 몬스터에 먹히는 것으로 가정함.
	if (human.collide(&monster) || monster.collide(&food)) // 휴먼과 몬스터가 만나거나, 몬스터가 푸드와 만남(패배)
	{
		print_base(); // 결과를 출력함
		cout << "Human is Looser!!" << endl;
		return true;
	}
	else if(human.collide(&food)) // 휴먼이 푸드와 만남(승리)
	{
		print_base(); // 결과를 출력함
		cout << "Human is Winner!!" << endl;
		return true;
	}
	else // 아직 안 끝났을때
	{
		return false;
	}
}

void Game::main_process() // 게임의 전반적인 진행을 담당
{
	cout << "** Human의 Food 먹기 게임을 시작합니다 **" << endl;
	while (1)
	{
		// 현재의 상태를 출력하고, 방향을 입력받은 후, 휴먼, 몬스터, 푸드 순으로 무브 함수를 호출해 움직임. 그러다가 승리 혹은 패배 조건이 만족되면 바로 종료
		// 종료될때까지 반복
		print_base();
		human.inputdir();
		human.move();
		monster.move();
		food.move();
		if (end_check()) // 게임이 끝난 경우
		{
			return; 
		}
	}
}
void Game::print_base() // 판을 출력하기 위한 담당 부분
{
	cout << endl;
	for (int i = 0; i < 10; i++) // i가 행 담당
	{
		for (int j = 0; j < 20; j++) // j가 열 담당
		{
			char printed = '-'; // 출력할 기본 값은 -로 설정
			if (monster.getX() == j && monster.getY() == i) // 해당 위치가 몬스터의 위치라면 몬스터의 모양으로 값 지정
			{
				printed = monster.getShape();
			}
			else if (human.getX() == j && human.getY() == i) // 해당 위치가 휴먼의 위치라면 휴먼의 모양으로 값 지정
			{
				printed = human.getShape();
			}
			else if (food.getX() == j && food.getY() == i) // 해당 위치가 푸드의 위치라면 푸드의 모양으로 값 지정
			{
				printed = food.getShape();
			}
			cout << printed; // 해당 값 출력
		}
		cout << endl; // 한 행마다 줄 넘김
	}
}