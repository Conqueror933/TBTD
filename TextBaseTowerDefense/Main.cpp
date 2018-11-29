#include "World.h"
#include <iostream>

World world(50.0f, 50.0f);
Mesh* mesh;

void f()
{
	world.SpawnTower({ 20.0f, 20.0f }, { 5.0f,5.0f }, mesh, "fred", 5.0f, 30.0f, 2.0f);
	world.SpawnTower({ 21.0f, 20.0f }, { 5.0f,5.0f }, mesh, "gustav", 5.0f, 30.0f, 2.0f);
	world.SpawnEnemy({ 23.0f, 20.0f }, { 5.0f,5.0f }, mesh, "esel", 10.0f, 2.0f);
	world.SpawnEnemy({ 24.0f, 20.0f }, { 5.0f,5.0f }, mesh, "hase", 15.0f, 2.0f);

	world.Update();
}
int main()
{
	{
		f();
	}

	std::cin.get();
	return 0;
}