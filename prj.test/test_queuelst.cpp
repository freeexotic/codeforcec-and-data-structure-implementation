#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include <queuelst/queuelst.hpp>
#include <complex/complex.hpp>


TEST_CASE("cons") {

    SUBCASE("copy, pop, push, top") {
        QueueLst a;
        for (int i = 0; i < 500; i++) {
            a.Push(Complex(i, i));
        }

        QueueLst b(a);
        CHECK(b.Top() == Complex(0,0));

        a.Push(Complex(13,114));
        b.Pop();
        CHECK(b.Top() == Complex(1,1));
        a.Pop();
        CHECK(a.Top() == Complex(1,1));
        for (int i = 0; i < 499; i++) {
            a.Pop();
        }
        CHECK(a.Top() == Complex(13,114));
    }
}

TEST_CASE("clear") {
    SUBCASE("clear") {
        QueueLst a;
        for (int i = 0; i < 500; i++){
            a.Push(Complex(i,i));
        }
        a.Pop();
        CHECK(a.Top() == Complex(1,1));
        CHECK(a.IsEmpty() != true);
        a.Clear();
        CHECK(a.IsEmpty() == true);
    }
}