#include <bits/stdc++.h>
using namespace std;


#ifdef LUCTIVUD
#include <buggyBaby.hpp>
pretty:: PrettyPrinter NonIterable;
#define cerr cout
#else
#define _____error_____(...)
#endif

#define int long long int

void solve(void) {
    int N;
    cin >> N;
    int sz;
    int res = 0;
    priority_queue<int> pq;
    for (int i = 0 ; i < N ; i++) {
        cin >> sz;
        vector<int> temp(sz);
        for (int j = 0 ; j < sz ; j++) cin >> temp[j];
        deque<int> breakPoints;
        // _____error_____(temp);
        // breakPoints.push_back(0);
        for (int j = 0 ; j < sz ; j++) {
            if (j - 1 >= 0 and temp[j] < temp[j - 1]) {
                // _____error_____(min(x, sz - i + 1));
                // res += min(x , sz - i + 1);
                // pq.push(-x);
                // x = 1;
                breakPoints.push_back(j);
            }
        }
        // breakPoints.push_back(sz);
        _____error_____(breakPoints);
        if ((breakPoints.size()) == 0) {
            pq.push(-sz);
            continue;
        }
        int ind1 = 0, ind2 = sz;
        while (breakPoints.size() > 0) {
            if (breakPoints.front() - ind1 <= ind2 - breakPoints.back()) {
                res += breakPoints.front() - ind1;
                pq.push(-breakPoints.front() + ind1);
                ind1 = breakPoints.front();
                breakPoints.pop_front();
            } else {
                res += ind2 - breakPoints.back();
                pq.push(-ind2 + breakPoints.back());
                ind2 = breakPoints.back();
                breakPoints.pop_back();
            }
            _____error_____(res);
        }

        // pq.push(-x);
        // NonIterable.print(pq);
    }

    // NonIterable.print(pq);

    while (pq.size() > 1) {
        int x1 = -pq.top();
        pq.pop();
        int x2 = -pq.top();
        pq.pop();
        pq.push(-(x1 + x2));
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