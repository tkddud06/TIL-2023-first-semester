#include <iostream>
using namespace std;

class Container {
	int size;
public:
	Container() { size = 10; }
	void fill(int n) { size = n; }
	void consume(int n) { size -= n; }
	int getSize() { return size; }
};

class CoffeeVendingMachine {
	Container tong[3];
	void fill();
	void selectEspresso() { tong[0].consume(1); tong[1].consume(1); cout << "에스프레소입니다." << endl; }
	void selectAmericano() { tong[0].consume(1); tong[1].consume(2); cout << "아메리카노입니다." << endl; }
	void selectSugarCoffee() { tong[0].consume(1); tong[1].consume(2); tong[2].consume(1); cout << "설탕커피입니다" << endl; }
	void show() { cout << "커피 " << tong[0].getSize() << ", 물 " << tong[1].getSize() << ", 설탕 " << tong[2].getSize() << endl; }
public:
	void run();
};

void CoffeeVendingMachine::fill()
{
	for (int i = 0; i < 3; i++)
	{
		tong[i].fill(10);
	}
	show();
}

void CoffeeVendingMachine::run()
{
	cout << "***** 커피자판기를 작동합니다. *****";
	int num;
	while (1)
	{
		cout << "\n메뉴를 눌러주세요(1.에스프레소 2:아메리카노 3:설탕커피 4.잔량보기 5:채우기) >> ";
		cin >> num;
		switch (num)
		{
		case 1:
			selectEspresso();
			break;
		case 2:
			selectAmericano();
			break;
		case 3:
			selectSugarCoffee();
			break;
		case 4:
			show();
			break;
		case 5:
			fill();
			break;
		}
	}
}



int main()
{
	CoffeeVendingMachine obj;
	obj.run();

}