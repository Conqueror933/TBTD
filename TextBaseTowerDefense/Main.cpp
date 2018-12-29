#include "Game.h"

int main()
{
	{
		//std::make_unique<Game>()->Go();
		Game g;
		g.Go();
	}
	std::cin.get();
	return 0;
}

/*
			STUFF TO IMPLEMENT
- Graphics (last on the list) { .NET , Matrices , Transformations , Sprite drawing , ... } maybe even DirectX
- Unit Pathing (path blocking with size and all that jazz) (also right now, there is no restriction to go outside of the world)
- Unit Text Display where they are / cout for tower gets in range, smth smth
- Implement $ system
- Make Towers Player placed
- have wave and building phases
- have rocks and walls and shit
- randomize start and end, rocks walls and shit		(actually a design decision, dont wanna handcraft invisible maps tho...)
- ASCII art like print the playfield?

*/

/*
	UNIT PATHING

ISSUES:
- grid base needed for smooth A*?
- collision detection needed
- collision between circle (Enemy) and square (tower)
- different sizes for enemies:
	- for towers that are 2x2 with holes between them how does that interact
		o o o o o
		x x o o o
		x x o x x
		o o o x x
		o o o o o
- on an integer grid, do units just move 1 square every 1-5sec? can i make them move smoothly instead?
	- otherwise towerrange in float doesn't make sense either,
	- also usually in TDs units move smoothly and dont just jump a square every set amount of time
	- also how will different movespeeds work?
	- do cells actually exist? and hold their contents?
		- would fuck over everything ive coded so far, completly throws of the design i was going for
	- or are cells just a construct for pathfinding?

- in general how should tower placing work?
	- entirely free placing without any concept of a grid might be awkward (especially cause no graphics interface == no mouse input)
	- could also make holes between towers everywhere,
		- which in turn makes pathfinding even harder

SOLUTIONS IDEAS/SUGGESTIONS:
- could code that weird octagon map splitting into parts thing, makes artifical squares


SOLUTIONS:
- make artifical grid for tower placing and pathfinding, making tower.cor an int, but keep enemy.cor float so they can move smoothly,
- enemies get a vector of waypoints (which are the grid.cor from the artifical grid)


- A* sets up node points


*/

/*
		TOWER

PARAMS:		targets, atks, dmg, atkspeed, minrange, maxrange, price, smart_targeting, apply debuff, ...

		DEBUFF
PARAMS:		dmg/tick, tickrate, duration, poison stacks, -armor on hit, take more dmg %, spawn lightning on all surrounding enemies, ...

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

/*
ich hab das mesh, ich brauch n vector von allen meshes, dann bekommt jeder tower nen pointer zu dem mesh von dessen typ er ist
speicher ich diesen mesh pointer in Object, Tower oder DerivedTower ? man w�rde doch meinen in Object, weil das dahin geh�rt richtig?
die welt hat ein object und dieses hat nen skin den ich male, v�llig irrelevant was 'under the hood' abgeht
deshalb hat ja jeder Tower auch n underlying Object
folglich:
muss ich den mesh vector in world? game? (Object?) storen, und somit in den constructor prozess passen, is das n unique pointer?
std::vector<Mesh*>[i] == AOETowerLvl1.mesh*
ok das is die liste von allen mesh pointern... wo sind die meshes? also doch
std::vector<std::unique_ptr<Mesh>>
dann h�ngen die meshes irgendwo in memory rum, muss ja jedes nur einmal geben in memory, muss die ja dann nur mehrfach malen,
sollte aber nix ausmachen, is ja immerhin nur das original sprite aus dem ich dann pixel f�r pixel extrahiere und on screen male,
via Graphics::Pipeline mit cam position etc.

*/