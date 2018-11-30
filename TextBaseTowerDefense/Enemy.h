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
	void Update();
	int takeDamage = 0;
	bool GetDestroy();
	int GetHp();

private:
	void Walk();

private:
	int hp;
	float speed;
	bool destroy = false;
};

// PARAMS: hp, speed, armor, killvalue

#define Goblin			1000, 5.0f,  0, 10 
#define Riese			2500, 2.0f, 20, 25 
#define ArmoredGoblin	1000, 4.5f, 50, 15
#define Imp				 200, 7.0f,  0,  2
#define ArmoredImp		 200, 6.5f, 20,  4