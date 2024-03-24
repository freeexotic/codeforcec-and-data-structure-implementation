#pragma once
#ifndef QUEUEARR_MISIS2023S_23_32
#define QUEUEARR_MISIS2023S_23_32

#include <complex/complex.hpp>
#include <cstddef>

class QueueArr {
public:
  QueueArr();

  QueueArr(const QueueArr&);

  QueueArr (QueueArr&& obj) noexcept;

  ~QueueArr();

  [[nodiscard]] QueueArr& operator=(const QueueArr&);

  QueueArr& operator=(QueueArr&&) noexcept;

  [[nodiscard]] bool IsEmpty() const noexcept;

  void Pop() noexcept;

  void Push(const Complex& val);

  [[nodiscard]] Complex& Top();

  [[nodiscard]] const Complex& Top() const;

  void Clear() noexcept;

  int Size() const {
    if (begin <= end)
      return end - begin;
    else
      return capacity_ - begin + end;
  }

private:
  std::ptrdiff_t begin = 0;
  std::ptrdiff_t end = 0;
  std::ptrdiff_t capacity_ = 10;
  Complex* mass_ = nullptr;
};

#endif