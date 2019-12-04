cmake_minimum_required(VERSION 3.12)
project(mrshv2)

set(CMAKE_CXX_STANDARD 14)

# Add -O0 to remove optimizations when using gcc
#IF(CMAKE_COMPILER_IS_GNUCC)
#    set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -O3")
#    set(CMAKE_C_FLAGS_DEBUG "${CMAKE_C_FLAGS_DEBUG} -O3")
#ENDIF(CMAKE_COMPILER_IS_GNUCC)

#add_executable(mrshv2_test main.cpp src/Mrshv2.cpp include/Mrshv2.h src/BloomFilter.cpp include/BloomFilter.h src/RollingHash.cpp include/RollingHash.h src/Fnv641a.cpp include/Fnv641a.h src/BloomFilterHash.cpp include/BloomFilterHash.h)
add_library(mrshv2 STATIC main.cpp src/Mrshv2.cpp include/Mrshv2.h src/BloomFilter.cpp include/BloomFilter.h src/RollingHash.cpp include/RollingHash.h src/Fnv641a.cpp include/Fnv641a.h src/BloomFilterHash.cpp include/BloomFilterHash.h)
target_include_directories(mrshv2 PUBLIC "$<BUILD_INTERFACE:${CMAKE_CURRENT_LIST_DIR}/include>")
#---------------------------------------------------------------------------------------
# Header only version
#---------------------------------------------------------------------------------------
#add_library(mrshv2_header_only INTERFACE )
#target_include_directories(mrshv2_header_only INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}/include)