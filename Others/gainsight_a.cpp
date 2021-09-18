#include<bits/stdc++.h>
using namespace std;


void compareElements(int &l, int &r) {

    if (to_string(r) < to_string(l)) {
        swap(l, r);
    }
}


void selection_sort(vector<int> &numbers, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            compareElements(numbers[i], numbers[j]);
        }
    }
}


// void merge_sort(vector<int> &numbers, int n, int l, int r) {
//     return;
//     if (l == r) {

//     }
//     vector<int> a, b;

// }


signed main() {
    int n;
    cin >> n;
    vector<int> numbers(n);

    for (auto &i : numbers) {
        cin >> i;
    }

    selection_sort(numbers, n);

    string ans;

    for (auto i : numbers) {
        ans += to_string(i);
    }

    cout << ans;

    return 0;
}