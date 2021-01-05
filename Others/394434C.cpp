#include <iostream>
#include <vector>

using namespace std;
typedef long long int lld;

#define         TESTCASES()    cin >> (T3X0); T353 = T3X0; while(T3X0--)
#define          input(V3C)    for(auto &V3C_I7 : (V3C)) cin >> (V3C_I7)
#define   mems(A77AY, V4LU)    memset((A77AY), (V4LU), sizeof((A77AY)))
#define    CH3K(I7, E4, S7)    (((S7)>0) ? (I7)<(E4) : (I7)>(E4))
#define   for4(I7,S4,E4,S7)    for(auto I7=(S4); CH3K(I7,E4,S7); (I7)+=(S7))
#define        forn(I7, E4)    for(lld I7=0ll; I7 < E4; (I7)+=1ll)
#define       forn1(I7, E4)    for(lld I7=1ll; I7 < E4+1; (I7)+=1ll)
#define        EACH(I7, A7)    for (auto& I7: A7)
#define              len(v)    ((int)((v).size()))
#define              all(x)    (x).begin(), (x).end()
#define             rall(x)    (x).rbegin(), (x).rend()
#define                  pb    push_back
#define         debhairu(x)    cout << #x << " = "; println(x);
#define         debspace(x)    cout << #x << " = "; print(x); cout << " ";
#define                  f1    first
#define                  s2    second

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    lld n; cin >> n;
	vector<lld> arr(n);

	forn(i, n) {
		cin >> arr[i];
	}

	lld dp[n] = {0};
	dp[0] = 1;

	forn(i, n) {
		forn(j, i) {
			if (arr[i] > arr[j]) {
				dp[i] = max(dp[i], 1 + dp[j]);
			}
		}
	}

	cout << (dp[n - 1]);

    return 0;
}
