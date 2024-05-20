//
// Created by Всеволод Силаев on 18.03.2024.
//
#include <bitset/bitset.hpp>
#include <iostream>
#include <fstream>

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
    else if(32*bits_.size() <= idx){
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
bool BitSet::operator!=(const BitSet &rhs) const noexcept {
    if (size_ == rhs.size_){
        if (rhs.bits_ != bits_){
            return true;
        }
        else{
            return false;
        }
    }
}
bool BitSet::operator==(const BitSet &rhs) const noexcept {
    if (size_ == rhs.size_){
        if (rhs.bits_ == bits_){
            return true;
        }
        else{
            return false;
        }
    }
}

BitSet &BitSet::operator&=(const BitSet &rhs) {
    if (size_ == rhs.size_){
        for (int i = 0; i != rhs.size_; i++) {
            bits_[i] = bits_[i] & rhs.bits_[i];
        }
    }
}

BitSet &BitSet::operator|=(const BitSet &rhs) {
    if (size_ == rhs.size_){
        for (int i = 0; i != rhs.size_; i++) {
            bits_[i] = bits_[i] | rhs.bits_[i];
        }
    }
}
BitSet &BitSet::operator^=(const BitSet &rhs) {
    if (size_ == rhs.size_){
        for (int i = 0; i != rhs.size_; i++) {
            bits_[i] = bits_[i] ^ rhs.bits_[i];
        }
    }
}

std::ofstream& BitSet::WriteTxt(std::ofstream& cout)
{
    int size_w = ceil(log10(size_));
    for (int i = 0; i < bits_.size() - 1; ++i)
    {
        cout << std::setw(size_w) << 32 * i << std::setw(0) << ": ";
        for (int j = 0; j < 32; ++j)
        {
            cout << ((bits_[i] & (1 << j))? '1' : '0');
            if (j % 8 == 7)
                cout << (j == 31 ? '\n' : ' ');
        }
    }
    cout << std::setw(size_w) << 32 * (bits_.size() - 1) << std::setw(0) << ": ";
    for (int j = 0; j < size_ - 32 * bits_.size() + 32; ++j)
    {
        cout << ((bits_.back() & (1 << j)) ? '1' : '0');
        if (j % 8 == 7 && j != 31)
            std::cout << ' ';
    }
    cout << "\n";
    cout << std::string(50, '-') << std::endl;
    return cout;
}

std::ofstream& BitSet::WriteBinary(std::ofstream& cout)
{
    cout.put('\0');
    cout.put(char((size_ >> 24) % 256));
    cout.put(char((size_ >> 16) % 256));
    cout.put(char((size_ >> 8 ) % 256));
    cout.put(char((size_) % 256));

    char check_sum = 0;
    for (int i = 0; i < bits_.size(); ++i)
    {
        if (i == bits_.size() - 1) {
            cout.put(char((bits_[i]) % 256));
            if (size_ - 32 * i > 8)
                cout.put(char((bits_[i] >> 8) % 256));
            if (size_ - 32 * i > 16)
                cout.put(char((bits_[i] >> 16) % 256));
            if (size_ - 32 * i > 24)
                cout.put(char((bits_[i] >> 24) % 256));
        }
        else {
            int a = (bits_[i]) % 256;
            int b = (bits_[i] >> 8) % 256;
            int c = (bits_[i] >> 16) % 256;
            int d = (bits_[i] >> 24) % 256;

            cout.put(a);
            cout.put(b);
            cout.put(c);
            cout.put(d);
        }

        bool check_flag = false;
        for (int j = 0; j < 32; ++j) if ((bits_[i] >> j) % 2 == 1)
                check_flag = !check_flag;

        check_sum = (check_sum | ((check_flag ? 1 : 0) << (7 - (i % 8))));

        if (i % 8 == 7 || i == bits_.size() - 1)
            cout.put(check_sum);
    }

    cout.put(char(255));
    return cout;
}


std::ifstream& BitSet::ReadTxt(std::ifstream& cin)
{
    if (cin.good())
    {
        size_ = 0;
        bits_.clear();
        int cnt = -1;
        uint32_t cache = 0;
        std::string tmp;
        bool wrong_string = false;
        while (!wrong_string && cin >> tmp && tmp[0] != '-') {
            if (cnt == -1/*start*/ || cnt == 4/*loop*/)
            {
                if (tmp.back() != ':')
                    wrong_string = true;

                int first_bit = 0;
                for (int i = 0; i < tmp.size() - 1; ++i)
                    if ('0' <= tmp[i] && tmp[i] <= '9')
                        first_bit = 10 * first_bit + tmp[i] - '0';
                    else
                    {
                        wrong_string = true;
                        break;
                    }

                if (cnt == 4)
                    bits_.push_back(cache);

                if (first_bit != bits_.size() * 32)
                    wrong_string = true;

                cnt = 0;
                cache = 0;
            }
            else
            {
                for (int i = 0; i < tmp.size(); ++i)
                    if (tmp[i] == '0' || tmp[i] == '1')
                        cache = cache | (uint32_t(tmp[i] - '0') << (i + cnt * 8));
                    else
                        wrong_string = true;

                size_ += tmp.size();
                ++cnt;
            }
        }
        bits_.push_back(cache);
        if (tmp != std::string(50, '-'))
            cin.setstate(std::ios_base::failbit);
    }
    return cin;
}


std::ifstream& BitSet::ReadBinary(std::ifstream& cin)
{
    if (cin.good())
    {
        if (cin.get() != '\0')
            cin.setstate(std::ios_base::failbit);
        else
        {
            //init size_
            {
                unsigned char a = cin.get();
                unsigned char b = cin.get();
                unsigned char c = cin.get();
                unsigned char d = cin.get();
                size_ = (a << 24) | (b << 16) | (c << 8) | d;
            }
            bits_.resize(size_ / 8 + (size_ % 8> 0));

            unsigned char check_sum = 0;
            for (int i = 0; i < bits_.size() && cin.good(); ++i)
            {
                if (i == bits_.size() - 1) {
                    unsigned char a = 0;
                    unsigned char b = 0;
                    unsigned char c = 0;
                    unsigned char d = 0;

                    a = cin.get();
                    if (size_ - 32 * i > 8)
                        b = cin.get();
                    if (size_ - 32 * i > 16)
                        c = cin.get();
                    if (size_ - 32 * i

                        > 24)
                        d = cin.get();

                    bits_[i] = a | (b << 8) | (c << 16) | (d << 24);
                }
                else {
                    unsigned char a = cin.get();
                    unsigned char b = cin.get();
                    unsigned char c = cin.get();
                    unsigned char d = cin.get();
                    int a_i = (int(a) % (1 << 8));
                    int b_i = ((int(b) << 8) % (1 << 16));
                    int c_i = ((int(c) << 16) % (1 << 24));
                    int d_i = ((int(d) << 24));
                    bits_[i] = a_i | b_i | c_i | d_i;
                }

                bool check_flag = false;
                for (int j = 0; j < 32; ++j) if ((bits_[i] >> j) % 2 == 1)
                        check_flag = !check_flag;

                check_sum = (check_sum | ((check_flag ? 1 : 0) << (7 - (i % 8))));

                if (i % 8 == 7 || i == bits_.size() - 1) {
                    if (cin.get() != check_sum) {
                        cin.setstate(std::ios_base::failbit);
                    }
                }
            }

            if (cin.good() && cin.get() != 255)
                cin.setstate(std::ios_base::failbit);
        }
    }
    return cin;
}

// доступ по индексу
// Думать, как сохранить экземпля в виде текстовом и нетекстовом
// форматированный и неформатированный ввод вывод