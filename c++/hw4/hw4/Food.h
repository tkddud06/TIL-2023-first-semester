#include "GameObject.h"

#ifndef FOOD_H
#define FOOD_H

class Food : public GameObject { // GameObject�� ���
public:
	Food() : GameObject(10, 9, 1) {} // �ʱ� ��ġ�� �̵��Ÿ� ����
	// ������ ��ġ�� 10,9 ���� ������ ����
	// �̵� �Ÿ��� 1�� ������ ����


	~Food() {}; // �Ҹ���
	virtual void move(); // �̵��Ͽ� ���ο� ��ġ�� x, y ����
	virtual char getShape() { return '@'; } // ��ü ����� ��Ÿ���� ���� ����(@)

};



#endif