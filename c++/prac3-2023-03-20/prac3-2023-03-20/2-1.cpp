#include <iostream>

using namespace std;

int main()
{
	int M[3][3] = { {1,2,3},{4,5,6},{7,8,9} };

	int(*ptr)[3];
	int* p;
	int** pt;

	ptr = M;
	cout << ptr << "\t" << M << endl;
	cout << ptr + 1 << "\t" << M + 1 << endl;
	cout << *(ptr + 1) << "\t" << ptr[1] << "\t" << *(M + 1) << "\t" << M[1] << endl;
	cout << **(ptr + 1) << "\t" << **(M + 1) << "\t" << *M[1] << "\t" << M[1][0] << endl;

	p = M[0];
	cout << p << "\t" << M[0] << "\t" << *M << endl;
	cout << p + 1 << "\t" << M[0] + 1 << "\t" << *M + 1 << endl;
	cout << *(p + 1) << "\t" << *(M[0] + 1) << "\t" << *(*M + 1) << endl;

	pt = &p; // pt = M; (X)
	cout << *pt << "\t" << p << endl;
	cout << **pt << "\t" << *p << endl;
	return 0;
}