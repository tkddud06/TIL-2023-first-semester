#include <iostream>
#include <string>
using namespace std;

int main()
{
	string a = "nice";
	char chr[100] = "hello";
	cin.getline(chr,100); // ���ڼ� �Է� �ʼ�. �ڿ� ���� ���� ���� ����. �ش� ���� ������ �ް�, �ش繮�ڴ� ���ۿ��� ����
	getline(cin,a); // �̶��� ���ڼ� �Է� XX. �ڿ� ���� ���� ������ ����.
	cout << a.front() << " " << a << endl; // front, back �ᵵ ����ų� ���� �ʴ´�.
	cout << chr << endl;
	return 0;
}

// https://rebro.kr/53 string ����
// length, size, append, insert, replace �� �پ��� �Լ� ����.