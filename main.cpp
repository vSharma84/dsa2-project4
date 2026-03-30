// main.cpp
#include <iostream>
#include <fstream>
#include <vector>
#include "BinPacking.h"

using namespace std;

int main() {
    ifstream file("items.txt");

    if (!file) {
        cout << "Error opening file" << endl;
        return 1;
    }

    int n;
    file >> n;

    vector<Item> items;

    for (int i = 0; i < n; i++) {
        double x;
        file >> x;

        if (x > 1) {
            cout << "Invalid item skipped: " << x << endl;
            continue;
        }

        items.push_back(Item(x));
    }

    // ONLINE
    vector<Bin> ff = BinPacking::firstFit(items);
    vector<Bin> nf = BinPacking::nextFit(items);
    vector<Bin> bf = BinPacking::bestFit(items);

    // OFFLINE
    vector<Item> sorted = BinPacking::sortDescending(items);
    vector<Bin> offFF = BinPacking::firstFit(sorted);
    vector<Bin> offBF = BinPacking::bestFit(sorted);

    // OUTPUT TABLE
    cout << "Policy\t\t\tBins Used\n";
    cout << "---------------------------------\n";

    cout << "Optimal Solution\t(too large to compute fully)\n";
    cout << "Online First Fit\t" << ff.size() << endl;
    cout << "Online Next Fit\t\t" << nf.size() << endl;
    cout << "Online Best Fit\t\t" << bf.size() << endl;
    cout << "Offline First Fit\t" << offFF.size() << endl;
    cout << "Offline Best Fit\t" << offBF.size() << endl;

    cout << "\n--- Online First Fit ---\n";
    BinPacking::printBins(ff);

    cout << "\n--- Online Next Fit ---\n";
    BinPacking::printBins(nf);

    cout << "\n--- Online Best Fit ---\n";
    BinPacking::printBins(bf);

    cout << "\n--- Offline First Fit ---\n";
    BinPacking::printBins(offFF);

    cout << "\n--- Offline Best Fit ---\n";
    BinPacking::printBins(offBF);

    return 0;
}
