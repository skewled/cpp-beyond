#pragma once
#include <string>
#include <app/RgbColor.h>
#include <app/NotImplException.h>

namespace training::geometry {
	class Rectangle
	{
	public:
		Rectangle() {}
		Rectangle(float width, float height, std::string name, RgbColor color)
		{

		}

		float Width() const { throw NotImplException(); }
		float Height() const { throw NotImplException(); }
		std::string Name() const { throw NotImplException(); }
		RgbColor Color() const { throw NotImplException(); }
		void SetDimension(float width, float height)
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
		float width;
		float height;
	};

}