//
// Created by Burndi on 03.10.2019.
//

#include "../include/RollingHash.h"

RollingHash::RollingHash(std::istream &data, uint32_t b, uint32_t windowLen) : data(data), b(b), windowLen(windowLen){
    // reset position in stream
    data.seekg(0, data.beg);
}

bool RollingHash::reachedEof(){
    return data.eof();
}

void RollingHash::insert(uint8_t byte){
    dataWindow.push_back(byte);
    if (dataWindow.size() > windowLen) {
        dataWindow.erase(dataWindow.begin());
    }
    // calculate hashvalue
    uint32_t a = 1;
    uint32_t b = 0;
    for (auto d : dataWindow){
        a = (a + d) % modulo;
        b = (a + b) % modulo;
    }
    hashVal = (b << 16) | a;
}

void RollingHash::digestNextByte(){
    uint byte = 0;
    if (data >> byte){
        insert((uint8_t)byte);
    }
}

void RollingHash::getDataUntilNextTriggerpoint(std::vector<uint8_t> &buffer){
    uint32_t numToIgnore = b/4;

    // try to read in bytes until trigger point or reach eof
    char byte = 0;

    while (data.get(byte)){
        buffer.push_back((uint8_t)byte);
        if (numToIgnore > 0) {
            numToIgnore--;
        } else {
            insert((uint8_t)byte);
            // check if trigger point is reached
            if ((hashVal+1)%b == 0){
                break;
            }
        }
    }
}