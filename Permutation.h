#ifndef PERMUTATION_H
#define PERMUTATION_H

#include <vector>
using namespace std;

class Permutation {
public:
    static bool perm1(vector<double>& a) {
        int n = a.size();
        int i = n - 2;

        while (i >= 0 && a[i] >= a[i + 1])
            i--;

        if (i < 0)
            return false;

        int j = n - 1;
        while (a[j] <= a[i])
            j--;

        swap(a[i], a[j]);

        int left = i + 1;
        int right = n - 1;

        while (left < right) {
            swap(a[left], a[right]);
            left++;
            right--;
        }

        return true;
    }
};

#endif
