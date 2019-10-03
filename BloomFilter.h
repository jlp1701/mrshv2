//
// Created by Burndi on 03.10.2019.
//

#ifndef MRSHV2_BLOOMFILTER_H
#define MRSHV2_BLOOMFILTER_H

#include <cstdint>
#include <vector>

class BloomFilter {
public:
    BloomFilter(uint32_t k=5, uint32_t m = 2048, uint32_t bfMax = 160);

    void insert(std::vector<uint32_t> bitNums);
    double compare(BloomFilter* bf, bool fragmentCompare = false);
    uint32_t size();

private:
    uint32_t k = 0;
    uint32_t m = 0;
    uint32_t bf = 0;
    uint32_t bfMax = 0;
    std::vector<uint64_t> filterBits;

    // functions
    void setBit(uint32_t bitNum);
    void setBits(std::vector<uint32_t> bitNums);

    bool isBitSet(uint32_t bitNum);
    uint32_t getSetBitsNum(std::vector<uint32_t> bitsSet);
};


#endif //MRSHV2_BLOOMFILTER_H
