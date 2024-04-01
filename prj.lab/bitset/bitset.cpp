//
// Created by Всеволод Силаев on 18.03.2024.
//
#include <bitset/bitset.hpp>
#include <iostream>

BitSet::BitSet(const int size) {
    size_ = size;
    bits_.resize(size_, 0);
}

int BitSet::Size() const noexcept {
    return size_;
}

void BitSet::Resize(const int size) {
    bits_.resize(size, 0);
    size_ = size;
}

void BitSet::Set(const int idx, const bool val) {
    if(Size()!=0 && idx == 0){
        uint32_t mask = 1;
        bits_[0] = bits_[0] ^ mask;
    }
    else if((32*bits_.size() % idx < 1)){
        std::cout << "Err";
    }
    else{
        int num = idx / 32;
        int idx_ = idx % 32;
        uint32_t mask = 1 << idx_;
        if (val == 1){
            bits_[num] = ~(~bits_[num] ^ mask);
        }
        else{
            bits_[num] = bits_[num] ^ mask;
        }

    }
}

void BitSet::Fill(const bool val) noexcept {
    uint32_t mask = 0;
    if (val == 0){
        for  (int i = 0; i!=size_; ++i){
            bits_[i] = mask;
        }
    }
    else{
        for  (int i = 0; i!=size_; ++i){
            bits_[i] = ~mask;
        }
    }
}

uint32_t BitSet::Value(const int num) {
    return bits_[num];
}

bool BitSet::Get(const int idx) const {
    if (Size()!=0){
        int num = idx / 32;
        int idx_ = idx % 32;
        uint32_t mask = 1 << idx_;
        mask = (bits_[num] & mask) >> idx_;
        if (mask == 1){
            return 1;
        }
        else{
            return 0;
        }
    }
}

// доступ по индексу
// Думать, как сохранить экземпля в виде текстовом и нетекстовом
// форматированный и неформатированный ввод вывод