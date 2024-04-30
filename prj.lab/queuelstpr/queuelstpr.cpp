//
// Created by Всеволод Силаев on 04.03.2024.
//
#include <queuelstr/queuelstr.hpp>
#include <iostream>

bool QueueLstR::IsEmpty() const noexcept {
    return size_ == 0;
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
    Node* new_node = new Node(val);
    Node* finder = head; //?
    Node* buf;
    if (IsEmpty()){
        head->data = val;
        size_++;
    }
    else if (size_ == 1){
        if (head->data <= val){
            buf = head;
            new_node->up = buf;
            head = new_node;
            size_++;
        }
    }
    else if (finder->up == nullptr){
        finder->up = new_node;
    }
    else {
        for (int i = 0; i!= size_-1 ; ++i){
            if (val <= finder->data) {
                new_node->up = finder->up;
                finder = new_node;
                size_++;
                break;
            }
            finder = finder->up;
        }
    }
}
