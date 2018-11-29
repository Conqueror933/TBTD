#pragma once

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

public: //Access
	Vec2 GetVec2()
	{
		return this;
	}
	void SetVec2(T in_x, T in_y)
	{
		x = in_x;
		y = in_y;
	}

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

	float Distance(const Vec2<T> target)
	{
		if (x < target.x)
		{
			if (y < target.y)
			{
				return (target.x - x) + (y - target.y);
			}
			return (target.x - x) + (y - target.y);
		}
		else
		{
			if (y < target.y)
			{
				return (x - target.x) + (target.y - y);
			}
			return (x - target.x) + (y - target.y);
		}
		
	}

private:
	T x;
	T y;
};