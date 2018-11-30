#include "Enemy.h"

Enemy::Enemy(EnemyCtorList)
	:
	Object(ObjectInit),
	hp(hp),
	speed(speed)
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
	if (hp <= 0)
	{
		destroy = true;
		std::cout << name << " died." << std::endl;
	}
	takeDamage = 0;
}

bool Enemy::GetDestroy()
{
	return destroy;
}

int Enemy::GetHp()
{
	return hp;
}

void Enemy::Walk()
{
	//check path
	//move
}