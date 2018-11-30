#pragma once
#include <memory>
#include <iostream>
//#include "Tower.h"

class Tower;
class Enemy;
struct Event
{
public:
	Event(Enemy& enemy, Tower& tower, float dis)
		:
		enemy(enemy),
		tower(tower),
		Distance(dis)
	{
		//std::cout << "Created an Event." << std::endl;
	}
	~Event()
	{
		//std::cout << "Destroyed an Event." << std::endl;
	}
	bool operator<(const Event& rhs)
	{
		return Distance < rhs.Distance;
	}
	Event operator=(const Event& rhs)
	{
		return Event{ rhs.enemy, rhs.tower, rhs.Distance };
	}
	Enemy& enemy;
	Tower& tower;
	float Distance;

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