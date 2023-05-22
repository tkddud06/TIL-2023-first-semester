#include <iostream>
#include <string>
using namespace std;

class Seat {
	string name;
public:
	Seat() { name = '\0'; }
	bool can_resv() { if (name == "\0") return true; else return false; }
	string get_name() { return name; }
	void set_name(string s) { this->name = s; }
};

class Schedule {
	Seat seat_list[8];
public:
	void show();
	void set_reserve(int n, string s);
	void set_cancle(int n);
};

class AirlineBook {
	Schedule schedule_list[3];
public:
	void reserve();
	void cancle();
	void show();
};

void Schedule::show()
{
	for (int i = 0; i < 8; i++)
	{
		string temp_name = seat_list[i].get_name();
		if (temp_name == "\0")
		{
			cout << "----- ";
		}
		else
		{
			cout << temp_name << " ";
		}
	}
	cout << endl;
}
void Schedule::set_reserve(int n, string s)
{
	if (seat_list[n].can_resv() == false)
	{
		cout << "이미 예약된 좌석입니다." << endl;
	}
	else
	{
		seat_list[n].set_name(s);
	}
}

void Schedule::set_cancle(int n);

int main()
{

	return 0;
}