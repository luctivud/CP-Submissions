#include <bits/stdc++.h>
using namespace std;
#ifdef LUCTIVUD
#include <buggyBaby.hpp>
pretty:: PrettyPrinter NonIterable;
#define cerr cout
#else
#define _____error_____(...)
#endif
#pragma GCC optimize "trapv"


typedef long long int lld;

class UDSort {
public:
    vector<int> sorted_arr;
    UDSort(vector<int> arr1) {
        sorted_arr = arr1;
    }
    void merge_sort(int l, int r) {
        if (l < r) {
            int mid = l + (r - l) / 2;
            merge_sort(l, mid);
            merge_sort(mid, r);
            merge(l, r, mid);
        }
    }
    void merge(int l, int r, int mid) {
        int i = mid - 1, j = r - 1;
        while (i >= l and j >= mid) {

        }
    }
};

signed main() {

    // Input - Output and optimization

    ios_base::sync_with_stdio(false); cin.tie(0);
    cout.precision(10); cout << fixed;

#ifdef LUCTIVUD
    freopen("/home/luctivud/CPPractice/Zinput.txt", "r", stdin);
    freopen("/home/luctivud/CPPractice/Zoutput.txt", "w", stdout);
#endif

    vector<int> arr {1, 4, 7, 2, 3, 9, 7, 4};
    UDSort ArrObj(arr);

    _____error_____(ArrObj.sorted_arr);

    return 0;
}
