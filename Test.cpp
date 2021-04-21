/**
 * AUTHOR: liel berniker
 * 
 */
#include <sstream>
#include "doctest.h"
#include "NumberWithUnits.hpp"
#include <string>
#include <stdlib.h>
#include <ctime>
using ariel::NumberWithUnits;

const unsigned int ZERO = 0, ONE = 1, TWO = 2, THEREE = 3, FOUR = 4, FIVE = 5;
const unsigned int SIX = 6, SEVEN = 7, EIGHT = 8, NINE = 9, TEN = 10;
const unsigned int RAND_FOR = 4294967270, HOUNDRED = 100;
const std::vector<std::string> arr{"mom", "dad", "grandad", "grandmom", "aunt", "uncle", "cousin", "son", "daughter", "__________"};

TEST_CASE("good + method tests")
{
    int i = 0;
    NumberWithUnits a{2, "km"}, b{11, "km"}, c{9, "km"}, d{1, "km"};
    CHECK_FALSE(a == (b + c));
    CHECK_FALSE((a + b) == c);
    CHECK_FALSE((c + d) == b);
    CHECK((a + c) == b);
    for (i = 1; i < TEN; i++)
    {
        NumberWithUnits e{i, "km"};
        CHECK_FALSE((d + e) == b);
    }
    NumberWithUnits e{i, "km"};
    CHECK((d + e) == b);
    CHECK((d + c + a) == (b + d));
}

