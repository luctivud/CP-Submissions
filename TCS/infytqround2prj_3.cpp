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

    lld a, b; cin >> a >> b;

    double zeta = sqrt(((double)(2*(a+b)) + 0.25)) - 0.5;

    lld n = lld(zeta);
    lld res = -1;

    for (lld j = n - 2; j < n+3; j++) {
    	if ((j*(j + 1)) == 2*(a+b)) {
    		res = j;
    		break;
    	}
    }

    cout << res << "res\n";
    if (res == -1) {
    	cout << -1;
    } else {
    	lld ans = 0ll;
    	for (lld i = n; i > 0; i--) {
    		if (a >= i) {
    			ans++;
    			a -= i;
    		}
    	}

    	cout << ans;
    }


    return 0;
}
