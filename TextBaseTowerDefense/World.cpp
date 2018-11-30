#include "World.h"


World::World(WorldCtorList)
	:
	size(width, height),
	lifes(lifes)
{
	start = std::make_unique<Start>(startcor, startsize, startname, startmesh);
	end = std::make_unique<End>(endcor, endsize, endname, endmesh);
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

int World::Step()
{
	const float dt = ft.Mark();
	//std::cout << dt << std::endl;
	int towercount = towers.end() - towers.begin();
	int enemycount = enemies.end() - enemies.begin();

	for (int i = 0; i < towercount; i++)
	{
		//std::cout << "loop 1" << std::endl;
		if (towers[i]->time_passed > towers[i]->GetTimePerAttack())
		{
			towers[i]->time_passed = 0.0f;
			int r = towers[i]->GetRange();
			std::vector<Event> events;
			for (int j = 0; j < enemycount; j++)
			{
				//std::cout << towers[i]->name << std::endl;
				float dist = towers[i]->cor.Distance(enemies[j]->cor);
				if (r >= dist)
				{
					events.emplace_back(Event{ *enemies[j], *towers[i], dist }); //event for max_targets
					//std::cout << "Emplaced an Event." << std::endl;
				}
			}
			towers[i]->Update(events);
		}
		towers[i]->time_passed += dt;
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
	}

	for (int i = 0; i < enemycount; i++)
	{
		enemies[i]->Update(*end, dt);
	}
	
	return enemycount;



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

Vec2<float> World::GetStart()
{
	return start->cor;
}