TEST_CASE("good - method tests")
{
    int i = 0;
    NumberWithUnits a{2, "km"}, b{11, "km"}, c{9, "km"}, d{1, "km"};
    CHECK_FALSE(a == (b - d));
    CHECK_FALSE((a - b) == c);
    CHECK_FALSE((c - d) == b);
    CHECK(c == (b - a));
    for (i = 11; i > THEREE; i--)
    {
        NumberWithUnits e{i, "km"};
        CHECK_FALSE((e - d) == a);
    }
    NumberWithUnits e{i, "km"};
    CHECK((e - d) == a);
}
TEST_CASE("good += method tests")
{
    int i = 0;
    NumberWithUnits a{2, "km"}, b{11, "km"}, c{9, "km"}, d{1, "km"}, e{1, "km"}, f{1, "km"};
    CHECK_FALSE(a == (d += c)); //a = 2 , d = 10
    CHECK((a += c) == b);       // a= 11 , b= 11
    for (i = 1; i < TEN; i++)
    {
        CHECK_FALSE((e += f) == b);
    }
    CHECK((e += f) == b); // e = 11
}
TEST_CASE("good -= method tests")
{
    int i = 0;
    NumberWithUnits a{2, "km"}, b{11, "km"}, c{9, "km"}, d{1, "km"}, e{1, "km"}, f{1, "km"};
    CHECK_FALSE((c -= a) == d); //c = 7, d = 1
    CHECK((a -= f) == e);       // a= 1, e =1
    for (i = 1; i < TEN; i++)
    {
        CHECK_FALSE((b -= f) == e);
    }
    CHECK((b -= f) == e); // b = 1
}
TEST_CASE("good ++ before number ,method tests")
{
    int i = 0;
    NumberWithUnits a{2, "km"}, b{11, "km"}, c{9, "km"}, d{1, "km"}, e{1, "km"};
    CHECK_FALSE(a == ++c); // c= 10
    CHECK(a == ++d);       // d = 2
    for (i = 1; i < TEN; i++)
    {
        CHECK_FALSE(++e == b);
    }
    CHECK(++e == b); // e =11
    ++b;
    CHECK(++(++c) == b); // c = 12
}
TEST_CASE("good ++ after number ,method tests")
{
    int i = 0;
    NumberWithUnits a{2, "km"}, b{11, "km"}, c{9, "km"}, d{1, "km"}, e{1, "km"};
    CHECK_FALSE(a == c++); //c = 10 after
    CHECK_FALSE(a == d++); // d = 2 after
    CHECK(a == d);         // d = 2
    for (i = 1; i < TEN; i++)
    {
        CHECK_FALSE(e++ == b);
    }
    CHECK_FALSE(e++ == b); // e = 11 after
    CHECK(e == b);         // e = 11
    b++;
    CHECK_FALSE((c++)++ == b);
    CHECK(c == b);
}
TEST_CASE("good -- before number ,method tests")
{
    int i = 0;
    NumberWithUnits a{2, "km"}, b{11, "km"}, c{9, "km"}, d{1, "km"}, e{1, "km"}, f{6, "km"};
    CHECK_FALSE(a == --c); // c= 8
    CHECK(--a == d);       // a = 1
    for (i = 1; i < TEN; i++)
    {
        CHECK_FALSE(e == --b);
    }
    CHECK(e == --b); // e =1
    ++b;
    CHECK(--(--c) == f); // c = 6
}
TEST_CASE("good -- after number ,method tests")
{
    int i = 0;
    NumberWithUnits a{2, "km"}, b{11, "km"}, c{9, "km"}, d{1, "km"}, e{1, "km"}, f{6, "km"};
    CHECK_FALSE(a == c--); //c = 8 after
    CHECK_FALSE(a-- == d); // a = 1 after
    CHECK(a == d);         // a = 1
    for (i = 1; i < TEN; i++)
    {
        CHECK_FALSE(b-- == e);
    }
    CHECK_FALSE(e == b--); // b = 1 after
    CHECK(e == b);         // b = 1
    b++;
    CHECK_FALSE((c--)-- == f); // c = 6 after
    CHECK(c == f);
}
TEST_CASE("good * ,num_u and double,method tests")
{
    int i = 0;
    double x = 3.0, y = 4.0, z = 9.0;
    NumberWithUnits a{2, "km"}, b{12, "km"}, c{9, "km"}, d{1, "km"}, e{3, "km"}, f{6, "km"}, g{27, "km"}, k{1, "km"};
    CHECK_FALSE(f * z == b);
    CHECK_FALSE(a * y == e);
    CHECK(e * y == b);
    for (i = 1; i < THEREE; i++)
    {
        CHECK_FALSE(d * x == g);
        d = d * x;
    }
    CHECK(d * x == g); //d = 9
}
TEST_CASE("good * , double and num_u ,method tests")
{
    int i = 0;
    double x = 3.0, y = 4.0, z = 9.0;
    NumberWithUnits a{2, "km"}, b{12, "km"}, c{9, "km"}, d{1, "km"}, e{3, "km"}, f{6, "km"}, g{27, "km"}, k{1, "km"};
    CHECK_FALSE(z * f == b);
    CHECK_FALSE(y * a == e);
    CHECK(y * e == b);
    for (i = 1; i < THEREE; i++)
    {
        CHECK_FALSE(x * d == g);
        d = x * d;
    }
    CHECK(x * d == g); //d = 9
}
TEST_CASE("good < method tests")
{
    int i = 0;
    NumberWithUnits a{2, "km"}, b{11, "km"}, c{9, "km"}, d{1, "km"}, e{1, "km"}, f{1, "km"};
    CHECK_FALSE(c < a);
    CHECK_FALSE(a < d);
    CHECK(d < a);
    for (i = 0; i < TEN; i++)
    {
        CHECK_FALSE(b < e);
        e++;
    }
    e++; // e = 12 after
    CHECK_FALSE(e < b);
    CHECK(b < e);
    CHECK(d < e);
    CHECK_FALSE(f < d);
}
TEST_CASE("good > method tests")
{
    int i = 0;
    NumberWithUnits a{2, "km"}, b{11, "km"}, c{9, "km"}, d{1, "km"}, e{1, "km"}, f{1, "km"};
    CHECK_FALSE(a > c);
    CHECK_FALSE(d > a);
    CHECK(a > d);
    for (i = 0; i < TEN; i++)
    {
        CHECK_FALSE(e > b);
        e++;
    }
    e++; // e = 12 after
    CHECK_FALSE(b > e);
    CHECK(e > b);
    CHECK(e > d);
    CHECK_FALSE(f < d);
}
TEST_CASE("good <= method tests")
{
    int i = 0;
    NumberWithUnits a{2, "km"}, b{11, "km"}, c{9, "km"}, d{1, "km"}, e{1, "km"}, f{1, "km"};
    CHECK_FALSE(c <= a);
    CHECK_FALSE(a <= d);
    CHECK(d <= a);
    for (i = 1; i < TEN; i++)
    {
        CHECK_FALSE(b <= e);
        e++;
    }
    e++; // e = 11 after
    CHECK(b <= e);
    CHECK(e <= b);
    CHECK(d <= e);
    CHECK(f <= d);
}
TEST_CASE("good >= method tests")
{
    int i = 0;
    NumberWithUnits a{2, "km"}, b{11, "km"}, c{9, "km"}, d{1, "km"}, e{1, "km"}, f{1, "km"};
    CHECK_FALSE(a >= c);
    CHECK_FALSE(d >= a);
    CHECK(a >= d);
    for (i = 1; i < TEN; i++)
    {
        CHECK_FALSE(e >= b);
        e++;
    }
    e++; // e = 11 after
    CHECK(e >= b);
    CHECK(b >= e);
    CHECK(e >= d);
    CHECK(f >= d);
}
TEST_CASE("good == method tests")
{
    int i = 0;
    NumberWithUnits a{2, "km"}, b{11, "km"}, c{9, "km"}, d{1, "km"}, e{1, "km"}, f{1, "km"};
    CHECK_FALSE(a == c);
    CHECK_FALSE(d == a);
    CHECK(e == d);
    for (i = 1; i < TEN; i++)
    {
        CHECK_FALSE(e == b);
        e++;
    }
    e++; // e = 11 after
    CHECK(e == b);
    CHECK(b == e);
    CHECK_FALSE(e == d);
    CHECK(f == d);
}
TEST_CASE("good != method tests")
{
    int i = 0;
    NumberWithUnits a{2, "km"}, b{11, "km"}, c{9, "km"}, d{1, "km"}, e{1, "km"}, f{1, "km"};
    CHECK(a != c);
    CHECK(d != a);
    CHECK_FALSE(e != d);
    for (i = 1; i < TEN; i++)
    {
        CHECK(e != b);
        e++;
    }
    e++; // e = 11 after
    CHECK_FALSE(e != b);
    CHECK_FALSE(b != e);
    CHECK(e != d);
    CHECK_FALSE(f != d);
}
TEST_CASE("good << method and >> method , input and output tests")
{
    std::istringstream input_1{"1 [ kg ]"}, input_2{"8 [ kg ]"};
    std::stringstream output_1;
    int i = 0;
    NumberWithUnits a{2, "km"}, b{11, "km"}, c{9, "km"}, d{1, "km"}, e{1, "km"}, f{1, "km"};
    input_1 >> a; //a = 1
    CHECK_FALSE(a == c);
    CHECK_FALSE(a == b);
    CHECK(a == e);

    input_2 >> f; // f = 8
    CHECK_FALSE(f == c);
    f++; //f=9
    CHECK(f == c);

    output_1 << c;
    CHECK(output_1.str()== "9[kg]");
    CHECK_FALSE(output_1.str() == "1[kg]");
    output_1 << b;
    CHECK(output_1.str() == "11[kg]");
}
TEST_CASE("bad + method tests")
{
    NumberWithUnits a{2, "km"}, b{11, "KM"}, c{9, "g"}, d{1, "mil"},e{10,"km"};
    CHECK_THROWS(a+b);
    CHECK_THROWS(a+c);
    CHECK_THROWS(a+d);
    CHECK_NOTHROW(a+e);
}
TEST_CASE("bad - method tests")
{
    NumberWithUnits a{2, "km"}, b{11, "KM"}, c{9, "g"}, d{1, "mil"},e{10,"km"};
    CHECK_THROWS(a-b);
    CHECK_THROWS(a-c);
    CHECK_THROWS(a-d);
    CHECK_NOTHROW(a-e);
}
TEST_CASE("bad -= method tests")
{
    NumberWithUnits a{2, "km"}, b{11, "KM"}, c{9, "g"}, d{1, "mil"},e{10,"km"};
    CHECK_THROWS(a-=b);
    CHECK_THROWS(a-=c);
    CHECK_THROWS(a-=d);
    CHECK_NOTHROW(a-=e);
}
TEST_CASE("bad += method tests")
{
    NumberWithUnits a{2, "km"}, b{11, "KM"}, c{9, "g"}, d{1, "mil"},e{10,"km"};
    CHECK_THROWS(a+=b);
    CHECK_THROWS(a+=c);
    CHECK_THROWS(a+=d);
    CHECK_NOTHROW(a+=e);
}
TEST_CASE("bad < method tests")
{
    NumberWithUnits a{2, "km"}, b{11, "KM"}, c{9, "g"}, d{1, "mil"},e{10,"km"};
    CHECK_THROWS(if(a<b));
    CHECK_THROWS(if(a<c));
    CHECK_THROWS(if(a<d));
    CHECK_NOTHROW(if(a<e));
}
TEST_CASE("bad <= method tests")
{
    NumberWithUnits a{2, "km"}, b{11, "KM"}, c{9, "g"}, d{1, "mil"},e{10,"km"};
    CHECK_THROWS(if(a<=b));
    CHECK_THROWS(if(a<=c));
    CHECK_THROWS(if(a<=d));
    CHECK_NOTHROW(if(a<=e));
}
TEST_CASE("bad > method tests")
{
    NumberWithUnits a{2, "km"}, b{11, "KM"}, c{9, "g"}, d{1, "mil"},e{10,"km"};
    CHECK_THROWS(if(a>b));
    CHECK_THROWS(if(a>c));
    CHECK_THROWS(if(a>d));
    CHECK_NOTHROW(if(a>e));
}
TEST_CASE("bad <= method tests")
{
    NumberWithUnits a{2, "km"}, b{11, "KM"}, c{9, "g"}, d{1, "mil"},e{10,"km"};
    CHECK_THROWS(if(a<=b));
    CHECK_THROWS(if(a<=c));
    CHECK_THROWS(if(a<=d));
    CHECK_NOTHROW(if(a<=e));
}
TEST_CASE("bad == method tests")
{
    NumberWithUnits a{2, "km"}, b{11, "KM"}, c{9, "g"}, d{1, "mil"},e{10,"km"};
    CHECK_THROWS(if(a==b));
    CHECK_THROWS(if(a==c));
    CHECK_THROWS(if(a==d));
    CHECK_NOTHROW(if(a==e));
}
TEST_CASE("bad != method tests")
{
    NumberWithUnits a{2, "km"}, b{11, "KM"}, c{9, "g"}, d{1, "mil"},e{10,"km"};
    CHECK_THROWS(if(a!=b));
    CHECK_THROWS(if(a!=c));
    CHECK_THROWS(if(a!=d));
    CHECK_NOTHROW(if(a!=e));
}
