#include <iostream>
#include <string>
using namespace std;

int main()
{
	string name, address;
	int age;
	cout << "�̸���? ";
	getline(cin, name);
	cout << "�ּҴ�? ";
	getline(cin, address);
	cout << "���̴�? ";
	cin >> age;
	cout << name << ". " << address << ". " << age << "��" << endl;
	return 0;
}