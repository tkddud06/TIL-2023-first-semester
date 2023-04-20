#include <iostream>
#include <vector>
using namespace std;

int main()
{
	vector<int> a = { 1,2,3,4,5 };
	cout << "capacity : " << a.capacity() << endl;
	a.push_back(6);
	for (int i = 0; i < a.size(); i++)
	{
		cout << a[i] << endl;
	}
	cout << "capacity : " << a.capacity() << endl;
	a.push_back(7);
	cout << "capacity : " << a.capacity() << endl;
	a.push_back(8);
	cout << "capacity : " << a.capacity() << endl;
	a.pop_back();
	a.pop_back();
	a.pop_back();
	a.pop_back();
	cout << "capacity : " << a.capacity() << endl;
	cout << a.back() << endl;
	//a[7] = 9;
	//cout << a[7]; // capacity는 충분해도, 데이터를 지운 공간에 임의로 뭔가 대입하면, 에러 발생

	a[1] = 10;
	cout << a[1]; // 이미 데이터가 할당된 공간은 무관.
	return 0;
}

// https://rebro.kr/37
// 벡터 관련 정리. 참고.

// c++ 수업때 배웠는진 잘 모르겠는데, 이터레이터와
// 그리고 2차원 벡터에 대해서 추가 공부좀 하자.