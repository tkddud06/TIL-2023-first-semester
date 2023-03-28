#pragma once
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <memory.h>
#include <time.h>
#include <ctype.h>

#define DIM	9 // 지뢰판의 크기를 표현하는 상수, 지뢰 수의 기본값으로도 사용됨 (9*9 지뢰판이 될 것임)

enum LabelType { Empty = 0, Bomb = 9 }; // 해당 위치가 비어있는지, 지뢰가 있는지 표현하기 위한 enum
enum MaskType { Hide = 0, Open, Flag }; // 해당 위치가 가려져있는지, 열려있는지, 깃발이 꽂혀있는지 표현하기 위한 enum
int	nx = DIM, ny = DIM; // x와 y가 나올 수 있는 범위를 체크하기 위한 변수. 9*9 지뢰판임.
int	nBomb = DIM; // 지뢰 수를 나타내는 변수. 기본값은 9

inline int& mask(int x, int y, int MineMapMask[][DIM]) { return MineMapMask[y][x]; } // mask판의 x,y 위치의 공간을 참조 리턴.
inline int& label(int x, int y, int MineMapLabel[][DIM]) { return MineMapLabel[y][x]; } // label판의 x,y 위치의 공간을 참조 리턴.
inline bool	isValid(int x, int y) { return (x >= 0 && x < nx&& y >= 0 && y < ny); } // 해당 x, y가 지뢰판의 크기를 넘지 않는지(유효한지) 확인하는 함수
inline bool	isBomb(int x, int y, int MineMapLabel[][DIM]) { return isValid(x, y) && label(x, y, MineMapLabel) == Bomb; } // 해당 위치가 유효하고, 지뢰인지 확인하는 함수
inline bool	isEmpty(int x, int y, int MineMapLabel[][DIM]) { return isValid(x, y) && label(x, y, MineMapLabel) == Empty; } // 해당 위치가 유효하고, 비어있는지 확인하는 함수
// 인라인 함수들 사용.
void dig(int x, int y, int MineMapMask[][DIM], int MineMapLabel[][DIM]) { // 땅을 파는 함수
	if (isValid(x, y) && mask(x, y, MineMapMask) != Open) { // 해당 위치가 유효하고, 파여있지 않은 경우라면
		mask(x, y, MineMapMask) = Open; // 판다 (mask 판에 반영)
		if (label(x, y, MineMapLabel) == 0) { // 해당 칸에 숫자가 없다면(둘러싼 칸들에 지뢰가 없다면)(label판을 확인하여 체크) 주변도 판다
			dig(x - 1, y - 1, MineMapMask, MineMapLabel);
			dig(x - 1, y, MineMapMask, MineMapLabel);
			dig(x - 1, y + 1, MineMapMask, MineMapLabel);
			dig(x, y - 1, MineMapMask, MineMapLabel);
			dig(x, y + 1, MineMapMask, MineMapLabel);
			dig(x + 1, y - 1, MineMapMask, MineMapLabel);
			dig(x + 1, y, MineMapMask, MineMapLabel);
			dig(x + 1, y + 1, MineMapMask, MineMapLabel);
		}
	}
}
void mark(int x, int y, int MineMapMask[][DIM]) { // 깃발을 세워주는 함수.
	if (isValid(x, y) && mask(x, y, MineMapMask) == Hide) // 해당 위치가 유효하고, 파여있지 않은 경우라면
		mask(x, y, MineMapMask) = Flag; // 깃발을 세운다 (mask 판에 반영)
}
int getBombCount(int MineMapMask[][DIM]) { // 깃발을 꽂아둔 것이 몇개인지 세주는 함수
	int count = 0; // 개수를 세기 위한 변수
	for (int y = 0; y < ny; y++)
		for (int x = 0; x < nx; x++) // 지뢰판 전체를 돌며 깃발 수를 센다
			if (mask(x, y, MineMapMask) == Flag) count++; // mask판을 확인함으로써 깃발 수를 센다.
	return count;
}
void print(int MineMapMask[][DIM], int MineMapLabel[][DIM]) { // 화면을 출력하는 함수. 내용은 아래와 같다.
	system("cls");
	printf("   발견:%2d   전체:%2d\n", getBombCount(MineMapMask), nBomb); // 깃발 수, 총 지뢰 수 출력
	printf("    ① ② ③ ④ ⑤ ⑥ ⑦ ⑧ ⑨\n"); // 열 번호 출력
	for (int y = 0; y < ny; y++) {
		printf("%2c ", 'A' + y); // 행 번호 출력
		for (int x = 0; x < nx; x++) {
			if (mask(x, y, MineMapMask) == Hide)	printf(" □"); // 안 판 경우
			else if (mask(x, y, MineMapMask) == Flag) printf("¤"); // 깃발을 세운 경우
			else {
				if (isBomb(x, y, MineMapLabel)) printf(" ※"); // 폭발한 경우(고른 칸이 지뢰가 있는 경우)
				else if (isEmpty(x, y, MineMapLabel)) printf("  "); // 빈 경우(숫자가 없는 경우)
				else printf("%2d", label(x, y, MineMapLabel)); // 숫자가 있는 경우
			}
		}
		printf("\n");
	}
}
int countNbrBombs(int x, int y, int MineMapLabel[][DIM]) { // 해당 칸에, 주변의 지뢰 수를 숫자로 표기해주기 위한 카운트 함수
	int count = 0; // 세기 위한 변수
	for (int yy = y - 1; yy <= y + 1; yy++)
		for (int xx = x - 1; xx <= x + 1; xx++) // 해당 칸의 상,하,좌,우,대각선(해당 칸을 둘러싸고 있는 칸)을 확인하여, 총 지뢰 수를 체크함
			if (isValid(xx, yy) && label(xx, yy, MineMapLabel) == Bomb)
				count++;
	return count;
}
void init(int MineMapMask[][DIM], int MineMapLabel[][DIM], int total = 9) { // 지뢰찾기를 위한 판(베이스) 생성 함수로 이동. total을 안 받았을 시, 9로 디폴트 인자 설정.
	srand((unsigned int)time(NULL)); // 시드 랜덤화
	for (int y = 0; y < ny; y++) // 지뢰판 초기화 for문 (이중 포문 구조)
		for (int x = 0; x < nx; x++) {
			mask(x, y, MineMapMask) = Hide; // mask판을 모두 hide(0)으로 초기화
			label(x, y, MineMapLabel) = 0; // label판을 모두 0(empty)로 초기화
		}
	nBomb = total; // nBomb에 입력받은 total수 대입.
	for (int i = 0; i < nBomb; i++) { // 지뢰의 수만큼 돌아가는 for문
		int x, y; // 위치를 나타내는 변수
		do { // rand함수를 통해 랜덤하게 x, y로 나타내어지는 위치가 empty일때까지 do-while문 계속 반복 (bomb인 자리에 한번 더 bomb를 하면 안 되니까)
			x = rand() % nx;
			y = rand() % ny;
		} while (label(x, y, MineMapLabel) != Empty);
		label(x, y, MineMapLabel) = Bomb; // x, y위치의 label판에 bomb 표시, 해당 위치를 지뢰로 설정
	}
	for (int y = 0; y < ny; y++) // label판에 주변의 지뢰 수를 저장해주기 위한 for문
		for (int x = 0; x < nx; x++)
			if (label(x, y,  MineMapLabel) == Empty)
				label(x, y, MineMapLabel) = countNbrBombs(x, y, MineMapLabel);
}
bool getPos(int& x, int& y) { // 입력받는 함수 (레퍼런스 사용해서, 실질적으로 여러 값을 입력받음)
	printf("\n지뢰(P)행(A-I)열(1-9)\n      입력 --> ");
	bool isBomb = false; // P를 입력했는지, 아닌지 확인하려는 bool. 깃발을 세울지 말지 여부를 결정지어줌.
	y = toupper(_getch()) - 'A';
	if (y == 'P' - 'A') { // P를 입력했다면을 조건으로 하는 if문. P가 입력됬다면, isBomb를 true로 전환하고, y를 다시 받음.
		isBomb = true;
		y = toupper(_getche()) - 'A';
	}
	x = _getch() - '1';
	// 입력받은 수들을 y, x에 각각 0~8 사이의 수로 바꾸어, 프로그램에서 이차원 배열에 바로 인덱스 번호로서 접근할 수 있게 저장.
	return isBomb;
}
int checkDone(int MineMapMask[][DIM], int MineMapLabel[][DIM]) { // 게임이 끝났는지 확인하는 함수
	int count = 0;
	for (int y = 0; y < ny; y++)
		for (int x = 0; x < nx; x++) { // 전체 지뢰 판을 확인하는 for문
			if (mask(x, y, MineMapMask) != Open) count++;
			else if (isBomb(x, y, MineMapLabel)) return -1; // 만약 파여있다면, 해당 칸이 지뢰는 아닌지(지뢰 위치를 건든건 아닌지) 확인하는 조건문. 지뢰를 팠다면 -1 리턴.
		}
	return (count == nBomb) ? 1 : 0; // 파인 칸 빼고, 모두 지뢰라면 1 리턴(끝남), 아니라면 0 리턴(안 끝남)
}
void playMineSweeper(int total, int MineMapMask[][DIM], int MineMapLabel[][DIM]) {
	int x, y, status; 
	init(MineMapMask, MineMapLabel, total); // 지뢰찾기를 위한 판(베이스) 생성 함수로 이동
	do {
		print(MineMapMask, MineMapLabel); // 화면 출력 함수.
		bool isBomb = getPos(x, y); // 입력받는 함수. x, y를 입력받는 동시에, isBomb 여부(P입력 여부)를 확인함.
		if (isBomb) mark(x, y, MineMapMask); // isBomb(P 입력 여부)가 True라면, 깃발을 세워주는 함수로 이동.
		else		  dig(x, y, MineMapMask, MineMapLabel); // 아니라면, 해당 위치의 hide 상태를 없애주는 함수로 이동. (땅을 파는 함수)
		status = checkDone(MineMapMask, MineMapLabel); // 게임이 끝났는지 확인하는 함수로 이동.
	} while (status == 0); // 게임이 끝나지 않았다면 반복
	print(MineMapMask, MineMapLabel);
	if (status < 0) // 지뢰가 터졌다면 실패 메시지 출력
		printf("\n실패: 지뢰 폭발!!!\n\n");
	else	printf("\n성공: 탐색 성공!!!\n\n"); // 지뢰를 모두 찾았다면 성공 메시지 출력
}
void main()
{
	int total; // 총 지뢰수 변수
	int	MineMapMask[DIM][DIM]; // 지뢰판의 mask 상태를 저장하는 판
	int	MineMapLabel[DIM][DIM]; // 지뢰판의 label 상태를 저장하는 판
	printf(" <Mine Sweeper>\n");
	printf(" 매설할 총 지뢰의 개수 입력 : ");
	scanf("%d", &total); // 매설할 총 지뢰 수 입력받기
	playMineSweeper(total, MineMapMask, MineMapLabel); // 지뢰찾기게임 실행 함수로 이동
}

// MineMapMask, MineMapLabel 지역변수를 다루며 느낀 점 : 너무 많이 쓰이는 변수, 광범위하게 쓰이는 변수는, 전역변수로 꼭 지정하자.
// 메인 함수의 지역번수로서 선언할 경우, 해당 변수가 어떤 함수에서 직접 쓰이지 않더라도, 그 함수 안에서 불려진 함수, 혹은 그 안에서 불려진 또다른 함수에서라도 필요하다면, 매개변수로 전달해주어야 한다.
// 이차원 배열을 매개변수로 넘겼기 때문에, 포인터를 이용하여 주소를 넘겼다.