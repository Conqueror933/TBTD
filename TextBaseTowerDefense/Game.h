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
	{ //remove world.~World(); in Game.cpp to get rid of the iterator bug
		std::cout << "Killed a Game" << std::endl;
	}
	void Go();
private:
	//Mesh m;
	//Mesh * mesh = nullptr;
	//mesh = &m;
	std::vector<Vec2<float>> Waypoints = //Start = bottomleft {x,y}
	{ { 0.0f,0.0f },{ 0.0f,100.0f },{ 100.0f,100.0f },{ 100.0f,50.0f },{ 150.0f,50.0f },{ 150.0f,200.0f },{ 200.0f,200.0f }, };
	World world{ 200.0f, 200.0f, 50, Waypoints };
		//Vec2<float>{ 0.0f, 0.0f }, Vec2<float>{ 1.0f, 1.0f }, "Start",
		//Vec2<float>{ 60.0f, 40.0f }, Vec2<float>{ 1.0f, 1.0f }, "End"};

};