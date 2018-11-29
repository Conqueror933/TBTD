#include "Tower.h"

Tower::Tower(Vec2<float> c, Vec2<float> size, Mesh* mesh, std::string name, float damage, float range, float firerate)
	:
	Object(c, size, mesh, name),
	damage(damage),
	range(range),
	firerate(firerate)
{
	std::cout << "Tower " << name << " created." << std::endl;
}

Tower::~Tower()
{
	std::cout << "Tower " << name << " destroyed." << std::endl;
}

void Tower::Update()
{

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