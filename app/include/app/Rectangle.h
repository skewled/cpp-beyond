#pragma once
#include <string>
#include <app/RgbColor.h>
#include <app/Shape.h>

namespace training::geometry {
	class Rectangle : public Shape
	{
	public:
		Rectangle() : Rectangle(0, 0, "noname", RgbColor::BLUE) {}
		Rectangle(float width, float height, const std::string& name, RgbColor color)
		: Shape(name, color)
		{
			SetDimension(width, height);
		}

		float Width() const { return width; }
		float Height() const {  return height; }

		void SetDimension(float width, float height)
		{
			if (width < 0 || height < 0)
				throw std::invalid_argument("Dimension should be positive");
			this->width = width;
			this->height = height;
		}

		float Area() const override
		{
			return Width() * Height();
		}
		float Perimeter() const override
		{
			return (Width() + Height())*2;
		}

	private:
		float width;
		float height;
	};

	inline std::ostream& operator << (std::ostream& out, const Rectangle& r)
	{
		out << "A rectangle [" << r.Name() << "] Area: " << r.Area();
		return out;
	}

}