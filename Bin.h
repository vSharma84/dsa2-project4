/***************************************************************
  Student Name: Vansh Sharma
  File Name: Bin.h
  Assignment number: 4

 Stores a group of items placed in the same bin and keeps track of
 the remaining space to decide if new items can fit.
***************************************************************/
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
