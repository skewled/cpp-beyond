#pragma once

#include <string>
#include <app/NotImplException.h>

namespace training
{
	class Landscape
	{
	public:
		Landscape(std::string name)
		{
		}
		std::string Name() const { throw NotImplException(); }
		void SetName(std::string name)
		{
			throw NotImplException();
		}
		float Area() const
		{
			throw NotImplException();
		}
		float Perimeter() const
		{
			throw NotImplException();
		}

	private:
		std::string name;
	};

}