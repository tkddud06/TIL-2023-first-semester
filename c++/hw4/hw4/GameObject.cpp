#include "GameObject.h"


bool GameObject::collide(GameObject* p) // �� ��ü�� ��ü p�� �浹������ true ����, �ƴϸ� false ����
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