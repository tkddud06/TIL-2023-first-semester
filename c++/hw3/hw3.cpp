#include <iostream>
#include <string>
using namespace std;

class Seat { // 시트 클래스
	string name;
public:
	Seat() { name = ""; } // 디폴트 생성자. name을 빈 공간으로 지정
	bool can_resv() { if (name == "") return true; else return false; } // 예약이 이미 있는지, 없는지를 판단하는 함수. 이름이 비었다면 true, 아니라면(다른 것이 들어가있다면) false 리턴
	string get_name() { return name; } // 이름을 리턴해주는 함수
	void set_name(string s) { this->name = s; } // 이름을 변경하는 함수.
};

class Schedule { // 스케줄 클래스
	Seat seat_list[8]; // 8개의 시트를 나타낼 시트리스트 생성
public:
	void show(); // 좌석들의 상태를 보여줄 show 함수
	void set_reserve(int n, string s); // 예약을 설정하는 함수
	void set_cancle(int n, string s); // 예약을 취소하는 함수
};

class AirlineBook { // 에어라인북 클래스
	Schedule schedule_list[3]; // 3개의 스케줄을 나타낼 스케줄리스트 생성
public:
	void reserve(); // 예약 함수
	void cancle(); // 취소 함수
	void show(); // 스케줄들의 상태를 보여줄 show 함수
};

void AirlineBook::reserve()
{
	int time; // 시간을 입력받을 time 변수 선언
	cout << "07시 1, 12시 2, 17시 3 >> ";
	cin >> time; // 시간을 입력받음
	if (cin.fail() == 1) // 숫자를 받기로 한 cin에 예상치 못한 데이터가 입력되었을 때
	{
		cout << "잘못 입력하셨습니다. 1~3 사이의 숫자만 입력 가능합니다. 처음부터 다시 진행합니다." << endl;
		cin.clear(); // 오류 플래그를 지우고
		cin.ignore(1000, '\n'); // 버퍼를 지운다
		return;
	}
	switch (time) // 입력받은 번호에 따라 시간 구분
	{
	case 1:
		cout << "07시 : ";
		break;
	case 2:
		cout << "12시 : ";
		break;
	case 3:
		cout << "17시 : ";
		break;
	default: // 1~3 사이의 숫자가 아닌 다른 숫자가 입력되었을 때
		cout << "숫자를 잘못 입력하셨습니다. 1~3 사이의 숫자를 입력해주세요. 처음부터 다시 진행합니다." << endl;
		return;
	}
	
	schedule_list[time-1].show(); // 해당 시간의 스케줄 보여주기 (time은 1~3을 받지만, 실제 인덱스는 0~2이므로 -1 해줌)

	int seat_num;
	string reserv_name;

	cout << "좌석번호 >> ";
	cin >> seat_num; // 좌석번호를 입력받는다
	if (cin.fail() == 1) // 숫자를 받기로 한 cin에 예상치 못한 데이터가 입력되었을 때
	{
		cout << "잘못 입력하셨습니다. 좌석 번호는 1~8번만 존재합니다. 1~8 사이의 숫자를 입력해주세요. 처음부터 다시 진행합니다." << endl;
		cin.clear(); // 오류 플래그를 지우고
		cin.ignore(1000, '\n'); // 버퍼를 지운다
		return;
	}
	if (seat_num <= 0 || seat_num >= 9) // 숫자를 받긴 했지만, 1~8 사이의 올바른 좌석 번호를 입력하지 않았을 때
	{
		cout << "숫자를 잘못 입력하셨습니다. 좌석 번호는 1~8번만 존재합니다. 1~8 사이의 숫자를 입력해주세요. 처음부터 다시 진행합니다." << endl;
		return;
	}
	cout << "이름 >> ";
	cin.ignore(); // getline에서 버퍼의 '\n'을 받지 않도록, '\n'을 버퍼에서 제거
	getline(cin, reserv_name); // 이름 입력받음

	schedule_list[time-1].set_reserve(seat_num-1, reserv_name); // 스케줄 클래스의 예약 메소드로 연결 (time은 1~3, seat_num은 1~8을 받지만, 실제 인덱스는 0~2, 0~7이므로 둘다 -1을 해줌)

}
void AirlineBook::cancle()
{
	int time; // 시간을 입력받을 time 변수 선언
	cout << "07시 1, 12시 2, 17시 3 >> ";
	cin >> time; // 시간을 입력받음
	if (cin.fail() == 1) // 숫자를 받기로 한 cin에 예상치 못한 데이터가 입력되었을 때
	{
		cout << "잘못 입력하셨습니다. 1~3 사이의 숫자만 입력 가능합니다. 처음부터 다시 진행합니다." << endl;
		cin.clear(); // 오류 플래그를 지우고
		cin.ignore(1000, '\n'); // 버퍼를 지운다
		return;
	}
	switch (time) // 입력받은 번호에 따라 시간 구분
	{
	case 1:
		cout << "07시 : ";
		break;
	case 2:
		cout << "12시 : ";
		break;
	case 3:
		cout << "17시 : ";
		break;
	default: // 1~3 사이의 숫자가 아닌 다른 숫자가 입력되었을 때
		cout << "숫자를 잘못 입력하셨습니다. 1~3 사이의 숫자를 입력해주세요. 처음부터 다시 진행합니다." << endl;
		return;
	}

	schedule_list[time-1].show(); // 해당 시간의 스케줄 보여주기 (time은 1~3을 받지만, 실제 인덱스는 0~2이므로 -1 해줌)

	int seat_num;
	string reserv_name;

	cout << "좌석번호 >> ";
	cin >> seat_num; // 좌석번호를 입력받는다
	if (cin.fail() == 1) // 숫자를 받기로 한 cin에 예상치 못한 데이터가 입력되었을 때
	{
		cout << "잘못 입력하셨습니다. 좌석 번호는 1~8번만 존재합니다. 1~8 사이의 숫자를 입력해주세요. 처음부터 다시 진행합니다." << endl;
		cin.clear(); // 오류 플래그를 지우고
		cin.ignore(1000, '\n'); // 버퍼를 지운다
		return;
	}
	if (seat_num <= 0 || seat_num >= 9) // 숫자를 받긴 했지만, 1~8 사이의 올바른 좌석 번호를 입력하지 않았을 때
	{
		cout << "숫자를 잘못 입력하셨습니다. 좌석 번호는 1~8번만 존재합니다. 1~8 사이의 숫자를 입력해주세요. 처음부터 다시 진행합니다." << endl;
		return;
	}
	cout << "이름 >> ";
	cin.ignore(); // getline에서 버퍼의 '\n'을 받지 않도록, '\n'을 버퍼에서 제거
	getline(cin, reserv_name); // 이름 입력받음
	schedule_list[time-1].set_cancle(seat_num-1, reserv_name); // 스케줄 클래스의 예약 취소 메소드로 연결 (time은 1~3, seat_num은 1~8을 받지만, 실제 인덱스는 0~2, 0~7이므로 둘다 -1을 해줌)

}
void AirlineBook::show()
{
	for (int i = 0; i < 3; i++) // 모든 스케줄 출력
	{
		switch (i) // i에 따라, 앞의 시간 표시 달라짐
		{
		case 0:
			cout << "07시 : ";
			break;
		case 1:
			cout << "12시 : ";
			break;
		case 2:
			cout << "17시 : ";
			break;
		}
		schedule_list[i].show(); // 스케줄 클래스의 show 메소드를 불러와 각 스케줄을 출력함
	}
}

