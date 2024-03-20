#include <complex/complex.hpp>
#include <stackarr/stackarr.hpp>

#include <algorithm>
#include <stdexcept>


StackArr::StackArr(const StackArr& obj) {
    if(!obj.IsEmpty())
    {
        i_top_=obj.i_top_;
        size_ =obj.size_;
        capacity = obj.capacity;
        data_ = new Complex[capacity*2];
        std::copy (obj.data_,obj.data_ + size_ + +1, data_);
    }
}

StackArr::StackArr(StackArr&& obj) {
    std::swap(size_, obj.size_);
    std::swap(i_top_, obj.i_top_);
    std::swap(data_, obj.data_);
}

StackArr& StackArr::operator=(StackArr&& obj) {
    if (this != &obj) {
        std::swap(size_, obj.size_);
        std::swap(i_top_, obj.i_top_);
        std::swap(data_, obj.data_);
    }
    return *this;
}

StackArr& StackArr::operator=(const StackArr& obj) {
    if(this != &obj){
        if(obj.IsEmpty()){
            Clear();
        }
        else if(capacity <= obj.capacity){
            capacity = obj.capacity*2;
            Complex* buf = new Complex[capacity];
            std::swap(data_, buf);
            delete[] buf;
        }
        i_top_= obj.i_top_;
        size_ = obj.size_;
        std::copy(obj.data_,obj.data_ + obj.size_ +1 ,data_);
    }
    return *this;
}



StackArr::~StackArr() {
    delete[] data_;
}

bool StackArr::IsEmpty() const noexcept {
  return 0 > size_;
}

void StackArr::Pop() noexcept {
  if (!IsEmpty()) {
    i_top_--;
    size_--;
  }
}

void StackArr::Push(const Complex& val) {
  if (nullptr == data_) {
    capacity = 8;
    data_ = new Complex[capacity];
  }
  else if (capacity == i_top_ + 1) {
    auto buf = new Complex[capacity * 2];
    std::copy(data_, data_ + capacity, buf);
    std::swap(data_, buf);
    delete[] buf;
    capacity *= 2;
  }
  data_[++i_top_] = val;
  size_ += 1;
}
  
Complex& StackArr::Top() {
  if (i_top_ < 0) {
    throw std::logic_error("StackArr - try get top form empty stack.");
  }
  return data_[i_top_];
}

const Complex& StackArr::Top() const {
  if (i_top_ < 0) {
    throw std::logic_error("StackArr - try get top form empty stack.");
  }
  return data_[i_top_];
}

int StackArr::Capacity() noexcept {
  return capacity;
}

int StackArr::Size() noexcept{
    return size_;
}

void StackArr::Clear() noexcept {
  i_top_ = -1;
  size_ = 0;
}

