#include <bits/stdc++.h>
#pragma GCC optimize "trapv"

using namespace std;

typedef long long int lld;

signed main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	lld n; cin >> n;
	lld ans1 = 1ll;
	lld MOD = lld(1e9)+7ll;
	for (lld i = 1ll; i <= n; i++) {
		ans1  = (ans1 % MOD * i % MOD) % MOD;
	}

	lld ans2 = 1ll;

	for (lld i = 1ll; i<n; i++) {
		ans2 = ((ans2 * 2) % MOD);
	}

	cout << (ans1 + MOD - ans2) % MOD;

	return 0;
}
