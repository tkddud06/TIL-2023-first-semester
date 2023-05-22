#include <iostream>
#include <string>
using namespace std;

class Seat { // ��Ʈ Ŭ����
	string name;
public:
	Seat() { name = ""; } // ����Ʈ ������. name�� �� �������� ����
	bool can_resv() { if (name == "") return true; else return false; } // ������ �̹� �ִ���, �������� �Ǵ��ϴ� �Լ�. �̸��� ����ٸ� true, �ƴ϶��(�ٸ� ���� ���ִٸ�) false ����
	string get_name() { return name; } // �̸��� �������ִ� �Լ�
	void set_name(string s) { this->name = s; } // �̸��� �����ϴ� �Լ�.
};

class Schedule { // ������ Ŭ����
	Seat seat_list[8]; // 8���� ��Ʈ�� ��Ÿ�� ��Ʈ����Ʈ ����
public:
	void show(); // �¼����� ���¸� ������ show �Լ�
	void set_reserve(int n, string s); // ������ �����ϴ� �Լ�
	void set_cancle(int n, string s); // ������ ����ϴ� �Լ�
};

class AirlineBook { // ������κ� Ŭ����
	Schedule schedule_list[3]; // 3���� �������� ��Ÿ�� �����ٸ���Ʈ ����
public:
	void reserve(); // ���� �Լ�
	void cancle(); // ��� �Լ�
	void show(); // �����ٵ��� ���¸� ������ show �Լ�
};

