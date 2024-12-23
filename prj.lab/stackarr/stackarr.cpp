#include <stackarr/stackarr.hpp>

#include <algorithm>
#include <stdexcept>

StackArr::StackArr(const StackArr& mas) : i_top_(mas.i_top_) {
    if (!mas.IsEmpty()) {
        size_ = ((i_top_ + 1) / 4 + 1) * 4;
        data_ = new Complex[size_];
        std::copy(mas.data_, mas.data_ + i_top_ + 1, data_);
    }
}


StackArr& StackArr::operator=(const StackArr& mas) {
    if (this != &mas) {
        if (mas.IsEmpty()) {
            Clear();
        }
        if (size_ <= mas.i_top_) {
            size_ = (mas.i_top_ + 4) / 4 * 4;
            Complex* buf = new Complex[size_];
            std::swap(data_, buf);
            delete[] buf;
        }
        i_top_ = mas.i_top_;
        std::copy(mas.data_, mas.data_ + i_top_ + 1, data_);
    }
    return *this;
}

StackArr::StackArr(StackArr&& mas) noexcept {
    std::swap(mas.size_, size_);
    std::swap(mas.i_top_, i_top_);
    std::swap(mas.data_, data_);
}



StackArr& StackArr::operator=(StackArr&& src) noexcept {
    if (this != &src) {
        if (!src.IsEmpty()) {
            std::swap(size_, src.size_);
            std::swap(i_top_, src.i_top_);
            std::swap(data_, src.data_);
        } else {
            Clear();
        }
    }
    return *this;
}

StackArr::~StackArr() {
    delete[] data_;
}

bool StackArr::IsEmpty() const noexcept {
    return i_top_ < 0;
}

void StackArr::Pop() noexcept {
    if (!IsEmpty()) {
        i_top_ -= 1;
    }
}

void StackArr::Push(const Complex& val) {
    if (nullptr == data_) {
        size_ = 1;
        data_ = new Complex[size_];
    } else if (size_ == i_top_ + 1) {
        auto buf = new Complex[size_ * 2];
        std::copy(data_, data_ + size_, buf);
        std::swap(data_, buf);
        delete[] buf;
        size_ *= 2;
    }
    data_[++i_top_] = val;
}

Complex& StackArr::Top() & {
    if (i_top_ >=0) {
        return data_[i_top_];
    }
    else {
        throw std::logic_error("StackArr - пуст");
    }
}

const Complex& StackArr::Top() const & {
    if (i_top_ >= 0) {
        return data_[i_top_];
    }
    else {
        throw std::logic_error("StackArr - пуст");
    }
}

void StackArr::Clear() noexcept {
    i_top_ = -1;
}
