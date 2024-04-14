//
// Created by Всеволод Силаев on 08.04.2024.
//
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include <stackarrt/stackarrt.hpp>
#include <complex/complex.hpp>
#include <string>

using StackArr = StackArrT<Complex>;
TEST_CASE("cons") {

    SUBCASE("copy") {
        StackArrT<int> a;
        for (int i = 0; i < 500; i++)
            a.Push(i);

        StackArrT b(a);
        CHECK(a.Size() == 512);
        CHECK(b.Size() == 512);

        for (int i = 0; i < 250; i++)
            a.Pop();

        CHECK(a.Size() == 512);
        CHECK(a.Top() == 249);
        CHECK(b.Top() == 499 );


    }
}

TEST_CASE("atr") {

    SUBCASE("copy") {
        StackArrT<std::string> a;
        for (int i = 0; i < 500; i++)
            a.Push("test");

        StackArrT b(a);
        CHECK(a.Size() == 512);
        CHECK(b.Size() == 512);

        for (int i = 0; i < 250; i++)
            a.Pop();

        CHECK(a.Size() == 512);
        CHECK(a.Top() == "test");
        CHECK(b.Top() == "test" );


    }
}