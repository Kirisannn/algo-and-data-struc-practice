/** Practice implementation for a int-string Hash Table w/ chaining */

#include <cassert>
#include <iostream>
#include <list>
#include <string>
using namespace std;

// Hash Table of a phonebook Number-Name key-value register
class HashTable {
   private:
    static const int hashGroups = 10;
    list<pair<int, string>> table[hashGroups];

   public:
    bool isEmpty() const;  // Check if list is empty

    int hashFunction(int key);  // Hashing function

    void insertEntry(int key, string val);  // Inserts a phonebook entry

    void removeEntry(int key);  // Removes a number from phonebook

    string search(int key);  // Searches associated name of phone nnumber

    void printTable();  // Print whole Hash Table
};

bool HashTable::isEmpty() const {
    int sum = 0;
    for (int i = 0; i < hashGroups; i++) {
        sum += table[i].size();
    }

    if (sum == 0) {
        return true;  // is empty as size = 0
    }
    return false;  // is populated
}

int HashTable::hashFunction(int key) {
    return key % hashGroups;  // Key = 905, function produces hash = 5
}

void HashTable::insertEntry(int key, string val) {
    int hash = hashFunction(key);
    auto it = table[hash].begin();
    bool keyExists = false;
    while (it != table[hash].end()) {
        if (it->first == key) {
            keyExists = true;
            it->second = val;
            cout << "[WARNING] Key exists. Replaced value." << endl;
            break;
        }

        it++;  // Iterate next
    }

    if (!keyExists) {
        table[hash].emplace_back(key, val);
        cout << "[INFO] Key-Value pair added." << endl;
    }
    return;
}

void HashTable::removeEntry(int key) {
    int hash = hashFunction(key);
    auto it = begin(table[hash]);
    bool keyExists = false;
    while (it != end(table[hash])) {
        if (it->first == key) {
            keyExists = true;
            cout << "[INFO] Key exists. Deleting entry." << endl;
            it = table[hash].erase(it);
            return;
        }

        it++;
    }

    if (!keyExists) {
        cout << "Key does not exist. Nothing to remove." << endl;
    }

    return;
}

string HashTable::search(int key) {
    int hash = hashFunction(key);
    auto it = begin(table[hash]);
    bool keyExists = false;
    while (it != end(table[hash])) {
        if (it->first == key) {
            keyExists = true;
            cout << "[INFO] Key exists." << endl;
            return it->second;
        }

        it++;
    }

    if (!keyExists) {
        cout << "[INFO] Key not found" << endl;
    }

    return "";
}

void HashTable::printTable() {
    for (int i = 0; i < hashGroups; i++) {
        if (table[i].size() == 0) continue;

        auto it = begin(table[i]);
        while (it != end(table[i])) {
            cout << "[INFO] Key: " << it->first << ", Value: " << it->second << endl;
            it++;
        }
    }
    return;
}

int main() {
    HashTable ht;

    // Check isEmpty()
    assert(ht.isEmpty() == true);
    cout << "isEmpty() functional." << endl;

    // Check hashFunction()
    assert(ht.hashFunction(901) == 1);
    cout << "hashFunction() functional." << endl;

    // Check insertEntry() & printTable()
    ht.insertEntry(1003, "George");
    ht.insertEntry(404, "Henry");
    ht.insertEntry(201, "Alicia");
    ht.printTable();

    // Check removeEntry()
    ht.removeEntry(1003);
    ht.printTable();

    // Check search()
    assert(ht.search(404) == "Henry");
    assert(ht.search(1003) == "");
    cout << "search() functional." << endl;

    return 0;
}