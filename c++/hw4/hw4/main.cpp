
#include "Game.h" // ������ �ҷ����µ� ���
#include <cstdlib> // ������ �Լ��� ���
#include <ctime> // ������ �Լ��� ���


int main()
{
	srand(time(NULL)); // ��ü �� ���� �Լ��� ����ø��� �������� �絵�� �ϱ� ����

	Game g; // ������ ������ Game ��ü g ����
	g.main_process(); // ���� ����
	return 0;
}