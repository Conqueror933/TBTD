#pragma once
#include "Object.h"

#define EnemyCtorList  Objectctorlist, int hp, float speed, int armor, int killvalue
#define EnemyInit ObjectInit, hp, speed, armor, killvalue

class Enemy : public Object
{
public:
	Enemy(EnemyCtorList);
	~Enemy();

public:
	void Update(std::vector<Vec2<float>> Waypoints , float dt);
	void Walk(std::vector<Vec2<float>> Waypoints , float dt);

public:
	bool GetDestroy();
	int GetHp();
	int GetArmor();
	void TakeDamage(int dmg);

private:
	void Walk();

private:
	int hp;
	float speed;
	int armor;
	int killvalue;
	bool destroy = false;
};

// PARAMS: Vec2<float>{size}, hp, speed, armor, killvalue

#define M_Goblin			Vec2<float>{ 5.0f,5.0f }, 1000, 5.0f,  0, 10 
#define M_Riese				Vec2<float>{ 5.0f,5.0f }, 2500, 2.0f, 20, 25 
#define M_ArmoredGoblin		Vec2<float>{ 5.0f,5.0f }, 1000, 4.5f, 50, 15
#define M_Imp				Vec2<float>{ 5.0f,5.0f },  200, 7.0f,  0,  2
#define M_ArmoredImp		Vec2<float>{ 5.0f,5.0f },  200, 6.5f, 20,  4