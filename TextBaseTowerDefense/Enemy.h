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
	void Update(End& end, float dt);
	void Walk(End& end, float dt);

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

// PARAMS: hp, speed, armor, killvalue

#define M_Goblin			1000, 5.0f,  0, 10 
#define M_Riese				2500, 2.0f, 20, 25 
#define M_ArmoredGoblin		1000, 4.5f, 50, 15
#define M_Imp				 200, 7.0f,  0,  2
#define M_ArmoredImp		 200, 6.5f, 20,  4