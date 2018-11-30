#pragma once
#include <vector>
#include <memory>
#include <chrono>
#include "Tower.h"
#include "Enemy.h"
#include "Event.h"
#include "FrameTimer.h"

#define WorldCtorList float width, float height, int lifes, Vec2<float> startcor, Vec2<float> startsize, std::string startname, Mesh* startmesh, Vec2<float> endcor, Vec2<float> endsize, std::string endname, Mesh* endmesh
class World
{
public:
	World(WorldCtorList);
	void SpawnTower(TowerCtorList);
	void SpawnEnemy(EnemyCtorList);
	int Step();
	Vec2<float> GetStart();

private:
	int lifes;
	FrameTimer ft;
	Vec2<float> size;
	std::vector<std::unique_ptr<Tower>> towers;
	std::vector<std::unique_ptr<Enemy>> enemies;
	std::unique_ptr<Start> start;	//asshole
	std::unique_ptr<End> end;		//asshole
};