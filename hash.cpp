#include "hash.h"

HashTable::HashTable(int size) : slots(size) {
    table = new Node * [slots]();
    slotLengths = new int[slots](); // Initialize slot lengths
}

HashTable::~HashTable() {
    for (int i = 0; i < slots; i++) {
        Node* current = table[i];
        while (current) {
            Node* temp = current;
            current = current->next;
            delete temp;
        }
    }
    delete[] table;
    delete[] slotLengths; // Clean up slotLengths array
}

int HashTable::hashFunction(const std::string& key) {
    int hashValue = 0;
    for (char ch : key) {
        hashValue = (hashValue * 31 + ch) % slots;
    }
    return hashValue;
}

void HashTable::insert(const std::string& key) {
    int index = hashFunction(key);
    std::cout << "Inserting '" << key << "' into slot " << index << std::endl;
    Node* newNode = new Node(key);
    newNode->next = table[index];
    table[index] = newNode;
    slotLengths[index]++; // Track the number of elements in each slot
}

void HashTable::printFirstFiveSlots() {
    std::cout << "==== Printing the contents of the first 5 slots ====\n";
    for (int i = 0; i < std::min(slots, 5); i++) {
        std::cout << "Slot " << i << ": ";
        Node* current = table[i];
        while (current) {
            std::cout << current->key << " ";
            current = current->next;
        }
        std::cout << "\n";
    }
}

void HashTable::printSlotLengths() {
    std::cout << "==== Printing the slot lengths ====\n";
    for (int i = 0; i < slots; i++) {
        std::cout << "Slot " << i << ": " << slotLengths[i] << "\n";
    }
}

void HashTable::printStandardDeviation() {
    double mean = 0, variance = 0;
    int totalKeys = 0;

    // Calculate mean (average slot length)
    for (int i = 0; i < slots; i++) {
        totalKeys += slotLengths[i];
    }
    mean = (slots > 0) ? (double)totalKeys / slots : 0;

    std::cout << "Total keys: " << totalKeys << ", Slots: " << slots << ", Mean: " << mean << std::endl;

    // Calculate variance
    for (int i = 0; i < slots; i++) {
        variance += (slotLengths[i] - mean) * (slotLengths[i] - mean);
    }
    variance = (slots > 0) ? variance / slots : 0;

    std::cout << "==== Printing the standard deviation ====\n";
    std::cout << sqrt(variance) << "\n";
}