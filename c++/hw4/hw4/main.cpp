
#include "Game.h" // 게임을 불러오는데 사용
#include <cstdlib> // 스랜드 함수에 사용
#include <ctime> // 스랜드 함수에 사용


int main()
{
	srand(time(NULL)); // 객체 내 랜드 함수가 실행시마다 랜덤성을 띄도록 하기 위함

	Game g; // 게임을 관장할 Game 객체 g 생성
	g.main_process(); // 게임 시작
	return 0;
}