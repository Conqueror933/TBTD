#include "Game.h"

void Game::Go()
{
	//auto s = std::make_unique<Start>(Vec2<float>{ 2.0f, 2.0f }, Vec2<float>{ 3.0f, 3.0f }, "ws", mesh);
	//auto start = std::make_unique<Tower>( Vec2<float>{ 2.0f, 2.0f }, Vec2<float>{ 3.0f, 3.0f }, "ws", mesh, AOETowerLvl1);
	//auto start = std::make_unique<World>(5.0f, 2.0f, 4, Start{ { 2.0f,2.0f },{ 3.0f, 3.0f }, "ws", mesh }, End{ { 1.0f,3.0f },{ 3.0f, 3.0f }, "we", mesh });
	//World w{5.0f, 2.0f, 4, Start{{2.0f,2.0f},{3.0f, 3.0f}, "ws", mesh},End{ { 1.0f,3.0f },{ 3.0f, 3.0f }, "we", mesh } };
	world.SpawnTower({ 20.0f, 20.0f }, { 5.0f,5.0f }, "AOE", eTowers::AOETowerLvl1);
	world.SpawnTower({ 21.0f, 20.0f }, { 5.0f,5.0f }, "Sniper", eTowers::SniperTowerLvl1);
	world.SpawnTower({ 22.0f, 20.0f }, { 5.0f,5.0f }, "Shock", eTowers::ShockTowerLvl1);

	world.SpawnEnemy(world.GetStart(), { 5.0f,5.0f }, "Goblin", eEnemies::Goblin);
	world.SpawnEnemy(world.GetStart(), { 5.0f,5.0f }, "Imp1", eEnemies::Imp);
	world.SpawnEnemy(world.GetStart(), { 5.0f,5.0f }, "Imp2", eEnemies::Imp);
	world.SpawnEnemy(world.GetStart(), { 5.0f,5.0f }, "Imp3", eEnemies::Imp);
	world.SpawnEnemy(world.GetStart(), { 5.0f,5.0f }, "Imp4", eEnemies::Imp);
	world.SpawnEnemy(world.GetStart(), { 5.0f,5.0f }, "ArmoredGoblin", eEnemies::ArmoredGoblin);
	world.SpawnEnemy(world.GetStart(), { 5.0f,5.0f }, "Riese", eEnemies::Riese);

	while (world.Step() != 0);
	world.~World();
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
