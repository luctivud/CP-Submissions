#include <bits/stdc++.h>
using namespace std;



int main() {
	#ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif 
	int n, x;
	cin >> n >> x;
	int coins[n];
	cout << "n" << n << "x" << x << " ";
	int dp[x + 1] = {0};
	for(int  i = 0; i < n; ++i) {
		cin >> coins[i];
		// cout << "coins[i]" << coins[i];
		// cout << "\ndp[coins[i]]" << dp[coins[i]];
		// dp[coins[i]] = 1;	
	}
	
	// sort(coins, coins + n);
	// if(x < coins[0]) {
	// 	cout << -1;
	// 	return 0;
	// }
	// for(int i = 1; i <= x; ++i) {
	// 	if(dp[i] == 1) continue;
	// 	int cn = INT_MAX;
	// 	for (int j = 0; j < n; ++j) {
	// 		if(i - coins[j] < 0) break;
	// 		if(dp[i - coins[j]])
	// 		cn = min(cn, dp[i - coins[j]]);
			
	// 	}
	// 	if(cn != INT_MAX)
	// 	dp[i] = cn  + 1;
	// }
	// if(dp[x])
	// cout << dp[x];
	// else cout << -1;	
	// cout << x;
	return 0;
}