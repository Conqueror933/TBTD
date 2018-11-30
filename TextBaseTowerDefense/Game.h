#pragma once
#include "World.h"
#include "Mesh.h"
#include <iostream>

class Game
{
public:
	void Go();
private:
	//Mesh m;
	Mesh* mesh;
	//mesh = &m;
	World world{ 50.0f, 50.0f, 50, 
		Vec2<float>{ 0.0f, 0.0f }, Vec2<float>{ 1.0f, 1.0f }, "Start", mesh, 
		Vec2<float>{ 50.0f, 50.0f }, Vec2<float>{ 1.0f, 1.0f }, "End", mesh };

};