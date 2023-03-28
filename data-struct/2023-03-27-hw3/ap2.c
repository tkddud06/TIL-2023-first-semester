#include <stdio.h>
#include <stdlib.h>

void main()
{

    int list[5]; // 정수형 배열 선언
    int *plist[5]; // 정수형 포인터 배열 선언 및 초기화

    list[0] = 10; // 정수형 배열의 0번째 인덱스 위치에 10 대입
    list[1] = 11; // 정수형 배열의 1번째 인덱스 위치에 11 대입

    plist[0] = (int*)malloc(sizeof(int)); // 정수형 포인터의 1번째 인덱스 위치에 동적할당

    printf("list[0] \t= %d\n", list[0]); // 10 출력
    printf("list \t\t= %p\n", list);
    printf("&list[0] \t= %p\n", &list[0]);
    printf("list + 0 \t= %p\n", list+0);
    printf("list + 1 \t= %p\n", list+1);
    printf("list + 2 \t= %p\n", list+2);
    printf("list + 3 \t= %p\n", list+3);
    printf("list + 4 \t= %p\n", list+4);
    printf("&list[4] \t= %p\n", &list[4]);

    free(plist[0]); // free.
}