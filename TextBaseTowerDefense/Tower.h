#pragma once
#include "Object.h"
#include "Enemy.h"

class Tower : public Object
{
public:
	Tower(Vec2<float> c, Vec2<float> size, Mesh* mesh, std::string name, float damage, float range, float firerate);
	~Tower();

public:
	void Update() override;
	void Shoot(Enemy& target);

private:
	float damage;
	float range;
	float firerate;
};