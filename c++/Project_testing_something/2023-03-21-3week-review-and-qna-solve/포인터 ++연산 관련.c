#include <stdio.h>

int main()
{
	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };

	int* ptr = arr;

	ptr++; // �̰� ������.
	ptr = arr;
	for (int i = 0; i < 10; i++)
	{
		printf("%d", ptr[0]);
		ptr++; // ptr�� ���� ������ i = 9�� ���� �ǹǷ�, ���������� ptr[10]�� ��. i = 0�� �� 1���ϰ� ������(ptr[1]), i = 9�� �� ���� 10���ϰ� ������(ptr[10]). �迭 ����.
	}
	printf("\n %d", ptr[0]); // �翬������, ������.
	return 0;
}