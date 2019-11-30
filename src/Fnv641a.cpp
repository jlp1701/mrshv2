//
// Created by Burndi on 03.10.2019.
//

#include "../include/Fnv641a.h"

uint64_t Fnv641a::hash(const std::vector<uint8_t> &data){
    uint64_t hash = Fnv641a::OffsetBasis;
    for (auto dataByte : data){
        hash = hash ^ dataByte;
        hash = hash * Fnv641a::Prime;
    }
    return hash;
}