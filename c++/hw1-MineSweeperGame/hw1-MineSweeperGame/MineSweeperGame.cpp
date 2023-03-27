#pragma once
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <memory.h>
#include <time.h>
#include <ctype.h>

#define DIM	9 // �������� ũ�⸦ ǥ���ϴ� ��� (9*9 �������� �� ����)

enum LabelType { Empty = 0, Bomb = 9 }; // �ش� ��ġ�� ����ִ���, ���ڰ� �ִ��� ǥ���ϱ� ���� enum
enum MaskType { Hide = 0, Open, Flag }; // �ش� ��ġ�� �������ִ���, �����ִ���, ����� �����ִ��� ǥ���ϱ� ���� enum
int	nx = DIM, ny = DIM;
int	nBomb = DIM;

inline int& mask(int x, int y, int MineMapMask[][DIM], int MineMapLabel[][DIM]) { return MineMapMask[y][x]; }
inline int& label(int x, int y, int MineMapMask[][DIM], int MineMapLabel[][DIM]) { return MineMapLabel[y][x]; }
inline bool	isValid(int x, int y) { return (x >= 0 && x < nx&& y >= 0 && y < ny); }
inline bool	isBomb(int x, int y, int MineMapMask[][DIM], int MineMapLabel[][DIM]) { return isValid(x, y) && label(x, y, MineMapMask, MineMapLabel) == Bomb; }
inline bool	isEmpty(int x, int y, int MineMapMask[][DIM], int MineMapLabel[][DIM]) { return isValid(x, y) && label(x, y, MineMapMask, MineMapLabel) == Empty; }

