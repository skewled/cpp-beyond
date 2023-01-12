#pragma once
#include <iostream>
#include <memory>
#include <app/RgbColor.h>
#include <app/Measurable.h>

namespace training::geometry
{
    class Shape : public Measurable
    {
        public:
            Shape(const std::string name, const RgbColor& color)
            {
                SetColor(color);
                SetName(name);
            }

            virtual ~Shape() {}

            std::string Name() const { return name; }
            RgbColor Color() const { return color; }

            void SetName(const std::string& name)
            {
                this->name = name;
            }
            void SetColor(RgbColor color)
            {
                this->color = color;
            }

            virtual float Area() const = 0;
            virtual float Perimeter() const = 0;

        private:
            std::string name;
		    RgbColor color;
    };

    using ShapeSptr = std::shared_ptr<Shape>;
    using ShapeWptr = std::weak_ptr<Shape>;
}