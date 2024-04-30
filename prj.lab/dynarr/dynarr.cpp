#include <stdexcept>
#include <dynarr/dynarr.hpp>

DynArr::DynArr(const std::ptrdiff_t size) {
  if (size <= 0) {
    throw std::runtime_error("It is impossible to create an array of this size");
  } else {
    size_ = size;
    capacity_ = (capacity_ > 2 * size_ ? capacity_ : 2 * size_);
    mass_ = new float[capacity_];
    for (std::ptrdiff_t i = 0; i < size_; ++i) {
      mass_[i] = 0;
    }
  }
}

DynArr::DynArr(const DynArr& rhs) {
  capacity_ = (capacity_ > 2 * rhs.size_ ? capacity_ : 2 * rhs.size_);
  size_ = rhs.size_;
  mass_ = new float[capacity_];
  for (std::ptrdiff_t i = 0; i < size_; ++i) {
    mass_[i] = rhs.mass_[i];
  }
}

DynArr::~DynArr() {
  delete[] mass_;
}

DynArr& DynArr::operator= (const DynArr& rhs) {
  if (rhs.size_ > capacity_ || 4 * rhs.size_ < capacity_) {
    capacity_ = 2 * rhs.size_;
    size_ = rhs.size_;
    delete[] mass_;
    mass_ = new float[capacity_];
    for (std::ptrdiff_t i = 0; i < size_; ++i) {
      mass_[i] = rhs.mass_[i];
    }
    return *this;
  } else {
    size_ = rhs.size_;
    for (std::ptrdiff_t i = 0; i < size_; ++i) {
      mass_[i] = rhs.mass_[i];
    }
    return *this;
  }
}

void DynArr::Resize(const std::ptrdiff_t size) {
  if (size <= 0) {
    throw std::runtime_error("It is impossible to resize an array of this size");
  } else {
    if (size > size_) {
      if (size > capacity_) {
        capacity_ = 2 * size;
        float* new_mass_ = new float[capacity_];
        for (std::ptrdiff_t i = 0; i < size_; ++i) {
          new_mass_[i] = mass_[i];
        }
        for (std::ptrdiff_t i = size_; i < size; ++i) {
          new_mass_[i] = 0;
        }
        size_ = size;
        delete[] mass_;
        mass_ = new_mass_;
      } else {
        for (std::ptrdiff_t i = size_; i < size; ++i) {
          mass_[i] = 0;
        }
        size_ = size;
      }
    } else {
      size_ = size;
    }
  }
}

float& DynArr::operator[] (const std::ptrdiff_t ind) {
  if (ind < 0 || ind >= size_) {
    throw std::runtime_error("Index out of range");
  } else {
    return mass_[ind];
  }
}

const float& DynArr::operator[](const std::ptrdiff_t ind) const {
  if (ind < 0 || ind >= size_) {
    throw std::runtime_error("Index out of range");
  } else {
    return mass_[ind];
  }
}