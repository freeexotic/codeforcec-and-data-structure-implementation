//
// Created by Всеволод Силаев on 15.04.2024.
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include <stacklstt/stacklstt.hpp>
#include <complex/complex.hpp>

#include <cstdint>


TEST_CASE("cons") {
    SUBCASE("copy") {
        StackLstT<int> a;
        for (int i = 0; i < 500; i++)
            a.Push(i);
        StackLstT<int> b = a;
        b.Push(123);
        CHECK(a.Top() == 490);
    }
}

TEST_CASE("appr") {
    SUBCASE("appr with empty") {
        StackLstT<Complex> a;
        StackLstT<Complex> b;
        for (int i = 0; i < 5; ++i)
            b.Push(Complex());
        a = b;

        b.Push(Complex());
    }
    SUBCASE("appr with full") {
        StackLstT<Complex> a;
        StackLstT<Complex> b;
        for (int i = 0; i < 5; ++i)
        {
            a.Push(Complex());
            b.Push(Complex());
        }
        a = b;
        b.Push(Complex(1, 4));
        CHECK(b.Top() == Complex(1,4));
    }
}

TEST_CASE("Push, Pop & Top"){
    StackLstT<Complex> a;
    for (int i = 0; i < 1000; ++i)
    {
        a.Push(Complex(i, i));
        CHECK(a.Top() == Complex(i,i)); //?
    }

    for (int i = 998; i >= 0; --i)
    {
        a.Pop();
        CHECK(a.Top() == Complex(i, i));
    }
    a.Pop();
    CHECK_THROWS(a.Top(), "123");
    a.Pop();
}
