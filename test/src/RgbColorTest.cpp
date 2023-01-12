#include <stdexcept>
#include <gtest/gtest.h>
#include <app/RgbColor.h>

namespace training::test
{
    using namespace training::geometry;
    using namespace std;

    class RgbColorTest : public ::testing::Test
    {
    protected:
        void SetUp() override
        {
            c1.SetRed(0x80);
            c1.SetGreen(0x60);
            c1.SetBlue(0x30);
        }
        RgbColor c1;
    };

    TEST_F(RgbColorTest, Color)
    {
        ASSERT_EQ(0x806030, c1.Value());
    }
    TEST_F(RgbColorTest, RGB)
    {
        ASSERT_TRUE(c1.Red() == 0x80 &&
                    c1.Green() == 0x60 &&
                    c1.Blue() == 0x30);
    }

    TEST_F (RgbColorTest, InvalidRed)
    {
        try 
        {
            c1.SetRed(-5);
            FAIL();
        }
        catch(std::invalid_argument& ex)
        {
            return;
        }
        ASSERT_THROW (c1.SetRed(-5), std::invalid_argument);
    }
    TEST_F (RgbColorTest, InvalidGreen)
    {
        ASSERT_THROW (c1.SetGreen(-5), std::invalid_argument);
    }
    TEST_F (RgbColorTest, InvalidBlue)
    {
        ASSERT_THROW (c1.SetGreen(270), std::invalid_argument);
    }

    TEST_F (RgbColorTest, IntConversion)
    {
        RgbColor color (2,3,6);
        int rgb = c1;
    }

    TEST_F (RgbColorTest, ColorAddition)
    {
        RgbColor c1 (1,2,3);
        RgbColor c2 (3,2,1);
        RgbColor result;
        result = c1 + c2;
        ASSERT_EQ(result.Value(), 0x040404);
    }

   TEST_F (RgbColorTest, ColorStream)
    {
        cout << c1 << endl;
    }

}
