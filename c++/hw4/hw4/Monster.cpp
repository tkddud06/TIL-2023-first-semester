#include "Monster.h"
#include <cstdlib> // 랜드 함수를 위함

void Monster::move() // 이동하여 새로운 위치로 x, y 변경
{
	int direction; // 방향을 나타내는 변수

	// distance만큼 이동하기
	// 랜덤으로 나온 방향으로 이동
	// 만약 이동할 수 없는 방향이 랜덤으로 나올 경우, 이동할 수 있을 때까지 다시 방향을 정하고 이동.

	int chk = 1; // 정상적으로 이동한 것을 확인하기 위한 체커 변수
	while (chk) // 체커가 0이 되었을 때(정상적으로 이동이 완료 되었을 때)까지 반복
	{
		direction = rand() % 4; // 0,1,2,3 4개의 정수만 나오도록 설정
		// 0 : 오른쪽 1 : 아래 2 : 왼쪽 3: 위

		switch (direction)
		{
		case 0: // 오른쪽
			if (getX() + distance > 19) // 만약 판을 벗어날 경우, 다시 무작위 지정하도록 함
			{
				break;
			}
			else
			{
				chk = 0;
				this->x += distance; // 오른쪽으로 두칸 이동함
				break;
			}
		case 1: // 아래
			if (getY() + distance > 9) // 만약 판을 벗어날 경우, 다시 무작위 지정하도록 함
			{
				break;
			}
			else
			{
				chk = 0;
				this->y += distance; // 아래쪽으로 두칸 이동함
				break;
			}
		case 2: // 왼쪽
			if (getX() - distance < 0) // 만약 판을 벗어날 경우, 다시 무작위 지정하도록 함
			{
				break;
			}
			else
			{
				chk = 0;
				this->x -= distance; // 왼쪽으로 두칸 이동함
				break;
			}
		case 3: // 위
			if (getY() - distance < 0) // 만약 판을 벗어날 경우, 다시 무작위 지정하도록 함
			{
				break;
			}
			else
			{
				chk = 0;
				this->y -= distance; // 위쪽으로 두칸 이동함
				break;
			}
		}

	}
}
