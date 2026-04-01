/***************************************************************
  Student Name: Vansh Sharma
  File Name: Permutation.h
  Assignment number: 4

 Generates the next permutation of item indices using the perm1()
 algorithm so all possible orderings can be tested.
***************************************************************/
#ifndef PERMUTATION_H
#define PERMUTATION_H

class Permutation {
public:
    /***************************************************************
    Function: perm1
    Description: Generates the next permutation of the array.
    Parameters: s[] (int array) - current permutation of indices
                n (int) - number of elements in the array
    Local Variables: m, k, p, q (int) - variables for swapping
    ***************************************************************/
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