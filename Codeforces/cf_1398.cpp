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
#define              deb(x)    cout << #x << "=" << (x) << "\n";


lld a, b, c;	

bool sortinrev(const pair<int, int> &a, const pair<int, int> &b) {
	return (a.first > b.first);
}

lld solve(vector<lld>va, vector<lld>vb, vector<lld>vc, lld ai, lld bi, lld ci, vector<vector<lld>> &dp) {

}


void solveEachTest(lld T35TC453N = 1) {
	cin >> a >> b >> c;
	vector<lld> va(a), vb(b), vc(c);
	_input(va); _input(vb); _input(vc);
	sort(va.begin(), va.end(), greater<lld>());
	sort(vb.begin(), vb.end(), greater<lld>());
	sort(vc.begin(), vc.end(), greater<lld>());
	// for (auto i : vb) cout << i << " ";
	vector<vector<lld>> dp (a+b+c, vector<lld>(3, -1));
	
	cout << solve(va, vb, vc, ai, bi, ci, dp);
	return;
}


signed main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.precision(10);

	lld T3X0 = 0, T353 = 1;

	// TESTCASES()
	solveEachTest(T353 - T3X0);
	return 0;
}
// Random Thought :  null