#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include <queue/queue.hpp>
#include <complex/complex.hpp>


TEST_CASE("cons") {

    SUBCASE("copy") {
        Queue a;
        for (int i = 0; i < 500; i++)
            a.Push(Complex());

        Queue b(a);
        CHECK(b.Size() == 500);

        b.Push(Complex());
        CHECK(b.Size() == 501);
        CHECK(a.Size() == 500);
    }
}

TEST_CASE("pop") {

    SUBCASE("pop") {
        Queue a;
        for (int i = 0; i < 500; i++)
            a.Push(Complex());

        Queue b(a);
        CHECK(b.Size() == 500);

        for(int i = 0 ; i != 500 ; ++i){
            b.Pop();
        }
        CHECK(a.Size() == 500);
        CHECK(b.Size() == 0);
    }
}