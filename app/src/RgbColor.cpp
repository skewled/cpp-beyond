#include <app/RgbColor.h>

namespace training::geometry
{
    RgbColor RgbColor::BLACK(0,0,0);
    RgbColor RgbColor::WHITE(255,255,255);
    RgbColor RgbColor::RED(255,0,0);
    RgbColor RgbColor::GREEN(0,255,0);
    RgbColor RgbColor::BLUE(0,0,255);

    void RgbColor::SetBlue(int value)
    {
        Set(Red(), Green(), value);
    }
}