void dig(int x, int y, int MineMapMask[][DIM], int MineMapLabel[][DIM]) {
	if (isValid(x, y) && mask(x, y, MineMapMask, MineMapLabel) != Open) {
		mask(x, y, MineMapMask, MineMapLabel) = Open;
		if (label(x, y, MineMapMask, MineMapLabel) == 0) {
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
void mark(int x, int y, int MineMapMask[][DIM], int MineMapLabel[][DIM]) { // �÷��׸� �����ִ� �Լ�.
	if (isValid(x, y) && mask(x, y, MineMapMask, MineMapLabel) == Hide)
		mask(x, y, MineMapMask, MineMapLabel) = Flag;
}
int getBombCount(int MineMapMask[][DIM], int MineMapLabel[][DIM]) {
	int count = 0;
	for (int y = 0; y < ny; y++)
		for (int x = 0; x < nx; x++)
			if (mask(x, y, MineMapMask, MineMapLabel) == Flag) count++;
	return count;
}
void print(int MineMapMask[][DIM], int MineMapLabel[][DIM]) {
	system("cls");
	printf("   �߰�:%2d   ��ü:%2d\n", getBombCount(MineMapMask, MineMapLabel), nBomb);
	printf("    �� �� �� �� �� �� �� �� ��\n");
	for (int y = 0; y < ny; y++) {
		printf("%2c ", 'A' + y);
		for (int x = 0; x < nx; x++) {
			if (mask(x, y, MineMapMask, MineMapLabel) == Hide)	printf(" ��");
			else if (mask(x, y, MineMapMask, MineMapLabel) == Flag) printf("��");
			else {
				if (isBomb(x, y, MineMapMask, MineMapLabel)) printf(" ��");
				else if (isEmpty(x, y, MineMapMask, MineMapLabel)) printf("  ");
				else printf("%2d", label(x, y, MineMapMask, MineMapLabel));
			}
		}
		printf("\n");
	}
}
int countNbrBombs(int x, int y, int MineMapMask[][DIM], int MineMapLabel[][DIM]) { // �ش� ĭ��, �ֺ��� ���� ���� ���ڷ� ǥ�����ֱ� ���� ī��Ʈ �Լ�
	int count = 0;
	for (int yy = y - 1; yy <= y + 1; yy++)
		for (int xx = x - 1; xx <= x + 1; xx++)
			if (isValid(xx, yy) && label(xx, yy, MineMapMask, MineMapLabel) == Bomb)
				count++;
	return count;
}
void init(int MineMapMask[][DIM], int MineMapLabel[][DIM], int total = 9) { // ����ã�⸦ ���� ��(���̽�) ���� �Լ��� �̵�. //  ???????????????????????????????????????? 9�� �����ǹ���
	srand((unsigned int)time(NULL)); // �õ� ����ȭ
	for (int y = 0; y < ny; y++) // ������ �ʱ�ȭ for�� (���� ���� ����)
		for (int x = 0; x < nx; x++) {
			mask(x, y, MineMapMask, MineMapLabel) = Hide; // mask���� ��� hide(0)���� �ʱ�ȭ
			label(x, y, MineMapMask, MineMapLabel) = 0; // label���� ��� 0(empty)�� �ʱ�ȭ
		}
	nBomb = total; // nBomb�� �Է¹��� total�� ����.
	for (int i = 0; i < nBomb; i++) { // ������ ����ŭ ���ư��� for��
		int x, y; // ��ġ�� ��Ÿ���� ����
		do { // rand�Լ��� ���� �����ϰ� x, y�� ��Ÿ�������� ��ġ�� empty�϶����� do-while�� ��� �ݺ� (bomb�� �ڸ��� �ѹ� �� bomb�� �ϸ� �� �Ǵϱ�)
			x = rand() % nx;
			y = rand() % ny;
		} while (label(x, y, MineMapMask, MineMapLabel) != Empty);
		label(x, y, MineMapMask, MineMapLabel) = Bomb; // x, y��ġ�� label�ǿ� bomb ǥ��
	}
	for (int y = 0; y < ny; y++)
		for (int x = 0; x < nx; x++)
			if (label(x, y, MineMapMask, MineMapLabel) == Empty)
				label(x, y, MineMapMask, MineMapLabel) = countNbrBombs(x, y, MineMapMask, MineMapLabel);
}
bool getPos(int& x, int& y) {
	printf("\n����(P)��(A-I)��(1-9)\n      �Է� --> ");
	bool isBomb = false; // P�� �Է��ߴ���, �ƴ��� Ȯ���Ϸ��� bool. ����� ������ ���� ���θ� ����������.
	y = toupper(_getch()) - 'A';
	if (y == 'P' - 'A') {
		isBomb = true;
		y = toupper(_getche()) - 'A';
	}
	x = _getch() - '1';
	return isBomb;
}
int checkDone(int MineMapMask[][DIM], int MineMapLabel[][DIM]) { // ������ �������� Ȯ���ϴ� �Լ�
	int count = 0;
	for (int y = 0; y < ny; y++)
		for (int x = 0; x < nx; x++) {
			if (mask(x, y, MineMapMask, MineMapLabel) != Open) count++;
			else if (isBomb(x, y, MineMapMask, MineMapLabel)) return -1;
		}
	return (count == nBomb) ? 1 : 0;
}
void playMineSweeper(int total, int MineMapMask[][DIM], int MineMapLabel[][DIM]) {
	int x, y, status; 
	init(MineMapMask, MineMapLabel, total); // ����ã�⸦ ���� ��(���̽�) ���� �Լ��� �̵�
	do {
		print(MineMapMask, MineMapLabel);
		bool isBomb = getPos(x, y);
		if (isBomb) mark(x, y, MineMapMask, MineMapLabel); // isBomb(P �Է� ����)�� True���, �÷��׸� �����ִ� �Լ��� �̵�.
		else		  dig(x, y, MineMapMask, MineMapLabel); // �ش� ��ġ�� hide ���¸� �����ִ� �Լ��� �̵�. (���� �Ĵ� �Լ�)
		status = checkDone(MineMapMask, MineMapLabel); // ������ �������� Ȯ���ϴ� �Լ��� �̵�.
	} while (status == 0);
	print(MineMapMask, MineMapLabel);
	if (status < 0)
		printf("\n����: ���� ����!!!\n\n");
	else	printf("\n����: Ž�� ����!!!\n\n");
}
void main()
{
	int total; // �� ���ڼ� ����
	int	MineMapMask[DIM][DIM]; // �������� mask���¸� �����ϴ� ��
	int	MineMapLabel[DIM][DIM]; // �������� label ���¸� �����ϴ� ��
	printf(" <Mine Sweeper>\n");
	printf(" �ż��� �� ������ ���� �Է� : ");
	scanf("%d", &total); // �ż��� �� ���� �� �Է¹ޱ�
	playMineSweeper(total, MineMapMask, MineMapLabel); // total�� ����, ����ã�� ���� �Լ��� �̵�
}

// MineMapMask, MineMapLabel ���������� �ٷ�� ���� ��. �ʹ� ���� ���̴� ����, �������ϰ� ���̴� ������, ���������� �� ��������.