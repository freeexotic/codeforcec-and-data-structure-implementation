#pragma once
#ifndef STACKARR_STACKARR_HPP_20240203
#define STACKARR_STACKARR_HPP_20240203

#include <cstddef>

struct Complex;

class StackArr {
public:
  StackArr() = default;

  StackArr(const StackArr&);

  StackArr (StackArr&&);
  
  ~StackArr();

  StackArr& operator=(const StackArr&);

  StackArr& operator=(StackArr&&);


  bool IsEmpty() const noexcept;

  void Pop() noexcept;

  void Push(const Complex& val);
  
  [[nodiscard]] Complex& Top();

  [[nodiscard]] const Complex& Top() const;

  void Clear() noexcept;
  
  int Size() noexcept;

  int Capacity() noexcept;

private:
  std::ptrdiff_t size_ = 0;   //!< вместимость элементов в буфере
  std::ptrdiff_t capacity = 0; //! < количество элементов в стеке
  std::ptrdiff_t i_top_ = -1; //!< индекс top элемента
  Complex* data_ = nullptr;   //!< элементы стека
};

#endif // !STACKARR_STACKARR_HPP_20240203
