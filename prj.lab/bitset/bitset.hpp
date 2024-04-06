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

    [[nodiscard]] bool operator==(const BitSet& rhs) const noexcept;

    [[nodiscard]] bool operator!=(const BitSet& rhs) const noexcept;

    int Size() const noexcept; // done

    void Resize(const int size); // done

    uint32_t Value(const int num); //done

    [[nodiscard]] bool Get(const int idx) const; //done

    void Set(const int idx, const bool val); // done

    void Fill(const bool val) noexcept; // done

    [[nodiscard]] BitSet& operator&=(const BitSet& rhs); // доделать в тесте

    [[nodiscard]] BitSet& operator|=(const BitSet& rhs); // доделать в тесте

    [[nodiscard]] BitSet& operator^=(const BitSet& rhs); // доделать в тесте


    // ? operator[](const uint32_t) - what can return
    // std::ostream& WriteTxt(std::ostream&)
    // std::ostream& WriteBinary(std::ostream&)
    // std::istream& ReadTxt(std::istream&)
    // std::istream& RaadBinary(std::istream&)
private:
    int size_ = 0;
    std::vector<uint32_t> bits_;
};

// std::ostream& operaror<<(std::ostream&, const BitSet&);
// std::istream& operaror>>(std::istream&, BitSet&);

// [[nodiscard]] BitSet operator&(const BitSet& rhs);

// [[nodiscard]] BitSet operator|(const BitSet& rhs);

// [[nodiscard]] BitSet operator^(const BitSet& rhs);

#endif
