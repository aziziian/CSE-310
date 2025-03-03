// hash.h
#ifndef HASH_H
#define HASH_H

#include <iostream>
#include <cmath>
#include <string>

struct Node {
    std::string key;
    Node* next;
    Node(std::string k) : key(k), next(nullptr) {}
};

class HashTable {
private:
    int slots;
    Node** table;
    int* slotLengths;
    int hashFunction(const std::string& key);

public:
    HashTable(int size);
    ~HashTable();
    void insert(const std::string& key);
    void printFirstFiveSlots();
    void printSlotLengths();
    void printStandardDeviation();
};

#endif
