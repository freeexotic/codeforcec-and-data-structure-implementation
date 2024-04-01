//
// Created by Всеволод Силаев on 25.03.2024.
//
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include <bitset/bitset.hpp>


TEST_CASE("Create") {
   SUBCASE("default") {
       BitSet a;
       CHECK(a.Size() == 0);
       BitSet b(10);
       CHECK(b.Size() == 10);
       b.Resize(7);
       CHECK(b.Size() == 7);
       b.Fill(1);
       CHECK(b.Value(2) == 4294967295);
       b.Fill(0);
       CHECK(b.Value(2) == 0);
   }

   SUBCASE("SET/GET"){
       BitSet a(2);
       a.Fill(0);
       a.Set(1, 1);
       a.Set(2, 1);
       a.Set(0,1);
       CHECK(a.Value(0) == 7);
       CHECK(a.Get(2) == 1);
       CHECK(a.Get(4) == 0);

       a.Set(32, 1);
       a.Set(33, 1);
       CHECK(a.Value(1) == 3);

   }
}