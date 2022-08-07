#include "./greynumber.hpp"
#include <iostream>
#include <sstream>
#include "gtest/gtest.h"

template <typename T>
bool approx(T a, T b, double eps = 0.000001)
{
    return std::abs(a - b) < eps;
}

TEST(SIMPLEARITH, EMPTYCONSTRUCTOR){
    GreyNumber<int> g1 = GreyNumber<int>();
    EXPECT_EQ(g1.A(), 0);
    EXPECT_EQ(g1.B(), 0);
}

TEST(SIMPLEARITH, SINGLECONSTRUCTOR)
{
    GreyNumber<int> g1 = GreyNumber<int>(5);
    EXPECT_EQ(g1.A(), 5);
    EXPECT_EQ(g1.B(), 5);
}

TEST(SIMPLEARITH, FULLCONSTRUCTOR)
{
    GreyNumber<int> g1 = GreyNumber<int>(5, 7);
    EXPECT_EQ(g1.A(), 5);
    EXPECT_EQ(g1.B(), 7);
}

TEST(SIMPLEARITH, CONSTRUCTRIGHTORDER)
{
    GreyNumber<int> g1 = GreyNumber<int>(10, 1);
    EXPECT_EQ(g1.A(), 1);
    EXPECT_EQ(g1.B(), 10);
}

TEST(SIMPLEARITH, OPERATORPLUS)
{
    GreyNumber<int> g1 = GreyNumber<int>(5, 7);
    GreyNumber<int> g2 = GreyNumber<int>(10, 70);
    GreyNumber<int> g3 = g1 + g2;
    EXPECT_EQ(g3.A(), 15);
    EXPECT_EQ(g3.B(), 77);
}

TEST(SIMPLEARITH, BINARYMINUS)
{
    GreyNumber<int> g1 = GreyNumber<int>(5, 7);
    GreyNumber<int> g2 = GreyNumber<int>(10, 70);
    GreyNumber<int> g3 = g1 - g2;
    EXPECT_EQ(g3.A(), -63);
    EXPECT_EQ(g3.B(), -5);
}

TEST(SIMPLEARITH, UNARYMINUS)
{
    GreyNumber<int> g1 = GreyNumber<int>(5, 7);
    GreyNumber<int> g2 = -g1;
    EXPECT_EQ(g2.A(), -7);
    EXPECT_EQ(g2.B(), -5);
}

TEST(SIMPLEARITH, OPERATORPRODUCT)
{
    GreyNumber<int> g1 = GreyNumber<int>(5, 7);
    GreyNumber<int> g2 = GreyNumber<int>(10, 70);
    GreyNumber<int> g3 = g1 * g2;
    EXPECT_EQ(g3.A(), 50);
    EXPECT_EQ(g3.B(), 490);
}

TEST(SIMPLEARITH, OPERATORPRODUCTWITHSCALAR)
{
    GreyNumber<double> g1 = GreyNumber<double>(3.14, 2.71);
    GreyNumber<double> result = 10.0 * g1;
    EXPECT_TRUE(approx(result.B(), 31.4));
    EXPECT_TRUE(approx(result.A(), 27.1));

    GreyNumber<double> otherresult = g1 * 10.0;
    EXPECT_TRUE(approx(otherresult.B(), 31.4));
    EXPECT_TRUE(approx(otherresult.A(), 27.1));
}

TEST(SIMPLEARITH, OPERATORDIVIDE)
{
    GreyNumber<double> g1 = GreyNumber<double>(3, 4);
    GreyNumber<double> g2 = GreyNumber<double>(5, 10);
    GreyNumber<double> g3 = g1 / g2;
    EXPECT_TRUE(approx(g3.A(), 0.3));
    EXPECT_TRUE(approx(g3.B(), 0.8));
}

TEST(LOGICAL, EQUALS)
{
    GreyNumber<double> g1 = GreyNumber<double>(3, 4);
    GreyNumber<double> g2 = GreyNumber<double>(3, 4);
    EXPECT_TRUE(g1 == g2);
}

TEST(LOGICAL, LESS)
{
    GreyNumber<int> g1 = GreyNumber<int>(1, 4);
    GreyNumber<int> g2 = GreyNumber<int>(1, 5);
    EXPECT_TRUE(g1 < g2);

    GreyNumber<int> g3 = GreyNumber<int>(1, 4);
    GreyNumber<int> g4 = GreyNumber<int>(2, 5);
    EXPECT_TRUE(g3 < g4);
}

TEST(LOGICAL, GREATER)
{
    GreyNumber<int> g1 = GreyNumber<int>(1, 4);
    GreyNumber<int> g2 = GreyNumber<int>(1, 5);
    EXPECT_TRUE(g2 > g1);

    GreyNumber<int> g3 = GreyNumber<int>(1, 4);
    GreyNumber<int> g4 = GreyNumber<int>(2, 5);
    EXPECT_TRUE(g4 > g3);
}

TEST(LOGICAL, LESSOREQUAL)
{
    GreyNumber<int> g1 = GreyNumber<int>(1, 4);
    GreyNumber<int> g2 = GreyNumber<int>(1, 5);
    EXPECT_TRUE(g1 <= g2);

    GreyNumber<int> g3 = GreyNumber<int>(1, 4);
    GreyNumber<int> g4 = GreyNumber<int>(2, 5);
    EXPECT_TRUE(g3 <= g4);
}

TEST(LOGICAL, GREATEROREQUAL)
{
    GreyNumber<int> g1 = GreyNumber<int>(1, 4);
    GreyNumber<int> g2 = GreyNumber<int>(1, 5);
    EXPECT_TRUE(g2 >= g1);

    GreyNumber<int> g3 = GreyNumber<int>(1, 4);
    GreyNumber<int> g4 = GreyNumber<int>(2, 5);
    EXPECT_TRUE(g4 >= g3);
}

TEST(MATH, SQRT){
    GreyNumber<int> g = GreyNumber<int>(100, 64);
    GreyNumber<double> result = sqrt(g);

    EXPECT_TRUE(approx(result.A(), 8.0));
    EXPECT_TRUE(approx(result.B(), 10.0));
}

TEST(MATH, POWER){
    GreyNumber<int> g = GreyNumber<int>(100, 64);
    GreyNumber<double> result = pow(g, 0.5);

    EXPECT_TRUE(approx(result.A(), 8.0));
    EXPECT_TRUE(approx(result.B(), 10.0));
}

TEST(REPRESENTATION, TOSTRING){
    GreyNumber<int> g = GreyNumber<int>(10, 20);
    std::ostringstream os;
    os << g;
    std::string s = os.str();
    EXPECT_TRUE(s == "GreyNumber(10, 20)");
}



int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}