void Schedule::show()
{
	for (int i = 0; i < 8; i++)
	{
		string temp_name = seat_list[i].get_name(); // 각 시트 클래스로부터, 이름 정보 가져옴
		if (temp_name == "") // 예약자가 없다면 (can_resv 메소드를 사용해도 됨)
		{
			cout << "----- "; // ----- 출력
		}
		else
		{
			cout << temp_name << " "; // 예약자가 있다면 해당 이름 출력
		}
	}
	cout << endl;
}
void Schedule::set_reserve(int n, string s)
{
	if (seat_list[n].can_resv() == false) // 입력받은 좌석 번호에 예약자가 이미 있다면
	{
		cout << "이미 예약된 좌석입니다." << endl;
	}
	else // 예약이 가능하다면
	{
		seat_list[n].set_name(s); // 입력받은 좌석 번호에 이름을 넣는 메소드로 연결
	}
}

void Schedule::set_cancle(int n, string s)
{
	if (seat_list[n].can_resv() == true) // 입력받은 좌석 번호에 예약이 존재하지 않는 경우
	{
		cout << "입력하신 예약은 존재하지 않습니다." << endl;
	}
	else if (seat_list[n].get_name() != s) // 입력받은 이름과 좌석의 예약 이름이 다른 경우
	{
		cout << "입력하신 이름과 예약된 이름이 다릅니다." << endl;
	}
	else
	{
		seat_list[n].set_name(""); // 예약자 정보를 정확하게 입력받은 경우
	}
}

int main()
{
	cout << "*** 한성항공에 오신 것을 환영합니다. ***" << endl;
	AirlineBook hansung;
	int c;
	while (1) // 4를 입력받을 때까지 무한 반복하며 메뉴를 출력
	{
		cout << "\n예약 1, 취소 2, 보기 3, 끝내기 4 >> ";
		cin >> c;
		if (cin.fail() == 1) // 숫자를 받기로 한 cin에 예상치 못한 데이터가 입력되었을 때
		{
			cout << "잘못 입력하셨습니다. 1~4 사이의 숫자만 입력 가능합니다. 처음부터 다시 진행합니다." << endl;
			cin.clear(); // 오류 플래그를 지우고
			cin.ignore(1000, '\n'); // 버퍼를 지운다
			continue;
		}
		switch (c) // c의 입력값에 따라 에어라인북 클래스의 각 메소드로 연결
		{
		case 1:
			hansung.reserve();
			break;
		case 2:
			hansung.cancle();
			break;
		case 3:
			hansung.show();
			break;
		case 4:
			cout << "예약 시스템을 종료합니다." << endl;
			break;
		default: // 1~4 외의 다른 숫자를 입력받았을 때
			cout << "숫자를 잘못 입력하셨습니다. 1~4 사이의 숫자만 입력 가능합니다. 처음부터 다시 진행합니다." << endl;
		}
		if (c == 4) // 4를 입력받으면 종료
		{
			break;
		}
	}
	return 0;
}