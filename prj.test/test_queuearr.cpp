#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include <queuearr/queuearr.hpp>

TEST_CASE("cons") {
  SUBCASE("default") {
    QueueArr a;
    CHECK_THROWS(a.IsEmpty() == true);
  }
  SUBCASE("copy") {
    QueueArr a;
    for (int i = 0; i < 500; ++i)
      a.Push(Complex(i, i));

    QueueArr b(a);
    CHECK(b.Top() == a.Top());

    b.Push(Complex(101, 101));
    CHECK(b.Top() == Complex(101,101));
    CHECK(a.Top() == b.Top());
    b.Pop();
    CHECK(b.Top() != a.Top());
  }
}

TEST_CASE("Clear") {
    SUBCASE("appr with empty") {
        QueueArr a;
        QueueArr b;
        for (int i = 1; i < 5; ++i)
            b.Push(Complex(i, i));
        a = b;
        CHECK(b.Top() == a.Top());

        b.Pop();
        CHECK(b.Top() != a.Top());
        CHECK(a.IsEmpty() != true);
        a.Clear();
        CHECK(a.IsEmpty() == true);
        CHECK(b.IsEmpty() != true);
    }
}
TEST_CASE("Push, Pop & Top"){
  QueueArr a;
  for (int i = 0; i < 1000; ++i)
  {
    a.Push(Complex(i, i));
  }

  for (int i = 1; i < 1000; ++i)
  {
    a.Pop();
    CHECK(a.Top() == Complex(i, i));
  }
  a.Pop();
  CHECK_THROWS(a.Top());
}

TEST_CASE("Run around") {
  QueueArr a;
  for (int i = 0; i < 9; ++i)
    a.Push(Complex(1, i));
  for (int i = 0; i < 5; ++i)
    a.Pop();
  for (int i = 0; i < 4; ++i)
    a.Push(Complex(1, i));

  QueueArr b(a);
  QueueArr c;
  c = a;

  while (!a.IsEmpty())
  {
    CHECK(a.Top() == b.Top());
    CHECK(b.Top() == c.Top());
    a.Pop();
    b.Pop();
    c.Pop();
  }
}