#include <bits/stdc++.h>
#pragma GCC optimize "trapv"

using namespace std;

typedef long long int lld;
#define int lld

void solve() {
    int n; cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int q; cin >> q;
    for (int qq = 0; qq < q; qq++) {
        int c, k; cin >> c >> k;
        set<int> broken;
        for (int kk = 0; kk < k; kk++) {
            int temp; cin >> temp;
            broken.insert(temp-1);
        }
        vector<int> res;
        for (int i = 0; i < n; i++) {
            if (broken.find(i) == broken.end()) {
                res.push_back(arr[i]);
            }
        }
        sort(res.begin(), res.end());
        for (int i = 1; i < (int)res.size(); i++) {
            res[i] += res[i-1];
        }
        cout << upper_bound(res.begin(), res.end(), c) - res.begin() << " ";
    }
}

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(0);

    int t; cin >> t;
    while(t--) {
        solve();
        cout << "\n";
    }

    
    return 0;
}
