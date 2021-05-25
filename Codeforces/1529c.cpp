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

const lld d4i[4]={-1, 0, 1, 0}, d4j[4]={0, 1, 0, -1};
const lld d8i[8]={-1, -1, 0, 1, 1, 1, 0, -1}, d8j[8]={0, 1, 1, 1, 0, -1, -1, -1};


const long double EPS = 1e-6;
lld TempVar, mod, MOD;


/*
:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
*/

const lld MAXN = (lld)1e5 + 2;
lld n; 
pair<lld, lld> arr[MAXN];


void add_undirected_edge(lld a, lld b, vector<lld> adj[]) {
    adj[a].push_back(b);
    adj[b].push_back(a);
    return;
}


lld solve(lld node, lld par, lld zetalr, lld prev, vector<lld> adj[], vector<vector<vector<lld>>> &dp) {
	if (dp[node][prev][0] != -1) {
		return max(dp[node][prev][0], dp[node][prev][1]);
	}
	lld &resL = dp[node][prev][0], &resR = dp[node][prev][1];
	resL = 0ll, resR = 0ll;
	if (node != 1) {
		resL = llabs(zetalr - arr[node].f1);
		resR = llabs(zetalr - arr[node].s2);
	}
	for (auto i : adj[node]) {
		if (i != par) {
			resL += solve(i, node, arr[node].f1, 0, adj, dp);
			resR += solve(i, node, arr[node].s2, 1, adj, dp);
		}
	}
	// _____error_____(node, par, zetalr, resL, resR);
	// return max(dp[node][0], dp[node][1]);
	return max(resL, resR);
}




void solveEachTest(int _TestCase) {
    // cout << "Case #" << _TestCase << ": ";
    
	cin >> n;

	vector<lld> adj[n+1];

	forn1(i, n) {
		cin >> arr[i].f1 >> arr[i].s2;
	}

	forn(i, n-1) {
		lld a, b; cin >> a >> b;
		add_undirected_edge(a, b, adj);
	}

	vector<vector<vector<lld>>> dp(n+1, vector<vector<lld>>(2, vector<lld>(2, -1)));

	cout << solve(1, -1, 0, 0, adj, dp);

    
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
    cin >> _T0T4; 

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
