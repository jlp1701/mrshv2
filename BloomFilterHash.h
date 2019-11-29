//
// Created by Burndi on 04.10.2019.
//

#ifndef MRSHV2_BLOOMFILTERLIST_H
#define MRSHV2_BLOOMFILTERLIST_H

#include <cstdint>
#include <vector>
#include <memory>
#include "BloomFilter.h"

class BloomFilterList {
public:
    explicit BloomFilterList(uint32_t m = 2048, uint32_t bfMax = 160);
    BloomFilterList(const BloomFilterList&) = delete;
    void operator=(const BloomFilterList&) = delete;

    void insertHash(uint64_t hashVal);
    double compare(BloomFilterList &bfList, bool fragmentCompare = false);
    uint64_t size();

private:
    uint32_t m = 0;
    uint32_t bf = 0;
    uint32_t bfMax = 0;
    std::vector<std::unique_ptr<BloomFilter>> bfList;
};


#endif //MRSHV2_BLOOMFILTERLIST_H
