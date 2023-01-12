#pragma once

#include <string>
#include <vector>
#include <memory>
#include <app/Measurable.h>

namespace training
{
	using geometry::MeasurableSptr;
	using geometry::MeasurableWptr;

	class Landscape
	{

	public:
		Landscape(const std::string& name)
		{
			SetName(name);
		}

		~Landscape() 
		{

		}

		std::string Name() const { return name; }
		void SetName(const std::string& name)
		{
			this->name = name;
		}
		void Add (MeasurableWptr sp)
		{
			shapes.push_back(sp);
		}
		float Area() const
		{
			float total = 0;
			for (int i=0; i<shapes.size(); i++)
			{
				if(auto sp = shapes[i].lock())
				total += sp->Area();
			} // sp goes out of scope and count of shared_ptr get's decremented.
			return total;
		}
		float Perimeter() const
		{
			float total = 0;
			for (int i=0; i<shapes.size(); i++)
			{
				if(auto sp = shapes[i].lock())
				total += sp->Perimeter();
			}
			return total;
		}

	private:
		std::string name;
		std::vector<MeasurableWptr> shapes;
	};

}