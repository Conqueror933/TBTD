#pragma once

class Mesh
{
public:
	Mesh() = default;
	Mesh(int g)
		:
		g(g)
	{
	}
	int g;
};