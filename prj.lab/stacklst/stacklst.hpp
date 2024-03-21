#pragma once
#ifndef STACKLST_STACKLSST_HPP_20240215
#define STACKLST_STACKLSST_HPP_20240215

#include <cstddef>
#include "complex/complex.hpp"

struct Complex;

class Node {
  public:
    Node* next = nullptr;
    Complex data ;
    Node(Complex data_) : data(data_), next(nullptr) {}
  };

class StackLst {
public:
  
  [[nodiscard]] StackLst() = default;

  [[nodiscard]] StackLst(const StackLst&) = default;

  StackLst(StackLst&& obj) noexcept; // ???

  
  ~StackLst() = default;
  
  [[nodiscard]] StackLst& operator=(const StackLst&) = default;

  StackLst& operator=(StackLst&& obj) noexcept; // ???

  bool IsEmpty() const noexcept;

  void Pop() noexcept;

  void Push(const Complex& val);
  
  [[nodiscard]] Complex& Top();

  [[nodiscard]] const Complex& Top() const;

  int Size() noexcept;

  void Clear() noexcept;

private:
  int size_ = 0;   //!< число элементов в буфере
  Node* head = nullptr;

};

#endif 
