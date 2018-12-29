#pragma once
#include <string>
#include <iostream>
#include <vector>
#include "Vec2.h"
#include "Mesh.h"

#define Objectctorlist Mesh* mesh, std::string name, Vec2<float> coordinates, Vec2<float> size
#define ObjectInit mesh, name, coordinates, size

class Object
{
public:
	Object(Objectctorlist)
		:
		mesh(mesh),
		name(name),
		cor(coordinates),
		size(size)
	{
	}
	//virtual void Update() = 0;

//protected:
	Vec2<float> cor;
	Vec2<float> size;
	std::string name;
	Mesh* mesh;
};
