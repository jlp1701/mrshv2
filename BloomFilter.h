//
// Created by Burndi on 03.10.2019.
//

#ifndef MRSHV2_BLOOMFILTER_H
#define MRSHV2_BLOOMFILTER_H

#include <cstdint>
#include <vector>
#include <map>
#include <iostream>
#include <cmath>

class BloomFilter {
public:
    explicit BloomFilter(uint32_t k = 5, uint32_t m = 2048, uint32_t bfMax = 160);

    void insertHash(uint64_t hashVal);
    double compare(BloomFilter &bf, bool fragmentCompare = false);
    uint32_t size();
    uint numBitsSet();

private:
    const double alpha = 0.3;
    uint32_t k = 0;
    uint32_t m = 0;
    uint32_t bfSize = 0;
    uint32_t bfMax = 0;
    std::map<uint, bool> filterBits;

    // functions
    bool isBitSet(uint32_t bitIdx);
    uint32_t getSetBitsNum(std::vector<uint32_t> bits);
};


#endif //MRSHV2_BLOOMFILTER_H
