#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>
using namespace std;


// 비주얼스튜디오 상에서, const char*이 아닌 char*로 자료형 지정시, 오류가 발생해서 const char*로 변경하였습니다.

class Book {
	char* title;
	int price;
public:
	Book(const char* title, int price);
	~Book();
	void set(const char* title, int price);
	void show() { cout << title << ' ' << price << "원" << endl; }
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


// + 교수님께서 말씀하신대로 그냥 공간에 넣는 방식으로만 코딩할 시, 
// 한글은 2바이트를 사용하기 때문에 '명품C++'을 사용하던 공간에서 '명품자바'로 set하면 오류가 발생하였습니다. (각각 strlen 사용시 7글자, 8글자로 판단)
// 그래서 공간이 부족한 경우에는, 공간 삭제후 다시 사이즈에 맞추어 공간을 만들어 set할수 있도록 구현하였습니다.

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
	// cout << strlen("명품자바") << " " << strlen("명품C++") << endl;
	Book cpp("명품C++", 10000);
	Book java = cpp;
	java.set("명품자바", 12000);
	cpp.show();
	java.show();

	return 0;
}