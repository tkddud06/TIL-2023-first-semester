#include <stdio.h>

int main()
{
    int i, *p; // 정수형 변수 i와, 정수형 포인터 변수 p 선언

    i = 10; // i에 10이라는 값 대입하여 초기화

    printf("value of i = %d\n", i); // i의 값 출력. 10이 출력될 것임
    printf("address of i = %p\n", &i); // i의 주솟값 출력
    printf("value of p = %p\n", p); // p의 값 출력. 초기화하지 않았기 때문에, 현재는 쓰레기값이 들어있음
    printf("address of p = %p\n", &p); // p의 주솟값 출력

    p = &i; // p에 i의 주솟값 대입하여 초기화

    printf("\n\n----- after p = &i ------------\n\n");

    printf("value of p = %p\n", p); // p의 값 출력. i의 주솟값을 출력할 것임. 그렇기에, 상단의 address of i와 출력값 동일
    printf("address of p = %p\n", &p); // p의 주솟값 출력. 상단의 address of p, 즉 기존값과 동일
    printf("dereferencing *p = %d\n", *p); // p를 역참조하여, p가 가지고 있는 주솟값이 가지고 있는 값 출력. 
    // p의 현재 값은 i의 주솟값이므로, i의 값인 10을 출력

    // 해당 코드에서, 주솟값은 실행 시마다 바뀔 수 있음
    return 0;
}