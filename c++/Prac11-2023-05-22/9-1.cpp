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
		cout << title << ' ' << price << "원 " << pages << "페이지" << endl;
	}
	Book operator+=(int num);
	friend Book operator-=(Book& a, int num);
};

Book Book::operator+=(int num)
{
	this->price += num;
	return *this;
}

Book operator-=(Book& a, int num)
{
	a.price -= num;
	return a;
}

int main()
{
	Book a("청춘", 20000, 300), b("미래", 30000, 500);
	a += 500;
	b -= 500;
	a.show();
	b.show();

	return 0;
}