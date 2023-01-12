#pragma once
#define _USE_MATH_DEFINES
#include <cmath>
#include <stdexcept>
#include <string>
#include <iostream>
#include <app/RgbColor.h>
#include <app/Shape.h>

namespace training::geometry
{
	class Circle : public Shape
	{
	public:
		static int Count() { return count; }

		Circle() : Circle(1, "noname", RgbColor::BLACK) {}

		Circle(const Circle& other)
		: Circle(other.radius, other.Name(), other.Color())
		{}

		Circle(float radius, const std::string& name, RgbColor color)
		: Shape(name, color)
		{
			SetRadius(radius);
			count++;
		}
		
		~Circle()
		{
			count--;
		}

		float Radius() const { return radius; }
		
		void SetRadius(float radius)
		{
			if (radius < 0)
				throw std::invalid_argument("Radius must be > 0");
			this->radius = radius;
		}
		
		float Area() const override
		{
			return (float) (M_PI * Radius() * Radius());
		}
		float Perimeter() const override
		{
			return (float) (M_PI * Radius() * 2);
		}

		Circle operator + (const Circle& c2)
		{
			auto area = Area() + c2.Area();
			Circle ret;
			ret.SetRadius((float)(std::sqrt(area / M_PI)));
			return ret;
		}
		Circle& operator ++ ()
		{
			return *this += 1;
		}
		void operator ++ (int) {++(*this);}
		Circle& operator += (float val)
		{
			SetRadius((float)(std::sqrt((Area() + val) / M_PI)));
			return *this;
		}

	private:
		static int count;
		float radius;
	};

	inline std::ostream& operator << (std::ostream& o, const Circle& c)
	{
		o << "a circle " << c.Name() << " with area of " << c.Area();
		return o;
	}

}