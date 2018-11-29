#include "Enemy.h"

Enemy::Enemy(Vec2<float> c, Vec2<float> size, Mesh* mesh, std::string name, float hp, float speed)
	:
	Object(c, size, mesh, name),
	hp(hp)
{
	std::cout << "Enemy " << name << " created." << std::endl;
}

Enemy::~Enemy()
{
	std::cout << "Enemy " << name << " destroyed." << std::endl;
}

void Enemy::Update()
{
	hp -= takeDamage;
	std::cout << "Enemy " << name << " took " << takeDamage << " damage and has " << hp << " left." << std::endl;
	if (hp <= 0.0f)
	{
		destroy = true;
		std::cout << name << " died." << std::endl;
	}
	takeDamage = 0.0f;
}

bool Enemy::GetDestroy()
{
	return destroy;
}

void Enemy::Walk()
{
	//check path
	//move
}