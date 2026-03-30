#ifndef BINPACKING_H
#define BINPACKING_H

#include <vector>
#include <algorithm>
#include <iostream>
#include "Bin.h"
#include "Permutation.h"

using namespace std;

class BinPacking {
public:

    // ---------------- FIRST FIT ----------------
    static vector<Bin> firstFit(vector<Item> items) {
        vector<Bin> bins;

        for (int i = 0; i < items.size(); i++) {
            bool placed = false;

            for (int j = 0; j < bins.size(); j++) {
                if (bins[j].canFit(items[i])) {
                    bins[j].addItem(items[i]);
                    placed = true;
                    break;
                }
            }

            if (!placed) {
                Bin newBin;
                newBin.addItem(items[i]);
                bins.push_back(newBin);
            }
        }

        return bins;
    }

    // ---------------- NEXT FIT ----------------
    static vector<Bin> nextFit(vector<Item> items) {
        vector<Bin> bins;
        Bin current;

        for (int i = 0; i < items.size(); i++) {
            if (current.canFit(items[i])) {
                current.addItem(items[i]);
            } else {
                bins.push_back(current);
                current = Bin();
                current.addItem(items[i]);
            }
        }

        bins.push_back(current);
        return bins;
    }

    // ---------------- BEST FIT ----------------
    static vector<Bin> bestFit(vector<Item> items) {
        vector<Bin> bins;

        for (int i = 0; i < items.size(); i++) {
            int bestIndex = -1;
            double minSpace = 2.0;

            for (int j = 0; j < bins.size(); j++) {
                if (bins[j].canFit(items[i])) {
                    double space = bins[j].remaining - items[i].size;

                    if (space < minSpace) {
                        minSpace = space;
                        bestIndex = j;
                    }
                }
            }

            if (bestIndex == -1) {
                Bin newBin;
                newBin.addItem(items[i]);
                bins.push_back(newBin);
            } else {
                bins[bestIndex].addItem(items[i]);
            }
        }

        return bins;
    }

    // ---------------- OFFLINE (SORT DESC) ----------------
    static vector<Item> sortDescending(vector<Item> items) {
        sort(items.begin(), items.end(), [](Item a, Item b) {
            return a.size > b.size;
        });
        return items;
    }

    // ---------------- OPTIMAL (BRUTE FORCE) ----------------
    static int optimal(vector<Item> items) {
        vector<double> arr;

        for (int i = 0; i < items.size(); i++) {
            arr.push_back(items[i].size);
        }

        sort(arr.begin(), arr.end());

        int minBins = 1000000;

        do {
            vector<Item> permItems;

            for (int i = 0; i < arr.size(); i++) {
                permItems.push_back(Item(arr[i]));
            }

            vector<Bin> bins = firstFit(permItems);

            if (bins.size() < minBins) {
                minBins = bins.size();
            }

        } while (Permutation::perm1(arr));

        return minBins;
    }

    // ---------------- PRINT BINS ----------------
    static void printBins(vector<Bin> bins) {
        for (int i = 0; i < bins.size(); i++) {
            cout << "b" << i + 1 << ": ";
            for (int j = 0; j < bins[i].items.size(); j++) {
                cout << bins[i].items[j].size << " ";
            }
            cout << endl;
        }
    }
};

#endif
