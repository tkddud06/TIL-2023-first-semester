#include "GameObject.h"

#ifndef FOOD_H
#define FOOD_H

class Food : public GameObject { // GameObject를 상속
public:
	Food() : GameObject(10, 9, 1) {} // 초기 위치와 이동거리 설정
	// 임의의 위치인 10,9 으로 지정될 것임
	// 이동 거리는 1로 지정할 것임


	~Food() {}; // 소멸자
	virtual void move(); // 이동하여 새로운 위치로 x, y 변경
	virtual char getShape() { return '@'; } // 객체 모양을 나타내는 문자 리턴(@)

};



#endif