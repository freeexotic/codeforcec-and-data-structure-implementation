#ifndef SILAEV_V_V_23_03_QUEUELSTT_HPP
#define SILAEV_V_V_23_03_QUEUELSTT_HPP

#include <complex/complex.hpp>
#include <iostream>
#include <cstddef>

template<class T>
class QueueLstT final {
public:
    QueueLstT() = default;

    QueueLstT(const QueueLstT& qul);

    QueueLstT(QueueLstT&& qul) noexcept;

    ~QueueLstT() = default;

    QueueLstT& operator=(const QueueLstT& qul);

    QueueLstT& operator=(QueueLstT&& qul) noexcept;

    [[nodiscard]] bool IsEmpty() const noexcept;

    void Pop() noexcept;

    void Push(const T& data);

    [[nodiscard]] T& Top() &;

    [[nodiscard]] const T& Top() const &;

    void Clear() noexcept;

private:
    struct Node {
        T val;
        Node* next = nullptr;
    };

    Node* head_ = nullptr;
    Node* tail_ = nullptr;
};

template <class T>
QueueLstT<T>::QueueLstT(const QueueLstT<T>& qul) {
    if (qul.head_ != nullptr) {
        head_ = new Node{qul.head_->val};
        Node* buf1 = qul.head_;
        Node* buf2 = head_;
        while (buf1->next) {
            buf2->next = new Node{buf1->next->val};
            buf1 = buf1->next;
            buf2 = buf2->next;
        }
        tail_ = buf2;
    }
}

template <class T>
QueueLstT<T>::QueueLstT(QueueLstT<T>&& qul) noexcept: head_(qul.head_), tail_(qul.tail_) {
    qul.head_ = nullptr;
    qul.tail_ = nullptr;
}

template <class T>
QueueLstT<T>& QueueLstT<T>::operator=(const QueueLstT<T>& qul) {
    if (this != &qul) {
        if (qul.head_ == nullptr) {
            Clear();
        } else {
            QueueLstT<T> copy(qul);
            std::swap(head_, copy.head_);
            std::swap(tail_, copy.tail_);
        }
    }
    return *this;
}

template <class T>
QueueLstT<T>& QueueLstT<T>::operator=(QueueLstT<T>&& qul) noexcept {
    if (this != &qul) {
        std::swap(head_, qul.head_);
        std::swap(tail_, qul.tail_);
    }
    return *this;
}

template <class T>
bool QueueLstT<T>::IsEmpty() const noexcept {
    return nullptr == head_;
}

template <class T>
void QueueLstT<T>::Pop() noexcept {
    if (this->head_!= nullptr) {
        Node* deleted = head_;
        head_ = head_->next;
        delete deleted;
    }
    if (this->head_== nullptr) {
        tail_ = nullptr;
    }
}

template <class T>
void QueueLstT<T>::Push(const T& data) {
    if (this->head_ == nullptr) {
        tail_ = new Node{data};
        head_ = tail_;
    } else {
        tail_->next = new Node{data};
        tail_ = tail_->next;
    }
}

template <class T>
T& QueueLstT<T>::Top() & {
    if (this->head_== nullptr) {
        throw std::logic_error("QueueLst - ПУСТ!");
    }
    return head_->val;
}

template <class T>
const T& QueueLstT<T>::Top() const & {
    if (this->head_== nullptr) {
        throw std::logic_error("QueueLst - ПУСТ!");
    }
    return head_->val;
}

template <class T>
void QueueLstT<T>::Clear() noexcept {
    while (this->head_!= nullptr) {
        Pop();
    }
}

#endif //SILAEV_V_V_23_03_QUEUELSTT_HPP
