#pragma once
#include <vector>
#include "Object.h"
#include "Enemy.h"
#include "Event.h"

#define TowerCtorList  Objectctorlist, int max_targets, int attackcount, int damage, float time_per_attack, int range, int price
#define TowerInit ObjectInit, max_targets, attackcount, damage, time_per_attack, range, price

class Tower : public Object
{
public:
	Tower(TowerCtorList);
	~Tower();

public:
	void Update(std::vector<Event>& events);
	void Shoot(Enemy& target);
	int GetRange();
	float time_passed = 0.0f;
	float GetTimePerAttack();

private:
	int max_targets;
	int attackcount;
	int damage;
	float time_per_attack;
	int range;
	int price;
	//std::weak_ptr<Event> lastTarget;
};

class PoisonTower : public Tower
{
public:
#define PoisonTowerCtorList TowerCtorList, int tickdamage, float tickrate, float duration, bool smart_targeting, bool stacking_poison
	PoisonTower(PoisonTowerCtorList);

private:
	int tickdamage;		//create DeBuff class?
	float tickrate;
	float duration;
	bool smart_targeting;
	bool stacking_poison;
};

class BaseTower : public Tower
{
public:
	BaseTower(TowerCtorList)
		:
		Tower(TowerInit)
	{}
private:

	
};

// PARAMS:Vec2<float>{size},  max_targets, attackcount, damage, time_per_attack, range, price

#define M_BaseTowerLvl1			Vec2<float>{ 5.0f,5.0f },   1,  1,  50, 0.5f, 20, 100
#define M_BaseTowerLvl2			Vec2<float>{ 5.0f,5.0f },   1,  1, 100, 0.5f, 25, 200
#define M_BaseTowerLvl3			Vec2<float>{ 5.0f,5.0f },   1,  1, 150, 0.5f, 30, 300

#define M_AOETowerLvl1			Vec2<float>{ 5.0f,5.0f }, 100,  1,  20, 0.7f, 10, 150
#define M_AOETowerLvl2			Vec2<float>{ 5.0f,5.0f }, 100,  1,  30, 0.6f, 10, 300
#define M_AOETowerLvl3			Vec2<float>{ 5.0f,5.0f }, 100,  1,  40, 0.5f, 10, 450

#define M_MultishotTowerLvl1	Vec2<float>{ 5.0f,5.0f },   2,  1,  50, 0.5f, 10, 120
#define M_MultishotTowerLvl2	Vec2<float>{ 5.0f,5.0f },   3,  1,  50, 0.5f, 15, 240
#define M_MultishotTowerLvl3	Vec2<float>{ 5.0f,5.0f },   4,  1,  50, 0.5f, 15, 320

#define M_SniperTowerLvl1		Vec2<float>{ 5.0f,5.0f },   1,  1, 300, 1.5f, 30, 170
#define M_SniperTowerLvl2		Vec2<float>{ 5.0f,5.0f },   1,  1, 450, 1.5f, 40, 240
#define M_SniperTowerLvl3		Vec2<float>{ 5.0f,5.0f },   1,  1, 450, 1.0f, 50, 400

#define M_BurnTowerLvl1			Vec2<float>{ 5.0f,5.0f }, 100,  1,   1, 0.1f,  5, 200
#define M_BurnTowerLvl2			Vec2<float>{ 5.0f,5.0f }, 100,  1,   2, 0.1f,  5, 300
#define M_BurnTowerLvl3			Vec2<float>{ 5.0f,5.0f }, 100,  1,   3, 0.1f,  5, 400

#define M_ShockTowerLvl1		Vec2<float>{ 5.0f,5.0f },   1, 10,   2, 0.2f, 12, 150
#define M_ShockTowerLvl2		Vec2<float>{ 5.0f,5.0f },   1, 15,   2, 0.2f, 12, 250
#define M_ShockTowerLvl3		Vec2<float>{ 5.0f,5.0f },   1, 20,   2, 0.2f, 12, 350