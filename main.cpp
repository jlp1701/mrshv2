#include <istream>
#include <fstream>
#include <ctime>
#include "Mrshv2.h"

int main() {

    Mrshv2 mrsh;
    double similarity = 0.0;
    std::ifstream if1 ("test1.txt", std::ifstream::in | std::ifstream::binary);
    std::ifstream if2 ("test2.txt", std::ifstream::in | std::ifstream::binary);
    if (!if1.good() || !if2.good()){
        std::cout << "Error with opening files!" << std::endl;
        return -1;
    }
    // get length of file:
    if1.seekg (0, if1.end);
    int length = if1.tellg();
    if1.seekg (0, if1.beg);

    time_t begin, end;
    time(&begin);
    //similarity = mrsh.compareData(if1, if2, false);
    auto hash1 = mrsh.computeHash(if1);
    auto hash2 = mrsh.computeHash(if2);
    similarity = hash1->compare(hash2.get());
    time(&end);
    double timeDiff = difftime(end, begin);
    std::cout << "similarity: " << similarity << std::endl;
    std::cout << "took: " << timeDiff << " seconds" << std::endl;
    return 0;
}