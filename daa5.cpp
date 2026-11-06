#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;

// Write a program for analysis of Quick sort by using deterministic and randomized variants.

int partition(vector<int>& a, int lo, int hi) {
    int pivot = a[hi], i = lo - 1;
    for (int j = lo; j < hi; j++)
        if (a[j] < pivot) swap(a[++i], a[j]);
    swap(a[i + 1], a[hi]);
    return i + 1;
}

// Deterministic: pivot = last element
void quickSort(vector<int>& a, int lo, int hi) {
    if (lo < hi) {
        int p = partition(a, lo, hi);
        quickSort(a, lo, p - 1);
        quickSort(a, p + 1, hi);
    }
}

// Randomized: pivot = random element
void randomizedQuickSort(vector<int>& a, int lo, int hi) {
    if (lo < hi) {
        int r = lo + rand() % (hi - lo + 1);
        swap(a[r], a[hi]);
        int p = partition(a, lo, hi);
        randomizedQuickSort(a, lo, p - 1);
        randomizedQuickSort(a, p + 1, hi);
    }
}

void print(const vector<int>& a) {
    for (int x : a) cout << x << " ";
    cout << "\n";
}

int main() {
    srand(time(0));
    vector<int> a = {10, 7, 8, 9, 1, 5, 3, 6, 2, 4};
    vector<int> b = a;

    quickSort(a, 0, a.size() - 1);
    cout << "Deterministic: "; print(a);

    randomizedQuickSort(b, 0, b.size() - 1);
    cout << "Randomized:    "; print(b);
}
