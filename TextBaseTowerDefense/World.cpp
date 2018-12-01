#include "World.h"

World::World(WorldCtorList)
	:
	size(width, height),
	lifes(lifes)
{

	for (int i = 0; i < 35; i++)
	{
		meshes.emplace_back(std::make_unique<Mesh>(i, 1)); //replace with Sprite and ifstream and all that jazz
	}
	auto da = meshes[4].get();
	start = std::make_unique<Start>(startcor, startsize, startname, meshes[20].get());
	end = std::make_unique<End>(endcor, endsize, endname, meshes[21].get());
	std::cout << "Made a World" << std::endl;
}

World::~World()
{
	std::cout << "Killed a World" << std::endl;
}

void World::SpawnTower(Vec2<float> cor, Vec2<float> size, std::string name, eTowers etower)
{
	switch (etower)
	{
	case eTowers::BaseTowerLvl1:
		towers.emplace_back(std::make_unique<Tower>(cor, size, name, meshes[0].get(), M_BaseTowerLvl1));
		break;
	case eTowers::BaseTowerLvl2:
		towers.emplace_back(std::make_unique<Tower>(cor, size, name, meshes[1].get(), M_BaseTowerLvl2));
		break;
	case eTowers::BaseTowerLvl3:
		towers.emplace_back(std::make_unique<Tower>(cor, size, name, meshes[2].get(), M_BaseTowerLvl3));
		break;

	case eTowers::AOETowerLvl1:
		towers.emplace_back(std::make_unique<Tower>(cor, size, name, meshes[3].get(), M_AOETowerLvl1));
		break;
	case eTowers::AOETowerLvl2:
		towers.emplace_back(std::make_unique<Tower>(cor, size, name, meshes[4].get(), M_AOETowerLvl2));
		break;
	case eTowers::AOETowerLvl3:
		towers.emplace_back(std::make_unique<Tower>(cor, size, name, meshes[5].get(), M_AOETowerLvl3));
		break;

	case eTowers::MultishotTowerLvl1:
		towers.emplace_back(std::make_unique<Tower>(cor, size, name, meshes[6].get(), M_MultishotTowerLvl1));
		break;
	case eTowers::MultishotTowerLvl2:
		towers.emplace_back(std::make_unique<Tower>(cor, size, name, meshes[7].get(), M_MultishotTowerLvl2));
		break;
	case eTowers::MultishotTowerLvl3:
		towers.emplace_back(std::make_unique<Tower>(cor, size, name, meshes[8].get(), M_MultishotTowerLvl3));
		break;

	case eTowers::SniperTowerLvl1:
		towers.emplace_back(std::make_unique<Tower>(cor, size, name, meshes[9].get(), M_SniperTowerLvl1));
		break;
	case eTowers::SniperTowerLvl2:
		towers.emplace_back(std::make_unique<Tower>(cor, size, name, meshes[10].get(), M_SniperTowerLvl2));
		break;
	case eTowers::SniperTowerLvl3:
		towers.emplace_back(std::make_unique<Tower>(cor, size, name, meshes[11].get(), M_SniperTowerLvl3));
		break;

	case eTowers::BurnTowerLvl1:
		towers.emplace_back(std::make_unique<Tower>(cor, size, name, meshes[12].get(), M_BurnTowerLvl1));
		break;
	case eTowers::BurnTowerLvl2:
		towers.emplace_back(std::make_unique<Tower>(cor, size, name, meshes[13].get(), M_BurnTowerLvl2));
		break;
	case eTowers::BurnTowerLvl3:
		towers.emplace_back(std::make_unique<Tower>(cor, size, name, meshes[14].get(), M_BurnTowerLvl3));
		break;

	case eTowers::ShockTowerLvl1:
		towers.emplace_back(std::make_unique<Tower>(cor, size, name, meshes[15].get(), M_ShockTowerLvl1));
		break;
	case eTowers::ShockTowerLvl2:
		towers.emplace_back(std::make_unique<Tower>(cor, size, name, meshes[16].get(), M_ShockTowerLvl2));
		break;
	case eTowers::ShockTowerLvl3:
		towers.emplace_back(std::make_unique<Tower>(cor, size, name, meshes[17].get(), M_ShockTowerLvl3));
		break;

	}
	//towers.emplace_back(std::make_unique<Tower>(TowerInit));
	//towers.emplace_back(std::make_unique<PoisonTower>(TowerInit));
}

void World::SpawnEnemy(Vec2<float> cor, Vec2<float> size, std::string name, eEnemies eenemy)
{
	switch (eenemy)
	{
	case eEnemies::Goblin:
		enemies.emplace_back(std::make_unique<Enemy>(cor, size, name, meshes[30].get(), M_Goblin));
		break;
	case eEnemies::Riese:
		enemies.emplace_back(std::make_unique<Enemy>(cor, size, name, meshes[31].get(), M_Riese));
		break;
	case eEnemies::ArmoredGoblin:
		enemies.emplace_back(std::make_unique<Enemy>(cor, size, name, meshes[32].get(), M_ArmoredGoblin));
		break;
	case eEnemies::Imp:
		enemies.emplace_back(std::make_unique<Enemy>(cor, size, name, meshes[33].get(), M_Imp));
		break;
	case eEnemies::ArmoredImp:
		enemies.emplace_back(std::make_unique<Enemy>(cor, size, name, meshes[34].get(), M_ArmoredImp));
		break;
	}
	//enemies.emplace_back(std::make_unique<Enemy>(EnemyInit));
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
