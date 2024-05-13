//
// Created by Всеволод Силаев on 15.04.2024.
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include <stacklstt/stacklstt.hpp>
#include <complex/complex.hpp>

#include <cstdint>
#include <string>

#define TYPES int, double, std::string

TEST_CASE_TEMPLATE_DEFINE("[stackarrt] - ctor", T, test_ctor) {
    SUBCASE("copy") {
        StackLstT<int> a;
        for (int i = 0; i < 500; i++)
            a.Push(i);
        StackLstT<int> b = a;
        b.Push(123);
        CHECK(a.Top() == 490);
    }
}

TEST_CASE_TEMPLATE_DEFINE("[stacklstt] - LIFO", T, test_lifo) {
    SUBCASE("appr with empty") {
        StackLstT<int> a;
        StackLstT<int> b;
        for (int i = 0; i < 5; ++i)
            b.Push(i);
        a = b;

        b.Push(1);
    }
    SUBCASE("appr with full") {
        StackLstT<int> a;
        StackLstT<int> b;
        for (int i = 0; i < 5; ++i)
        {
            a.Push(i);
            b.Push(i);
        }
        a = b;
        b.Push(5);
        CHECK(b.Top() == 5);
    }
}

/*TEST_CASE("Push, Pop & Top"){
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
*/
TEST_CASE_TEMPLATE_INVOKE(test_ctor, TYPES);
TEST_CASE_TEMPLATE_INVOKE(test_lifo, TYPES);