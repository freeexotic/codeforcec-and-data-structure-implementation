#include <queuelstpr/queuelstpr.hpp>
#include <stdexcept>

bool QueueLstPr::IsEmpty() const noexcept {
    return nullptr == head_;
}

void QueueLstPr::Pop() noexcept {
    if (!IsEmpty()) {
        Node* deleted = head_;
        head_ = head_->next;
        delete deleted;
    }
}
// TODO Доделать Push
/*void QueueLstPr::Push(const float &val) {
    Node* new_node = new Node(val);
    Node* finder = head_;
    Node* buf;
    if (IsEmpty()){
        head_->val = val;
        size_++;
    }
    else if (size_ == 1){
        if (head_->val <= val){
            buf = head_;
            new_node->next = buf;
            head_ = new_node;
            size_++;
        }
    }
    else if (finder->next == nullptr){
        finder->next = new_node;
    }
    else {
        for (int i = 0; i!= size_-1 ; ++i){
            if (val <= finder->val) {
                new_node->next = finder->next;
                finder = new_node;
                size_++;
                break;
            }
            finder = finder->next;
        }
    }
} */

float& QueueLstPr::Top() {
    if (IsEmpty()) {
        throw std::logic_error("QueueLstPr - ПУСТ");
    }
    return head_->val;
}

const float& QueueLstPr::Top() const {
    if (IsEmpty()) {
        throw std::logic_error("QueueLstPr - ПУСТ");
    }
    return head_->val;
}

void QueueLstPr::Clear() noexcept {
    while (!IsEmpty()) {
        Pop();
    }
}