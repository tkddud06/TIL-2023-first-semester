#include <stdio.h>

#define MAX_SIZE 100

float sum1(float list[], int);

float sum2(float *list, int);

float sum3(int n, float *list);

float input[MAX_SIZE], answer;

int i;

void main(void)
{
    for(i=0; i < MAX_SIZE; i++)
    {
        input[i] = i;
    }
    /* for checking call by reference */
    printf("--------------------------------------\n");
    printf(" sum1(input, MAX_SIZE) \n");
    printf("--------------------------------------\n");

    printf("input \t= %p\n", input);
    answer = sum1(input, MAX_SIZE);
    printf("The sum is: %f\n\n", answer);


    printf("--------------------------------------\n");
    printf(" sum2(input, MAX_SIZE) \n");
    printf("--------------------------------------\n");

    printf("input \t= %p\n", input);
    answer = sum2(input, MAX_SIZE);
    printf("The sum is: %f\n\n", answer);


    printf("--------------------------------------\n");
    printf(" sum3(MAX_SIZE, input) \n");
    printf("--------------------------------------\n");

    printf("input \t= %p\n", input);
    answer = sum3(MAX_SIZE, input);
    printf("The sum is: %f\n\n", answer);
}

float sum1(float list[], int n) 
{
    printf("list \t= %p\n", list); // 왜 둘이 다르지? 아! 여기서 list는 실제 list가 아니라 포인터다! 그러니 진짜 배열인 list에 &때린거랑은 다르지. 포인터의 주소가 나오니까.
    printf("&list \t= %p\n\n", &list);

    int i;
    float tempsum = 0;

    for(i = 0; i < n; i++) 
    {
        tempsum += list[i];
    }

    return tempsum;
}

float sum2(float *list, int n) 
{
    printf("list \t= %p\n", list);
    printf("&list \t= %p\n\n", &list);

    int i;
    float tempsum = 0;

    for(i = 0; i < n; i++)
    {
        tempsum += *(list + i);
    }
    return tempsum;
}
/* stack variable reuse test */
float sum3(int n, float *list) 
{
    printf("list \t= %p\n", list);
    printf("&list \t= %p\n\n", &list);

    int i;
    float tempsum = 0;

    for(i = 0; i < n; i++)
    {
        tempsum += *(list + i);
    }
    return tempsum;
}