#pragma once
#include "World.h"
#include "Mesh.h"
#include <iostream>
#include <random>

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
	unsigned int level = 1;
	const std::vector<Vec2<float>> Waypoints = //Start = bottomleft {x,y}
	{ { 0.0f,0.0f }, { 0.0f,100.0f }, { 100.0f,100.0f }, { 100.0f,50.0f }, { 150.0f,50.0f }, { 150.0f,200.0f }, { 200.0f,200.0f } };
	World world{ Waypoints };
	std::mt19937 rng;
};