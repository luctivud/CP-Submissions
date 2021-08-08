#include <bits/stdc++.h>
using namespace std;
#define int long long int

void solve(void) {
    int N;
    cin >> N;
    int sz;
    int res = 0;
    priority_queue<int> pq2;
    for (int i = 0 ; i < N ; i++) {
        priority_queue<int> pq;
        cin >> sz;
        vector<int> temp(sz);
        for (int j = 0 ; j < sz ; j++) cin >> temp[j];
        int x = 0;
        for (int j = 0 ; j < sz ; j++) {
            if (j - 1 >= 0 and temp[j] < temp[j - 1]) {
                res += min(x , sz - i + 1);
                pq.push(-x);
                x = 1;
            } else {
                x++;
            }
        }
        pq.push(-x);
        while (pq.size() > 1) {
            int x1 = -pq.top();
            pq.pop();
            int x2 = -pq.top();
            pq.pop();
            pq.push(-(x1 + x2));
            res += x1 + x2;
        }
        pq2.push(pq.top());
    }
    while (pq2.size() > 1) {
        int x1 = -pq2.top();
        pq2.pop();
        int x2 = -pq2.top();
        pq2.pop();
        pq2.push(-(x1 + x2));
        res += x1 + x2;
    }
    cout << res << "\n";

    return;
}

int32_t main() {

#ifdef LUCTIVUD
    // const auto start_time = std::chrono::high_resolution_clock::now();
    freopen("/home/luctivud/CPPractice/IO/Zinput.txt", "r", stdin);
    freopen("/home/luctivud/CPPractice/IO/Zoutput.txt", "w", stdout);
#endif

    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}