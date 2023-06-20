
#include "GameObject.h"

#ifndef HUMAN_H
#define HUMAN_H

class Human : public GameObject { // GameObject를 상속
private:
	char direction;
public:
	Human() : GameObject(0,0,1) {} // 초기 위치와 이동거리 설정
	// 임의의 위치인 0,0 으로 지정될 것임
	// 이동 거리는 1로 지정할 것임

	~Human() {}; // 소멸자
	virtual void move(); // 이동하여 새로운 위치로 x, y 변경
	virtual char getShape() { return 'H'; } // 객체 모양을 나타내는 문자 리턴(H)
	void inputdir();
};



#endif