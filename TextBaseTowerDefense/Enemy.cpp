#include "Enemy.h"

Enemy::Enemy(EnemyCtorList)
	:
	Object(ObjectInit),
	hp(hp),
	speed(speed),
	armor(armor),
	killvalue(killvalue),
	Waypoints(Waypoints)
{
	std::cout << "Enemy " << name << " created." << std::endl;
}

Enemy::~Enemy()
{
	std::cout << "Enemy " << name << " destroyed." << std::endl;
}

void Enemy::Update(float dt)
{
	if (hp <= 0)
	{
		destroy = true;
		std::cout << name << " died." << std::endl;
	}

	if (cor.isClose(Waypoints[nextWaypoint], 0.0f)) nextWaypoint++;	//0.0f because i dont need room for error with rasterrails
	if (nextWaypoint >= 6) nextWaypoint = 6;
	Walk(dt);
}

void Enemy::Walk(float dt)
{
	//check path
	//move


	//move to Vec2(end)
	//speed*dt
	//calculate new cor
	cor = cor.Move(this->cor, Waypoints[nextWaypoint], speed*dt);
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
