#include <complex/complex.hpp>
#include <queuelst/queuelst.hpp>


bool Queue::IsEmpty() const noexcept{
    return head == nullptr;
}

Queue::Queue(Queue && obj) {
    std::swap(head, obj.head);
    std::swap(tail, obj.tail);
    std::swap(size_, obj.size_);
}


Queue &Queue::operator=(Queue && obj) {
    if (this != &obj){
        std::swap(head, obj.head);
        std::swap(tail, obj.tail);
        std::swap(size_, obj.size_);
    }
    return *this;
}

int Queue::Size() noexcept{
    return size_;
}

void Queue::Push(const Complex& val){
    if (head == nullptr) {
        Node* last_head = new Node(val);
        head = last_head;
        tail = last_head;
        size_++;
    }
    else {
        Node* last_head = new Node(val);
        tail->up = last_head;
        tail = last_head;
        size_++;
    }
}
void Queue::Clear() noexcept{
    for(int i = 0; i!=size_; ++i ){
        Pop();
    }
}
void Queue::Pop() noexcept {
    if (!IsEmpty()){
        Node* buf  = head;
        head = buf->up;
        delete buf;
        size_--;
    }
    if (IsEmpty()){
        tail = nullptr;
    }
}

Complex& Queue::Top() {
    return head->data;
}

const Complex& Queue::Top() const {
    return head->data;
}

