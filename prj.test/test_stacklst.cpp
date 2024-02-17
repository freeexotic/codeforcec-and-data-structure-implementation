
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include <stacklst/stacklst.hpp>
#include <complex/complex.hpp>

#include <cstdint>

TEST_CASE("Check operations"){
    SUBCASE("Initialize stacklst"){
        StackLst a;
        for (int i = 0; i < 500; ++i)
            a.Push(Complex());
        StackLst b(a);
        CHECK(b.IsEmpty() == 0);
    }
} 
