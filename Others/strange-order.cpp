#include<bits/stdc++.h>
using namespace std;

int main() {
    #ifdef LUCTIVUD
      // const auto start_time = std::chrono::high_resolution_clock::now();
      freopen("/home/luctivud/CPPractice/Zinput.txt", "r", stdin);
      freopen("/home/luctivud/CPPractice/Zoutput.txt", "w", stdout);
    #endif

    int n; cin >> n;
    pair<int, int> arr[n];
    arr[0] = {1, 1};

    int spf[n+1] = {0};
    spf[1] = 1;

    for (int i = 2; i <= n; i++) {
        if (spf[i] != 0) continue;
        spf[i] = i;
        for (int j = 2 * i; j <= n; j += i) {
            if (spf[j] != 0) continue;
            spf[j] = i;
        }
    }

    // // debug
    // for (int i = 1; i <=n; i++) {
    //     cout << i << " " << spf[i] << "\n";
    // }

    for (int i = 1; i < n; i++) {
        arr[i] = {i+1, (n / (spf[i+1])) * (spf[i+1])};
    }

    // // debug
    // for (int i = 0; i < n; i++) {
    //     cout << arr[i].first << " " << arr[i].second << "\n";
    // }

    sort(arr, arr+n, [](pair<int, int> &a, pair<int, int> &b) {
        return a.second == b.second ? a.first > b.first : a.second > b.second;
    });

    for (int i = 0; i < n; i++) {
        cout << arr[i].first << " ";
    }
    return 0;
}