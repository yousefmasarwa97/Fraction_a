#include "doctest.h"
#include "sources/Fraction.hpp"
#include <cstdlib>
using namespace ariel;


TEST_CASE("check constructor")
{
    CHECK_NOTHROW(Fraction(5, 4));
    CHECK_THROWS(Fraction(0));
    CHECK_NOTHROW(Fraction(5432.3251342));
    
}

TEST_CASE("DIVIDE BY ZERO"){
    CHECK_THROWS(Fraction(15,0));
    CHECK_THROWS(Fraction(2,0));
    CHECK_THROWS(Fraction(4,0));

}

TEST_CASE("CHEK THE REDUCE FUNCTION"){
    Fraction a(12,6);
    a.reduce();
    Fraction b(2,1);
    CHECK(b==a);

    Fraction c(3.333333333);
    a.reduce();
    Fraction d(60,45);
    d.reduce();
    CHECK(c==d);


    Fraction e(232,1060);
    e.reduce();
    Fraction f(58,265);
    CHECK(e==f);


}


TEST_CASE("CHECK IF THE OPERATORES WORK PROPERLY")
{
    for (int i = 1; i < 1000; i++)
    {
        Fraction a(i*1,i*2),b(i*3,i*4);
        CHECK_NOTHROW(a + b);
        CHECK_NOTHROW(a - b);
        CHECK_NOTHROW(a * b);
        CHECK_NOTHROW(a / b);
        CHECK_NOTHROW(a++);
        CHECK_NOTHROW(++a);
        CHECK_NOTHROW(b++);
        CHECK_NOTHROW(++b);
        CHECK_NOTHROW(a--);
        CHECK_NOTHROW(--a);
        CHECK_NOTHROW(b--);
        CHECK_NOTHROW(--b);
        CHECK(a<=1);
        CHECK(b<=1);
        CHECK(a<1);
        CHECK(b<1);
        CHECK(a>b);


        Fraction c(15.459272342), d(567.2314955);
        CHECK_NOTHROW(c + d);
        CHECK_NOTHROW(c - d);
        CHECK_NOTHROW(c * d);
        CHECK_NOTHROW(c / d);
        CHECK_NOTHROW(c++);
        CHECK_NOTHROW(++c);
        CHECK_NOTHROW(d++);
        CHECK_NOTHROW(++d);
        CHECK_NOTHROW(c--);
        CHECK_NOTHROW(--c);
        CHECK_NOTHROW(d--);
        CHECK_NOTHROW(--d);
        CHECK(c<=1);
        CHECK(d<=1);
        CHECK(c<1);
        CHECK(d<1);
        CHECK(c>d);
    }

}
TEST_CASE("negtive number"){
    for(int i=1;i<100;i++){

        int numerator1=rand();
        int denominator1=rand();

        int numerator2=rand();
        int denominator2=rand();

        Fraction a(numerator1,denominator1),b(numerator2,denominator2);
        b=Fraction(-1,1)*b;
        CHECK_NOTHROW(Fraction a(numerator1,denominator1));
        CHECK_NOTHROW(Fraction b(numerator2,denominator2));

        CHECK(b<1);
        CHECK(a>b);
        CHECK(b<=-1);
        
        
        CHECK_NOTHROW(a + b);
        CHECK_NOTHROW(a - b);
        CHECK_NOTHROW(a / b);
        CHECK_NOTHROW(a++);
        CHECK_NOTHROW(++a);
        CHECK_NOTHROW(b++);
        CHECK_NOTHROW(++b);
        CHECK_NOTHROW(a--);
        CHECK_NOTHROW(--a);
        CHECK_NOTHROW(b--);
        CHECK_NOTHROW(--b);

    
    }
}
