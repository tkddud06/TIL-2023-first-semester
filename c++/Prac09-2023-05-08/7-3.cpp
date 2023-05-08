#include <iostream>
#include <string>
using namespace std;
class Person {
	string name;
public:
	Person() { name = ""; }
	Person(string name) { this->name = name; }
	string getName() { return name; }
	void setName(string name) { this->name = name; }
};

class Family {
	string name;
	Person* p;
	int size;
public:
	Family(string name, int size);
	void setName(int index, string name);
	void show();
	~Family();
};

Family::Family(string name, int size)
{
	this->name = name;
	p = new Person[size];
	this->size = size;
}

void Family::setName(int index, string name)
{
	p[index].setName(name);
}

void Family::show()
{
	cout << name << " 가족은 다음과 같이 " << size << "명입니다." << endl;
	for (int i = 0; i < size; i++)
	{
		cout << p[i].getName() << "	";
	}
}

Family::~Family()
{
	delete[] p;
}

int main()
{
	Family* simpson = new Family("Simpson", 3);
	simpson->setName(0, "Mr. Simpson");
	simpson->setName(1, "Mrs. Simpson");
	simpson->setName(2, "Bart Simpson");
	simpson->show();
	delete simpson;
	return 0;
}