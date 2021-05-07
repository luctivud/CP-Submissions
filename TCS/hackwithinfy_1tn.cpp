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


    lld a, b, numP, numW, costP, costW;
    cin >> a >> b >> numP >> numW >> costP >> costW;
    lld ans = 0ll;

    for (lld i = 0; i <= numP; i++) {
    	if (i * costP > a) break;
    	lld remCoins = a - (i * costP);
    	lld pink2 = min({i, b/costP, numP - i});
    	lld remCoins2 = b - (pink2 * costP);
    	lld remainingWhite = numW;
    	lld moreWhite = min(remCoins2 / costW, remainingWhite);
    	remainingWhite = numW - moreWhite;
    	lld extraWhite = min(remCoins / costW, numW);
    	ans = max(ans, i + pink2 + moreWhite + extraWhite);
    }
 
    cout << ans;

    return 0;
}
