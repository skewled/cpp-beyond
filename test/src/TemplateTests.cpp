#include <iostream>
#include <string>
#include <gtest/gtest.h>
#include <app/Circle.h>
#include <app/Rectangle.h>
#include <app/Templates.h>

namespace training::test
{
    using namespace training::geometry;
    using std::cout;

    TEST (TemplatesTest, ShowTest) 
    {
        Circle c(10, "TC1", RgbColor::BLUE);
        Rectangle r (10, 10, "TR1", RgbColor::RED);

        Show(c);
        Show(r);
        Show(std::string("Hello World"));
        Show(5.6);

        Show(r, c, 5.6);

    }

}