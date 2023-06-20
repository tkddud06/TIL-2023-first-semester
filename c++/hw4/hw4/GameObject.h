#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

class GameObject {
protected:
	int distance; // 한번에 이동 거리
	int x, y; // 현재 위치
public:
	GameObject(int startX, int startY, int distance) // 초기 위치와 이동거리 설정
	{
		this->x = startX; this->y = startY;
		this->distance = distance;
	}


	virtual ~GameObject() {}; // 가상 소멸자
	virtual void move() = 0; // 이동한 후 새로운 위치로 x, y 변경
	virtual char getShape() = 0; // 객체 모양을 나타내는 문자 리턴(H, M, @)



	int getX() { return x; }
	int getY() { return y; } // 위치값 리턴

	bool collide(GameObject* p); // 이 객체가 객체 p와 충돌했으면 true 리턴
};



#endif