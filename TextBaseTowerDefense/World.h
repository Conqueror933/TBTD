#pragma once
#include <vector>
#include <memory>
#include "Tower.h"
#include "Enemy.h"

class World
{
public:
	World(float width, float height);
	void SpawnTower(TowerCtorList);
	void SpawnEnemy(EnemyCtorList);
	void Update();

private:
	Vec2<float> size;
	std::vector<std::unique_ptr<Tower>> towers;
	std::vector<std::unique_ptr<Enemy>> enemies;
};