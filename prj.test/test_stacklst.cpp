
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include <stacklst/stacklst.hpp>
#include <complex/complex.hpp>

#include <cstdint>

TEST_CASE("cons") {
    SUBCASE("copy") {
    StackLst a;
    for (int i = 0; i < 500; i++) {
        a.Push(Complex(i, i));
    }
    StackLst b(a);
    CHECK(a.Top() == b.Top());
    b.Pop();
    CHECK(a.Top() != b.Top());
    }
}

TEST_CASE("appr") {
    SUBCASE("copy") {
        StackLst a;
        StackLst b;
        for (int i = 0; i < 5; ++i) {
            b.Push(Complex(i,i));
        }
        CHECK(a.IsEmpty() == true);
        a = b;
        CHECK(a.IsEmpty() == false);
    }
    SUBCASE("Clear") {
        StackLst a;
        StackLst b;
        for (int i = 0; i < 5; ++i)
        {
            a.Push(Complex(i,i));
            b.Push(Complex());
        }
        CHECK(a.IsEmpty() == false);
        CHECK(b.IsEmpty() == false);
        a.Clear();
        CHECK(a.IsEmpty() == true);
        CHECK(b.IsEmpty() == false);
    }
}
TEST_CASE("throw") {
    SUBCASE("throw") {
        StackLst a;
        CHECK_THROWS(a.Top());
    }
}
