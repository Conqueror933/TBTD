#pragma once
#include <memory>
//#include "Tower.h"

class Tower;
class Enemy;
struct Event
{
public:
	Event(Enemy& enemy, Tower& tower)
		:
		enemy(enemy),
		tower(tower)
	{
	}
	Enemy& enemy;
	Tower& tower;

	//std::weak_ptr<Object> tower;

	/*Event(std::shared_ptr<Tower> tower, std::shared_ptr<Enemy> enemy)
		:
		enemy(enemy),
		tower(tower)
	{
	}

	const std::shared_ptr<Enemy> enemy;
	const std::shared_ptr<Tower> tower;*/
};