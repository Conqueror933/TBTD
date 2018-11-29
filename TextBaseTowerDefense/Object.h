#pragma once
#include <string>
#include <iostream>
#include "Vec2.h"
#include "Mesh.h"

#define Objectctorlist Vec2<float> coordinates, Vec2<float> size, std::string name, Mesh* mesh
#define ObjectInit coordinates, size, name, mesh

class Object
{
public:
	Object(Objectctorlist)
		:
		cor(coordinates),
		size(size),
		name(name),
		mesh(mesh)
	{
	}
	//virtual void Update() = 0;

//protected:
	Vec2<float> cor;
	Vec2<float> size;
	Mesh* mesh;
	std::string name;
};

