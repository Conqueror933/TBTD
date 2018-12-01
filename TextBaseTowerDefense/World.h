#pragma once
#include <vector>
#include <memory>
#include <chrono>
#include "Tower.h"
#include "Enemy.h"
#include "Event.h"
#include "FrameTimer.h"
#include "Enums.h"

#define WorldCtorList float width, float height, int lifes, Vec2<float> startcor, Vec2<float> startsize, std::string startname, Vec2<float> endcor, Vec2<float> endsize, std::string endname
class World
{
public:
	World(WorldCtorList);
	~World();
	void SpawnTower(Vec2<float> cor, Vec2<float> size, std::string name, eTowers etower);
	void SpawnEnemy(Vec2<float> cor, Vec2<float> size, std::string name, eEnemies eenemy);
	int Step();
	Vec2<float> GetStart();

private:
	int lifes;
	FrameTimer ft;
	Vec2<float> size;
	std::vector<std::unique_ptr<Mesh>> meshes;
	std::vector<std::unique_ptr<Tower>> towers;
	std::vector<std::unique_ptr<Enemy>> enemies;
	std::unique_ptr<Start> start;
	std::unique_ptr<End> end;
};