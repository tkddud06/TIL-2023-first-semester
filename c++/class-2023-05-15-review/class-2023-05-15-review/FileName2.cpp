#include <iostream>
#include <string>
#include <vector>
using namespace std;

class hi {
public:
	string name;
	vector<int> arr;
	hi(const string& n, vector<int> arr)
	{
		name = n;
		this->arr = arr;
	}
};

class test {
public:
	vector<vector<int>> arr;
	test(vector<vector<int>> arr)
	{
		this->arr = arr;
	}
};

class pointer {
public:
	int* point;
};

class Person {
public:
	string name;
	int id;
	Person(int id, const string& name)
	{
		cout << "person ������ �۵�" << endl;
		this->id = id;
		this->name = name;
	}
	Person(const Person& c)
	{
		this->id = c.id;
		this->name = c.name;
		cout << "person ���� ������ �۵�" << endl;
	}
};

Person g() {
	Person mother(2, "Mother");
	return mother;
}

int main()
{
	int p = 1;
	pointer pp;
	pp.point = &p;
	pointer pp2 = pp;
	cout << pp.point << " " << pp2.point << endl;
	*(pp.point) = 3;
	cout << *(pp.point) << " " << *(pp2.point) << endl;

	// �����ʹ�, ���� �Ҵ� �ƴϴ��� �ʰ� �����ϴ� ��� ������.

	hi a("HELLO", { 1,2,3,4,5 });
	hi b = a;

	a.name = "Nice";
	a.arr = { 4,5,6,7,8 };
	cout << b.name << endl;
	cout << b.arr[0] << endl;
	// Ư���ϰ� ���� ���縦 ���� �ʾƵ�, ���� ������ ���簡 �ȴ�.

	test z({ {1,2,3,4},{5,6,7,8} });

	test c = z;

	z.arr = { {9,9,9,9},{9,9,9} };
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			cout << c.arr[i][j] << " ";
		}
		cout << endl;
	}
	// ����������, Ư���ϰ� ���� ���縦 ���� �ʾƵ�, ���� ������ ���簡 �ȴ�.

	Person m = g();
	cout << m.id << m.name << endl;


	return 0;
}