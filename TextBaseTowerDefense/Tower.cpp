#include <algorithm>
#include "Tower.h"

Tower::Tower(TowerCtorList)
	:
	Object(ObjectInit),
	max_targets(max_targets),
	attackcount(attackcount),
	damage(damage),
	time_per_attack(time_per_attack),
	range(range),
	price(price)
{
	std::cout << "Tower " << name << " created." << std::endl;
}

Tower::~Tower()
{
	std::cout << "Tower " << name << " destroyed." << std::endl;
}

void Tower::Update(std::vector<Event>& events)
{
	std::sort(events.begin(), events.end());
	int mt = max_targets;
	//make tower do stuff on his own
	//tower keeps ptr to his target
	//when target dies, checks range and picks new target


	//implement multishot via pick target from events, -1 atk, pick another, repeat til 0 atks left
	for (int i = 0; i < (int)events.size() && mt != 0; i++)
	{
		if (0 < events[i].enemy.GetHp())
		{
			for (int j = 0; j < attackcount; j++)
			{
				int rawdmg = damage - events[i].enemy.GetArmor();
				if (rawdmg < 1)
					rawdmg = 1;
				events[i].enemy.TakeDamage(rawdmg);
			}
			mt--;
		}
	}
	//check target hp, shoot if above 0
	//Shoot(target);
}

void Tower::Shoot(Enemy& target)
{
	std::cout << "Dealt " << damage << " to " << target.name << std::endl;
}

int Tower::GetRange()
{
	return range;
}

float Tower::GetTimePerAttack()
{
	return time_per_attack;
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
