/***************************************************************
  Student Name: Vansh Sharma
  File Name: main.cpp
  Assignment number: 4

 Reads the input from the file, calls the bin packing algorithms,
 and prints the results and bin contents to the console.
***************************************************************/
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

    vector<Bin> ff = BinPacking::firstFit(items);
    vector<Bin> nf = BinPacking::nextFit(items);
    vector<Bin> bf = BinPacking::bestFit(items);

    vector<Item> sorted = BinPacking::sortDescending(items);
    vector<Bin> offFF = BinPacking::firstFit(sorted);
    vector<Bin> offBF = BinPacking::bestFit(sorted);

    int opt = BinPacking::optimal(items);

    cout << "Policy                     Total Bins Used\n";
    cout << "-----------------------------------------\n";

    if (opt == -1)
        cout << "Optimal Solution          Not computed\n";
    else
        cout << "Optimal Solution          " << opt << endl;


    cout << "\nOnline Algorithm\n";
    cout << "  First Fit               " << ff.size() << endl;
    cout << "  Next Fit                " << nf.size() << endl;
    cout << "  Best Fit                " << bf.size() << endl;

    cout << "\nOffline Algorithm\n";
    cout << "  First Fit               " << offFF.size() << endl;
    cout << "  Best Fit                " << offBF.size() << endl;

    cout << "=========================================\n";

    cout << "\n--- Optimal ---\n";
    if (opt != -1)
        cout << "(Computed using permutations)\n";
    else
        cout << "(Not computed due to input size)\n";

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