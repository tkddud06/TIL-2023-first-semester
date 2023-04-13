#include <iostream>
using namespace std;

class MyVector {
	int* mem;
	int size;
public:
	MyVector(int n = 100, int val = 0);
	~MyVector() { delete[] mem; };

	int* get_mem() { return mem; };

};

MyVector::MyVector(int n, int val)
{
	mem = new int[n];
	size = n;
	for (int i = 0; i < size; i++)
	{
		mem[i] = val;
	}
}

int main()
{
	MyVector obj;
	MyVector obj2(30, 1);

	cout << obj.get_mem()[3] << endl;
	cout << obj2.get_mem()[3] << endl;

	return 0;
}