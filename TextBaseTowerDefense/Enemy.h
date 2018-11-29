#pragma once
#include "Object.h"

class Enemy : public Object
{
public:
	Enemy(Vec2<float> c, Vec2<float> size, Mesh* mesh, std::string name, float hp, float speed);
	~Enemy();

public:
	void Update() override;
	float takeDamage = 0.0f;
	bool GetDestroy();

private:
	void Walk();

private:
	float hp;
	float speed;
	bool destroy = false;
};