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
	void selectEspresso() { tong[0].consume(1); tong[1].consume(1); cout << "�����������Դϴ�." << endl; }
	void selectAmericano() { tong[0].consume(1); tong[1].consume(2); cout << "�Ƹ޸�ī���Դϴ�." << endl; }
	void selectSugarCoffee() { tong[0].consume(1); tong[1].consume(2); tong[2].consume(1); cout << "����Ŀ���Դϴ�" << endl; }
	void show() { cout << "Ŀ�� " << tong[0].getSize() << ", �� " << tong[1].getSize() << ", ���� " << tong[2].getSize() << endl; }
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
	cout << "***** Ŀ�����Ǳ⸦ �۵��մϴ�. *****";
	int num;
	while (1)
	{
		cout << "\n�޴��� �����ּ���(1.���������� 2:�Ƹ޸�ī�� 3:����Ŀ�� 4.�ܷ����� 5:ä���) >> ";
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