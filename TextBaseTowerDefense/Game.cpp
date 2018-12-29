#include "Game.h"

void Game::Go()
{
	world.SpawnTower({ 20.0f, 20.0f }, "AOE", eTowers::AOETowerLvl1);
	world.SpawnTower({ 21.0f, 20.0f }, "Sniper", eTowers::SniperTowerLvl1);
	world.SpawnTower({ 22.0f, 20.0f }, "Shock", eTowers::ShockTowerLvl1);

	world.SpawnEnemy("Goblin", eEnemies::Goblin);
	world.SpawnEnemy("Imp1", eEnemies::Imp);
	world.SpawnEnemy("Imp2", eEnemies::Imp);
	world.SpawnEnemy("Imp3", eEnemies::Imp);
	world.SpawnEnemy("Imp4", eEnemies::Imp);
	world.SpawnEnemy("ArmoredGoblin", eEnemies::ArmoredGoblin);
	world.SpawnEnemy("Riese", eEnemies::Riese);
	
	while (world.Step() != 0);
	world.~World();	//remove this line to get rid of the weird iterator past end bug, that happens when dtor of Game is called
	std::cin.get();
}

//void testcode(World world, Start start, Mesh* mesh)
//{
//	world.SpawnTower({ 20.0f, 20.0f }, { 5.0f,5.0f }, "AOE", mesh, AOETowerLvl1);
//	world.SpawnTower({ 21.0f, 20.0f }, { 5.0f,5.0f }, "Sniper", mesh, SniperTowerLvl1);
//	world.SpawnTower({ 22.0f, 20.0f }, { 5.0f,5.0f }, "Shock", mesh, ShockTowerLvl1);
//
//	world.SpawnEnemy(start.cor, { 5.0f,5.0f }, "Goblin", mesh, Goblin);
//	world.SpawnEnemy(start.cor, { 5.0f,5.0f }, "Imp1", mesh, Imp);
//	world.SpawnEnemy(start.cor, { 5.0f,5.0f }, "Imp2", mesh, Imp);
//	world.SpawnEnemy(start.cor, { 5.0f,5.0f }, "Imp3", mesh, Imp);
//	world.SpawnEnemy(start.cor, { 5.0f,5.0f }, "Imp4", mesh, Imp);
//	world.SpawnEnemy(start.cor, { 5.0f,5.0f }, "ArmoredGoblin", mesh, ArmoredGoblin);
//	world.SpawnEnemy(start.cor, { 5.0f,5.0f }, "Riese", mesh, Riese);
//}
