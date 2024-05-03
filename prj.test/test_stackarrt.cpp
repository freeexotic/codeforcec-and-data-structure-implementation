#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN


#include "utils.hpp"
#include "doctest.h"
#include <stackarrt/stackarrt.hpp>
#include <complex/complex.hpp>
#include <string>

#define TYPES int, double, std::string

TEST_CASE_TEMPLATE_DEFINE("[stackarrt] - ctor", T, test_ctor) {

    SUBCASE("copy") {
        StackArrT<double> a;
        for (int i = 0; i < 500; i++) {
            a.Push(i);
        }
        StackArrT<double> b(a);
        CHECK(a.Top() == b.Top());
        b.Pop();
        CHECK(a.Top() != b.Top());
    }
    SUBCASE("copy") {
        StackArrT<std::string> a;
        for (int i = 0; i < 500; i++) {
            a.Push(std::to_string(i));
        }
        StackArrT<std::string> b(a);
        CHECK(a.Top() == b.Top());
        b.Pop();
        CHECK(a.Top() != b.Top());
    }
}

TEST_CASE_TEMPLATE_DEFINE("[stacklstt] - LIFO", T, test_lifo) {
    SUBCASE("appr with empty") {
        StackArrT<double> a;
        StackArrT<double> b;
        for (int i = 0; i < 5; ++i) {
            b.Push(i);
        }
        a = b;
        CHECK(a.Top() == b.Top());

        b.Push(1.2);
        CHECK(b.Top() == 1.2);

    }
    SUBCASE("appr with empty") {
        StackArrT<std::string> a;
        StackArrT<std::string> b;
        for (int i = 0; i < 5; ++i) {
            b.Push(std::to_string(i));
        }
        a = b;
        CHECK(a.Top() == b.Top());

        b.Push("test");
        CHECK(b.Top() == "test");

    }
    SUBCASE("Clear") {
        StackArrT<double> a;
        StackArrT<double> b;
        for (int i = 0; i < 5; ++i)
        {
            a.Push(i);
            b.Push(i);
        }
        CHECK(a.Top() == 4);
        CHECK(a.IsEmpty() == false);
        a.Clear();
        CHECK(a.IsEmpty() == true);
       // CHECK_THROWS(a.Top()); TODO: почему не работает чек сроу?
        CHECK(b.IsEmpty() == false);
        b = a;
        CHECK(b.IsEmpty() == true);
    }

    SUBCASE("Clear") {
        StackArrT<std::string> a;
        StackArrT<std::string> b;
        for (int i = 0; i < 5; ++i)
        {
            a.Push(std::to_string(i));
            b.Push(std::to_string(i));
        }
        CHECK(a.Top() == "4");
        CHECK(a.IsEmpty() == false);
        a.Clear();
        CHECK(a.IsEmpty() == true);
        // CHECK_THROWS(a.Top()); TODO: почему не работает чек сроу?
        CHECK(b.IsEmpty() == false);
        b = a;
        CHECK(b.IsEmpty() == true);
    }
}

TEST_CASE_TEMPLATE_INVOKE(test_ctor, TYPES);
TEST_CASE_TEMPLATE_INVOKE(test_lifo, TYPES);