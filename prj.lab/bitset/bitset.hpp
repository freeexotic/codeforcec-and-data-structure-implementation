#ifndef SILAEV_V_V_23_03_BITSET_HPP
#define SILAEV_V_V_23_03_BITSET_HPP

#include <vector>


class BitSet{
public:
    [[nodiscard]] BitSet() = default;
    [[nodiscard]] BitSet(const BitSet &) = default;
    // семантика перехода
    [[nodiscard]] BitSet& operator=(const BitSet&) = default;
    BitSet& operator=(BitSet&&) = default;
    ~BitSet() = default;


private:
    int size_vec = 17;
    std::vector<uint32_t> bit_set;


};

#endif //SILAEV_V_V_23_03_BITSET_HPP
