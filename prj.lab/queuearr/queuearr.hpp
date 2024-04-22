#ifndef QUEUEARR_QUEUEARR_HPP_20240230
#define QUEUEARR_QUEUEARR_HPP_20240230

#include <complex/complex.hpp>
#include <algorithm>
#include <stdexcept>
#include <cstddef>

class QueueArr {
public:
    QueueArr() = default;

    QueueArr(const QueueArr& src);

    QueueArr(QueueArr&& src) noexcept;

    ~QueueArr();

    QueueArr& operator=(const QueueArr& src);

    QueueArr& operator=(QueueArr&& src);

    [[nodiscard]] bool IsEmpty() const noexcept;

    void Pop() noexcept;

    void Push(const Complex& val);

    [[nodiscard]] Complex& Top();

    [[nodiscard]] const Complex& Top() const;

    int Size();

    void Clear() noexcept;

private:
    std::ptrdiff_t size_ = 0;  //!<
    Complex* data_ = nullptr;  //!<
    std::ptrdiff_t head_ = -1; //!<
    std::ptrdiff_t tail_ = -1; //!<
private:
    std::ptrdiff_t Count() const;
};

#endif