//
// Created by Burndi on 03.10.2019.
//

#ifndef MRSHV2_MRSHV2_H
#define MRSHV2_MRSHV2_H


#include <cstdint>
#include <vector>
#include <istream>
#include <memory>
#include "BloomFilterList.h"
#include "RollingHash.h"
#include "Fnv641a.h"

class Mrshv2 {
public:
    // constructors
    explicit Mrshv2(const uint32_t b = 256, const uint32_t k = 5, const uint32_t m = 2048, const uint32_t bfMax = 160);

    // functions
    double compareData(std::istream &data1, std::istream &data2, bool fragmentCompare = false);

private:
    uint32_t b = 0;
    uint32_t k = 0;
    uint32_t m = 0;
    uint32_t bfMax = 0;

    // functions
    std::unique_ptr<BloomFilterList> computeHash(std::istream &data);

};


#endif //MRSHV2_MRSHV2_H
