#include <iostream>
#include <map>
#include <string>
using namespace std;

int main()
{
	map<string, string> dic;

	dic.insert(make_pair("love", "사랑"));
	dic.insert(make_pair("apple", "사과"));
	dic["cherry"] = "체리";

	cout << "저장된 단어 개수" << dic.size() << endl;

	string eng;
	while (true)
	{
		cout << "찾고 싶은 단어>> ";
		cin >> eng;
		if (eng == "exit")
		{
			break;
		}
		if (dic.end() == dic.find(eng))
		{
			cout << "없음" << endl;
		}
		else
		{
			cout << dic[eng] << endl;
		}
	}
	cout << "종료합니다..." << endl;
	return 0;
}