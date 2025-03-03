#include "hash.h"
#include <fstream>
#include <sstream>

int main() {
    int slots;
    std::cin >> slots;
    HashTable hashTable(slots);
    std::string word;
    while (std::cin >> word) {
        hashTable.insert(word);
    }
    hashTable.printFirstFiveSlots();
    hashTable.printSlotLengths();
    hashTable.printStandardDeviation();
    return 0;
}