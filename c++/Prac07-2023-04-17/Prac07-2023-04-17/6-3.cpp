#include <iostream>
#include <string>
using namespace std;

class Board {
private:
	static int count;
	static string message;
public:
	static void add(const char* s)
	{
		message += (char)(count + 48);
		message += ". ";
		message += s;
		message += '\n';
		count += 1;
	}

	static void print()
	{
		cout << "************ �Խ��� ************" << endl;
		cout << message << endl;
	}
};

int Board::count = 0;
string Board::message = "";

int main()
{
	Board::add("�����ִ� �߰���簡 �ֽ��ϴ�.");
	Board::add("�ڵ����̾ ���� �̿��� �ּ���.");
	Board::print();
	Board::add("ȫ�浿 �л��� ������ȸ�� �Ի��Ͽ����ϴ�.");
	Board::print();

	return 0;
}