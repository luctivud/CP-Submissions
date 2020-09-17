
#include <bits/stdc++.h>
#pragma GCC optimize "trapv"

using namespace std;

typedef long long int lld;
typedef unsigned long long int llu;

#define         TESTCASES()    cin >> (T3X0); T353 = T3X0; while(T3X0--)
#define         _input(V3C)    for(auto &V3C_I7 : (V3C)) cin >> (V3C_I7)
#define   mems(A77AY, V4LU)    memset((A77AY), (V4LU), sizeof((A77AY)))
#define    CH3K(I7, E4, S7)    (((S7)<0) ? (I7)>(E4) : (I7)<(E4))
#define   for4(I7,S4,E4,S7)    for(auto I7=(S4); CH3K(I7,E4,S7); (I7)+=(S7))
#define              all(x)    (x).begin(), (x).end()
#define              deb(x)    cout << #x << "=" << (x) << " ";

lld n, m;

lld solve(vector<vector<lld>> bitwiseAND, lld ind, vector<lld>& dp) {
	if (ind == n) return 0;
	lld mini = 1ll << 10;
	if (dp[ind] == mini) {
		for4(i, 0ll, m, 1ll) {
			mini = min(mini, bitwiseAND[ind][i] | solve(bitwiseAND, ind + 1, dp));
		}
		dp[ind] = mini;
	}

	// deb(ind);deb(dp[ind]) cout << "\n";
	return dp[ind];
}



void solveEachTest(lld T35TC453N = 1) {
	cin >> n >> m;
	vector<lld> a(n);
	_input(a);
	vector<lld> b(m);
	_input(b);

	// lld bitwiseAND[n][m];
	vector<vector<lld>> bitwiseAND(n, vector<lld> (m));
	for4(i, 0ll, n, 1ll) {
		for4(j, 0ll, m, 1ll) {
			bitwiseAND[i][j] = a[i] & b[j];
			// cout << bitwiseAND[i][j] << " ";
		}
		// cout << "\n";
	}

	// lld ans = 0ll;

	vector<lld>dp(n, 1ll << 10);
	// cout <<	solve(bitwiseAND, 0, dp);
	// for (auto i : dp) cout << i << " ";
	lld done[n] = {0};
	lld maxmin = 0ll;
	lld maxminpos = 0ll;
	for4(i, 0ll, n, 1ll) {
		lld minm = bitwiseAND[i][0];
		for4(j, 1ll, m, 1ll) {
			minm = min(minm, bitwiseAND[i][j]);
		}
		maxmin = max(maxmin, minm);
		if (minm > maxmin) {
			done[maxminpos] = 0;
			maxminpos = i;
			done[maxminpos] = 1;
		}
		// if (minm != 128)
		// ans |= minm;
	}
	lld ans = maxmin;

	for4(i, 0, n, 1) {
		if (!done[i]) {
			lld minm = ans | bitwiseAND[i][0];
			for4(j, 1, m, 1) {
				minm = min(minm, ans | bitwiseAND[i][j]);
			}
			ans = minm;
		}
	}
	cout << ans;

	cout << "\n";

	return;
}


signed main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.precision(10);

	lld T3X0 = 0, T353 = 1;

	// TESTCASES()
	solveEachTest(T353 - T3X0);
	return 0;
}

