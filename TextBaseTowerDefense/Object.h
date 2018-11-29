#pragma once
#include <string>
#include <iostream>
#include "Vec2.h"
#include "Mesh.h"

class Object
{
public:
	Object(Vec2<float> c, Vec2<float> size, Mesh* mesh, std::string name)
		:
		cor(c),
		size(size),
		mesh(mesh),
		name(name)
	{
	}
	virtual void Update() = 0;

//protected:
	Vec2<float> cor;
	Vec2<float> size;
	Mesh* mesh;
	std::string name;
};

