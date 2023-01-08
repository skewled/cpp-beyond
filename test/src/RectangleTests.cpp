#include <gtest/gtest.h>
#include <app/Rectangle.h>

using namespace training::geometry;

class RectangleTest : public ::testing::Test {
  public:
    RectangleTest() : name("Randy"), color(20, 50, 20) {}

  protected:
    
    void SetUp() override {
      r1.SetName(name);
      r1.SetColor(color);
      r1.SetDimension(width, height);

    }
    double width = 10;
    double height = 5;
    std::string name;
    RgbColor color;
    Rectangle r1;

};

TEST_F(RectangleTest, Name) {
  ASSERT_EQ(name, r1.Name());
}

TEST_F(RectangleTest, Size) {
  ASSERT_DOUBLE_EQ(width, r1.Width());
  ASSERT_DOUBLE_EQ(height, r1.Height());
}

TEST_F(RectangleTest, Color)
{
  ASSERT_EQ(color.Value(), r1.Color().Value());
}
TEST_F(RectangleTest, Area)
{
  ASSERT_DOUBLE_EQ(50, r1.Area());
}
TEST_F(RectangleTest, Perimeter)
{
  ASSERT_DOUBLE_EQ(50, r1.Perimeter());
}