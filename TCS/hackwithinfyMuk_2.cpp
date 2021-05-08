#include <bits/stdc++.h>
#pragma GCC optimize "trapv"

using namespace std;


typedef long long int lld;

lld blocksGame(lld N) {
	if (N & 1) return 0ll;

	vector<lld> dp1(N+1, 0), dp2(N+1, 0);
	dp1[0] = 1, dp2[1] = 1;
	
	for (lld i = 2; i <= N; i++) {
		dp1[i] = dp1[i-2] + 2 * dp2[i-1];
		dp2[i] = dp1[i-1] + dp2[i-2];
	}

	return dp1[N];
}


signed main() {
	
	// Input - Output and optimization
	
    ios_base::sync_with_stdio(false); cin.tie(0);
    cout.precision(10); cout << fixed;

    #ifdef LUCTIVUD
      freopen("/home/luctivud/CPPractice/Zinput.txt", "r", stdin);
      freopen("/home/luctivud/CPPractice/Zoutput.txt", "w", stdout);
    #endif

    lld n; cin >> n;
    cout << blocksGame(n);
    return 0;
}
