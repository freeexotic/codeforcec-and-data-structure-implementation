#include <complex/complex.hpp>
#include <stacklst/stacklst.hpp>
#include <memory> // Почему при добавлении все работает

#include <stdexcept>


StackLst::StackLst(StackLst &&obj) noexcept{
    std::swap(size_, obj.size_);
    std::swap(head, obj.head);
}

StackLst& StackLst::operator=(StackLst&& obj) noexcept{
    std::swap(size_, obj.size_);
    std::swap(head, obj.head);
    return *this;
}

bool StackLst::IsEmpty () const noexcept{
    return head == nullptr;
}

void StackLst::Push (const Complex& val){
    Node* new_node = new Node(val);
    (new_node->next) = head;
    head = new_node;
    size_+=1;
}

void StackLst::Pop() noexcept {
    if (!IsEmpty()){
        Node* buf = head;
        head = (head->next);
        delete buf;
        --size_;
    }
}


Complex& StackLst::Top(){
    if (!IsEmpty()){
        return head->data;
    }
    else{
        throw std::logic_error("StackList is Empty.");
    }
}

const Complex& StackLst::Top() const{
    if (!IsEmpty()){
        return head->data;
    }
    else{
        throw std::logic_error("StackList is Empty.");
    }
}

int StackLst::Size() noexcept {
    return size_;
}

