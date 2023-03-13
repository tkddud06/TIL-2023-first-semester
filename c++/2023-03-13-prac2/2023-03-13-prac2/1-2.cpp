#include <iostream>
using namespace std;

double getmax(double arr[]);

int main()
{
	double arr[5];
	for (int i = 0; i < 5; i++)
	{
		cin >> arr[i];
	}
	double max = getmax(arr);
	cout << "제일 큰 수 = " << max << endl;
	return 0;
}

double getmax(double arr[])
{
	double max = arr[0];
	for (int i = 0; i < 5; i++)
	{
		if (max < arr[i])
		{
			max = arr[i];
		}
	}
	return max;
}