#include "Enemy.h"

Enemy::Enemy(EnemyCtorList)
	:
	Object(ObjectInit),
	hp(hp),
	speed(speed),
	armor(armor),
	killvalue(killvalue)
{
	std::cout << "Enemy " << name << " created." << std::endl;
}

Enemy::~Enemy()
{
	std::cout << "Enemy " << name << " destroyed." << std::endl;
}

void Enemy::Update(const std::vector<Vec2<float>>& Waypoints, float dt)
{
	if (hp <= 0)
	{
		destroy = true;
		std::cout << name << " died." << std::endl;
	}
	Walk(Waypoints, dt);
}

void Enemy::Walk(const std::vector<Vec2<float>>& Waypoints, float dt)
{
	//move to Vec2(end)
	//speed*dt
	//calculate new cor
	cor = cor.Move(this->cor, Waypoints[6], speed*dt);
	//std::cout << "Enemy " << speed * dt;// << std::endl;
}

bool Enemy::GetDestroy()
{
	return destroy;
}

int Enemy::GetHp()
{
	return hp;
}

int Enemy::GetArmor()
{
	return armor;
}

void Enemy::TakeDamage(int dmg)
{
	hp -= dmg;
}

void Enemy::Walk()
{
	//check path
	//move
}