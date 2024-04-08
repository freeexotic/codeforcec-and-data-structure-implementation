#ifndef STACKARR_STACKARR_HPP_20240203
#define STACKARR_STACKARR_HPP_20240203


#include <cstddef>
#include <algorithm>
#include <stdexcept>

template <class T>
class StackArrT final {
public:
    StackArrT() = default;

    StackArrT(const StackArrT& src);

    StackArrT(StackArrT&& src) noexcept;

    ~StackArrT();

    StackArrT& operator=(const StackArrT& src);

    StackArrT& operator=(StackArrT&& src) noexcept;

    [[nodiscard]] bool IsEmpty() const noexcept;

    void Pop() noexcept;

    void Push(const T& val);

    [[nodiscard]] T& Top() &;

    [[nodiscard]] const T& Top() const &;

    void Clear() noexcept;

private:
    std::ptrdiff_t size_ = 0;   //!< число элементов в буфере
    std::ptrdiff_t i_top_ = -1; //!< индекс top элемента
    T* data_ = nullptr;   //!< элементы стека
};

template <class T>
StackArrT<T>::StackArrT(const StackArrT<T>& st)
        : i_top_(st.i_top_) {
    if (!st.IsEmpty()) {
        size_ = ((i_top_ + 1) / 4 + 1) * 4;
        data_ = new T[size_];
        std::copy(st.data_, st.data_ + i_top_ + 1, data_);
    }
}

template <class T>
StackArrT<T>& StackArrT<T>::operator=(const StackArr<T>& st) {
    if (this != &st) {
        if (st.IsEmpty()) {
            Clear();
        }
        if (size_ <= st.i_top_) {
            size_ = (st.i_top_ + 4) / 4 * 4;
            T* buf = new T[size_];
            std::swap(data_, buf);
            delete[] buf;
        }
        i_top_ = st.i_top_;
        std::copy(st.data_, st.data_ + i_top_ + 1, data_);
    }
    return *this;
}

template <class T>
StackArrT<T>& StackArrT<T>::operator=(StackArrT<T>&& src) noexcept {
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

template <class T>
StackArrT<T>::~StackArrT() {
    delete[] data_;
}
template <class T>
bool StackArrT<T>::IsEmpty() const noexcept {
    return i_top_ < 0;
}

template <class T>
void StackArrT<T>::Pop() noexcept {
    if (!IsEmpty()) {
        i_top_ -= 1;
    }
}

template <class T>
void StackArrT<T>::Push(const T& val) {
    if (nullptr == data_) {
        size_ = 1;
        data_ = new T[size_];
    } else if (size_ == i_top_ + 1) {
        auto buf = new T[size_ * 2];
        std::copy(data_, data_ + size_, buf);
        std::swap(data_, buf);
        delete[] buf;
        size_ *= 2;
    }
    data_[++i_top_] = val;
}

template <class T>
T& StackArrT<T>::Top() & {
    if (i_top_ >=0) {
        return data_[i_top_];
    }
}

template <class T>
const T& StackArrT<T>::Top() const & {
    if (i_top_ >= 0) {
        return data_[i_top_];
    }
}

template <class T>
void StackArrT<T>::Clear() noexcept {
    i_top_ = -1;
}


#endif // !STACKARR_STACKARR_HPP_20240203
