/*      ░░█ ▄▀█ █   █▀ █░█ █▀█ █▀▀ █▀▀   █▀█ ▄▀█ █▀▄▀█
        █▄█ █▀█ █   ▄█ █▀█ █▀▄ ██▄ ██▄   █▀▄ █▀█ █░▀░█     */

// Author : Udit "luctivud" Gupta @ (https://www.linkedin.com/in/udit-gupta-1b7863135/)


#include <bits/stdc++.h>
#pragma GCC optimize "trapv"

using namespace std;

typedef long long int lld;
typedef unsigned long long int llu;


#define       TESTCASES()  cin >> (T3X0); T353 = T3X0; while(T3X0--)
#define       _input(V3C)  for(auto &V3C_I7 : (V3C)) cin >> (V3C_I7)
#define mems(A77AY, V4LU)  memset((A77AY), (V4LU), sizeof((A77AY)))
#define  CH3K(I7, E4, S7)  (((S7)<0) ? (I7)>(E4) : (I7)<(E4))
#define for4(I7,S4,E4,S7)  for(auto I7=(S4); CH3K(I7,E4,S7); (I7)+=(S7))




void solveEachTest(lld T35TC453N = 1) {

	string s; cin >> s;
	lld k; cin >> k;

	vector <lld> arr(26);
	_input(arr);

	lld ans = 0ll;
	lld n = (lld) s.length();

	for4(i, 0ll, n, 1ll) {
		ans += (i + 1) * arr[s[i] - 'a'];
	}

	lld mx = *max_element(arr.begin(), arr.end());

	for4(i, n + 1, n + k + 1, 1ll) {
		ans += (mx) * (i);
	}
	cout << ans;
	cout << "\n";

	return;
}


signed main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	lld T3X0 = 0, T353 = 1;

	// TESTCASES()
	solveEachTest(T353 - T3X0);
	return 0;
}
// Random Thought : speed to repro start time : 18:30