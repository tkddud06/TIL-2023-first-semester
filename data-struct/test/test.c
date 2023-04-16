#include <stdio.h>

void print(int* arr)
{
    for(int i = 0 ; i < 10; i++)
    {
        printf("%d", arr[i]);
    } // int* 형식으로 받아도, [] 쓸수 있고, int[] 형식으로 받아도 *쓸수 있음
}

int main()
{
    int arr[10] = {1,2,3,4,5,6,7,8,9,10};
    print(arr);
    // printf("\n%d", arr[-1]); 쓰레기값 출력.
    return 0;
}