#include <bits/stdc++.h>

using namespace std;

typedef long long int lld;
signed main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	#ifdef LUCTIVUD
	  freopen("/home/luctivud/CPPractice/Zinput.txt", "r", stdin);
	  freopen("/home/luctivud/CPPractice/Zoutput.txt", "w", stdout);
	#endif
	lld n, k; cin >> n >> k;
	lld arr[n];
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	lld dp[k + 1] = {0};
	for (int i = 1; i < k + 1; i++) {
		dp[i] = (lld)(1e9);
	}

	for (int i = 0; i < k + 1; i++) {
		for (int j = 0; j < n; j++) {
			if (i - arr[j] >= 0) {
				dp[i] = min(dp[i], 1 + dp[i - arr[j]]);
			}
		}
	}

	cout << ((dp[k] == lld(1e9)) ? -1 : dp[k]);

	return 0;
}
