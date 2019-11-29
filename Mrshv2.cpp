//
// Created by Burndi on 03.10.2019.
//

#include "Mrshv2.h"

Mrshv2::Mrshv2(const uint32_t b, const uint32_t k, const uint32_t m, const uint32_t bfMax): b{b}, k{k}, m{m}, bfMax{bfMax} {};

std::unique_ptr<BloomFilterHash> Mrshv2::computeHash(std::istream &data){
    auto bfList = std::make_unique<BloomFilterHash>(m, bfMax);
    RollingHash rh(data, b);
    std::vector<uint8_t> buf;

    // get next triggerpoint
    while (!rh.reachedEof()){
        buf.clear();
        rh.getDataUntilNextTriggerpoint(buf);

        // calculate chunk hash value
        auto chunkHash = Fnv641a::hash(buf);

        // insert hash value into bloom filter
        bfList->insertHash(chunkHash);
    }
    // return bloom filter list
    return (std::move(bfList));
}

double Mrshv2::compareData(std::istream &data1, std::istream &data2, bool fragmentCompare){
    // compute the hashes
    auto bfList1 = computeHash(data1);
    auto bfList2 = computeHash(data2);

    // compare the hashes
    double similarity = 0.0;

    similarity = bfList1->compare(bfList2.get(), fragmentCompare);

    return similarity;
}