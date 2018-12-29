#pragma once
#include <vector>
#include <memory>
#include "Tower.h"
#include "Enemy.h"
#include "Event.h"
#include "FrameTimer.h"
#include "Enums.h"

#define WorldCtorList float width, float height, int lifes,const std::vector<Vec2<float>> Waypoints
class World
{
public:
	World(WorldCtorList);
	~World();
	void SpawnTower(Vec2<float> cor, eTowers etower, std::string name = "");
	void SpawnEnemy(eEnemies eenemy, std::string name = "");
	int Step();
	void Update();
	const std::vector<Vec2<float>>& GetWaypoints();

private:
	float time_passed = 0.0f;
	int lifes;
	int towercount = 0;
	int enemycount = 0;
	FrameTimer ft;
	Vec2<float> size;
	const std::vector<Vec2<float>> Waypoints;
	std::vector<std::unique_ptr<Mesh>> meshes;
	std::vector<std::unique_ptr<Tower>> towers;
	std::vector<std::unique_ptr<Enemy>> enemies;
};