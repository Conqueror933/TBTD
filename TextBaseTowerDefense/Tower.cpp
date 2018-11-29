#include "Tower.h"

Tower::Tower(TowerCtorList)
	:
	Object(ObjectInit),
	damage(damage),
	range(range),
	time_per_attack(time_per_attack)
{
	std::cout << "Tower " << name << " created." << std::endl;
}

Tower::~Tower()
{
	std::cout << "Tower " << name << " destroyed." << std::endl;
}

void Tower::Update(Enemy& target)
{
	Shoot(target);
}

void Tower::Shoot(Enemy& target)
{
	std::cout << "Tower " << name << " tries to shoot." << std::endl;
	if (range >= cor.Distance(target.cor))
	{
		target.takeDamage += damage;
		std::cout << "Dealt " << damage << " to " << target.name << std::endl;
	}
}

PoisonTower::PoisonTower(PoisonTowerCtorList)
	:
	Tower(TowerInit),
	tickdamage(tickdamage), 
	tickrate(tickrate), 
	duration(duration), 
	smart_targeting(smart_targeting), 
	stacking_poison(stacking_poison)
{
}
