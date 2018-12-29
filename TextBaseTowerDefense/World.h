#pragma once
//#include <vector>
#include <memory>
#include "Tower.h"
#include "Enemy.h"
#include "Event.h"
#include "FrameTimer.h"
#include "Enums.h"

class World
{
public:
	World(const std::vector<Vec2<float>> Waypoints, float gridsize = 10.0f, float squaresize = 1.0f, int lifes = 50);
	~World();
	void SpawnTower(Vec2<float> cor, eTowers etower, std::string name = "");
	void SpawnEnemy(eEnemies eenemy, std::string name = "");
	int Step();
	void Update();
	const std::vector<Vec2<float>>& GetWaypoints();

private:
	float time_passed = 0.0f;
	float time_step = 1.0f;
	int lifes;
	int towercount = 0;
	int enemycount = 0;
	FrameTimer ft;
	Vec2<float> worldsize = { 100.0f,100.0f };
	float gridsize;
	float squaresize;
	const std::vector<Vec2<float>> Waypoints;
	std::vector<std::unique_ptr<Mesh>> meshes;
	std::vector<std::unique_ptr<Tower>> towers;
	std::vector<std::unique_ptr<Enemy>> enemies;
};