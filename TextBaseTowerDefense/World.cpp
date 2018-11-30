#include "World.h"


World::World(float width, float height)
	:
	size(width, height)
{
}

void World::SpawnTower(TowerCtorList)
{
	towers.emplace_back(std::make_unique<Tower>(TowerInit));
	//towers.emplace_back(std::make_unique<PoisonTower>(TowerInit));
}

void World::SpawnEnemy(EnemyCtorList)
{
	enemies.emplace_back(std::make_unique<Enemy>(EnemyInit));
}

void World::Update()
{
	int towercount = towers.end() - towers.begin();
	int enemycount = enemies.end() - enemies.begin();

	for (int i = 0; i < towercount; i++)
	{
		int r = towers[i]->GetRange();
		std::vector<Event> events;
		for (int j = 0; j < enemycount; j++)
		{
			if (r >= towers[i]->cor.Distance(enemies[j]->cor))
			{
				Event e = {*enemies[j], *towers[i] };
				events.push_back(e);
			}
		}
		towers[i]->Update(events);
	}







	/*for (int i = 0; i < towercount; i++)
	{
		for (int j = 0; j < enemycount; j++)
		{
			towers[i]->Update(*enemies[j]);
		}
	}

	for (int i = 0; i < enemycount; i++)
	{
		enemies[i]->Update();
	}

	for (int i = 0; i < enemycount;)
	{
		if (!enemies.empty())
		{
			if (enemies[i]->GetDestroy())
			{
				enemies.erase(enemies.begin() + i);
				enemycount--;
			}
			else
			{
				i++;
			}
		}
	}*/
}
