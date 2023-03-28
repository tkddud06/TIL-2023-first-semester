#pragma once
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <memory.h>
#include <time.h>
#include <ctype.h>

#define DIM	9 // �������� ũ�⸦ ǥ���ϴ� ���, ���� ���� �⺻�����ε� ���� (9*9 �������� �� ����)

enum LabelType { Empty = 0, Bomb = 9 }; // �ش� ��ġ�� ����ִ���, ���ڰ� �ִ��� ǥ���ϱ� ���� enum
enum MaskType { Hide = 0, Open, Flag }; // �ش� ��ġ�� �������ִ���, �����ִ���, ����� �����ִ��� ǥ���ϱ� ���� enum
int	nx = DIM, ny = DIM; // x�� y�� ���� �� �ִ� ������ üũ�ϱ� ���� ����. 9*9 ��������.
int	nBomb = DIM; // ���� ���� ��Ÿ���� ����. �⺻���� 9

inline int& mask(int x, int y, int MineMapMask[][DIM]) { return MineMapMask[y][x]; } // mask���� x,y ��ġ�� ������ ���� ����.
inline int& label(int x, int y, int MineMapLabel[][DIM]) { return MineMapLabel[y][x]; } // label���� x,y ��ġ�� ������ ���� ����.
inline bool	isValid(int x, int y) { return (x >= 0 && x < nx&& y >= 0 && y < ny); } // �ش� x, y�� �������� ũ�⸦ ���� �ʴ���(��ȿ����) Ȯ���ϴ� �Լ�
inline bool	isBomb(int x, int y, int MineMapLabel[][DIM]) { return isValid(x, y) && label(x, y, MineMapLabel) == Bomb; } // �ش� ��ġ�� ��ȿ�ϰ�, �������� Ȯ���ϴ� �Լ�
inline bool	isEmpty(int x, int y, int MineMapLabel[][DIM]) { return isValid(x, y) && label(x, y, MineMapLabel) == Empty; } // �ش� ��ġ�� ��ȿ�ϰ�, ����ִ��� Ȯ���ϴ� �Լ�
// �ζ��� �Լ��� ���.
void dig(int x, int y, int MineMapMask[][DIM], int MineMapLabel[][DIM]) { // ���� �Ĵ� �Լ�
	if (isValid(x, y) && mask(x, y, MineMapMask) != Open) { // �ش� ��ġ�� ��ȿ�ϰ�, �Ŀ����� ���� �����
		mask(x, y, MineMapMask) = Open; // �Ǵ� (mask �ǿ� �ݿ�)
		if (label(x, y, MineMapLabel) == 0) { // �ش� ĭ�� ���ڰ� ���ٸ�(�ѷ��� ĭ�鿡 ���ڰ� ���ٸ�)(label���� Ȯ���Ͽ� üũ) �ֺ��� �Ǵ�
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
void mark(int x, int y, int MineMapMask[][DIM]) { // ����� �����ִ� �Լ�.
	if (isValid(x, y) && mask(x, y, MineMapMask) == Hide) // �ش� ��ġ�� ��ȿ�ϰ�, �Ŀ����� ���� �����
		mask(x, y, MineMapMask) = Flag; // ����� ����� (mask �ǿ� �ݿ�)
}
int getBombCount(int MineMapMask[][DIM]) { // ����� �ȾƵ� ���� ����� ���ִ� �Լ�
	int count = 0; // ������ ���� ���� ����
	for (int y = 0; y < ny; y++)
		for (int x = 0; x < nx; x++) // ������ ��ü�� ���� ��� ���� ����
			if (mask(x, y, MineMapMask) == Flag) count++; // mask���� Ȯ�������ν� ��� ���� ����.
	return count;
}
void print(int MineMapMask[][DIM], int MineMapLabel[][DIM]) { // ȭ���� ����ϴ� �Լ�. ������ �Ʒ��� ����.
	system("cls");
	printf("   �߰�:%2d   ��ü:%2d\n", getBombCount(MineMapMask), nBomb); // ��� ��, �� ���� �� ���
	printf("    �� �� �� �� �� �� �� �� ��\n"); // �� ��ȣ ���
	for (int y = 0; y < ny; y++) {
		printf("%2c ", 'A' + y); // �� ��ȣ ���
		for (int x = 0; x < nx; x++) {
			if (mask(x, y, MineMapMask) == Hide)	printf(" ��"); // �� �� ���
			else if (mask(x, y, MineMapMask) == Flag) printf("��"); // ����� ���� ���
			else {
				if (isBomb(x, y, MineMapLabel)) printf(" ��"); // ������ ���(�� ĭ�� ���ڰ� �ִ� ���)
				else if (isEmpty(x, y, MineMapLabel)) printf("  "); // �� ���(���ڰ� ���� ���)
				else printf("%2d", label(x, y, MineMapLabel)); // ���ڰ� �ִ� ���
			}
		}
		printf("\n");
	}
}
int countNbrBombs(int x, int y, int MineMapLabel[][DIM]) { // �ش� ĭ��, �ֺ��� ���� ���� ���ڷ� ǥ�����ֱ� ���� ī��Ʈ �Լ�
	int count = 0; // ���� ���� ����
	for (int yy = y - 1; yy <= y + 1; yy++)
		for (int xx = x - 1; xx <= x + 1; xx++) // �ش� ĭ�� ��,��,��,��,�밢��(�ش� ĭ�� �ѷ��ΰ� �ִ� ĭ)�� Ȯ���Ͽ�, �� ���� ���� üũ��
			if (isValid(xx, yy) && label(xx, yy, MineMapLabel) == Bomb)
				count++;
	return count;
}
void init(int MineMapMask[][DIM], int MineMapLabel[][DIM], int total = 9) { // ����ã�⸦ ���� ��(���̽�) ���� �Լ��� �̵�. total�� �� �޾��� ��, 9�� ����Ʈ ���� ����.
	srand((unsigned int)time(NULL)); // �õ� ����ȭ
	for (int y = 0; y < ny; y++) // ������ �ʱ�ȭ for�� (���� ���� ����)
		for (int x = 0; x < nx; x++) {
			mask(x, y, MineMapMask) = Hide; // mask���� ��� hide(0)���� �ʱ�ȭ
			label(x, y, MineMapLabel) = 0; // label���� ��� 0(empty)�� �ʱ�ȭ
		}
	nBomb = total; // nBomb�� �Է¹��� total�� ����.
	for (int i = 0; i < nBomb; i++) { // ������ ����ŭ ���ư��� for��
		int x, y; // ��ġ�� ��Ÿ���� ����
		do { // rand�Լ��� ���� �����ϰ� x, y�� ��Ÿ�������� ��ġ�� empty�϶����� do-while�� ��� �ݺ� (bomb�� �ڸ��� �ѹ� �� bomb�� �ϸ� �� �Ǵϱ�)
			x = rand() % nx;
			y = rand() % ny;
		} while (label(x, y, MineMapLabel) != Empty);
		label(x, y, MineMapLabel) = Bomb; // x, y��ġ�� label�ǿ� bomb ǥ��, �ش� ��ġ�� ���ڷ� ����
	}
	for (int y = 0; y < ny; y++) // label�ǿ� �ֺ��� ���� ���� �������ֱ� ���� for��
		for (int x = 0; x < nx; x++)
			if (label(x, y,  MineMapLabel) == Empty)
				label(x, y, MineMapLabel) = countNbrBombs(x, y, MineMapLabel);
}
bool getPos(int& x, int& y) { // �Է¹޴� �Լ� (���۷��� ����ؼ�, ���������� ���� ���� �Է¹���)
	printf("\n����(P)��(A-I)��(1-9)\n      �Է� --> ");
	bool isBomb = false; // P�� �Է��ߴ���, �ƴ��� Ȯ���Ϸ��� bool. ����� ������ ���� ���θ� ����������.
	y = toupper(_getch()) - 'A';
	if (y == 'P' - 'A') { // P�� �Է��ߴٸ��� �������� �ϴ� if��. P�� �Է�ٸ�, isBomb�� true�� ��ȯ�ϰ�, y�� �ٽ� ����.
		isBomb = true;
		y = toupper(_getche()) - 'A';
	}
	x = _getch() - '1';
	// �Է¹��� ������ y, x�� ���� 0~8 ������ ���� �ٲپ�, ���α׷����� ������ �迭�� �ٷ� �ε��� ��ȣ�μ� ������ �� �ְ� ����.
	return isBomb;
}
int checkDone(int MineMapMask[][DIM], int MineMapLabel[][DIM]) { // ������ �������� Ȯ���ϴ� �Լ�
	int count = 0;
	for (int y = 0; y < ny; y++)
		for (int x = 0; x < nx; x++) { // ��ü ���� ���� Ȯ���ϴ� for��
			if (mask(x, y, MineMapMask) != Open) count++;
			else if (isBomb(x, y, MineMapLabel)) return -1; // ���� �Ŀ��ִٸ�, �ش� ĭ�� ���ڴ� �ƴ���(���� ��ġ�� �ǵ�� �ƴ���) Ȯ���ϴ� ���ǹ�. ���ڸ� �ʹٸ� -1 ����.
		}
	return (count == nBomb) ? 1 : 0; // ���� ĭ ����, ��� ���ڶ�� 1 ����(����), �ƴ϶�� 0 ����(�� ����)
}
void playMineSweeper(int total, int MineMapMask[][DIM], int MineMapLabel[][DIM]) {
	int x, y, status; 
	init(MineMapMask, MineMapLabel, total); // ����ã�⸦ ���� ��(���̽�) ���� �Լ��� �̵�
	do {
		print(MineMapMask, MineMapLabel); // ȭ�� ��� �Լ�.
		bool isBomb = getPos(x, y); // �Է¹޴� �Լ�. x, y�� �Է¹޴� ���ÿ�, isBomb ����(P�Է� ����)�� Ȯ����.
		if (isBomb) mark(x, y, MineMapMask); // isBomb(P �Է� ����)�� True���, ����� �����ִ� �Լ��� �̵�.
		else		  dig(x, y, MineMapMask, MineMapLabel); // �ƴ϶��, �ش� ��ġ�� hide ���¸� �����ִ� �Լ��� �̵�. (���� �Ĵ� �Լ�)
		status = checkDone(MineMapMask, MineMapLabel); // ������ �������� Ȯ���ϴ� �Լ��� �̵�.
	} while (status == 0); // ������ ������ �ʾҴٸ� �ݺ�
	print(MineMapMask, MineMapLabel);
	if (status < 0) // ���ڰ� �����ٸ� ���� �޽��� ���
		printf("\n����: ���� ����!!!\n\n");
	else	printf("\n����: Ž�� ����!!!\n\n"); // ���ڸ� ��� ã�Ҵٸ� ���� �޽��� ���
}
void main()
{
	int total; // �� ���ڼ� ����
	int	MineMapMask[DIM][DIM]; // �������� mask ���¸� �����ϴ� ��
	int	MineMapLabel[DIM][DIM]; // �������� label ���¸� �����ϴ� ��
	printf(" <Mine Sweeper>\n");
	printf(" �ż��� �� ������ ���� �Է� : ");
	scanf("%d", &total); // �ż��� �� ���� �� �Է¹ޱ�
	playMineSweeper(total, MineMapMask, MineMapLabel); // ����ã����� ���� �Լ��� �̵�
}

// MineMapMask, MineMapLabel ���������� �ٷ�� ���� �� : �ʹ� ���� ���̴� ����, �������ϰ� ���̴� ������, ���������� �� ��������.
// ���� �Լ��� ���������μ� ������ ���, �ش� ������ � �Լ����� ���� ������ �ʴ���, �� �Լ� �ȿ��� �ҷ��� �Լ�, Ȥ�� �� �ȿ��� �ҷ��� �Ǵٸ� �Լ������� �ʿ��ϴٸ�, �Ű������� �������־�� �Ѵ�.
// ������ �迭�� �Ű������� �Ѱ�� ������, �����͸� �̿��Ͽ� �ּҸ� �Ѱ��.