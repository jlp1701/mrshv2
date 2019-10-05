cmake_minimum_required(VERSION 3.12)
project(mrshv2)

set(CMAKE_CXX_STANDARD 14)

add_executable(mrshv2 main.cpp Mrshv2.cpp Mrshv2.h BloomFilter.cpp BloomFilter.h RollingHash.cpp RollingHash.h Fnv641a.cpp Fnv641a.h BloomFilterList.cpp BloomFilterList.h)