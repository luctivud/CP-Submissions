//  J A I  S H R E E  R A M  //

#include <bits/stdc++.h>

#pragma GCC optimize "trapv"
// #pragma GCC optimize ("Ofast")
// // #pragma GCC target ("fpmath=sse,sse2")
// #pragma GCC target ("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx")
// #pragma GCC optimize ("-ffloat-store")


using namespace std;

typedef long long int lld;
typedef unsigned long long int llu;

#define        forn(I7, E4)    for(lld I7=0ll; I7 < E4; (I7)+=1ll)
#define       forn1(I7, E4)    for(lld I7=1ll; I7 < E4+1; (I7)+=1ll)
#define              len(v)    ((int)((v).size()))
#define              all(x)    (x).begin(), (x).end()
#define             rall(x)    (x).rbegin(), (x).rend()
#define                  f1    first
#define                  s2    second

template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template < typename T_container, typename T = typename enable_if < !is_same<T_container, string>::value, typename T_container::value_type >::type >
ostream & operator<<(ostream &os, const T_container &v) { os << '{'; string sep; for (const T &x : v) os << sep << x, sep = ", "; return os << '}'; }
void dbg_out() { cout << "\n"; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cout << H << ", "; dbg_out(T...);}
#define _____error_____(...) cout << #__VA_ARGS__ << " : ", dbg_out(__VA_ARGS__)

const lld d4i[4] = { -1, 0, 1, 0}, d4j[4] = {0, 1, 0, -1};
const lld d8i[8] = { -1, -1, 0, 1, 1, 1, 0, -1}, d8j[8] = {0, 1, 1, 1, 0, -1, -1, -1};


const long double EPS = 1e-6;
lld TempVar, mod, MOD;


/*
:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
*/



lld power(lld x, lld y) {
	lld res = 1;

	x = x % MOD;

	if (x == 0) return 0;

	while (y > 0)  {
		if (y & 1)
			res = (res * x) % MOD;
		y = y >> 1;
		x = (x * x) % MOD;
	}
	return res;
}




void matrMul(vector<lld> &ans, lld k) {
	// Calculate M ^ k;;
	if (k == 0) return;

	vector<vector<lld>> MaGiC(2, vector<lld>(2));

	MaGiC[0][0] = 0, MaGiC[0][1] = 1;
	MaGiC[1][0] = 3, MaGiC[1][1] = 2;

	while (k > 0) {
		if (k & 1) {
			// MaGiC * ans
			lld T0 = ans[0], T1 = ans[1];
			ans[0] = ((MaGiC[0][0] * T0) % MOD + (MaGiC[0][1] * T1) % MOD) % MOD;
			ans[1] = ((MaGiC[1][0] * T0) % MOD + (MaGiC[1][1] * T1) % MOD) % MOD;
		}
		k >>= 1;
		// MaGiC * MaGiC;
		lld T00 = MaGiC[0][0], T01 = MaGiC[0][1], 
			T10 = MaGiC[1][0], T11 = MaGiC[1][1];

		MaGiC[0][0] = ((T00 * T00) % MOD + (T01 * T10) % MOD) % MOD; 
		MaGiC[0][1] = ((T00 * T01) % MOD + (T01 * T11) % MOD) % MOD; 
		MaGiC[1][0] = ((T10 * T00) % MOD + (T11 * T10) % MOD) % MOD; 
		MaGiC[1][1] = ((T10 * T01) % MOD + (T11 * T11) % MOD) % MOD; 
		// _____error_____(MaGiC);
		// _____error_____(ans);
	}
}




void solveEachTest(int _TestCase) {
	// cout << "Case #" << _TestCase << ": ";
	lld n; cin >> n;

	vector<lld> ans = {1, 0};

	matrMul(ans, n);

	cout << ans[0];

	return;
}


signed main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	// cout.precision(10); cout << fixed;
#ifdef LUCTIVUD
	// const auto start_time = std::chrono::high_resolution_clock::now();
	freopen("/home/luctivud/CPPractice/Zinput.txt", "r", stdin);
	freopen("/home/luctivud/CPPractice/Zoutput.txt", "w", stdout);
#endif


	MOD = mod = lld(1e9) + 7ll;
	lld _T0T4 = 1;
	// cin >> _T0T4;

	for (int _TestCase = 1; _TestCase <= _T0T4; _TestCase++) {
		solveEachTest(_TestCase);
		cout << "\n";
	}


#ifdef LUCTIVUD
	// auto end_time = std::chrono::high_resolution_clock::now();
	// std::chrono::duration<double> diff = end_time - start_time;
	// cerr << "Finished in : " << diff.count() << "\n";
#endif

	return 0;
}


/*  ~~
Author   :  Udit "luctivud" Gupta
linkedin :  https://www.linkedin.com/in/udit-gupta-1b7863135/
*/
