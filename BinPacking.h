/***************************************************************
  Student Name: Vansh Sharma
  File Name: BinPacking.h
  Assignment number: 4

 Contains all the bin packing algorithms and computes how many bins each 
 method uses, including the optimal solution.
***************************************************************/
#ifndef BINPACKING_H
#define BINPACKING_H

#include <vector>
#include <algorithm>
#include <iostream>
#include <cmath>
#include "Bin.h"
#include "Permutation.h"

using namespace std;

class BinPacking {
public:

    /***************************************************************
     Function: firstFit
     Description: Places items into bins using the First Fit strategy
     Parameters: items (vector<Item>) - list of items to be packed
     Local Variables:
        bins (vector<Bin>) - stores bins created during packing
        placed (bool) - indicates whether current item was placed
     Returns: vector<Bin> - bins after packing all items
    ***************************************************************/
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

    /***************************************************************
     Function: nextFit
     Description: Places items into bins using the Next Fit strategy
     Parameters: items (vector<Item>) - list of items to be packed
     Local Variables:
        bins (vector<Bin>) - stores completed bins
        current (Bin) - current bin being filled
     Returns: vector<Bin> - bins after packing all items
    ***************************************************************/
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

    /***************************************************************
     Function: bestFit
     Description: Places items into bins using the Best Fit strategy
     Parameters: items (vector<Item>) - list of items to be packed
     Local Variables:
        bins (vector<Bin>) - stores bins created during packing
        bestIndex (int) - index of best bin for placement
        minSpace (double) - smallest remaining space after placement
     Returns: vector<Bin> - bins after packing all items
    ***************************************************************/
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

    /***************************************************************
     Function: sortDescending
     Description: Sorts items in descending order for offline algorithms.
     Parameters:items (vector<Item>) - list of items to sort
     Returns: vector<Item> - sorted items from largest to smallest
    ***************************************************************/
    static vector<Item> sortDescending(vector<Item> items) {
        sort(items.begin(), items.end(), [](Item a, Item b) {
            return a.size > b.size;
        });
        return items;
    }

    /***************************************************************
     Function: optimalPacking
     Description: Computes the optimal bin packing by generating permutations
                  of items and selecting the arrangement with the fewest bins.
     Parameters:items (vector<Item>) - list of items to be packed
     Local Variables:
        s[] (int array) - stores permutation indices
        sum (double) - total size of all items
        lowerBound (int) - minimum possible bins
        minBins (int) - smallest number of bins found
        bestBins (vector<Bin>) - stores best packing arrangement
     Returns: vector<Bin> - bins representing optimal packing
    ***************************************************************/
    static vector<Bin> optimalPacking(vector<Item> items)
    {
        int n = items.size();

        int s[20];
        for (int i = 0; i < n; i++)
            s[i] = i;

        double sum = 0;
        for (int i = 0; i < n; i++)
            sum += items[i].size;

        int lowerBound = (int)ceil(sum);

        int minBins = 1000000;
        vector<Bin> bestBins;

        vector<Item> perm(n);

        int total = 1;
        for (int i = 1; i <= n; i++)
            total *= i;

        for (int count = 0; count < total; count++)
        {
            for (int i = 0; i < n; i++)
                perm[i] = items[s[i]];

            vector<Bin> bins = firstFit(perm);

            if (bins.size() < minBins)
            {
                minBins = bins.size();
                bestBins = bins;
            }

            //if (minBins == lowerBound)
            //    break;

            Permutation::perm1(s, n);
        }

        return bestBins;
    }

    /***************************************************************
     Function: printBins
     Description: Prints the contents of each bin to the console.
     Parameters:
        bins (vector<Bin>) - bins to display
    ***************************************************************/
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