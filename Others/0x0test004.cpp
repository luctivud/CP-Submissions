#include <bits/stdc++.h>
using namespace std;

typedef long long lld; typedef unsigned long long llu;

const lld MOD = lld(1e9) + 7;



lld power(lld x, lld y) {
    lld res = 1;

    x = x % MOD;

    if (x == 0) return 0;

    while (y > 0)  {
        if (y & 1)
            res = (res * x) % MOD;

        y = y >> 1; 
        x = (x * x) % MOD;
    }
    return res;
}



signed main() {

    cin.tie(0)->sync_with_stdio(0);
    cout.precision(10); cout << fixed;

    #ifdef LUCTIVUD
        // const auto start_time = std::chrono::high_resolution_clock::now();
        freopen("/home/udit/CPPrc/zinput.txt", "r", stdin);
        freopen("/home/udit/CPPrc/zoutput.txt", "w", stdout);
    #endif

    int n, k; cin >> n >> k;
    int x[k];
    for (int i = 0; i < k; i++) {
        cin >> x[i];
    }

    map <int, set<char>> forbiddenChars;

    for (int i = 0; i < k; i++) {
        char c; cin >> c;
        forbiddenChars[x[i]].insert(c);

    }

    lld ans = power(26, n - forbiddenChars.size());
    for (auto [ke, va] : forbiddenChars) {
        (ans *= (26 - va.size())) %= MOD;
    }

    cout << ans;

    return 0; 
}




/*  ~~
    .?.?.?.
*/
