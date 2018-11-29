#include "World.h"


World::World(float width, float height)
	:
	size(width, height)
{
}

void World::SpawnTower(Vec2<float> c, Vec2<float> size, Mesh* mesh, std::string name, float damage, float range, float firerate) //params
{
	towers.emplace_back(std::make_unique<Tower>(c, size, mesh, name, damage, range, firerate));
}

void World::SpawnEnemy(Vec2<float> c, Vec2<float> size, Mesh* mesh, std::string name, float hp, float speed)
{
	enemies.emplace_back(std::make_unique<Enemy>(c, size, mesh, name, hp, speed));
}

void World::Update()
{
	int towercount = towers.end() - towers.begin();
	int enemycount = enemies.end() - enemies.begin();
	for (int i = 0; i < towercount; i++)
	{
		for (int j = 0; j < enemycount; j++)
		{
			towers[i]->Shoot(*enemies[j]);
		}
	}

	for (int i = 0; i < enemycount; i++)
	{
		enemies[i]->Update();
	}
	/*towers[0]->Shoot(*enemies[0]);
	towers[1]->Shoot(*enemies[0]);
	enemies[0]->Update();
	enemies[1]->Update();*/

	for (int i = 0; i < 1;)
	{
		if (enemies[i]->GetDestroy())
		{
			enemies.erase(enemies.begin()+i);
		}
		else
		{
			i++;
		}
	}
}
