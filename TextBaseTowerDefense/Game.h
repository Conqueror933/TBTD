#pragma once
#include "World.h"
#include "Mesh.h"
#include <iostream>

class Game
{
public:
	Game()
	{
		std::cout << "Made a Game" << std::endl;
	}
	~Game()
	{
		std::cout << "Killed a Game" << std::endl;
	}
	void Go();
private:
	//Mesh m;
	//Mesh * mesh = nullptr;
	//mesh = &m;
	World world{ 500.0f, 500.0f, 50, 
		Vec2<float>{ 0.0f, 0.0f }, Vec2<float>{ 1.0f, 1.0f }, "Start",
		Vec2<float>{ 50.0f, 50.0f }, Vec2<float>{ 1.0f, 1.0f }, "End"};

};