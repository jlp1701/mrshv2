//
// Created by Burndi on 04.10.2019.
//

#include "BloomFilterHash.h"

BloomFilterHash::BloomFilterHash(uint32_t m, uint32_t bfMax) : m{m}, bfMax{bfMax}{
    bf = 0;
}

void BloomFilterHash::insertHash(uint64_t hashVal){
    if (bfList.empty() || bfList.back()->size() >= bfMax){
        bfList.emplace_back(std::make_unique<BloomFilter>(5, m, bfMax));
    }
    bfList.back().get()->insertHash(hashVal);
    bf++;
}

uint64_t BloomFilterHash::size() const {
    return bf;
}


double BloomFilterHash::compare(const BloomFilterHash* bfList, bool fragmentCompare){
    const BloomFilterHash *bflLess = this;
    const BloomFilterHash *bflMore = bfList;
    // sort lists according to sizes
    if (bflLess->bfList.size() > bflMore->bfList.size()){
        bflLess = bfList;
        bflMore = this;
    }
    if (bflLess->size() < 6 || bflMore->size() < 6){
        return -1;  // TOdo: ugly
    }

    // perform all-against-all compare
    double bfScore = 0.0;
    double bfScoreMax = 0.0;
    double finalScore = 0.0;
    for (auto const& s : bflLess->bfList){
        bfScoreMax = 0.0;
        for (auto const& r : bflMore->bfList){
            bfScore = s->compare(*r, fragmentCompare);
            if (bfScore > bfScoreMax){
                bfScoreMax = bfScore;
            }
        }
        finalScore += bfScoreMax;
    }
    if (fragmentCompare){
        finalScore = finalScore / bflLess->bfList.size();
    } else {
        finalScore = finalScore / bflMore->bfList.size();
    }
    return finalScore;
}