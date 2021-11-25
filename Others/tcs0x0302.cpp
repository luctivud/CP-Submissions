#include<bits/stdc++.h>
using namespace std;

int main() {
    #ifdef LUCTIVUD
        // const auto start_time = std::chrono::high_resolution_clock::now();
        freopen("/home/luctivud/CPPractice/Zinput.txt", "r", stdin);
        freopen("/home/luctivud/CPPractice/Zoutput.txt", "w", stdout);
    #endif
    int n, m; cin >> n >> m;
    int arr[n], brr[m];

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    for (int i = 0; i < m; i++) {
        cin >> brr[i];
    }

    multiset<int> ml;
    for (int i = 0; i < n; i++) {
        ml.insert(arr[i]);
    }

    int ans = 1;
    while (ml.size()) {
        
    }

    cout << ans;

}