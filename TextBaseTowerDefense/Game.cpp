#include "Game.h"

void Game::Go()
{
	world.SpawnTower({ 20.0f, 20.0f }, eTowers::AOETowerLvl1, "AOE");
	world.SpawnTower({ 21.0f, 20.0f }, eTowers::SniperTowerLvl1, "Sniper");
	world.SpawnTower({ 22.0f, 20.0f }, eTowers::ShockTowerLvl1, "Shock");

	world.SpawnEnemy(eEnemies::Goblin, "Goblin");
	world.SpawnEnemy(eEnemies::Imp, "Imp1");
	world.SpawnEnemy(eEnemies::Imp, "Imp2");
	world.SpawnEnemy(eEnemies::Imp, "Imp3");
	world.SpawnEnemy(eEnemies::Imp, "Imp4");
	world.SpawnEnemy(eEnemies::ArmoredGoblin, "ArmoredGoblin");
	world.SpawnEnemy(eEnemies::Riese, "Riese");
	
	std::cout << "\n";
	while (world.Step() != 0);
}

