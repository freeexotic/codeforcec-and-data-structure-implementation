#ifndef STACKLST_STACKLSST_HPP_20240215
#define STACKLST_STACKLSST_HPP_20240215

#include <cstddef>

class Complex;

class StackLst {
public:
  [[nodiscard]] StackLst() = default;

  [[nodiscard]] StackLst(const StackLst&) = default;
  
  ~StackLst() = default;
  
  [[nodiscard]] StackLst& operator=(const StackLst&) = default;

  bool IsEmpty() const noexcept;

  void Pop() noexcept;

  void Push(const Complex& val);
  
  [[nodiscard]] Complex& Top();

  [[nodiscard]] const Complex& Top() const;

  void Clear() noexcept;

private:
  std::ptrdiff_t size_ = 0;   //!< число элементов в буфере
  std::ptrdiff_t i_top_ = -1; //!< индекс top элемента
  Complex* data_ = nullptr;   //!< элементы стека
};

#endif 
