#include <stdio.h>
int main()
{
int i;
int *ptr;
int **dptr;
// int형 변수 i, int형 포인터 변수 ptr, int형 이중포인터 변수 dptr 선언
i = 1234; // i에 1234를 대입하여 초기화
// ptr, dptr은 현재 쓰레기값 가짐

printf("[checking values before ptr = &i] \n");
printf("value of i == %d\n", i); // i의 값인 1234 출력 
printf("address of i == %p\n", &i); // i의 주솟값 출력 
printf("value of ptr == %p\n", ptr); // ptr의 현재 값인 쓰레기값 출력 
printf("address of ptr == %p\n", &ptr); // ptr의 주솟값 출력 

ptr = &i; // ptr에 i의 주솟값 대입

printf("\n[checking values after ptr = &i] \n");
printf("value of i == %d\n", i); // 1234 출력 (위에서와 동일)
printf("address of i == %p\n", &i); // i의 주솟값 출력 (위에서와 동일)
printf("value of ptr == %p\n", ptr); // ptr이 가진 값 출력 (i의 주솟값 출력됨)
printf("address of ptr == %p\n", &ptr); // ptr의 주솟값 출력 (위에서와 동일)
printf("value of *ptr == %d\n", *ptr); // ptr은 i를 가리키고 있으므로, i의 값인 1234 출력

dptr = &ptr; // dptr에 ptr의 주솟값 대입

printf("\n[checking values after dptr = &ptr] \n");
printf("value of i == %d\n", i); // 1234 출력 (위에서와 동일)
printf("address of i == %p\n", &i); // i의 주솟값 출력 (위에서와 동일)
printf("value of ptr == %p\n", ptr); // ptr이 가진 값 출력 (i의 주솟값 출력됨)
printf("address of ptr == %p\n", &ptr); // ptr의 주솟값 출력 (위에서와 동일)
printf("value of *ptr == %d\n", *ptr); // ptr은 i를 가리키고 있으므로, i의 값인 1234 출력 (위에서와 동일)
printf("value of dptr == %p\n", dptr); // dptr이 가진 값 출력 (ptr의 주솟값 출력됨)
printf("address of dptr == %p\n", &dptr); // dptr의 주솟값 출력
printf("value of *dptr == %p\n", *dptr); // dptr은 ptr을 가리키고 있으므로, ptr의 값인 i의 주솟값 출력
printf("value of **dptr == %d\n", **dptr); // dptr은 ptr을 가리키고 있고, ptr은 i를 가리키고 있으므로, i의 값인 1234 출력

*ptr = 7777; // *ptr의 값 변경 (ptr은 i를 가리키고 있으므로, i의 값이 7777로 변경)

printf("\n[after *ptr = 7777] \n");
printf("value of i == %d\n", i); // 7777 출력
printf("value of *ptr == %d\n", *ptr); // ptr은 i를 가리키고 있으므로, i의 값인 7777 출력
printf("value of **dptr == %d\n", **dptr); // dptr은 ptr을 가리키고 있고, ptr은 i를 가리키고 있으므로, i의 값인 7777 출력

**dptr = 8888; // **dptr의 값 변경 (dptr은 ptr을 가리키고 있고, ptr은 i를 가키리고 있으므로, i의 값이 8888로 변경)

printf("\n[after **dptr = 8888] \n");
printf("value of i == %d\n", i); // 8888 출력
printf("value of *ptr == %d\n", *ptr); // ptr은 i를 가리키고 있으므로, i의 값인 8888 출력
printf("value of **dptr == %d\n", **dptr); // dptr은 ptr을 가리키고 있고, ptr은 i를 가리키고 있으므로, i의 값인 8888 출력

printf("[----- [최상영]  [2022041062] -----]");

return 0;
}