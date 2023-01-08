#include <stdexcept>
#include <gtest/gtest.h>
#include <app/RgbColor.h>

namespace training::test {
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

}
