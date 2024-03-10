//
// Created by Всеволод Силаев on 04.03.2024.
//
#include <queuelstr/queuelstr.hpp>
#include <iostream>

bool QueueLstR::IsEmpty() const noexcept {
    return head->up == nullptr;
}

int QueueLstR::Size() noexcept {
    return size_;
}

void QueueLstR::Pop() noexcept {
    if ( !IsEmpty() ){
        head = head->up;
        size_--;
    }
}

float QueueLstR::Top() noexcept {
    if (!IsEmpty()){
        return head->data;
    }
}

void QueueLstR::Push(const float &val) {
    if (size_ == 0){
        head->data = val;
        head->up = nullptr;
        size_++;
    }
    else {
        Node* new_node = new Node(val);
        Node* finder = head; //?


        for (int i = 0; i!=size_ ; ++i){
            if (finder->up == nullptr){ // доделать 
                if (val <= finder->data){
                    new_node->up = head;
                    head = new_node;
                    break;
                }
                else{
                    finder->up = new_node;
                    new_node->up = nullptr;
                    break;
                }
            }
            else {
                Node* buf = finder->up;
                if (val <= buf->data)
                {
                    finder->up = new_node;
                    new_node->up = buf;
                    break;
                }
            }
            finder = finder->up;
        }
    }
}
