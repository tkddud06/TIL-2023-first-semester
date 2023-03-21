#include <iostream>

using namespace std;

void print(int (&ref)[10]) // 당연하지만, int& ref같은건 안됨. int& ref[10] 의경우는, 참조 배열인거지. 포인터배열 비슷한거 생각하면될듯. 당연히 안되겠지.
// 다만, 지금 해둔것처럼, 배열 레퍼런스가 가능.
{
	for (int i = 0; i < 10; i++)
	{
		cout << ref[i] << endl;
	}
}

int main()
{
	int a, b;
	// int& ref[2] = {a,b};
	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
	print(arr);
	// 찾아보다가 의문 든거 : 레퍼런스가 메모리 상에 반드시 존재해야 하는 경우가 있나?
	return 0;
}

// 레퍼런스의 함수 리턴 관련.
// 책 내용은 아마 내가 알던 표랑은 별개의 개념인듯?