void AirlineBook::reserve()
{
	int time; // �ð��� �Է¹��� time ���� ����
	cout << "07�� 1, 12�� 2, 17�� 3 >> ";
	cin >> time; // �ð��� �Է¹���
	if (cin.fail() == 1) // ���ڸ� �ޱ�� �� cin�� ����ġ ���� �����Ͱ� �ԷµǾ��� ��
	{
		cout << "�߸� �Է��ϼ̽��ϴ�. 1~3 ������ ���ڸ� �Է� �����մϴ�. ó������ �ٽ� �����մϴ�." << endl;
		cin.clear(); // ���� �÷��׸� �����
		cin.ignore(1000, '\n'); // ���۸� �����
		return;
	}
	switch (time) // �Է¹��� ��ȣ�� ���� �ð� ����
	{
	case 1:
		cout << "07�� : ";
		break;
	case 2:
		cout << "12�� : ";
		break;
	case 3:
		cout << "17�� : ";
		break;
	default: // 1~3 ������ ���ڰ� �ƴ� �ٸ� ���ڰ� �ԷµǾ��� ��
		cout << "���ڸ� �߸� �Է��ϼ̽��ϴ�. 1~3 ������ ���ڸ� �Է����ּ���. ó������ �ٽ� �����մϴ�." << endl;
		return;
	}
	
	schedule_list[time-1].show(); // �ش� �ð��� ������ �����ֱ� (time�� 1~3�� ������, ���� �ε����� 0~2�̹Ƿ� -1 ����)

	int seat_num;
	string reserv_name;

	cout << "�¼���ȣ >> ";
	cin >> seat_num; // �¼���ȣ�� �Է¹޴´�
	if (cin.fail() == 1) // ���ڸ� �ޱ�� �� cin�� ����ġ ���� �����Ͱ� �ԷµǾ��� ��
	{
		cout << "�߸� �Է��ϼ̽��ϴ�. �¼� ��ȣ�� 1~8���� �����մϴ�. 1~8 ������ ���ڸ� �Է����ּ���. ó������ �ٽ� �����մϴ�." << endl;
		cin.clear(); // ���� �÷��׸� �����
		cin.ignore(1000, '\n'); // ���۸� �����
		return;
	}
	if (seat_num <= 0 || seat_num >= 9) // ���ڸ� �ޱ� ������, 1~8 ������ �ùٸ� �¼� ��ȣ�� �Է����� �ʾ��� ��
	{
		cout << "���ڸ� �߸� �Է��ϼ̽��ϴ�. �¼� ��ȣ�� 1~8���� �����մϴ�. 1~8 ������ ���ڸ� �Է����ּ���. ó������ �ٽ� �����մϴ�." << endl;
		return;
	}
	cout << "�̸� >> ";
	cin.ignore(); // getline���� ������ '\n'�� ���� �ʵ���, '\n'�� ���ۿ��� ����
	getline(cin, reserv_name); // �̸� �Է¹���

	schedule_list[time-1].set_reserve(seat_num-1, reserv_name); // ������ Ŭ������ ���� �޼ҵ�� ���� (time�� 1~3, seat_num�� 1~8�� ������, ���� �ε����� 0~2, 0~7�̹Ƿ� �Ѵ� -1�� ����)

}
void AirlineBook::cancle()
{
	int time; // �ð��� �Է¹��� time ���� ����
	cout << "07�� 1, 12�� 2, 17�� 3 >> ";
	cin >> time; // �ð��� �Է¹���
	if (cin.fail() == 1) // ���ڸ� �ޱ�� �� cin�� ����ġ ���� �����Ͱ� �ԷµǾ��� ��
	{
		cout << "�߸� �Է��ϼ̽��ϴ�. 1~3 ������ ���ڸ� �Է� �����մϴ�. ó������ �ٽ� �����մϴ�." << endl;
		cin.clear(); // ���� �÷��׸� �����
		cin.ignore(1000, '\n'); // ���۸� �����
		return;
	}
	switch (time) // �Է¹��� ��ȣ�� ���� �ð� ����
	{
	case 1:
		cout << "07�� : ";
		break;
	case 2:
		cout << "12�� : ";
		break;
	case 3:
		cout << "17�� : ";
		break;
	default: // 1~3 ������ ���ڰ� �ƴ� �ٸ� ���ڰ� �ԷµǾ��� ��
		cout << "���ڸ� �߸� �Է��ϼ̽��ϴ�. 1~3 ������ ���ڸ� �Է����ּ���. ó������ �ٽ� �����մϴ�." << endl;
		return;
	}

	schedule_list[time-1].show(); // �ش� �ð��� ������ �����ֱ� (time�� 1~3�� ������, ���� �ε����� 0~2�̹Ƿ� -1 ����)

	int seat_num;
	string reserv_name;

	cout << "�¼���ȣ >> ";
	cin >> seat_num; // �¼���ȣ�� �Է¹޴´�
	if (cin.fail() == 1) // ���ڸ� �ޱ�� �� cin�� ����ġ ���� �����Ͱ� �ԷµǾ��� ��
	{
		cout << "�߸� �Է��ϼ̽��ϴ�. �¼� ��ȣ�� 1~8���� �����մϴ�. 1~8 ������ ���ڸ� �Է����ּ���. ó������ �ٽ� �����մϴ�." << endl;
		cin.clear(); // ���� �÷��׸� �����
		cin.ignore(1000, '\n'); // ���۸� �����
		return;
	}
	if (seat_num <= 0 || seat_num >= 9) // ���ڸ� �ޱ� ������, 1~8 ������ �ùٸ� �¼� ��ȣ�� �Է����� �ʾ��� ��
	{
		cout << "���ڸ� �߸� �Է��ϼ̽��ϴ�. �¼� ��ȣ�� 1~8���� �����մϴ�. 1~8 ������ ���ڸ� �Է����ּ���. ó������ �ٽ� �����մϴ�." << endl;
		return;
	}
	cout << "�̸� >> ";
	cin.ignore(); // getline���� ������ '\n'�� ���� �ʵ���, '\n'�� ���ۿ��� ����
	getline(cin, reserv_name); // �̸� �Է¹���
	schedule_list[time-1].set_cancle(seat_num-1, reserv_name); // ������ Ŭ������ ���� ��� �޼ҵ�� ���� (time�� 1~3, seat_num�� 1~8�� ������, ���� �ε����� 0~2, 0~7�̹Ƿ� �Ѵ� -1�� ����)

}
void AirlineBook::show()
{
	for (int i = 0; i < 3; i++) // ��� ������ ���
	{
		switch (i) // i�� ����, ���� �ð� ǥ�� �޶���
		{
		case 0:
			cout << "07�� : ";
			break;
		case 1:
			cout << "12�� : ";
			break;
		case 2:
			cout << "17�� : ";
			break;
		}
		schedule_list[i].show(); // ������ Ŭ������ show �޼ҵ带 �ҷ��� �� �������� �����
	}
}

