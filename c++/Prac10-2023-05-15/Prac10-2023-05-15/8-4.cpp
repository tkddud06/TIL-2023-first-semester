#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>
using namespace std;


// ���־�Ʃ��� �󿡼�, const char*�� �ƴ� char*�� �ڷ��� ������, ������ �߻��ؼ� const char*�� �����Ͽ����ϴ�.

class Book {
	char* title;
	int price;
public:
	Book(const char* title, int price);
	~Book();
	void set(const char* title, int price);
	void show() { cout << title << ' ' << price << "��" << endl; }
	Book(const Book& c);
};

Book::Book(const char* title, int price)
{
	int len = strlen(title);
	this->title = new char[len + 1];
	strcpy(this->title, title);
	this->price = price;
}

Book::~Book()
{
	delete[] title;
}


// + �����Բ��� �����ϽŴ�� �׳� ������ �ִ� ������θ� �ڵ��� ��, 
// �ѱ��� 2����Ʈ�� ����ϱ� ������ '��ǰC++'�� ����ϴ� �������� '��ǰ�ڹ�'�� set�ϸ� ������ �߻��Ͽ����ϴ�. (���� strlen ���� 7����, 8���ڷ� �Ǵ�)
// �׷��� ������ ������ ��쿡��, ���� ������ �ٽ� ����� ���߾� ������ ����� set�Ҽ� �ֵ��� �����Ͽ����ϴ�.

void Book::set(const char* title, int price)
{
	
	if (strlen(title) > strlen(this->title))
	{
		delete[] this->title;
		int len = strlen(title);
		this->title = new char[len + 1];
		strcpy(this->title, title);
	}
	else
	{
		strcpy(this->title, title);
	}

	this->price = price;
}

Book::Book(const Book& c)
{
	this->price = c.price;
	int len = strlen(c.title);
	this->title = new char[len + 1];
	strcpy(this->title, c.title);
}

int main()
{
	// cout << strlen("��ǰ�ڹ�") << " " << strlen("��ǰC++") << endl;
	Book cpp("��ǰC++", 10000);
	Book java = cpp;
	java.set("��ǰ�ڹ�", 12000);
	cpp.show();
	java.show();

	return 0;
}