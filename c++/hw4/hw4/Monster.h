
#include "GameObject.h"

#ifndef MONSTER_H
#define MONSTER_H

class Monster : public GameObject { // GameObject를 상속
public:
	Monster() : GameObject(6,6,2) {} // 초기 위치와 이동거리 설정
	// 임의의 위치인 6,6 으로 지정될 것임
	// 이동 거리는 2로 지정할 것임


	~Monster() {}; // 소멸자
	virtual void move(); // 이동하여 새로운 위치로 x, y 변경
	virtual char getShape() { return 'M'; } // 객체 모양을 나타내는 문자 리턴(M)

};



#endif