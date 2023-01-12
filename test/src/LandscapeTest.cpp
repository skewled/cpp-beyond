#include <stdexcept>
#include <memory>
#include <gtest/gtest.h>
#include <app/Landscape.h>
#include <app/Measurable.h>


using namespace training;
using namespace training::geometry;

class Foo : public Measurable
{
    public:
        float Area() const override { return 100; }
        float Perimeter() const override { return 200; }
};

class LandscapeTest : public ::testing::Test
{
public:
    LandscapeTest() : sut("Test") {}

protected:
    void SetUp() override
    {
        s1 = std::make_shared<Foo>();
        s2 = std::make_shared<Foo>();
        sut.Add(s1);
        sut.Add(s2);
    }
    Landscape sut;
    MeasurableSptr s1;
    MeasurableSptr s2;
};

TEST_F(LandscapeTest, WeakPointerTest)
{
    {
        MeasurableSptr cptr = std::make_shared<Foo>();
        sut.Add(cptr);
        EXPECT_FLOAT_EQ(s1->Area() + s2->Area() + cptr->Area(), sut.Area());
    }
    ASSERT_FLOAT_EQ(s1->Area() + s2->Area(), sut.Area());
}

void func(Landscape ls)
{

}
TEST_F(LandscapeTest, MemoryCorrupt)
{
    func(sut);
    sut.Area();
}

TEST_F(LandscapeTest, Name)
{
    ASSERT_EQ("Test", sut.Name());
}

TEST_F(LandscapeTest, Area)
{
    ASSERT_NEAR(200, sut.Area(), 1.0f);
}

TEST_F(LandscapeTest, Perimeter)
{
    ASSERT_NEAR(400, sut.Perimeter(), 1.0f);
}