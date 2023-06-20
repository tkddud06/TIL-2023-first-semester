#include "Food.h"
#include <cstdlib> // 랜드 함수를 위함


void Food::move() // 이동한 후 새로운 위치로 x, y 변경
{


	static int movement_count = 0; // 움직인 횟수를 체크하기 위한 변수
	static int not_movement_count = 0; // 움직이지 않은 횟수를 체크하기 위한 변수

	int move_chk; // 0 과 1 중 하나로, 움직일지 말지 정하는 변수. 0은 정지, 1은 이동


	if (movement_count + not_movement_count == 5) // 합쳐서 5회의 시간이 지난 후라면,
	{
		movement_count = 0;
		not_movement_count = 0;
	} // 누적 횟수 초기화

	if (movement_count == 2) // 2번 움직였다면
	{
		move_chk = 0; // 무조건 멈추도록
	}
	else if (not_movement_count == 3) // 3번 멈춰있었다면
	{
		move_chk = 1; // 무조건 움직이도록
	}
	else // 두 상황에 모두 속하지 않아서, 완전 랜덤으로 하면 될 경우
	{
		move_chk = rand() % 2;
	}

	if (move_chk == 0) // 0일땐 정지 카운트, 1일땐 이동 카운트에 1을 더한다
	{
		not_movement_count++;
	}
	else
	{
		movement_count++;
	}

	// distance만큼 이동하기
	// 랜덤으로 나온 방향으로 이동
	// 만약 이동할 수 없는 방향이 랜덤으로 나올 경우, 이동할 수 있을 때까지 다시 방향을 정하고 이동.


	if (move_chk) // 움직여야 하는 상황에서만 작동
	{
		int direction; // 방향을 나타내는 변수

		int chk = 1; // 정상적으로 이동한 것을 확인하기 위한 체커 변수
		while (chk) // 체커가 0이 되었을 때(정상적으로 이동이 완료 되었을 때)까지 반복
		{
			direction = rand() % 4; // 0,1,2,3 4개의 정수만 나오도록 설정
			// 0 : 오른쪽, 1 : 아래, 2 : 왼쪽, 3: 위

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
}