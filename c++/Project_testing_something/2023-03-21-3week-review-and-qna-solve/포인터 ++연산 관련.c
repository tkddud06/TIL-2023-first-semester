#include <stdio.h>

int main()
{
	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };

	int* ptr = arr;

	ptr++; // 이건 누적됨.
	ptr = arr;
	for (int i = 0; i < 10; i++)
	{
		printf("%d", ptr[0]);
		ptr++; // ptr에 덧셈 연산이 i = 9일 때도 되므로, 마지막에는 ptr[10]인 셈. i = 0일 때 1더하고 마무리(ptr[1]), i = 9일 때 총합 10더하고 마무리(ptr[10]). 배열 넘음.
	}
	printf("\n %d", ptr[0]); // 당연하지만, 누적됨.
	return 0;
}