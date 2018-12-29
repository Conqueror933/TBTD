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
