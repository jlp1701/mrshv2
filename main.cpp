#include <istream>
#include <fstream>
#include "Mrshv2.h"

int main() {

    Mrshv2 mrsh;
    double similarity = 0.0;
    std::ifstream if1 ("test1.txt", std::ifstream::in | std::ifstream::binary);
    std::ifstream if2 ("test2.txt", std::ifstream::in | std::ifstream::binary);
    // get length of file:
    if1.seekg (0, if1.end);
    int length = if1.tellg();
    if1.seekg (0, if1.beg);
    similarity = mrsh.compareData(if1, if2, false);
    std::cout << "similarity: " << similarity << std::endl;
    return 0;
}