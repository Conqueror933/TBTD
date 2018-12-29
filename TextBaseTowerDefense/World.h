#pragma once
#include <vector>
#include <memory>
#include "Tower.h"
#include "Enemy.h"
#include "Event.h"
#include "FrameTimer.h"
#include "Enums.h"

#define WorldCtorList float width, float height, int lifes, std::vector<Vec2<float>> Waypoints
class World
{
public:
	World(WorldCtorList);
	~World();
	void SpawnTower(Vec2<float> cor, std::string name, eTowers etower);
	void SpawnEnemy(std::string name, eEnemies eenemy);
	int Step();
	void Update();
	Vec2<float> GetStart();

private:
	float time_passed = 0.0f;
	int lifes;
	int towercount = 0;
	int enemycount = 0;
	FrameTimer ft;
	Vec2<float> size;
	std::vector<Vec2<float>> Waypoints;
	std::vector<std::unique_ptr<Mesh>> meshes;
	std::vector<std::unique_ptr<Tower>> towers;
	std::vector<std::unique_ptr<Enemy>> enemies;
	std::unique_ptr<Start> start;
	std::unique_ptr<End> end;
};