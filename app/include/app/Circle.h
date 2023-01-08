#pragma once
#include <string>
#include <app/RgbColor.h>
#include <app/NotImplException.h>

namespace training::geometry
{
	class Circle
	{
	public:
		Circle() {}

		Circle(float radius, std::string name, RgbColor color)
		{
		}
		float Radius() const { throw NotImplException(); }
		std::string Name() const { throw NotImplException(); }
		RgbColor Color() const { throw NotImplException(); }
		void SetRadius(float radius)
		{
			throw NotImplException();
		}
		void SetName(std::string name)
		{
			throw NotImplException();
		}
		void SetColor(RgbColor color)
		{
			throw NotImplException();
		}

		float Area()
		{
			throw NotImplException();
		}
		float Perimeter()
		{
			throw NotImplException();
		}

	private:
		std::string name;
		RgbColor color;
		float radius;
	};

}