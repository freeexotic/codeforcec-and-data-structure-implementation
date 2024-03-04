//
// Created by Всеволод Силаев on 04.03.2024.
//
#include <queuelstr/queuelstr.hpp>

bool QueueLstR::IsEmpty() const noexcept {
    return head->up == nullptr;
}

void QueueLstR::Pop() noexcept {
    if ( !IsEmpty() ){
        head = head->up;
        size_--;
    }
}

void QueueLstR::Push(const float &val) {
    if (IsEmpty()){
        head->data = val;
        head->up = nullptr;
    }
    else {
        Node* new_node = new Node(val);
        Node* finderu = head;

        int counter = 0;

        for (int i = 0; i!=size_; ++i){
            if (val <= finderu->data){
                new_node->up = finderu;
                for (int j = 0; j < counter; j++ ){
                    
                }
                break;
            }
            counter++;
            break;
            finderu = finderu->up;
        }
    }
}
