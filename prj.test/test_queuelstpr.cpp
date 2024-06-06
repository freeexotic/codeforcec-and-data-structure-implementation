#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include <queuelstpr/queuelstpr.hpp>




TEST_CASE("cons") {

    SUBCASE("copy, pop, push, top") {
        QueueLstPr a;
        CHECK(a.IsEmpty() == true);
        a.Push(20.0);
        CHECK(a.Top() == 20.0);
        a.Push(1.0);
        CHECK(a.Top() == 1.0);
        a.Push(3.0);
        CHECK(a.Top() == 1.0);

    }
}