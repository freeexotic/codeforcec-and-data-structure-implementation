#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include <queuelst/queuelst.hpp>
#include <complex/complex.hpp>


TEST_CASE("cons") {

    SUBCASE("copy") {
        QueueLst a;
        for (int i = 0; i < 500; i++)
            a.Push(Complex());

        QueueLst b(a);
        CHECK(b.Size() == 500);

        b.Push(Complex());
        CHECK(b.Size() == 501);
        CHECK(a.Size() == 500);
    }
}

TEST_CASE("pop") {

    SUBCASE("pop") {
        QueueLst a;
        for (int i = 0; i < 500; i++){
            a.Push(Complex(i,i));
        }


        QueueLst b(a);
        CHECK(b.Size() == 500);

        for(int i = 0 ; i != 500 ; ++i){
            b.Pop();
        }
        CHECK(a.Size() == 500);
        CHECK(b.Size() == 0);
    }
}