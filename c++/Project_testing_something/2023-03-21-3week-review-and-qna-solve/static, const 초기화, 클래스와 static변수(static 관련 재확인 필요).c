#include <stdio.h>

const aa;

static ii;

int main()
{
	const a;
	// a = 3; // ����
	printf("%d", aa); // �ش� ��쿡��, ���������� Ư¡�� ����, aa�� 0���� �ʱ�ȭ ��.
	// printf("%d", a); // �ʱ�ȭ �ȵȰ� ���ٰ� ����
	// ��� : �ʱ�ȭ ���ص� ������ �� �� �ִµ�, �� ������ ��.

	static i;
	printf("%d", ii);
	printf("%d", i); // �ڵ����� 0���� �ʱ�ȭ ��
	i = 3;
	ii = 2;
	printf("%d", i);
	// ��� : �ʱ�ȭ ���ϸ�, �ڵ����� 0���� �ʱ�ȭ ��. 
	// statc Ư¡ �� �ϳ���, �ܺο��� ���� ������ ������ �� ����, ���м� �ִٴ� ���� �ִ�. ����.
	// https://blog.naver.com/dhrtpdnjs/222974544617
	// https://cafe.naver.com/cafec/393651?art=ZXh0ZXJuYWwtc2VydmljZS1uYXZlci1zZWFyY2gtY2FmZS1wcg.eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJjYWZlVHlwZSI6IkNBRkVfVVJMIiwiY2FmZVVybCI6ImNhZmVjIiwiYXJ0aWNsZUlkIjozOTM2NTEsImlzc3VlZEF0IjoxNjc5NDk1MTg5NTk4fQ.A6lQVoXY1XwgMp6TvmVu4TilLnyZPThK7nBCHrPvSjk ������ ���ôٽ���, �ش� �Լ���, Ŭ������ �ܺο��� ���� ���� �ȵ�.
	return 0;
}