#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

class GameObject {
protected:
	int distance; // �ѹ��� �̵� �Ÿ�
	int x, y; // ���� ��ġ
public:
	GameObject(int startX, int startY, int distance) // �ʱ� ��ġ�� �̵��Ÿ� ����
	{
		this->x = startX; this->y = startY;
		this->distance = distance;
	}


	virtual ~GameObject() {}; // ���� �Ҹ���
	virtual void move() = 0; // �̵��� �� ���ο� ��ġ�� x, y ����
	virtual char getShape() = 0; // ��ü ����� ��Ÿ���� ���� ����(H, M, @)



	int getX() { return x; }
	int getY() { return y; } // ��ġ�� ����

	bool collide(GameObject* p); // �� ��ü�� ��ü p�� �浹������ true ����
};



#endif