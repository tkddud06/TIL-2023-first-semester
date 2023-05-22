#include <iostream>
using namespace std;

class BaseArray {
private:
	int capacity;
	int* mem;
protected:
	BaseArray(int capacity = 100) { this->capacity = capacity; mem = new int[capacity]; }
	~BaseArray() { delete[] mem; }
	void put(int index, int val) { mem[index] = val; }
	int get(int index) { return mem[index]; }
	int getCapacity() { return capacity; }
};

class MyQueue : public BaseArray {
private:
	int head;
	int tail;
public:
	MyQueue(int capacity) : BaseArray(capacity) { head = 0; tail = 0; }
	int capacity() { return getCapacity(); }
	int length() { return tail - head; }
	void enqueue(int n);
	int dequeue();
};

void MyQueue::enqueue(int n)
{
	put(tail, n);
	tail++;
}
int MyQueue::dequeue()
{
	int temp = get(head);
	head++;
	return temp;
}

int main()
{
	MyQueue mQ(100);
	int n;

	cout << "ť�� ������ 5���� ������ �Է��϶�>> ";
	for (int i = 0; i < 5; i++)
	{
		cin >> n;
		mQ.enqueue(n);
	}

	cout << "ť�� �뷮 : " << mQ.capacity() << ", ť�� ũ�� : " << mQ.length() << endl;

	cout << "ť�� ���Ҹ� ������� �����Ͽ� ����Ѵ�>> ";
	while (mQ.length() != 0)
	{
		cout << mQ.dequeue() << ' ';
	}

	cout << endl << "ť�� ���� ũ�� : " << mQ.length() << endl;

	return 0;
}