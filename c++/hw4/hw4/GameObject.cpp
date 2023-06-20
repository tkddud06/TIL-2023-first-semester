#include "GameObject.h"


bool GameObject::collide(GameObject* p) // 이 객체가 객체 p와 충돌했으면 true 리턴, 아니면 false 리턴
{
	if (this->x == p->getX() && this->y == p->getY())
	{
		return true;
	}
	else
	{
		return false;
	}
}