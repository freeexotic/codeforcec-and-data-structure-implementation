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
       a.Set(17, 1);
       a.Set(0, 1);
       a.Set(37, 1);
       a.Set(32, 1);
       a.Set(37, 1);
       a.Set(32, 1);
       BitSet b = a;
       a.Set(37, 0);
       a.Set(32, 0);
       CHECK(b.Value(0) == 131073);
       CHECK(b.Value(1) == 0);
       CHECK(a.Value(1) == 33);



   }



   SUBCASE("Equality"){
       BitSet a(4);
       a.Fill(false);
       BitSet b(4);
       b.Fill(false);
       CHECK(a == b);
       a.Fill(true);
       CHECK(a != b);
   }
}
