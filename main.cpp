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

    // 🔥 UPDATED: get optimal bins instead of just number
    vector<Bin> optBins = BinPacking::optimalPacking(items);
    int opt = optBins.size();

    cout << "Policy                   Total Bins Used\n";
    cout << "========================================\n";

    cout << "Optimal Solution          " << opt << endl;

    cout << "\nOnline Algorithm\n";
    cout << "  First Fit               " << ff.size() << endl;
    cout << "  Next Fit                " << nf.size() << endl;
    cout << "  Best Fit                " << bf.size() << endl;

    cout << "\nOffline Algorithm\n";
    cout << "  First Fit               " << offFF.size() << endl;
    cout << "  Best Fit                " << offBF.size() << endl;

    cout << "=========================================\n";

    cout << "\nOptimal:\n";
    BinPacking::printBins(optBins);

    cout << "\nOnline First Fit:\n";
    BinPacking::printBins(ff);

    cout << "\nOnline Next Fit:\n";
    BinPacking::printBins(nf);

    cout << "\nOnline Best Fit:\n";
    BinPacking::printBins(bf);

    cout << "\nOffline First Fit:\n";
    BinPacking::printBins(offFF);

    cout << "\nOffline Best Fit:\n";
    BinPacking::printBins(offBF);

    return 0;
}