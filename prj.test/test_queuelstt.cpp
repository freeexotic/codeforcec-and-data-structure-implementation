#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include "utils.hpp"
#include "doctest.h"
#include <queuelstt/queuelstt.hpp>
#include <complex/complex.hpp>
#include <string>

#define TYPES int, double, std::string

TEST_CASE_TEMPLATE_DEFINE("[queuelstt] - cppt", T, test_ctor) {
    SUBCASE("copy, pop, push, top") {
        QueueLstT<double> a;
        for (int i = 0; i < 500; i++) {
            a.Push(i);
        }
        QueueLstT b(a);
        CHECK(b.Top() == 0);

        a.Push(13.14);
        b.Pop();
        CHECK(b.Top() == 1);
        a.Pop();
        CHECK(a.Top() == 1);
        for (int i = 0; i < 499; i++) {
            a.Pop();
        }
        CHECK(a.Top() == 13.14);
    }
    SUBCASE("copy, pop, push, top") {
        QueueLstT<std::string> a;
        for (int i = 0; i < 500; i++) {
            a.Push(std::to_string(i));
        }
        QueueLstT b(a);
        CHECK(b.Top() == "0");

        a.Push("13.14");
        b.Pop();
        CHECK(b.Top() == "1");
        a.Pop();
        CHECK(a.Top() == "1");
        for (int i = 0; i < 499; i++) {
            a.Pop();
        }
        CHECK(a.Top() == "13.14");
    }
}


TEST_CASE_TEMPLATE_DEFINE("[IE C] - ", T, test_lifo)
{
    SUBCASE("IsEmpty, Clear") {
        QueueLstT<double> a;
        for (int i = 0; i < 500; i++) {
            a.Push(i);
        }
        a.Pop();
        CHECK(a.Top() == 1);
        CHECK(a.IsEmpty() != true);
        a.Clear();
        CHECK(a.IsEmpty() == true);
    }
    SUBCASE("IsEmpty, Clear") {
        QueueLstT<std::string> a;
        for (int i = 0; i < 500; i++) {
            a.Push(std::to_string(i));
        }
        a.Pop();
        CHECK(a.Top() == "1");
        CHECK(a.IsEmpty() != true);
        a.Clear();
        CHECK(a.IsEmpty() == true);
    }
}

TEST_CASE_TEMPLATE_INVOKE(test_ctor, TYPES);
TEST_CASE_TEMPLATE_INVOKE(test_lifo, TYPES);