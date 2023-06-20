
#include "GameObject.h"

#ifndef MONSTER_H
#define MONSTER_H

class Monster : public GameObject { // GameObject�� ���
public:
	Monster() : GameObject(6,6,2) {} // �ʱ� ��ġ�� �̵��Ÿ� ����
	// ������ ��ġ�� 6,6 ���� ������ ����
	// �̵� �Ÿ��� 2�� ������ ����


	~Monster() {}; // �Ҹ���
	virtual void move(); // �̵��Ͽ� ���ο� ��ġ�� x, y ����
	virtual char getShape() { return 'M'; } // ��ü ����� ��Ÿ���� ���� ����(M)

};



#endif