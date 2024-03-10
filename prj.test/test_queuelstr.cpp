#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include <queuelstr/queuelstr.hpp>


TEST_CASE("cons") {
    SUBCASE("default") {
        QueueLstR a;
        CHECK(a.Size() == 0);
    }
    SUBCASE("copy") {
        QueueLstR a;
        for (int i = 0; i < 500; ++i)
            a.Push(1.0);

        QueueLstR b(a);
        CHECK(b.Size() == 500);

        b.Push(2.5);
        CHECK(b.Size() == 501);
        CHECK(a.Size() == 500);

        b.Pop();
        CHECK(b.Size() == 500);
        CHECK(a.Size() == 500);
    }
}

TEST_CASE("first test") {
    SUBCASE("default") {
        QueueLstR a;
        float b = 2.5;
        a.Push(b);

        CHECK(a.Top() == b );
        float c = 3.5;
        a.Push(c);
        CHECK(a.Top() == c);
        a.Pop();
        CHECK(a.Top() == b );
    }
}

