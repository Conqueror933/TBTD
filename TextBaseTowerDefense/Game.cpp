#include "Game.h"

void Game::Go()
{
	world.SpawnTower({ 20.0f, 20.0f }, eTowers::AOETowerLvl1, "AOE");
	world.SpawnTower({ 21.0f, 20.0f }, eTowers::SniperTowerLvl1, "Sniper");
	world.SpawnTower({ 22.0f, 20.0f }, eTowers::ShockTowerLvl1, "Shock");

	//world.SpawnEnemy(eEnemies::Goblin, "Goblin");
	//world.SpawnEnemy(eEnemies::Imp, "Imp1");
	//world.SpawnEnemy(eEnemies::Imp, "Imp2");
	//world.SpawnEnemy(eEnemies::Imp, "Imp3");
	//world.SpawnEnemy(eEnemies::Imp, "Imp4");
	//world.SpawnEnemy(eEnemies::ArmoredGoblin, "ArmoredGoblin");
	//world.SpawnEnemy(eEnemies::Riese, "Riese");
	
	std::cout << "\n";
	bool gamenotover = true; //obviously schwachsinn
	while (gamenotover)
	{
		//build phase
		bool buildphase = true;
		while (buildphase)
		{
			// QUOTE ON QUOTE "OPTIONS MENU"	...		LuL
			std::cout << "What Tower do you wanna place? " << std::endl;
			std::cout << "pick a number from 0 - 17 " << std::endl;
			int t; std::cin >> t;
			//check if player has enough money
			std::cout << "Where do you wanna place the Tower? " << std::endl;
			std::cout << "enter x: " << std::endl;
			float x; std::cin >> x;
			std::cout << "enter y: " << std::endl;
			float y; std::cin >> y;
			world.SpawnTower({ x,y }, (eTowers)t);

			world.DisplayTowers();
			std::cout << "Place more Towers or continue game? " << std::endl;
			std::cout << "1 for more Towers, 2 to continue " << std::endl;
			std::cin >> t;
			if(t == 2) buildphase = false;
		}

		//wave phase

		//do the enemy spawning
		rng.seed(level);
		for (unsigned int i = 0; i <= level; i++)
		{
			std::uniform_int_distribution<int> Dist(0,4);
			world.SpawnEnemy((eEnemies)Dist(rng));
		}

		//move the world
		while (world.Step() != 0);
		level++;
	}
}
