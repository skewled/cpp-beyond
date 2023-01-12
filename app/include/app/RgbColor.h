#pragma once
#include <stdexcept>
#include <iostream>

namespace training::geometry {

	class RgbColor
	{
	public:
		static RgbColor BLACK;
		static RgbColor WHITE;
		static RgbColor RED;
		static RgbColor GREEN;
		static RgbColor BLUE;

		RgbColor() { rgb = 0; }
		RgbColor(int rgb)
		{
			this->rgb = rgb; // when instance vars are the same you need to use this
		}
		RgbColor(int r, int g, int b)
		{
			Set(r, g, b);
		}
		int Red() const { return (rgb >> 16); }
		int Green() const { return (rgb >> 8) & 0xFF; }
		int Blue() const { return rgb & 0xFF; }
		int Value() const	{	return rgb;	}
		void SetRed(int value)
		{
			Set(value, Green(), Blue());
		}
		void SetGreen(int value)
		{
			Set(Red(), value, Blue());
		}
		void SetBlue(int value);
		void Set(int r, int g, int b);
		operator int () {return rgb;}
		RgbColor operator + (const RgbColor& c2) const
		{
			int r = Red() + c2.Red();
			int g = Green() + c2.Green();
			int b = Blue() + c2.Blue();
			r = r > 255 ? 255 : r;
			g = g > 255 ? 255 : g;
			b = b > 255 ? 255 : b;
			return RgbColor(r, b, g);
		}
	private:
		int rgb;
	};

	inline std::ostream& operator << (std::ostream& o, const RgbColor& c)
	{
		o << "Color object (" << c.Red() << "," << c.Green() << "," << c.Blue()
		  << ")";
		return o;
	}

	inline void RgbColor::Set(int r, int g, int b)
	{
		if(r >= 0 && r <= 255 && 
		   g >= 0 && g <= 255 &&
		   b >= 0 && b <= 255) {
			// masking bits to store in the int
			rgb = r << 16 | g << 8 | b;
		} else {
			throw std::invalid_argument("rgb must be between 0-255");
		}
	}

}