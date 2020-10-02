// ************************.- J A I  S H R E E  R A M -.*************************
 
 
/*
      ::: All is One ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
 
          Author   :  Udit "luctivud" Gupta
 
          linkedin :  https://www.linkedin.com/in/udit-gupta-1b7863135/
          github   :  https://github.com/luctivud
 
      :::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: One is All :::
*/
 
 
#include <bits/stdc++.h>
 
#pragma GCC optimize "trapv"
#pragma GCC optimize ("Ofast")
// #pragma GCC target ("fpmath=sse,sse2")
#pragma GCC target ("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx")
#pragma GCC optimize ("-ffloat-store")
 
 
using namespace std;
 
 
 
typedef long long int lld;
typedef unsigned long long int llu;
 
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
#define           PLEASE_AC    return
 
 
 
template <class T> T inf() {
	return numeric_limits<T>::max();
}
 
const auto start_time = std::chrono::high_resolution_clock::now();
 
signed light() {
 
	ios_base::sync_with_stdio(false); cin.tie(0);
	cout.precision(10); cout << fixed;
 
#ifdef LUCTIVUD
	freopen("/home/luctivud/CPPractice/Zinput.txt", "r", stdin);
	freopen("/home/luctivud/CPPractice/Zoutput.txt", "w", stdout);
#endif
 
	return 0;
}
 
 
signed luctivud() {
 
#ifdef LUCTIVUD
	auto end_time = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double> diff = end_time - start_time;
	cerr << "Finished in : " << diff.count() << "\n";
#endif
 
	return 0;
}
 
 
 
const lld MOD = lld(1e9) + 7ll;
const lld mod = MOD;
 
 
const long double EPS = 1e-6;
 
const lld INFll = inf<lld>();
const int INFi = inf<int>();
 
 
void add_undirected_edge(lld a, lld b, vector<lld> adj[]) {
	adj[a].pb(b);
	adj[b].pb(a);
	return;
}
 
 
 
/*
:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
*/
 
 
const lld maxn = lld(1e6);
 
 
 
 
 
void solveEachTest(lld _TestCase) {
	// cout << "Case#" << _TestCase << ": ";
	lld n, k; cin >> n >> k;
 
	lld arr[n];
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
 
	lld dp[k + 1] = {0};
	for (int i = 1; i < k + 1; i++) {
		dp[i] = (lld)(1e9);
	}
	
	dp[0] = 0ll;
 
	for (int i = 0; i < k + 1; i++) {
		for (int j = 0; j < n; j++) {
			if (i - arr[j] >= 0) {
				dp[i] = min(dp[i - arr[j]] + 1, dp[i]);
			}
		}
	}
 
 
	cout << ((dp[k] == (lld)(1e9)) ? -1 : dp[k]);
 
	// cout << "\n";
	return;
}
 
 
signed main() {
 
	light(); lld T3X0 = 0, T353 = 1;
 
	// TESTCASES()
	solveEachTest(T353 - T3X0);
 
	PLEASE_AC luctivud();
}
 
// Random Thought :  null
/*
        My lungs will fill and then deflate
        They fill with fire, exhale desire
*/