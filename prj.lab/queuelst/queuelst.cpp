#include <complex/complex.hpp>
#include <queuelst/queuelst.hpp>

QueueLst::QueueLst(const QueueLst& qul) {
    if (!qul.IsEmpty()) {
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

QueueLst::QueueLst(QueueLst&& qul) noexcept: head_(qul.head_), tail_(qul.tail_) {
    qul.head_ = nullptr;
    qul.tail_ = nullptr;
}

QueueLst& QueueLst::operator=(const QueueLst& qul) {
    if (this != &qul) {
        if (qul.IsEmpty()) {
            Clear();
        } else {
            QueueLst copy(qul);
            std::swap(head_, copy.head_);
            std::swap(tail_, copy.tail_);
        }
    }
    return *this;
}

QueueLst& QueueLst::operator=(QueueLst&& qul) noexcept {
    if (this != &qul) {
        std::swap(head_, qul.head_);
        std::swap(tail_, qul.tail_);
    }
    return *this;
}

bool QueueLst::IsEmpty() const noexcept {
    return nullptr == head_;
}

void QueueLst::Pop() noexcept {
    if (!IsEmpty()) {
        Node* deleted = head_;
        head_ = head_->next;
        delete deleted;
    }
    if (IsEmpty()) {
        tail_ = nullptr;
    }
}

void QueueLst::Push(const Complex& data) {
    if (IsEmpty()) {
        tail_ = new Node{data};
        head_ = tail_;
    } else {
        tail_->next = new Node{data};
        tail_ = tail_->next;
    }
}

Complex& QueueLst::Top() & {
    if (IsEmpty()) {
        throw std::logic_error("QueueLst - ПУСТ!");
    }
    return head_->val;
}

const Complex& QueueLst::Top() const & {
    if (IsEmpty()) {
        throw std::logic_error("QueueLst - ПУСТ!");
    }
    return head_->val;
}

void QueueLst::Clear() noexcept {
    while (!IsEmpty()) {
        Pop();
    }
}