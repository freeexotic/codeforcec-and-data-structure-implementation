#pragma once
#ifndef STACKLST_STACKLST_HPP_20240213
#define STACKLST_STACKLST_HPP_20240213

#include <complex/complex.hpp>

#include <cstddef>

class StackLst final {
public:
    StackLst() = default;

    StackLst(const StackLst& st);

    StackLst(StackLst&& st) noexcept;

    ~StackLst() = default;

    StackLst& operator=(const StackLst& st);

    StackLst& operator=(StackLst&& st) noexcept;

    [[nodiscard]] bool IsEmpty() const noexcept;

    void Pop() noexcept;

    void Push(const Complex& val);

    [[nodiscard]] Complex& Top()&;

    [[nodiscard]] const Complex& Top() const &;

    void Clear() noexcept;

private:
    struct Node {
        Complex val;
        Node* next = nullptr;
    };

    Node* head_ = nullptr;
};

#endif
