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
		cout << "************ 게시판 ************" << endl;
		cout << message << endl;
	}
};

int Board::count = 0;
string Board::message = "";

int main()
{
	Board::add("다음주는 중간고사가 있습니다.");
	Board::add("코딩다이어리 많이 이용해 주세요.");
	Board::print();
	Board::add("홍길동 학생이 경진대회에 입상하였습니다.");
	Board::print();

	return 0;
}