void Schedule::show()
{
	for (int i = 0; i < 8; i++)
	{
		string temp_name = seat_list[i].get_name(); // �� ��Ʈ Ŭ�����κ���, �̸� ���� ������
		if (temp_name == "") // �����ڰ� ���ٸ� (can_resv �޼ҵ带 ����ص� ��)
		{
			cout << "----- "; // ----- ���
		}
		else
		{
			cout << temp_name << " "; // �����ڰ� �ִٸ� �ش� �̸� ���
		}
	}
	cout << endl;
}
void Schedule::set_reserve(int n, string s)
{
	if (seat_list[n].can_resv() == false) // �Է¹��� �¼� ��ȣ�� �����ڰ� �̹� �ִٸ�
	{
		cout << "�̹� ����� �¼��Դϴ�." << endl;
	}
	else // ������ �����ϴٸ�
	{
		seat_list[n].set_name(s); // �Է¹��� �¼� ��ȣ�� �̸��� �ִ� �޼ҵ�� ����
	}
}

void Schedule::set_cancle(int n, string s)
{
	if (seat_list[n].can_resv() == true) // �Է¹��� �¼� ��ȣ�� ������ �������� �ʴ� ���
	{
		cout << "�Է��Ͻ� ������ �������� �ʽ��ϴ�." << endl;
	}
	else if (seat_list[n].get_name() != s) // �Է¹��� �̸��� �¼��� ���� �̸��� �ٸ� ���
	{
		cout << "�Է��Ͻ� �̸��� ����� �̸��� �ٸ��ϴ�." << endl;
	}
	else
	{
		seat_list[n].set_name(""); // ������ ������ ��Ȯ�ϰ� �Է¹��� ���
	}
}

int main()
{
	cout << "*** �Ѽ��װ��� ���� ���� ȯ���մϴ�. ***" << endl;
	AirlineBook hansung;
	int c;
	while (1) // 4�� �Է¹��� ������ ���� �ݺ��ϸ� �޴��� ���
	{
		cout << "\n���� 1, ��� 2, ���� 3, ������ 4 >> ";
		cin >> c;
		if (cin.fail() == 1) // ���ڸ� �ޱ�� �� cin�� ����ġ ���� �����Ͱ� �ԷµǾ��� ��
		{
			cout << "�߸� �Է��ϼ̽��ϴ�. 1~4 ������ ���ڸ� �Է� �����մϴ�. ó������ �ٽ� �����մϴ�." << endl;
			cin.clear(); // ���� �÷��׸� �����
			cin.ignore(1000, '\n'); // ���۸� �����
			continue;
		}
		switch (c) // c�� �Է°��� ���� ������κ� Ŭ������ �� �޼ҵ�� ����
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
			cout << "���� �ý����� �����մϴ�." << endl;
			break;
		default: // 1~4 ���� �ٸ� ���ڸ� �Է¹޾��� ��
			cout << "���ڸ� �߸� �Է��ϼ̽��ϴ�. 1~4 ������ ���ڸ� �Է� �����մϴ�. ó������ �ٽ� �����մϴ�." << endl;
		}
		if (c == 4) // 4�� �Է¹����� ����
		{
			break;
		}
	}
	return 0;
}