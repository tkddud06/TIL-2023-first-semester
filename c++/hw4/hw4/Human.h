
#include "GameObject.h"

#ifndef HUMAN_H
#define HUMAN_H

class Human : public GameObject { // GameObject�� ���
private:
	char direction;
public:
	Human() : GameObject(0,0,1) {} // �ʱ� ��ġ�� �̵��Ÿ� ����
	// ������ ��ġ�� 0,0 ���� ������ ����
	// �̵� �Ÿ��� 1�� ������ ����

	~Human() {}; // �Ҹ���
	virtual void move(); // �̵��Ͽ� ���ο� ��ġ�� x, y ����
	virtual char getShape() { return 'H'; } // ��ü ����� ��Ÿ���� ���� ����(H)
	void inputdir();
};



#endif