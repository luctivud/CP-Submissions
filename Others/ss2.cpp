#include <bits/stdc++.h>
#pragma GCC optimize "trapv"

using namespace std;

typedef long long int lld;
#define int lld


void solve() {
    string s; cin >> s;
    int n = (int)s.size();
    int res[n];
    for (int i = 0; i < n; i++) {
        res[i] = (s[i] == '0' ? -1 : 1);
        cout << res[i] << " ";
    }

    cout << kmin(res, n, 1);

    return;
}

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    cout.precision(10); cout << fixed;

    #ifdef LUCTIVUD
      freopen("/home/luctivud/CPPractice/Zinput.txt", "r", stdin);
      freopen("/home/luctivud/CPPractice/Zoutput.txt", "w", stdout);
    #endif

    int t; cin >> t;
    while(t--) {
        solve();
        cout << "\n";
    }
    
    return 0;
}
