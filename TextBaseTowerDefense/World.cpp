#include "World.h"

World::World(WorldCtorList)
	:
	size(width, height),
	lifes(lifes),
	Waypoints(Waypoints)
{

	for (int i = 0; i < 35; i++)
	{
		meshes.emplace_back(std::make_unique<Mesh>(i, 1)); //replace with Sprite and ifstream and all that jazz
	}
	start = std::make_unique<Start>(meshes[20].get(), "Start", GetStart());
	end = std::make_unique<End>(meshes[21].get(), "End", GetEnd());
	std::cout << "Made a World" << std::endl;
}

World::~World()
{
	std::cout << "Killed a World" << std::endl;
}

void World::SpawnTower(Vec2<float> cor, eTowers etower, std::string name)
{
	switch (etower)
	{
	case eTowers::BaseTowerLvl1:
		towers.emplace_back(std::make_unique<Tower>(meshes[0].get(), name, cor, M_BaseTowerLvl1));
		break;
	case eTowers::BaseTowerLvl2:
		towers.emplace_back(std::make_unique<Tower>(meshes[1].get(), name, cor, M_BaseTowerLvl2));
		break;
	case eTowers::BaseTowerLvl3:
		towers.emplace_back(std::make_unique<Tower>(meshes[2].get(), name, cor, M_BaseTowerLvl3));
		break;

	case eTowers::AOETowerLvl1:
		towers.emplace_back(std::make_unique<Tower>(meshes[3].get(), name, cor, M_AOETowerLvl1));
		break;
	case eTowers::AOETowerLvl2:
		towers.emplace_back(std::make_unique<Tower>(meshes[4].get(), name, cor, M_AOETowerLvl2));
		break;
	case eTowers::AOETowerLvl3:
		towers.emplace_back(std::make_unique<Tower>(meshes[5].get(), name, cor, M_AOETowerLvl3));
		break;

	case eTowers::MultishotTowerLvl1:
		towers.emplace_back(std::make_unique<Tower>(meshes[6].get(), name, cor, M_MultishotTowerLvl1));
		break;
	case eTowers::MultishotTowerLvl2:
		towers.emplace_back(std::make_unique<Tower>(meshes[7].get(), name, cor, M_MultishotTowerLvl2));
		break;
	case eTowers::MultishotTowerLvl3:
		towers.emplace_back(std::make_unique<Tower>(meshes[8].get(), name, cor, M_MultishotTowerLvl3));
		break;

	case eTowers::SniperTowerLvl1:
		towers.emplace_back(std::make_unique<Tower>(meshes[9].get(), name, cor, M_SniperTowerLvl1));
		break;
	case eTowers::SniperTowerLvl2:
		towers.emplace_back(std::make_unique<Tower>(meshes[10].get(), name, cor, M_SniperTowerLvl2));
		break;
	case eTowers::SniperTowerLvl3:
		towers.emplace_back(std::make_unique<Tower>(meshes[11].get(), name, cor, M_SniperTowerLvl3));
		break;

	case eTowers::BurnTowerLvl1:
		towers.emplace_back(std::make_unique<Tower>(meshes[12].get(), name, cor, M_BurnTowerLvl1));
		break;
	case eTowers::BurnTowerLvl2:
		towers.emplace_back(std::make_unique<Tower>(meshes[13].get(), name, cor, M_BurnTowerLvl2));
		break;
	case eTowers::BurnTowerLvl3:
		towers.emplace_back(std::make_unique<Tower>(meshes[14].get(), name, cor, M_BurnTowerLvl3));
		break;

	case eTowers::ShockTowerLvl1:
		towers.emplace_back(std::make_unique<Tower>(meshes[15].get(), name, cor, M_ShockTowerLvl1));
		break;
	case eTowers::ShockTowerLvl2:
		towers.emplace_back(std::make_unique<Tower>(meshes[16].get(), name, cor, M_ShockTowerLvl2));
		break;
	case eTowers::ShockTowerLvl3:
		towers.emplace_back(std::make_unique<Tower>(meshes[17].get(), name, cor, M_ShockTowerLvl3));
		break;

	}
	//towers.emplace_back(std::make_unique<Tower>(TowerInit));
	//towers.emplace_back(std::make_unique<PoisonTower>(TowerInit));
	towercount++;
}

void World::SpawnEnemy(eEnemies eenemy, std::string name)
{
	switch (eenemy)
	{
	case eEnemies::Goblin:
		if (name == "") name = "Goblin";
		enemies.emplace_back(std::make_unique<Enemy>(meshes[30].get(), name, Waypoints[0], M_Goblin));
		break;
	case eEnemies::Riese:
		if (name == "") name = "Riese";
		enemies.emplace_back(std::make_unique<Enemy>(meshes[31].get(), name, Waypoints[0], M_Riese));
		break;
	case eEnemies::ArmoredGoblin:
		if (name == "") name = "ArmoredGoblin";
		enemies.emplace_back(std::make_unique<Enemy>(meshes[32].get(), name, Waypoints[0], M_ArmoredGoblin));
		break;
	case eEnemies::Imp:
		if (name == "") name = "Imp";
		enemies.emplace_back(std::make_unique<Enemy>(meshes[33].get(), name, Waypoints[0], M_Imp));
		break;
	case eEnemies::ArmoredImp:
		if (name == "") name = "ArmoredImp";
		enemies.emplace_back(std::make_unique<Enemy>(meshes[34].get(), name, Waypoints[0], M_ArmoredImp));
		break;
	}
	//enemies.emplace_back(std::make_unique<Enemy>(EnemyInit));
	enemycount++;
}

int World::Step()
{
	const float dt = ft.Mark();
	//std::cout << dt << std::endl;

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

	//dead enemy removal
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

	//enemy updates
	for (int i = 0; i < enemycount; i++)
	{
		enemies[i]->Update(*end, dt);
	}
	
	//spit out frames
	time_passed += dt;
	if (time_passed > 1.0f)
	{
		Update();
		time_passed = 0.0f;
	}
	
	return enemycount;
}

void World::Update()
{
	//WHATEVER THE FUCK YOU WANT TO DISPLAY, PUT IN HERE

	for (int i = 0; i < enemycount; i++)
	{
		//enemy at cor is in range of tower
		std::cout << "Enemy " << enemies[i]->name << " at " << enemies[i]->cor.GetX() << "/" << enemies[i]->cor.GetY() << 
			" has " << enemies[i]->GetHp() << " hp left." << std::endl;
	}

	//std::cout << "Enemy " << name << " has " << hp << " left." << std::endl;
	//print out all the damn stats
	//Tower cor //could also do this differently
	//Tower.enemiesinrange();
	//Enemy cor
	//Enemy hp
}

Vec2<float> World::GetStart()
{
	return Waypoints[0];
}

Vec2<float> World::GetEnd()
{
	return Waypoints[6]; //needs some Waypoints.back() action, just dont feel like fucking with iterators right now
}
