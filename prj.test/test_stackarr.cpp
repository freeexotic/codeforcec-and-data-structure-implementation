#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include <stackarr/stackarr.hpp>
#include <complex/complex.hpp>

TEST_CASE("cons") {

  SUBCASE("copy") {
    StackArr a;
    for (int i = 0; i < 500; i++)
      a.Push(Complex());

    StackArr b(a);
    CHECK(b.Size() == 500);
    
    b.Push(Complex());
    CHECK(b.Size() == 501);
    CHECK(a.Size() == 500);
    CHECK(a.Capacity() == 512);
  }
}

TEST_CASE("appr") {
  SUBCASE("appr with empty") {
    StackArr a;
    StackArr b;
    for (int i = 0; i < 5; ++i)
      b.Push(Complex());
    a = b;
    CHECK(a.Size() == 5);

    b.Push(Complex());
    CHECK(b.Size() == 6);
    CHECK(a.Size() == 5);
  }
  SUBCASE("appr with full") {
    StackArr a;
    StackArr b;
    for (int i = 0; i < 5; ++i)
    {
      a.Push(Complex());
      b.Push(Complex());
    }
    a = b;
    CHECK(a.Size() == 5);

    b.Push(Complex());
    CHECK(b.Size() == 6);
    CHECK(a.Size() == 5);
  }
}

TEST_CASE("Push, Pop & Top"){
  StackArr a;
  CHECK(a.Size() == 0);
  for (int i = 0; i < 1000; ++i)
  {
    a.Push(Complex(i, i));
    CHECK(a.Size() == i + 1);
    CHECK(a.Top() == Complex(i,i)); //?
  }

  for (int i = 998; i >= 0; --i)
  {
    a.Pop();
    CHECK(a.Size() == i + 1);
    CHECK(a.Top() == Complex(i, i));
  }
  a.Pop();
  CHECK_THROWS(a.Top(), "123");
  a.Pop();
}