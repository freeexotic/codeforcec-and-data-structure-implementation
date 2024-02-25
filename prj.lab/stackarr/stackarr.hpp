#pragma once
#ifndef STACKARR_STACKARR_HPP_20240203
#define STACKARR_STACKARR_HPP_20240203

#include <cstddef>

struct Complex;

class StackArr {
public:
  [[nodiscard]] StackArr() = default;

  [[nodiscard]] StackArr(const StackArr&) = default;
  
  ~StackArr() = default;
  
  [[nodiscard]] StackArr& operator=(const StackArr&) = default;

  bool IsEmpty() const noexcept;

  void Pop() noexcept;

  void Push(const Complex& val);
  
  [[nodiscard]] Complex& Top();

  [[nodiscard]] const Complex& Top() const;

  void Clear() noexcept;
  
  int Size() noexcept;

  int Counter() noexcept;

private:
  std::ptrdiff_t size_ = 0;   //!< вместимость элементов в буфере
  std::ptrdiff_t counter_ = 0; //! < количество элементов в стеке
  std::ptrdiff_t i_top_ = -1; //!< индекс top элемента
  Complex* data_ = nullptr;   //!< элементы стека
};

#endif // !STACKARR_STACKARR_HPP_20240203
