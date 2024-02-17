#include <complex/complex.hpp>
#include <stacklst/stacklst.hpp>

#include <stdexcept>
  

bool StackLst::IsEmpty () const noexcept{
    return head == nullptr;
}

void StackLst::Push (const Complex& val){
    Node* new_node = new Node(val);
    (new_node->back) = head;
    head = new_node;
    size_+=1;
}

void StackLst::Pop() noexcept {
    if (!IsEmpty()){
        Node* buf = head;
        head = (head->back);
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


