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

void QueueLstPr::Push(const float& num) {
    Node *f_ptr = nullptr;
    Node *buf;

    int stop = 1;
    if (IsEmpty()) {
        head_ = new Node(num, nullptr);
        stop = 0;
    }

    Node* finder = head_;
    if (stop == 1){
        while(finder != nullptr){
            if (finder->val >= num) {
                if (f_ptr == nullptr) {
                    buf = head_;
                    head_ = new Node{num, buf};
                    break;
                }
                else{
                    f_ptr->next = new Node(num, finder);
                    break;
                }
            }
            else {
                f_ptr = finder;
                finder = finder->next;
            }
            if (finder == nullptr){
                f_ptr->next = new Node(num, nullptr);
                break;
            }
        }
    }

}

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