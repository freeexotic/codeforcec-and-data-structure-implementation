#pragma once
#ifndef STACKARR_STACKARR_HPP_20240203
#define STACKARR_STACKARR_HPP_20240203

#include <complex/complex.hpp>


class StackArr final {
public:
    StackArr() = default;

    StackArr(const StackArr& mas);

    StackArr(StackArr&& mas) noexcept;

    ~StackArr();

    StackArr& operator=(const StackArr& mas);

    StackArr& operator=(StackArr&& mas) noexcept;

    [[nodiscard]] bool IsEmpty() const noexcept;

    void Pop() noexcept;

    void Push(const Complex& val);

    [[nodiscard]] Complex& Top() &;

    [[nodiscard]] const Complex& Top() const &;

    void Clear() noexcept;


private:
    int size_ = 0;
    int i_top_ = -1;
    Complex* data_ = nullptr;
};

#endif
