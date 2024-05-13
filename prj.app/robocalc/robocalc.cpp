#include <robocalc/robocalc.hpp>

#include <algorithm>
#include <stdexcept>
#include <string>



bool RoboCalc::IsEmpty() const noexcept {
    return nullptr == head_;
}

void RoboCalc::Pop() noexcept {
    if (!IsEmpty()) {
        Node* deleted = head_;
        head_ = head_->next;
        delete deleted;
    }
    if (IsEmpty()) {
        tail_ = nullptr;
    }
}

void RoboCalc::Push(const std::string& com, const double& val) {
    if (IsEmpty()) {
        tail_ = new Node;
        head_ = tail_;
        head_->data_com = com;
        head_->data_val = val;
    } else {
        tail_->next = new Node;
        tail_ = tail_->next;
        tail_->data_com = com;
        tail_->data_val = val;
    }
    size_++;
}
int RoboCalc::Size() const noexcept {
    return size_;
}

void RoboCalc::Desk(const std::string &com ,double& val, double& out) {
    if (com == "ADD"){
        return ADD(out, val);
    }
    else if (com == "SUB"){
        return SUB(out, val);
    }
    else if (com == "MUL"){
        return MUL(out, val);
    }
    else if (com == "DIV"){
        return DIV(out, val);
    }
}

double RoboCalc::OUT(double &out) noexcept {
    Node* buf = head_;
    do{

    } while (buf != tail_);
}


// при неверном вводе - заканчиваем ошибкой
// сделать ключ значение
// консольное приложение принимающее параметры командной строки
// если что-то приводит к некорректному состоянию - пишим err - "сама ошибка"