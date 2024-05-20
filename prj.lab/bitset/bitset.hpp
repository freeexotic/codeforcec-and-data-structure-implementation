#pragma once
#ifndef BITSET_BITSET_HPP_20240318
#define BITSET_BITSET_HPP_20240318

#include <cstdint>
#include <iosfwd>
#include <vector>

class BitSet {
public:
    BitSet() = default;

    BitSet(const BitSet&) = default; // done?

    BitSet(BitSet&&) = default; // done?

    BitSet(const int size); // done

    BitSet& operator=(const BitSet&) = default; // done?

    BitSet& operator=(BitSet&&) = default; // done ?

    ~BitSet() = default; // done ?

    [[nodiscard]] bool operator==(const BitSet& rhs) const noexcept; // done

    [[nodiscard]] bool operator!=(const BitSet& rhs) const noexcept; // done

    int Size() const noexcept; // done

    void Resize(const int size); // done

    uint32_t Value(const int num); //done

    [[nodiscard]] bool Get(const int idx) const; //done

    void Set(const int idx, const bool val); // done

    void Fill(const bool val) noexcept; // done

    [[nodiscard]] BitSet& operator&=(const BitSet& rhs); // доделать в тесте

    [[nodiscard]] BitSet& operator|=(const BitSet& rhs); // доделать в тесте

    [[nodiscard]] BitSet& operator^=(const BitSet& rhs); // доделать в тесте

    std::ofstream& WriteTxt(std::ofstream& cout);

    std::ofstream& WriteBinary(std::ofstream& cout);

    std::ifstream& ReadBinary(std::ifstream& cin);

    std::ifstream& ReadTxt(std::ifstream& cin);

private:
    int size_ = 0;
    std::vector<uint32_t> bits_;
};


#endif
