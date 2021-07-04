#include <bits/stdc++.h>
#pragma GCC optimize "trapv"

using namespace std;

typedef long long int lld;

signed main() {
    
    // Input - Output and optimization
    
    ios_base::sync_with_stdio(false); cin.tie(0);
    cout.precision(10); cout << fixed;

    #ifdef LUCTIVUD
      freopen("/home/luctivud/CPPractice/Zinput.txt", "r", stdin);
      freopen("/home/luctivud/CPPractice/Zoutput.txt", "w", stdout);
    #endif

    int n; 
    cin >> n;
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 2; j <= n; j++) {
            if (i % j != 0) {
                // if (j > 10) cout << j << "\n";
                if (!(i % 6))
                cout << i << " " << j << "\n";
                break;
            }
        }
    }

    return 0;
}
