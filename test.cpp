#define CATCH_CONFIG_MAIN

#include "./greynumber.hpp"
#include <iostream>
#include <sstream>
#include <catch2/catch_test_macros.hpp>
#include <catch2/catch_all.hpp>


template <typename T>
static bool approx(T a, T b, double eps = 0.000001)
{
    return std::abs(a - b) < eps;
}



TEST_CASE("No params", "Constructor"){
    GreyNumber<int> g1 = GreyNumber<int>();
    REQUIRE(g1.A() == 0);
    REQUIRE(g1.B() == 0);
}

TEST_CASE("Single param", "Constructor")
{
    GreyNumber<int> g1 = GreyNumber<int>(5);
    REQUIRE(g1.A() == 5);
    REQUIRE(g1.B() == 5);
}

TEST_CASE("Two params", "Constructor")
{
    GreyNumber<int> g1 = GreyNumber<int>(5, 7);
    REQUIRE(g1.A() == 5);
    REQUIRE(g1.B() == 7);
}

TEST_CASE("Right order", "CONSTRUCTRIGHTORDER")
{
    GreyNumber<int> g1 = GreyNumber<int>(10, 1);
    REQUIRE(g1.A() == 1);
    REQUIRE(g1.B() == 10);
}

TEST_CASE("Operator Plus", "OPERATOR")
{
    GreyNumber<int> g1 = GreyNumber<int>(5, 7);
    GreyNumber<int> g2 = GreyNumber<int>(10, 70);
    GreyNumber<int> g3 = g1 + g2;
    REQUIRE(g3.A() == 15);
    REQUIRE(g3.B() == 77);
}

TEST_CASE("Operator Minus", "OPERATOR")
{
    GreyNumber<int> g1 = GreyNumber<int>(5, 7);
    GreyNumber<int> g2 = GreyNumber<int>(10, 70);
    GreyNumber<int> g3 = g1 - g2;
    REQUIRE(g3.A() == -63);
    REQUIRE(g3.B() == -5);
}

TEST_CASE("OPERATOR UNARY MINUS", "OPERATOR")
{
    GreyNumber<int> g1 = GreyNumber<int>(5, 7);
    GreyNumber<int> g2 = -g1;
    REQUIRE(g2.A() == -7);
    REQUIRE(g2.B() == -5);
}

TEST_CASE("Multiply", "OPERATOR")
{
    GreyNumber<int> g1 = GreyNumber<int>(5, 7);
    GreyNumber<int> g2 = GreyNumber<int>(10, 70);
    GreyNumber<int> g3 = g1 * g2;
    REQUIRE(g3.A() == 50);
    REQUIRE(g3.B() == 490);
}

TEST_CASE("Multiply with scalar", "OPERATOR")
{
    GreyNumber<double> g1 = GreyNumber<double>(3.14, 2.71);
    GreyNumber<double> result = 10.0 * g1;
    REQUIRE(approx(result.B(), 31.4));
    REQUIRE(approx(result.A(), 27.1));

    GreyNumber<double> otherresult = g1 * 10.0;
    REQUIRE(approx(otherresult.B(), 31.4));
    REQUIRE(approx(otherresult.A(), 27.1));
}

TEST_CASE("Division", "OPERATOR")
{
    GreyNumber<double> g1 = GreyNumber<double>(3, 4);
    GreyNumber<double> g2 = GreyNumber<double>(5, 10);
    GreyNumber<double> g3 = g1 / g2;
    REQUIRE(approx(g3.A(), 0.3));
    REQUIRE(approx(g3.B(), 0.8));
}

TEST_CASE("Equals", "OPERATOR")
{
    GreyNumber<double> g1 = GreyNumber<double>(3, 4);
    GreyNumber<double> g2 = GreyNumber<double>(3, 4);
    REQUIRE(g1 == g2);
}

TEST_CASE("Less than", "OPERATOR")
{
    GreyNumber<int> g1 = GreyNumber<int>(1, 4);
    GreyNumber<int> g2 = GreyNumber<int>(1, 5);
    REQUIRE(g1 < g2);

    GreyNumber<int> g3 = GreyNumber<int>(1, 4);
    GreyNumber<int> g4 = GreyNumber<int>(2, 5);
    REQUIRE(g3 < g4);
}

TEST_CASE("Greater than", "OPERATOR")
{
    GreyNumber<int> g1 = GreyNumber<int>(1, 4);
    GreyNumber<int> g2 = GreyNumber<int>(1, 5);
    REQUIRE(g2 > g1);

    GreyNumber<int> g3 = GreyNumber<int>(1, 4);
    GreyNumber<int> g4 = GreyNumber<int>(2, 5);
    REQUIRE(g4 > g3);
}

TEST_CASE("Less than or equal", "OPERATOR")
{
    GreyNumber<int> g1 = GreyNumber<int>(1, 4);
    GreyNumber<int> g2 = GreyNumber<int>(1, 5);
    REQUIRE(g1 <= g2);

    GreyNumber<int> g3 = GreyNumber<int>(1, 4);
    GreyNumber<int> g4 = GreyNumber<int>(2, 5);
    REQUIRE(g3 <= g4);
}

TEST_CASE("Greater than or equal", "OPERATOR")
{
    GreyNumber<int> g1 = GreyNumber<int>(1, 4);
    GreyNumber<int> g2 = GreyNumber<int>(1, 5);
    REQUIRE(g2 >= g1);

    GreyNumber<int> g3 = GreyNumber<int>(1, 4);
    GreyNumber<int> g4 = GreyNumber<int>(2, 5);
    REQUIRE(g4 >= g3);
}

TEST_CASE("Square root", "MATH"){
    GreyNumber<int> g = GreyNumber<int>(100, 64);
    GreyNumber<double> result = sqrt(g);

    REQUIRE(approx(result.A(), 8.0));
    REQUIRE(approx(result.B(), 10.0));
}

TEST_CASE("Power", "MATH"){
    GreyNumber<int> g = GreyNumber<int>(100, 64);
    GreyNumber<double> result = pow(g, 0.5);

    REQUIRE(approx(result.A(), 8.0));
    REQUIRE(approx(result.B(), 10.0));
}

TEST_CASE("Representation", "TOSTRING"){
    GreyNumber<int> g = GreyNumber<int>(10, 20);
    std::ostringstream os;
    os << g;
    std::string s = os.str();
    REQUIRE(s == "GreyNumber(10, 20)");
}



int main(int argc, char *argv[])
{
    // your setup ...

    int result = Catch::Session().run(argc, argv);

    // your clean-up...

    return result;
}
