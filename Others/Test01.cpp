#include <bits/stdc++.h>

using namespace std;

typedef long long int lld;

signed light() {

    ios_base::sync_with_stdio(false); cin.tie(0);
    cout.precision(10); cout << fixed;

    #ifdef LUCTIVUD
      freopen("/home/luctivud/CPPractice/Zinput.txt", "r", stdin);
      freopen("/home/luctivud/CPPractice/Zoutput.txt", "w", stdout);
    #endif

    return 0;
}



void solve() {
	lld n, m; cin >> n >> m;

	lld boxes[n][7] = {0};

	lld dp[n+1][7] = {0};

	for (int i = 0; i < m; ++i) {
		lld bi, ci, vi;
		cin >> bi >> ci >> vi;
		ci--; bi--;
		boxes[bi][ci] = max(vi, boxes[bi][ci]);
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 7; j++) {
			dp[i+1][j] = -1;
			if (boxes[i][j] == 0ll) {
				dp[i+1][j] = -1ll;
			} else {
				for (int k = 0; k < 7; k++) {
					if (j != k and dp[i][k] != -1) {
						dp[i+1][j] = max(boxes[i][j] + dp[i][k], dp[i+1][j]);
					}
				}
			}
		}
	}

	lld ans = -1ll;

	for (int i = 0; i < 7; i++) {
		ans = max(ans, dp[n][i]);
	}

	cout << ans << "\n";

}

signed main() {

    light();
    int T; cin >> T;

    while (T--) {
    	solve();
    }
    return 0;
}
