#include <complex/complex.hpp>
#include <queue/queue.hpp>


bool Queue::IsEmpty() const noexcept{
    return head == nullptr;
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
    Node* buf  = head;
    head = buf->up;
    delete buf;
    size_--;
}


