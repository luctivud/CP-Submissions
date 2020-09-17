
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



// const int maxn = int(2e8) + 1;
const int modulo = int(1e9) + 7;


void solveEachTest(lld T35TC453N = 1) {
	// input part
	lld n, k, w; cin >> n >> k >> w;
	vector <lld> L(k), H(k);
	_input(L);
	lld al, bl, cl, dl; cin >> al >> bl >> cl >> dl;
	_input(H);
	lld ah, bh, ch, dh; cin >> ah >> bh >> ch >> dh;

	// previous two 
	// lld liminus2 = L[k-2], liminus1 = L[k-1];
	// lld himinus2 = H[k-2], himinus1 = H[k-1];

	// prev_perimeter : , ans : , prev_end :
	lld prev_perimeter = 0ll;
	lld ans = 1ll;
	lld prev_end = 0ll;

	for4(i, 0, k, 1) {
		if (i == 0) {
			prev_end = L[i] + w;
			lld this_perimeter = 2 * (H[i] + w);
			ans = this_perimeter;
			prev_perimeter = this_perimeter;
		} else {
			if (L[i] > prev_end) {
				prev_perimeter += 2 * (H[i] + w);
			} else {
				lld incr = (H[i] - H[i-1]);
				// _|```|
				if (incr > 0) {
					prev_perimeter += w;
					prev_perimeter += 2 * incr;
					prev_perimeter += L[i] + w - prev_end;
				} else if (incr == 0) {
					prev_perimeter += 2 * (L[i] + w - prev_end);
				} else {
					prev_perimeter += 2 * (L[i] + w - prev_end);
				}
			}
			prev_end = L[i] + w;
			ans *= prev_perimeter;
		}
		deb(prev_perimeter);	
	}


	cout << "Case #" << T35TC453N << ": " << ans << "\n";
	return;
}


signed main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.precision(10);

	lld T3X0 = 0, T353 = 1;

	TESTCASES()
	solveEachTest(T353 - T3X0);
	return 0;
}

