#pragma once
#include <vector>
#include <memory>
#include "Tower.h"
#include "Enemy.h"

class World
{
public:
	World(float width, float height);
	void SpawnTower(Vec2<float> c, Vec2<float> size, Mesh* mesh, std::string name, float damage, float range, float firerate);
	void SpawnEnemy(Vec2<float> c, Vec2<float> size, Mesh* mesh, std::string name, float hp, float speed);
	void Update();

private:
	Vec2<float> size;
	std::vector<std::unique_ptr<Tower>> towers;
	std::vector<std::unique_ptr<Enemy>> enemies;
};