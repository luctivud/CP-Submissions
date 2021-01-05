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

    lld n; string s;

    cin >> n >> s;

    char prev = '$';
    lld ans = 0ll;

    for (int i = 0; i < n; i++) {
    	if ((!(ans % 2)) || (prev != s[i])) {
    		prev = s[i];
    		ans += 1;
    	}
    }

    ans -= (ans % 2);

    cout << n - ans << "\n";

    return 0;
}
