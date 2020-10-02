#include <bits/stdc++.h>

using namespace std;

typedef long long int lld;
signed main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
#ifdef LUCTIVUD
	freopen("/home/luctivud/CPPractice/Zinput.txt", "r", stdin);
	freopen("/home/luctivud/CPPractice/Zoutput.txt", "w", stdout);
#endif
	const int maxn = int(1e6) + 1;
	lld n, k; cin >> n >> k;
	lld arr[n];
	lld dp[maxn] = {0};
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		dp[arr[i]] = 1;
	}

	const int mod = int(1e9) + 7;

	for (int i = 0; i < k + 1; i++) {
		for (int j = 0; j < n; j++) {
			if (i - arr[j] >= 0) {
				dp[i] += dp[i - arr[j]];
				dp[i] %= mod;
			}
		}
	}

	cout << ((dp[k] == lld(1e9)) ? -1 : dp[k]);

	return 0;
}
