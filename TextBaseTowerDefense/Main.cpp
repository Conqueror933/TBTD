#include "World.h"
#include <iostream>

World world(50.0f, 50.0f);
Mesh* mesh;

void testcode()
{
	world.SpawnTower({ 20.0f, 20.0f }, { 5.0f,5.0f }, "Sniper", mesh, SniperTowerLvl1);
	world.SpawnTower({ 21.0f, 20.0f }, { 5.0f,5.0f }, "AOE", mesh, AOETowerLvl1);
	world.SpawnEnemy({ 23.0f, 20.0f }, { 5.0f,5.0f }, "Goblin", mesh, Goblin);
	world.SpawnEnemy({ 24.0f, 20.0f }, { 5.0f,5.0f }, "Imp", mesh, Imp);

	world.Update();
}
int main()
{

	testcode();

	world.~World();
	std::cin.get();
	return 0;
}


/*
	TOWER

tower with stats and just shoot random stuff
PRO: tower is just a bunch of stats, logic is outside
CON: tower is not independent

or tower actual simulation, aka shoots first enemy first
so basically, tower has to manage doing dmg himself
PRO: more like a real TD, usually shooting at and killing the first enemy that comes in range first
CON: seems to be a lot harder and more complicated to code
PRO: can use Update();
CON: tower behaviour has to be in Update(); with no params, which makes it harder to code

PARAMLIST: targets, atks, dmg, atkspeed, range, price, dmg/tick, tickrate, duration, smart_targeting, poison stacks

BaseTowerLvl1 (1 targets, 1 atks,  5dmg, 0.5 atkspeed, range 20)
BaseTowerLvl2 (1 targets, 1 atks,  10dmg, 0.5 atkspeed, range 25)
BaseTowerLvl3 (1 targets, 1 atks,  15dmg, 0.5 atkspeed, range 30)

AOETowerLvl1 (i targets, 1 atks,  2 dmg, 0.7 atkspeed, range 10)
AOETowerLvl2 (i targets, 1 atks,  3 dmg, 0.6 atkspeed, range 10)
AOETowerLvl3 (i targets, 1 atks,  4 dmg, 0.5 atkspeed, range 10)

MultishotTowerLvl1 (2 targets, 1 atks,  5dmg, 0.5 atkspeed, range 10)
MultishotTowerLvl2 (3 targets, 1 atks,  5dmg, 0.5 atkspeed, range 15)
MultishotTowerLvl3 (4 targets, 1 atks,  5dmg, 0.5 atkspeed, range 15)

SniperTowerLvl1 (1 targets, 1 atks,  30dmg, 1.5 atkspeed, range 30)
SniperTowerLvl2 (1 targets, 1 atks,  45dmg, 1.5 atkspeed, range 40)
SniperTowerLvl3 (1 targets, 1 atks,  45dmg, 1.0 atkspeed, range 50)

PoisonTowerLvl1 (1 targets, 1 atks,  3dmg, 0.5 atkspeed, range 20, 2 dmg/tick, 1.0 tickrate, 5sec duration)
PoisonTowerLvl2 (1 targets, 1 atks,  3dmg, 0.5 atkspeed, range 25, 2 dmg/tick, 0.5 tickrate, 10sec duration, smart_targeting)
PoisonTowerLvl3 (1 targets, 1 atks,  3dmg, 0.5 atkspeed, range 30, 2 dmg/tick, 0.5 tickrate, 15sec duration, smart_targeting, poison stacks) 
																	#define smart_targeting wont hit an enemy already effected by poison
BurnTowerLvl1 (i targets, 1 atks,  0.1 dmg, 0.1 atkspeed, range 5)
BurnTowerLvl2 (i targets, 1 atks,  0.2 dmg, 0.1 atkspeed, range 5)
BurnTowerLvl3 (i targets, 1 atks,  0.3 dmg, 0.1 atkspeed, range 5)

ShockTowerLvl1 (1 targets, 10 atks, 0.2 dmg, 0.2 atkspeed, range 12)
ShockTowerLvl2 (1 targets, 15 atks, 0.2 dmg, 0.2 atkspeed, range 12)
ShockTowerLvl3 (1 targets, 20 atks, 0.2 dmg, 0.2 atkspeed, range 12)

...

*/

/*
	ENEMIES

Goblin			(1000hp, 5.0 speed,  0 armor, 10 killvalue)
Riese			(2500hp, 2.0 speed, 20 armor, 25 killvalue)
ArmoredGoblin	(1000hp, 4.5 speed, 50 armor, 15 killvalue)
Imp				( 200hp, 7.0 speed,  0 armor, 2 killvalue)
ArmoredImp		( 200hp, 6.5 speed, 20 armor, 4 killvalue)

*/