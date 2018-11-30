#include "World.h"


World::World(float width, float height, int lifes, Object start, Object end)
	:
	size(width, height),
	lifes(lifes),
	start(start),
	end(end)
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

int World::Update()
{
	const float dt = ft.Mark();
	//std::cout << dt << std::endl;
	int towercount = towers.end() - towers.begin();
	int enemycount = enemies.end() - enemies.begin();

	int death = 0;
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
					//Event e = {*enemies[j], *towers[i] };
					events.emplace_back(Event{ *enemies[j], *towers[i], dist });
					//std::cout << "Emplaced an Event." << std::endl;

					//get rid of event bullshit
					/*if(towers[i]->Update(enemies[j]))
					{
					enemies.erase(enemies.begin() + j);
					//instead of erase, swap with last and .pop_back();
					enemycount--;
					}
					else
					{
					j++;
					}*/
				}
			}
			death += towers[i]->Update(events);
		}
		towers[i]->time_passed += dt;
	}



	//event for attacks and target selection e.g. multishot tower
	//max_targets


	if (death > 0)
	{
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
