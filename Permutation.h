#ifndef PERMUTATION_H
#define PERMUTATION_H

class Permutation {
public:
    static void perm1(int s[], int n)
    {
        int m = n - 2;

        while (m >= 0 && s[m] > s[m + 1])
            m = m - 1;

        if (m < 0)
            return;

        int k = n - 1;

        while (s[m] > s[k])
            k = k - 1;

        // swap values
        int temp = s[m];
        s[m] = s[k];
        s[k] = temp;

        int p = m + 1;
        int q = n - 1;

        while (p < q)
        {
            temp = s[p];
            s[p] = s[q];
            s[q] = temp;

            p++;
            q--;
        }
    }
};

#endif