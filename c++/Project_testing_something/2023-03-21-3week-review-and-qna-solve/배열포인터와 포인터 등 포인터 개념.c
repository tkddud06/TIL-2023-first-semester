#include <stdio.h>

int main()
{
	int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	int arr2[2][3] = { 1,2,3,4,5,6 };
	int (*parr2)[3] = arr2;
	int (*prr)[10] = arr; // cpp 형식으로 파일 지정시, &arr로 적어야 에러 안남. gcc에선 경고는 하지만, 실행 가능.
	// 단, c형식 파일에선 arr도 문제 없음.
	int* prr2 = &arr; // cpp 형식으로 파일 지정시, arr로 적어야 에러 안남. gcc에선 경고는 하지만, 실행 가능.
	// 단, c형식에선 문제 없음. &arr로 적어도 문제 없음.
	int* pointer = &arr2; // gcc에서 해당 부분에 대해, 경고해줌. 실행은 가능.
	printf("%p %p\n", arr2, pointer);
	printf("%p\n", &pointer[1]);
	printf("%d", pointer[4]);// 4*4, 16바이트 뒤인 5 출력

	int** doublepointer = arr2; // gcc에선 경고해줌. 실행은 가능.
	//printf("%d", doublepointer[1][0]); // 애초에 더블포인터로 배열을 가르키는게 무의미한 일.
	// 이차원 배열을, 상수형 더블 포인터같은 것으로 이해를 할 수 있지만, 이거랑은 다름.
	printf("%d", prr[0][1]);
	printf("%d", parr2[1][1]);
	// parr2와 prr은 배열 포인터이고, 이 경우, 이중 포인터같은 역할을 함. 보면 직관적으로 확인 가능
	printf("%d", prr2[9]);
	return 0;
}