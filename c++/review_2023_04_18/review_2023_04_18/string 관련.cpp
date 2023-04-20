#include <iostream>
#include <string>
using namespace std;

int main()
{
	string a = "nice";
	char chr[100] = "hello";
	cin.getline(chr,100); // 문자수 입력 필수. 뒤에 끊을 문자 지정 가능. 해당 문자 전까지 받고, 해당문자는 버퍼에서 삭제
	getline(cin,a); // 이때는 문자수 입력 XX. 뒤에 끊을 문자 지정은 가능.
	cout << a.front() << " " << a << endl; // front, back 써도 지우거나 하진 않는다.
	cout << chr << endl;
	return 0;
}

// https://rebro.kr/53 string 정리
// length, size, append, insert, replace 등 다양한 함수 설명.