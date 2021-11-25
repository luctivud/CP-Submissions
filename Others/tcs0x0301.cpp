#include<bits/stdc++.h>
using namespace std;

int main() {
    #ifdef LUCTIVUD
        // const auto start_time = std::chrono::high_resolution_clock::now();
        freopen("/home/luctivud/CPPractice/Zinput.txt", "r", stdin);
        freopen("/home/luctivud/CPPractice/Zoutput.txt", "w", stdout);
    #endif
    int n; cin >> n;
    int arr[n], brr[n];
    int sum1 = 0, sum2 = 0;

    bool odd1 = false, odd2 = false, even1 = false, even2 = false;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        sum1 += arr[i];
        ((arr[i] & 1) ? odd1 : even1) = true;
    }

    for (int i = 0; i < n; i++) {
        cin >> brr[i];
        sum2 += brr[i];
        ((brr[i] & 1) ? odd2 : even2) = true;
    }

    if (((sum1 + sum2) & 1) == 1) {
        cout << "-1\n";
    } else if ((sum1 & 1) == 0 and (sum2 & 1) == 0) {
        cout << "0\n";
    } else {
        if ((odd1 && even2) or (odd2 and even1)) {
            cout << "1\n";
        } else {
            cout << "-1\n";
        }
    }

}