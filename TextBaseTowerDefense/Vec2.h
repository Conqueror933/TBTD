#pragma once
#include <cmath>
#include <algorithm>
#include <iostream>

template<typename T>
class Vec2
{
public:	//Ctor, Dtor, Copy, Move
	Vec2() = default;
	Vec2(T in_x, T in_y)
	{
		x = in_x;
		y = in_y;
	}

	/*Vec2(const Vec2& rhs);
	Vec2& operator= (const Vec2& rhs);
	Vec2(Vec2&& rhs);
	Vec2& operator= (Vec2&& rhs);
	~Vec2() = default;*/

public: //Math
	Vec2<T> operator+(const Vec2<T>& rhs)
	{
		return Vec2<T>{ x + rhs.x, y + rhs.y };
	}
	Vec2<T>& operator+=(Vec2<T>& rhs)
	{
		return Vec2<T>{this.x + rhs.x, this.y + rhs.y};
	}

	Vec2<T> operator-(const Vec2<T>& rhs)
	{
		return Vec2<T>{ x - rhs.x, y - rhs.y };
	}
	Vec2<T>& operator-=(Vec2<T>& rhs)
	{
		return Vec2<T>{this.x - rhs.x, this.y - rhs.y};
	}

	Vec2<T> operator*(const Vec2<T>& rhs)
	{
		return Vec2<T>{ x * rhs.x, y * rhs.y };
	}
	Vec2<T>& operator*=(Vec2<T>& rhs)
	{
		return Vec2<T>{this.x * rhs.x, this.y * rhs.y};
	}

	Vec2<T> operator/(const Vec2<T>& rhs)
	{
		return Vec2<T>{ x / rhs.x, y / rhs.y };
	}
	Vec2<T>& operator/=(Vec2<T>& rhs)
	{
		return Vec2<T>{this.x / rhs.x, this.y / rhs.y};
	}

public: //Comparison
	bool operator==(const Vec2<T> rhs)
	{
		return x == rhs.x && y == rhs.y;
	}

public: //Utility
	float Distance(const Vec2<T> v1, const Vec2<T> v2)
	{
		return std::sqrt((v1.x - v2.x)*(v1.x - v2.x) + (v1.y - v2.y)*(v1.y - v2.y));
	}

	//Vec2<T> Move(const Vec2<T> start, const Vec2<T> end, float speed)
	//{
	//	float length = Distance(start, end);  //std::sqrt(x_dist * x_dist + y_dist * y_dist);

	//	float x_dist;
	//	float y_dist;
	//	start.x < end.x ? x_dist = end.x - start.x : x_dist = start.x - end.x;
	//	start.y < end.y ? y_dist = end.y - start.y : y_dist = start.y - end.y;
	//	float a = x_dist + y_dist;	//% based distribution weighted on the length
	//	x_dist <= 0.0f ? 0.0f : x_dist = x_dist / length;
	//	y_dist <= 0.0f ? 0.0f : y_dist = y_dist / length;

	//	if (x_dist == 0.0f && y_dist == 0.0f) throw "logic error, (x && y) == 0";

	//	x_dist *= speed;
	//	y_dist *= speed;
	//	//std::cout << "moved to " << start.x + x_dist << "/" << start.y + y_dist << std::endl;
	//	return Vec2<T>{start.x + x_dist, start.y + y_dist};
	//}
	Vec2<T> Move(const Vec2<T> start, const Vec2<T> end, float speed)	//non dynamic movement on rails
	{//call this RasterMove when switching in the far far future
		//figure out if north south west or east
		//assumes x,y coordinatesystem starting bottomleft
		if (start.x < end.x)
		{
			//east
			return Vec2<T>{std::min(start.x + speed,end.x), start.y};
		}
		else if (start.x > end.x)
		{
			//west
			return Vec2<T>{std::max(start.x - speed,end.x), start.y};
		}
		else if (start.y < end.y)
		{
			//north
			return Vec2<T>{start.x, std::min(start.y + speed, end.y)};
		}
		else if (start.y > end.y)
		{
			//south
			return Vec2<T>{start.x, std::max(start.y - speed, end.y)};
		}
		else
		{
			//error or target reached
			return Vec2<T>{-1.0f, -1.0f};
		}
	}

	bool isClose(const Vec2<T> rhs, float dis)
	{
		return Distance({x,y}, rhs) <= dis ? true : false;	// {x,y} cheese much
	}
public:
	T x;
	T y;
};




/*
if (start.x < end.x)
{
if (start.y < end.y)
{
return (end.x -start.x) + (end.y -start.y);
}
return (end.x -start.x) + (start.y - end.y);
}
else
{
if (start.y < end.y)
{
return (start.x - end.x) + (end.y -start.y);
}
return (start.x - end.x) + (start.y - end.y);
}
*/