/***************************************************************
  Student Name: Vansh Sharma
  File Name: Item.h
  Assignment number: 4

 Represents a single item by storing its size, which is used when
 placing items into bins.
***************************************************************/
#ifndef ITEM_H
#define ITEM_H

class Item {
public:
    double size;

    Item() {
        size = 0;
    }

    Item(double s) {
        size = s;
    }
};

#endif
