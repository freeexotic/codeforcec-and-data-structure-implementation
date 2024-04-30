#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include <stackarr/stackarr.hpp>
#include <complex/complex.hpp>

TEST_CASE("cons") {

  SUBCASE("copy") {
    StackArr a;
    for (int i = 0; i < 500; i++)
      a.Push(Complex(i, i));

    StackArr b(a);
    CHECK(a.Top() == b.Top());
    b.Pop();
    CHECK(a.Top() != b.Top());
  }
}

TEST_CASE("appr") {
  SUBCASE("appr with empty") {
    StackArr a;
    StackArr b;
    for (int i = 0; i < 5; ++i) {
        b.Push(Complex(i, i));
    }
    a = b;
    CHECK(a.Top() == b.Top());

    b.Push(Complex(11,11));
    CHECK(b.Top() == Complex(11,11));

  }
  SUBCASE("Clear") {
    StackArr a;
    StackArr b;
    for (int i = 0; i < 5; ++i)
    {
      a.Push(Complex(i,i));
      b.Push(Complex(i,i));
    }
    CHECK(a.Top() == Complex(4,4));
    CHECK(a.IsEmpty() == false);
    a.Clear();
    CHECK(a.IsEmpty() == true);
    CHECK_THROWS(a.Top());
    CHECK(b.IsEmpty() == false);
    b = a;
    CHECK(b.IsEmpty() == true);
  }
}
