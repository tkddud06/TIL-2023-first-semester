#include <stdio.h>
int main()
{
char charType;
int integerType;
float floatType;
double doubleType;
// char형 변수 charType, int형 변수 integerType, float형 변수 floatType, double형 변수 doubleType 선언
// 초기화는 하지 않았으므로, 쓰레기값이 들어 있을 것임

printf("Size of char: %ld byte\n",sizeof(charType)); // charType은 char 자료형이므로, 1바이트 출력
printf("Size of int: %ld bytes\n",sizeof(integerType)); // integerType은 int 자료형이므로, 4바이트 출력
printf("Size of float: %ld bytes\n",sizeof(floatType)); // floatType은 float 자료형이므로, 4바이트 출력
printf("Size of double: %ld bytes\n",sizeof(doubleType)); // doubleType은 double 자료형이므로, 8바이트 출력

printf("-----------------------------------------\n");

// 위와 동일함. char 자료형은 1바이트, int 자료형은 4바이트, float 자료형은 4바이트, double 자료형은 8바이트 출력
printf("Size of char: %ld byte\n",sizeof(char));
printf("Size of int: %ld bytes\n",sizeof(int));
printf("Size of float: %ld bytes\n",sizeof(float));
printf("Size of double: %ld bytes\n",sizeof(double));

printf("-----------------------------------------\n");

// 포인터 변수들의 크기는 모두 동일함. 32비트 환경의 경우 4바이트, 64비트 환경의 경우 8바이트로 출력.
// 메모리 주소 길이만큼의 크기임.
// 현재의 경우, 32비트 환경이므로 4바이트 출력됨
printf("Size of char*: %ld byte\n",sizeof(char*));
printf("Size of int*: %ld bytes\n",sizeof(int*));
printf("Size of float*: %ld bytes\n",sizeof(float*));
printf("Size of double*: %ld bytes\n",sizeof(double*));

printf("[----- [최상영]  [2022041062] -----]\n");
// 변수의 주솟값은 실행 시마다 변할 수 있음
return 0;
}