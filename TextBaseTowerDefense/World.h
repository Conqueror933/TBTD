#pragma once
#include <vector>
#include <memory>
#include <chrono>
#include "Tower.h"
#include "Enemy.h"
#include "Event.h"
#include "FrameTimer.h"

class World
{
public:
	World(float width, float height, int lifes, Object start, Object end);
	void SpawnTower(TowerCtorList);
	void SpawnEnemy(EnemyCtorList);
	int Update();

private:
	int lifes;
	FrameTimer ft;
	Vec2<float> size;
	std::vector<std::unique_ptr<Tower>> towers;
	std::vector<std::unique_ptr<Enemy>> enemies;
	Object start;
	Object end;
};