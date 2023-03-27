#include <iostream>
using namespace std;

template <class T>
void reverseArray(T arr[], int size)
{
	for (int i = 0; i < size / 2; i++) // 자꾸 범위랑 개수 등의 단위개념 차이가 헷갈리는데,
		// 나중에 시간을 들이든 해서 좀 해결을 해보던지, 계속 보던지 해야겠음.
	{
		T temp = arr[i];
		arr[i] = arr[size - 1 - i];
		arr[size - 1 - i] = temp;
	}
}

int main()
{
	int x[] = { 1,10,100,5,4 };
	reverseArray(x, 5);
	for (int i = 0; i < 5; i++)
	{
		cout << x[i] << ' ';
	}
	cout << endl;
	return 0;
}