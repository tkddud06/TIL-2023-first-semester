#include <iostream>
#include <string>
using namespace std;

class Book {
	string title;
	int price, pages;
public:
	Book(string title = "", int price = 0, int pages = 0)
	{
		this->title = title; this->price = price; this->pages = pages;
	}
	void show()
	{
		cout << title << ' ' << price << "�� " << pages << "������" << endl;
	}
	bool operator==(Book b);
	bool operator==(int num);
	bool operator==(string s);
};

bool Book::operator==(Book b)
{
	if (this->pages == b.pages && this->price == b.price && this->title == b.title)
	{
		return true;
	}
	else
	{
		return false;
	}
}
bool Book::operator==(int num)
{
	if (this->price == num)
	{
		return true;
	}
	else
	{
		return false;
	}
}
bool Book::operator==(string s)
{
	if (this->title == s)
	{
		return true;
	}
	else
	{
		return false;
	}
}

int main()
{
	Book a("C++", 30000, 500), b("���̽�", 30000, 500);
	if (a == 30000) cout << "���� 30000��" << endl;
	if (a == "C++") cout << "C++" << endl;
	if (a == b) cout << "�� å�� ���� å�Դϴ�." << endl;
	return 0;
}