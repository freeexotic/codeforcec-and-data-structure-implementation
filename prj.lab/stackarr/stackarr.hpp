#ifndef STACKARR_STACKARR_HPP_20240203
#define STACKARR_STACKARR_HPP_20240203

#include <complex/complex.hpp>

#include <cstddef>

class StackArr {
public:
    StackArr() = default;

    StackArr(const StackArr& src);

    StackArr(StackArr&& src) noexcept;

    ~StackArr();

    StackArr& operator=(const StackArr& src);

    StackArr& operator=(StackArr&& src) noexcept;

    [[nodiscard]] bool IsEmpty() const noexcept;

    void Pop() noexcept;

    void Push(const Complex& val);

    [[nodiscard]] Complex& Top() &;

    [[nodiscard]] const Complex& Top() const &;

    void Clear() noexcept;

    int Size() noexcept;

    int Capacity() noexcept;

private:
    int size_ = 0;   //!< число элементов в буфере
    int i_top_ = -1; //!< индекс top элемента
    Complex* data_ = nullptr;   //!< элементы стека
};

#endif // !STACKARR_STACKARR_HPP_20240203
