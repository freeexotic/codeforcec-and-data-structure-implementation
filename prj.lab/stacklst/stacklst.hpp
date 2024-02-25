#pragma once
#ifndef STACKLST_STACKLSST_HPP_20240215
#define STACKLST_STACKLSST_HPP_20240215

#include <cstddef>

struct Complex;

class Node {
  public:
    Node* back;
    Complex data;
    Node() = default;
    Node(Complex data_) : data(data_), back(nullptr) {}
    ~Node() = default;
  };

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
  Node* head = nullptr;

};

#endif 
