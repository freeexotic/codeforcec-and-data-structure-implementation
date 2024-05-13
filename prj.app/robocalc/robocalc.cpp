#include "robocalc.hpp"

#include <algorithm>
#include <stdexcept>
#include <string>



bool RoboCalc::IsEmpty() const noexcept {
    return nullptr == head_;
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

double RoboCalc::ADD(double &from_out, double &val) noexcept {
    return from_out + val;
}

double RoboCalc::DIV(double &from_out, double &val) noexcept {
    return from_out/val;
}

double RoboCalc::MUL(double &from_out, double &val) noexcept {
    return from_out*val;
}

double RoboCalc::SUB(double &from_out, double &val) noexcept {
    return from_out - val;
}

double RoboCalc::Desk(const std::string &com ,double& val, double& from_out) {
    if (com == "ADD"){
        return ADD(from_out, val);
    }
    else if (com == "SUB"){
        return SUB(from_out, val);
    }
    else if (com == "MUL"){
        return MUL(from_out, val);
    }
    else if (com == "DIV"){
        return DIV(from_out, val);
    }
}

double RoboCalc::OUT(double &out) noexcept {
    double from_out = out;
    Node* buf = head_;
    do {
        from_out = Desk(buf->data_com, buf->data_val, from_out);
        buf = buf->next;
    }while (buf != nullptr);
    return from_out;
}

double RoboCalc::REV(int &num) noexcept {
    if (num >= 0 && num <= size_){
        Node* buf = head_;
        for (int i = 1; i!=size_-num; ++i){
            buf = buf->next;
        }
        tail_=buf;
        tail_->next = nullptr;
    }
    else{
        throw std::logic_error("The number in is not in the allowed range");
    }
}

// при неверном вводе - заканчиваем ошибкой
// сделать ключ значение
// консольное приложение принимающее параметры командной строки
// если что-то приводит к некорректному состоянию - пишим err - "сама ошибка"