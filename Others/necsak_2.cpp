#include <bits/stdc++.h>
using namespace std;

signed main() {
    #ifdef LUCTIVUD
      freopen("/home/luctivud/CPPractice/Zinput.txt", "r", stdin);
      freopen("/home/luctivud/CPPractice/Zoutput.txt", "w", stdout);
    #endif

    string s1, s2; cin >> s1 >> s2;

    int n = s1.size(), m = s2.size();
    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (i + m >= n) break;
        bool ok = true;
        for (int j = 0; j < m; j++) {
            if (s1[i+j] != s2[j]) {
                ok = false;
                break;
            }
        }
        ans += ok;
    }
    cout << ans;
    
    return 0;
}
