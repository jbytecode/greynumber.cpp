#include "./greynumber.hpp"
#include <iostream>
#include <sstream>
#include <cassert>


template <typename T>
bool approx(T a, T b, double eps = 0.000001){
    return std::abs(a - b) < eps;
}

bool testEmptyConstructor(){
    GreyNumber<int> g1 = GreyNumber<int>();
    assert(g1.A() == 0);
    assert(g1.B() == 0);
    return true;
}

bool testSingleConstructor()
{
    GreyNumber<int> g1 = GreyNumber<int>(5);
    assert(g1.A() == 5);
    assert(g1.B() == 5);
    return true;
}

bool testFullConstructor()
{
    GreyNumber<int> g1 = GreyNumber<int>(5, 7);
    assert(g1.A() == 5);
    assert(g1.B() == 7);
    return true;
}

bool testRightOrder(){
    GreyNumber<int> g1 = GreyNumber<int>(10, 1);
    assert(g1.A() == 1);
    assert(g1.B() == 10);
    return true;
}

bool testOperatorPlus()
{
    GreyNumber<int> g1 = GreyNumber<int>(5, 7);
    GreyNumber<int> g2 = GreyNumber<int>(10, 70);
    GreyNumber<int> g3 = g1 + g2;
    assert(g3.A() == 15);
    assert(g3.B() == 77);
    return true;
}

bool testOperatorBinaryMinus()
{
    GreyNumber<int> g1 = GreyNumber<int>(5, 7);
    GreyNumber<int> g2 = GreyNumber<int>(10, 70);
    GreyNumber<int> g3 = g1 - g2;
    assert(g3.A() == -63);
    assert(g3.B() == -5);
    return true;
}

bool testOperatorUnaryMinus()
{
    GreyNumber<int> g1 = GreyNumber<int>(5, 7);
    GreyNumber<int> g2 = -g1;
    assert(g2.A() == -7);
    assert(g2.B() == -5);
    return true;
}

bool testOperatorProduct()
{
    GreyNumber<int> g1 = GreyNumber<int>(5, 7);
    GreyNumber<int> g2 = GreyNumber<int>(10, 70);
    GreyNumber<int> g3 = g1 * g2;
    assert(g3.A() == 50);
    assert(g3.B() == 490);
    return true;
}

bool testOperatorProductWithScalar(){
    GreyNumber<double> g1 = GreyNumber<double>(3.14, 2.71);
    GreyNumber<double> result = 10.0 * g1;
    assert(approx(result.B(), 31.4));
    assert(approx(result.A(), 27.1));

    GreyNumber<double> otherresult = g1 * 10.0;
    assert(approx(otherresult.B(), 31.4));
    assert(approx(otherresult.A(), 27.1));
    return true;
}

bool testOperatorDivide()
{
    GreyNumber<double> g1 = GreyNumber<double>(3, 4);
    GreyNumber<double> g2 = GreyNumber<double>(5, 10);
    GreyNumber<double> g3 = g1 / g2;
    assert(approx(g3.A(), 0.3));
    assert(approx(g3.B(), 0.8));
    return true;
}

bool testOperatorEquals(){
    GreyNumber<double> g1 = GreyNumber<double>(3, 4);
    GreyNumber<double> g2 = GreyNumber<double>(3, 4);
    assert(g1 == g2);
    return true;
}

bool testIndexOperator(){
    GreyNumber<int> g = GreyNumber<int>(1, 4);
    assert(g[0] == 1);
    assert(g[1] == 4);
    return true;
}

bool testLessOperator(){
    GreyNumber<int> g1 = GreyNumber<int>(1, 4);
    GreyNumber<int> g2 = GreyNumber<int>(1, 5);
    assert(g1 < g2);

    GreyNumber<int> g3 = GreyNumber<int>(1, 4);
    GreyNumber<int> g4 = GreyNumber<int>(2, 5);
    assert(g3 < g4);
    return true;
}

bool testGreaterOperator()
{
    GreyNumber<int> g1 = GreyNumber<int>(1, 4);
    GreyNumber<int> g2 = GreyNumber<int>(1, 5);
    assert(g2 > g1);

    GreyNumber<int> g3 = GreyNumber<int>(1, 4);
    GreyNumber<int> g4 = GreyNumber<int>(2, 5);
    assert(g4 > g3);
    return true;
}

bool testLessOrEqualOperator()
{
    GreyNumber<int> g1 = GreyNumber<int>(1, 4);
    GreyNumber<int> g2 = GreyNumber<int>(1, 5);
    assert(g1 <= g2);

    GreyNumber<int> g3 = GreyNumber<int>(1, 4);
    GreyNumber<int> g4 = GreyNumber<int>(2, 5);
    assert(g3 <= g4);
    return true;
}

bool testGreaterOrEqualOperator()
{
    GreyNumber<int> g1 = GreyNumber<int>(1, 4);
    GreyNumber<int> g2 = GreyNumber<int>(1, 5);
    assert(g2 >= g1);

    GreyNumber<int> g3 = GreyNumber<int>(1, 4);
    GreyNumber<int> g4 = GreyNumber<int>(2, 5);
    assert(g4 >= g3);
    return true;
}

bool testSqrt(){
    GreyNumber<int> g = GreyNumber<int>(100, 64);
    GreyNumber<double> result = sqrt(g);

    assert(approx(result.A(), 8.0));
    assert(approx(result.B(), 10.0));
    return true;
}

bool testPower()
{
    GreyNumber<int> g = GreyNumber<int>(100, 64);
    GreyNumber<double> result = pow(g, 0.5);

    assert(approx(result.A(), 8.0));
    assert(approx(result.B(), 10.0));
    return true;
}

bool testRepresentation(){
    GreyNumber<int> g = GreyNumber<int>(10, 20);
    std::ostringstream os;
    os << g;
    std::string s = os.str();
    assert(s == "GreyNumber(10, 20)");
    return true;
}

int main(){
    std::cout << "Empyty Constructor: " << testEmptyConstructor() << std::endl;
    std::cout << "Single Constructor: " << testSingleConstructor() << std::endl;
    std::cout << "Full Constructor: " << testFullConstructor() << std::endl;
    std::cout << "Test Right Order:" << testRightOrder() << std::endl;
    std::cout << "Operator Plus: " << testOperatorPlus() << std::endl;
    std::cout << "Operator Binary Minus: " << testOperatorBinaryMinus() << std::endl;
    std::cout << "Operator Unary Minus:" << testOperatorUnaryMinus() << std::endl;
    std::cout << "Operator Product: " << testOperatorProduct() << std::endl;
    std::cout << "Operator Product with Scalar: " << testOperatorProductWithScalar() << std::endl;
    std::cout << "Operator Divide: " << testOperatorDivide() << std::endl;
    std::cout << "Equals: " << testOperatorEquals() << std::endl;
    std::cout << "Index: " << testIndexOperator() << std::endl;
    std::cout << "Less than: " << testLessOperator() << std::endl;
    std::cout << "Greater than: " << testGreaterOperator() << std::endl;
    std::cout << "Less than or equal: " << testLessOrEqualOperator() << std::endl;
    std::cout << "Greater than or equal: " << testGreaterOrEqualOperator() << std::endl;
    std::cout << "Sqrt: " << testSqrt() << std::endl;
    std::cout << "Power: " << testPower() << std::endl;
    std::cout << "Print into stream: " << testRepresentation() << std::endl;
    return 0;
}

