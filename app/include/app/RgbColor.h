#pragma once
#include <app/NotImplException.h>

namespace training::geometry {

	class RgbColor
	{
	public:
		RgbColor() {}
		RgbColor(int rgb)
		{

		}
		RgbColor(int r, int g, int b)
		{

		}
		int Red() const { throw NotImplException(); }
		int Green() const { throw NotImplException(); }
		int Blue() const { throw NotImplException(); }
		int Value() const	{	throw NotImplException();	}
		void SetRed(int value)
		{
			throw NotImplException();
		}
		void SetGreen(int value)
		{
			throw NotImplException();
		}
		void SetBlue(int value)
		{
			throw NotImplException();
		}
	private:

	};

}