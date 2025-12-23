#include <iostream>
#include <cmath>

struct table {
    int key;
    int val;
    bool ocp = false;
};

class MyHashMap {
public:
    static const int size = 10007; // Increased size to a prime number to reduce collisions
    table entery[size];

    MyHashMap() {}
    
    void put(int key, int val) {
        int index = abs(key) % size;
        while (entery[index].ocp && entery[index].key != key) {
            index = (index + 1) % size;
        }
        entery[index].key = key;
        entery[index].val = val;
        entery[index].ocp = true;
    }
    
    int get(int key) {
        int index = abs(key) % size;
        int start = index;
        while (entery[index].ocp) {
            if (entery[index].key == key) return entery[index].val;
            index = (index + 1) % size;
            if (index == start) break;
        }
        return -1;
    }
    
    void remove(int key) {
        int i = abs(key) % size;
        // Find the key
        while (entery[i].ocp && entery[i].key != key) {
            i = (i + 1) % size;
        }

        if (!entery[i].ocp) return; // Key doesn't exist

        // Remove the key
        entery[i].ocp = false;

        // "Heal" the cluster so GET doesn't stop at this new hole
        int j = i;
        while (true) {
            j = (j + 1) % size;
            if (!entery[j].ocp) break; // End of cluster

            int k = abs(entery[j].key) % size;
            
            // Check if this element belongs in the hole 'i' or after it
            // This complex condition handles the circular wrap-around of the array
            if ((i < j) ? (k <= i || k > j) : (k <= i && k > j)) {
                entery[i] = entery[j];
                entery[j].ocp = false;
                i = j;
            }
        }
    }
};