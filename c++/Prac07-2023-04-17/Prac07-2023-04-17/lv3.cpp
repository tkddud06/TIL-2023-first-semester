#include <iostream>
#include <string>
using namespace std;

class Account
{
private:
	string name;
	string address;
	int money;
public:
	Account(const string s, string add, int m)
	{
		name = s;
		add = address;
		money = m;
	}
	void deposit(int m);
	int withdraw(int m);
	string getOwner() { return name; }
	int inquiry() { return money; }
};

void Account::deposit(int m)
{
	money += m;
}

int Account::withdraw(int m)
{
	int r = money - m;
	money -= m;
	return r;
}


int main()
{
	Account a("È«±æµ¿", "11-111", 50000);
	a.deposit(500000);
	cout << a.getOwner() << "ÀÇ ÀÜ¾×Àº " << a.inquiry() << endl;
	int money = a.withdraw(200000);
	cout << a.getOwner() << "ÀÇ ÀÜ¾×Àº " << a.inquiry() << endl;


	return 0;
}