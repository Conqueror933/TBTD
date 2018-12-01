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
	std::string name;
	Mesh* mesh;
};

class Start : public Object
{
public:
	Start(Objectctorlist)
		:
		Object(ObjectInit)
	{
	}

	void Update()
	{
		//spawn mobs at start
	}
};

class End : public Object
{
public:
	End(Objectctorlist)
		:
		Object(ObjectInit)
	{
	}

	void Update()
	{
		//mob gets to end, dies, lifes -1
	}
};
