#include <iostream>
#include "Human.h"
using namespace std;

void Human::inputdir()
{
	int chk = 1; // 정상 입력을 확인하기 위한 체커 변수
	while (chk)
	{
		cout << "왼쪽(a), 아래(s), 위(d), 오른쪽(f) >> ";
		cin >> direction; // 방향을 입력받는다
		if (direction != 'a' && direction != 's' && direction != 'd' && direction != 'f') // 다른 것을 입력한 경우
		{
			cout << "잘못 입력하셨습니다. 다시 입력해 주십시오." << endl;
			cin.clear(); // 오류 플래그를 지우고
			cin.ignore(1000, '\n'); // 버퍼를 지운다
		}
		else
			chk = 0; // 정상 입력시엔 체커를 0으로 만들어 와일문 정지
	}
}


void Human::move() // 이동하여 새로운 위치로 x, y 변경
{
	// distance만큼 이동하기
	// 입력값을 바탕으로 이동 (휴먼의 경우, 사용자가 원하는 방향에 맞추어 이동함
	// 만약 이동할 수 없을 경우, 이동하지 않는다.

	int chk = 1; // 정상적으로 이동한 것을 확인하기 위한 체커 변수
	while (chk) // 체커가 0이 되었을 때(정상적으로 이동이 완료 되었을 때)까지 반복
	{

		switch (direction)
		{
		case 'a': // 왼쪽으로 이동
			chk = 0;
			if (getX() - distance < 0) // 만약 판을 벗어날 경우, 이동하지 않고 넘김
			{
				break;
			}
			else
			{
				this->x -= distance; // 왼쪽으로 한칸 이동함
				break;
			}
		case 's': // 아래
			chk = 0;
			if (getY() + distance > 9) // 만약 판을 벗어날 경우, 이동하지 않고 넘김
			{
				break;
			}
			else
			{
				this->y += distance; // 아래로 한칸 이동함
				break;
			}
			break;
		case 'd': // 위
			chk = 0;
			if (getY() - distance < 0) // 만약 판을 벗어날 경우, 이동하지 않고 넘김
			{
				break;
			}
			else
			{
				this->y -= distance; // 위로 한칸 이동함
				break;
			}
			break;
		case 'f': // 오른쪽
			chk = 0;
			if (getX() + distance > 19) // 만약 판을 벗어날 경우, 이동하지 않고 넘김
			{
				break;
			}
			else
			{
				this->x += distance; // 오른쪽으로 한칸 이동함
				break;
			}
			break;
		}
	}
}
