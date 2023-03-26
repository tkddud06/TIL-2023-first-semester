#pragma once
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <memory.h>
#include <time.h>
#include <ctype.h>

#define DIM	9 // 지뢰판의 크기를 표현하는 상수 (9*9 지뢰판이 될 것임)

enum LabelType { Empty = 0, Bomb = 9 }; // 해당 위치가 비어있는지, 지뢰가 있는지 표현하기 위한 enum
enum MaskType { Hide = 0, Open, Flag }; // 해당 위치가 가려져있는지, 열려있는지, 깃발이 꽂혀있는지 표현하기 위한 enum
int	MineMapMask[DIM][DIM];
int	MineMapLabel[DIM][DIM];
int	nx = DIM, ny = DIM;
int	nBomb = DIM;

inline int& mask(int x, int y) { return MineMapMask[y][x]; } 
inline int& label(int x, int y) { return MineMapLabel[y][x]; }
inline bool	isValid(int x, int y) { return (x >= 0 && x < nx&& y >= 0 && y < ny); }
inline bool	isBomb(int x, int y) { return isValid(x, y) && label(x, y) == Bomb; }
inline bool	isEmpty(int x, int y) { return isValid(x, y) && label(x, y) == Empty; }

void dig(int x, int y) {
	if (isValid(x, y) && mask(x, y) != Open) {
		mask(x, y) = Open;
		if (label(x, y) == 0) {
			dig(x - 1, y - 1);
			dig(x - 1, y);
			dig(x - 1, y + 1);
			dig(x, y - 1);
			dig(x, y + 1);
			dig(x + 1, y - 1);
			dig(x + 1, y);
			dig(x + 1, y + 1);
		}
	}
}
void mark(int x, int y) { // 플래그를 세워주는 함수.
	if (isValid(x, y) && mask(x, y) == Hide) 
		mask(x, y) = Flag;
}
int getBombCount() {
	int count = 0;
	for (int y = 0; y < ny; y++)
		for (int x = 0; x < nx; x++)
			if (mask(x, y) == Flag) count++;
	return count;
}
void print() {
	system("cls");
	printf("   발견:%2d   전체:%2d\n", getBombCount(), nBomb);
	printf("    ① ② ③ ④ ⑤ ⑥ ⑦ ⑧ ⑨\n");
	for (int y = 0; y < ny; y++) {
		printf("%2c ", 'A' + y);
		for (int x = 0; x < nx; x++) {
			if (mask(x, y) == Hide)	printf(" □");
			else if (mask(x, y) == Flag) printf("¤");
			else {
				if (isBomb(x, y)) printf(" ※");
				else if (isEmpty(x, y)) printf("  ");
				else printf("%2d", label(x, y));
			}
		}
		printf("\n");
	}
}
int countNbrBombs(int x, int y) { // 해당 칸에, 주변의 지뢰 수를 숫자로 표기해주기 위한 카운트 함수
	int count = 0;
	for (int yy = y - 1; yy <= y + 1; yy++)
		for (int xx = x - 1; xx <= x + 1; xx++)
			if (isValid(xx, yy) && label(xx, yy) == Bomb)
				count++;
	return count;
}
void init(int total = 9) { // 지뢰찾기를 위한 판(베이스) 생성 함수로 이동. //  ???????????????????????????????????????? 9눈 무슨의미지
	srand((unsigned int)time(NULL)); // 시드 랜덤화
	for (int y = 0; y < ny; y++) // 지뢰판 초기화 for문 (이중 포문 구조)
		for (int x = 0; x < nx; x++) {
			mask(x, y) = Hide; // mask판을 모두 hide(0)으로 초기화
			label(x, y) = 0; // label판을 모두 0(empty)로 초기화
		}
	nBomb = total; // nBomb에 입력받은 total수 대입.
	for (int i = 0; i < nBomb; i++) { // 지뢰의 수만큼 돌아가는 for문
		int x, y; // 위치를 나타내는 변수
		do { // rand함수를 통해 랜덤하게 x, y로 나타내어지는 위치가 empty일때까지 do-while문 계속 반복 (bomb인 자리에 한번 더 bomb를 하면 안 되니까)
			x = rand() % nx;
			y = rand() % ny;
		} while (label(x, y) != Empty);
		label(x, y) = Bomb; // x, y위치의 label판에 bomb 표시
	}
	for (int y = 0; y < ny; y++)
		for (int x = 0; x < nx; x++)
			if (label(x, y) == Empty)
				label(x, y) = countNbrBombs(x, y);
}
bool getPos(int& x, int& y) {
	printf("\n지뢰(P)행(A-I)열(1-9)\n      입력 --> ");
	bool isBomb = false; // P를 입력했는지, 아닌지 확인하려는 bool. 깃발을 세울지 말지 여부를 결정지어줌.
	y = toupper(_getch()) - 'A';
	if (y == 'P' - 'A') {
		isBomb = true;
		y = toupper(_getche()) - 'A';
	}
	x = _getch() - '1';
	return isBomb;
}
int checkDone() {
	int count = 0;
	for (int y = 0; y < ny; y++)
		for (int x = 0; x < nx; x++) {
			if (mask(x, y) != Open) count++;
			else if (isBomb(x, y)) return -1;
		}
	return (count == nBomb) ? 1 : 0;
}
void playMineSweeper(int total) {
	int x, y, status; 
	init(total); // 지뢰찾기를 위한 판(베이스) 생성 함수로 이동
	do {
		print();
		bool isBomb = getPos(x, y);
		if (isBomb) mark(x, y); // isBomb(P 입력 여부)가 True라면, 플래그를 세워주는 함수로 이동.
		else		  dig(x, y); // 해당 위치의 hide 상태를 없애주는 함수로 이동. (땅을 파는 함수)
		status = checkDone(); // 게임이 끝났는지 확인하는 함수로 이동.
	} while (status == 0);
	print();
	if (status < 0)
		printf("\n실패: 지뢰 폭발!!!\n\n");
	else	printf("\n성공: 탐색 성공!!!\n\n");
}
void main()
{
	int total; // 총 지뢰수 변수
	printf(" <Mine Sweeper>\n");
	printf(" 매설할 총 지뢰의 개수 입력 : ");
	scanf("%d", &total); // 매설할 총 지뢰 수 입력받기
	playMineSweeper(total); // total을 갖고, 지뢰찾기 실행 함수로 이동
}