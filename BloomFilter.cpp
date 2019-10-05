//
// Created by Burndi on 03.10.2019.
//

#include "BloomFilter.h"

BloomFilter::BloomFilter(uint32_t k, uint32_t m, uint32_t bfMax) : k(k), m(m), bfMax(bfMax) {
    bfSize = 0;

    // Todo: check if k*ld(m) <= 64 is true; otherwise error

}

void BloomFilter::insertHash(uint64_t hashVal){
    if (size() >= bfMax) {
        // we have a problem
        std::cerr << "Bloom filter already full!" << std::endl;
        // Todo: throw exception
    }
    uint shifts = (uint)std::ceil(std::log2(m));
    uint64_t mask = m-1;
    for (uint i = 0; i < k; i++){
        uint64_t bitNum = (hashVal >> (shifts*i)) & mask;
        filterBits[bitNum] = true;
    }
    bfSize++;
}

uint32_t BloomFilter::size(){
    return bfSize;
}

uint BloomFilter::numBitsSet(){
    return filterBits.size();
}

double BloomFilter::compare(BloomFilter &bf, bool fragmentCompare){
    // calculate E_Min
    double p = 1 - 1 / double(m);
    uint sizeBf1 = this->size();
    uint sizeBf2 = bf.size();

    double EMin = m*(1-std::pow(p, k*sizeBf1) - std::pow(p, k*sizeBf2) + std::pow(p, k*(sizeBf1+sizeBf2)));
    double EMax = 0.0;
    if (fragmentCompare){
        EMax = std::min(numBitsSet(), bf.numBitsSet());
    } else {
        EMax = std::max(numBitsSet(), bf.numBitsSet());
    }
    // get number of overlapping bits
    // check which bloom filer has more bits set
    BloomFilter* bfLess = this;
    BloomFilter* bfMore = &bf;
    if (bfLess->numBitsSet() > bfMore->numBitsSet()){
        bfLess = &bf;
        bfMore = this;
    }

    uint e = 0;
    for (auto fBits : bfMore->filterBits){
        if (bfLess->filterBits.find(fBits.first) != bfLess->filterBits.end()){
            e++;
        }
    }

    // calculate score
    double cutoffPoint = alpha*(EMax-EMin)+EMin;
    double score = 0.0;
    if (e > cutoffPoint){
        score = 100*((e-cutoffPoint)/(EMax-cutoffPoint));
    }
    return score;
}