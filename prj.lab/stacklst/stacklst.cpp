#include <stacklst/stacklst.hpp>

#include <memory>
#include <stdexcept>

StackLst::StackLst(const StackLst& st) {
    if (!st.IsEmpty()) {
        head_ = new Node{st.Top()};
        Node* buf1 = st.head_;
        Node* buf2 = head_;
        while (buf1->next) {
            buf2->next = new Node{buf1->next->val};
            buf1 = buf1->next;
            buf2 = buf2->next;
        }
    }
}

StackLst::StackLst(StackLst&& src) noexcept {
    std::swap(head_, src.head_);
}

StackLst& StackLst::operator=(const StackLst& st) {
    if (this != &st) {
        if (st.IsEmpty()) {
            Clear();
        } else {
            Node* buf1 = st.head_;
            if (IsEmpty()) {
                head_ = new Node{st.head_->val};
            } else {
                head_->val = st.head_->val;
            }
            Node* buf2 = head_;
            while (buf1->next) {
                if (buf2->next) {
                    buf2->next->val = buf1->next->val;
                } else {
                    buf2->next = new Node{ buf1->next->val };
                }
                buf1 = buf1->next;
                buf2 = buf2->next;
            }
            if (buf2->next) {
                Node* tail = buf2->next->next;
                while (buf2->next) {
                    delete buf2->next;
                    buf2->next = nullptr;
                    buf2 = tail;
                }
            }
        }
    }
    return *this;
}

StackLst& StackLst::operator=(StackLst&& src) noexcept {
    std::swap(head_, src.head_);
    return *this;
}

bool StackLst::IsEmpty() const noexcept {
    return nullptr == head_;
}

void StackLst::Pop() noexcept {
    if (!IsEmpty()) {
        Node* deleted = head_;
        head_ = head_->next;
        delete deleted;
    }
}

void StackLst::Push(const Complex& val) {
    head_ = new Node{val, head_};
}

Complex& StackLst::Top() & {
    if (IsEmpty()) {
        throw std::logic_error("StackLst - ПУСТ");
    }
    return head_->val;
}

const Complex& StackLst::Top() const & {
    if (IsEmpty()) {
        throw std::logic_error("StackLst - ПУСТ");
    }
    return head_->val;
}

void StackLst::Clear() noexcept {
    while (!IsEmpty()) {
        Pop();
    }
}