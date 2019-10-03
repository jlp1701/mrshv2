//
// Created by Burndi on 03.10.2019.
//

#ifndef MRSHV2_MRSHV2_H
#define MRSHV2_MRSHV2_H


#include <cstdint>
#include <vector>
#include "BloomFilter.h"

class Mrshv2 {
public:
    // constructors
    Mrshv2();
    Mrshv2(const uint32_t b = 256, const uint32_t k = 5, const uint32_t m = 2048, const uint32_t bfMax = 160);

    // functions
    double compareData(std::vector<uint8_t> data1, std::vector<uint8_t> data2, bool fragmentCompare = false);



private:

    // functions
    uint64_t computeChunkHash(std::vector<uint8_t>* data, uint64_t idxFrom, uint64_t idxTo);
    std::vector<BloomFilter> computeHash(std::vector<uint8_t> data);

};


#endif //MRSHV2_MRSHV2_H
