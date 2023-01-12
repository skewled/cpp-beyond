#pragma once
#include <memory>

namespace training::geometry
{
    // This is an interface for all shapes which decouples the shapes from the landscape
    // Shapes will adhere to this interface and ease unit testing. Landscape can be tested independent of shapes.
    class Measurable
    {
        public:
            virtual float Area() const = 0;
            virtual float Perimeter() const = 0;
            virtual ~Measurable() {}
    };

    using MeasurableSptr = std::shared_ptr<Measurable>;
    using MeasurableWptr = std::weak_ptr<Measurable>;
}