#ifndef BIN_H
#define BIN_H

#include <vector>
#include "Item.h"

using namespace std;

class Bin {
public:
    vector<Item> items;
    double remaining;

    Bin() {
        remaining = 1.0;
    }

    bool canFit(Item item) {
        return item.size <= remaining;
    }

    void addItem(Item item) {
        items.push_back(item);
        remaining -= item.size;
    }
};

#endif
